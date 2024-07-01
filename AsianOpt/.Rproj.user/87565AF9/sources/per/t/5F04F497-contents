# Load the required packages
install.packages("Rcpp")
library(Rcpp)

# Source the C++ code using the correct path
sourceCpp("C:/Users/Afat/Documents/UW - MASTER/2Y2S/CPP/Ibadova2/AsianOpt/src/simulate_option_prices.cpp")

# Define the parameters based on the project requirements
num_simulations <- 1000
S0 <- 115
K1 <- 105
K2 <- 110
K3 <- 115
sigma <- 0.25
r <- 0.05
T <- 5/12
barrier_down <- 0.8 * S0  # 20% below S0
barrier_up <- 1.2 * S0    # 20% above S0
is_down_and_out <- TRUE

# Call the function defined in your C++ code
result <- simulate_option_prices(
  num_simulations = num_simulations,
  S0 = S0,
  K1 = K1,
  K2 = K2,
  K3 = K3,
  sigma = sigma,
  r = r,
  T = T,
  barrier = barrier_down,  # or barrier_up depending on the type of option
  is_down_and_out = is_down_and_out
)

# Print the result
print(result)
