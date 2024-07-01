#include <Rcpp.h>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm> 

// [[Rcpp::export]]
std::vector<double> simulate_option_prices(int num_simulations, double S0, double K1, double K2, double K3, double sigma, double r, double T, double barrier, bool is_down_and_out) {
    auto rand_normal = [](double mean, double stddev) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::normal_distribution<> d(mean, stddev);
        return d(gen);
    };

    auto simulate_asset_path = [&](double S0, double mu, double sigma, double T, int steps) {
        std::vector<double> path(steps + 1);
        path[0] = S0;
        double dt = T / steps;
        for (int i = 1; i <= steps; ++i) {
            double dWt = rand_normal(0, sqrt(dt));
            path[i] = path[i-1] * exp((mu - 0.5 * sigma * sigma) * dt + sigma * dWt);
        }
        return path;
    };

    auto calculate_payoff = [&](const std::vector<double>& path, double K1, double K2, double K3, double barrier, bool is_down_and_out) {
        double ST = path.back();
        if ((is_down_and_out && *std::min_element(path.begin(), path.end()) <= barrier) || 
            (!is_down_and_out && *std::max_element(path.begin(), path.end()) >= barrier)) {
            return 0.0;
        }
        double payoff_long_OTM = std::max(K1 - ST, 0.0);
        double payoff_short_ATM = -2 * std::max(K2 - ST, 0.0);
        double payoff_long_ITM = std::max(K3 - ST, 0.0);
        return payoff_long_OTM + payoff_short_ATM + payoff_long_ITM;
    };

    int steps = 100;
    double sum_payoffs = 0.0;
    std::vector<double> option_prices;

    for (int i = 0; i < num_simulations; ++i) {
        auto path = simulate_asset_path(S0, r, sigma, T, steps);
        double payoff = calculate_payoff(path, K1, K2, K3, barrier, is_down_and_out);
        double discounted_payoff = exp(-r * T) * payoff;
        sum_payoffs += discounted_payoff;
        option_prices.push_back(discounted_payoff);
    }

    return option_prices;
}
