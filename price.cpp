#include <iostream>
#include <cmath> // C++ Math Library
#include <iomanip> // "Input/Output Manipulation" for formatting currency


// whatever is in the curly brackets of main gets executed when we run the program, the int next to it is the return type, which is an integer in this 
// case

// Our custom function to calculate the Normal Distribution CDF
double standardNormalCDF(double x) {
    //We are declaring a new function. 
    // The first double means this function will spit out a decimal number as its final answer. 
    // standardNormalCDF is just the name we gave it. 
    // (double x) means that whenever we use this function, 
    // we must feed it a decimal number (which it will temporarily call x while it does the math).

    // The Black-Scholes formula needs the area under the normal distribution curve 
    // (the probability that a random variable is less than $x$). 
    // C++ doesn't have a direct "finance" normal distribution function, but it does have something 
    // called the "Complementary Error Function" (std::erfc). 
    // We use a well-known statistical conversion to turn the error function into our required 
    // Cumulative Density Function (CDF):
    return 0.5 * std::erfc(-x / std::sqrt(2.0));
}

// The Black-Scholes Math Engine
double calculateCallPrice(double S, double K, double T, double r, double sigma) {
    // 1. Calculate d1
    double d1 = (std::log(S / K) + (r + 0.5 * std::pow(sigma, 2.0)) * T) / (sigma * std::sqrt(T));
    
    // 2. Calculate d2
    double d2 = d1 - sigma * std::sqrt(T);

    // 3. Calculate the Call Price
    double callPrice = S * standardNormalCDF(d1) - K * std::exp(-r * T) * standardNormalCDF(d2);
    
    return callPrice;
}

int main() {
    // 1. Declare our financial variables using Strict Typing
    // This is Strict Typing in action. Unlike Python, C++ needs to know exactly how much computer memory to reserve for a variable. 
    // double stands for "double-precision floating-point format"—which is just a fancy computer science term for a number with decimals. 
    // We use double for all our financial variables because prices, rates, and volatilities require decimals.

    double stockPrice = 100.0;      // Current price of the underlying stock (S)
    double strikePrice = 100.0;     // Strike price of the option (K)
    double timeToMaturity = 1.0;    // Time to expiration in years (T)
    double riskFreeRate = 0.05;     // Risk-free interest rate (r) - 5%
    double volatility = 0.20;       // Volatility of the stock (sigma) - 20%

    // 2. Print a test message to the screen
    // This stands for "Character Output" from the "Standard" (std) library. It pushes the text inside the quotation marks to your screen. 
    // << std::endl just tells the program to hit "Enter" and start a new line after printing.
    std::cout << "Welcome to the High-Speed Options Pricer!" << std::endl;
    double optionPrice = calculateCallPrice(stockPrice, strikePrice, timeToMaturity, riskFreeRate, volatility);
    std::cout << "The fair price of the European Call Option is: $" << optionPrice << std::endl;

    return 0;
}