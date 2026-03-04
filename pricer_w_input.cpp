#include <iostream>
#include <cmath> 
#include <iomanip> 

double standardNormalCDF(double x) {
    return 0.5 * std::erfc(-x / std::sqrt(2.0));
}

double calculateCallPrice(double S, double K, double T, double r, double sigma) {
    double d1 = (std::log(S / K) + (r + 0.5 * std::pow(sigma, 2.0)) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);
    double callPrice = S * standardNormalCDF(d1) - K * std::exp(-r * T) * standardNormalCDF(d2);
    return callPrice;
}

int main() {
    double stockPrice, strikePrice, timeToMaturity, riskFreeRate, volatility;

    std::cout << "=======================================" << std::endl;
    std::cout << "  High-Speed Options Pricer (C++)      " << std::endl;
    std::cout << "=======================================" << std::endl;

    // 2. Prompt the user and capture their input
    std::cout << "Enter current Stock Price (e.g., 100.0): ";
    std::cin >> stockPrice;

    std::cout << "Enter Strike Price (e.g., 100.0): ";
    std::cin >> strikePrice;

    std::cout << "Enter Time to Maturity in years (e.g., 1.0): ";
    std::cin >> timeToMaturity;

    std::cout << "Enter Risk-Free Rate as a decimal (e.g., 0.05): ";
    std::cin >> riskFreeRate;

    std::cout << "Enter Volatility as a decimal (e.g., 0.20): ";
    std::cin >> volatility;

    // 3. Calculate the price using our engine
    double optionPrice = calculateCallPrice(stockPrice, strikePrice, timeToMaturity, riskFreeRate, volatility);

    // 4. Print the final answer, formatted like real money!
    std::cout << "\n---------------------------------------" << std::endl;
    std::cout << "The fair price of the European Call is: $" 
              << std::fixed << std::setprecision(2) << optionPrice << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    return 0;
}