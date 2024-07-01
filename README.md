# AsianOpt: Monte Carlo Simulation for Option Pricing

## Project Description

AsianOpt is a Monte Carlo simulation project aimed at pricing Asian options with barriers. This project leverages C++ for computational efficiency and R for easy integration and visualization. The primary objective is to analyze the relationship between the theoretical price of a portfolio of options and various underlying factors such as the price of the underlying instrument and the level of the barrier.

## Installation

### Prerequisites

- **R** (version 4.4.1 or later)
- **Rtools** for Windows
- **Rcpp** package in R
- **RStudio** (recommended)

### Steps

1. **Install R and RStudio**:
   - Download and install R from [CRAN](https://cran.r-project.org/).
   - Download and install RStudio from [RStudio](https://www.rstudio.com/products/rstudio/download/).

2. **Install Rtools**:
   - Download and install Rtools from [CRAN Rtools](https://cran.r-project.org/bin/windows/Rtools/).

3. **Install Required R Packages**:
   Open RStudio and run the following commands to install the necessary packages:
   ```r
   install.packages("Rcpp")
4. **Project Structure**

- `DESCRIPTION`: Contains metadata about the package.
- `NAMESPACE`: Manages the exported functions and dependencies.
- `R/`: Directory containing R scripts.
  - `simulate_option_prices.R`: R wrapper function for the C++ simulation.
- `src/`: Directory containing C++ source code.
  - `simulate_option_prices.cpp`: C++ code for simulating option prices.
5. **Usage**

To use the functions provided in this package:

1. Load the `AsianOpt` package.
2. Define the parameters for your option pricing.
3. Call the `simulate_option_prices` function with the defined parameters.
4. Print the result.

For a detailed example, refer to the `simulate_option_prices.R` script in the `R` directory.

6. **Example Parameters**

- `num_simulations`: Number of simulations (e.g., 1000)
- `S0`: Initial stock price (e.g., 115)
- `K1`: Strike price of the first put option (e.g., 105)
- `K2`: Strike price of the second put option (e.g., 110)
- `K3`: Strike price of the third put option (e.g., 115)
- `sigma`: Volatility (e.g., 0.25)
- `r`: Risk-free rate (e.g., 0.05)
- `T`: Time to maturity in years (e.g., 5/12)
- `barrier_down`: Barrier level for down-and-out options (e.g., 0.8 * S0)
- `barrier_up`: Barrier level for up-and-out options (e.g., 1.2 * S0)
- `is_down_and_out`: Boolean indicating if the option is down-and-out (e.g., TRUE)

7. **Running the Simulation**

After setting up the parameters, you can run the simulation by calling the `simulate_option_prices` function in R. The function will return a vector of simulated option prices based on the defined parameters.

To execute the function, ensure that your R session has loaded the required packages and sourced the C++ code correctly. Then, call the function with the specified parameters to perform the simulation and obtain the results.
