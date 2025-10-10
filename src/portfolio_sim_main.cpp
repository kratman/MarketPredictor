#include <iostream>
#include <vector>

#include <cstdlib>
#include "brownian_asset.h"
#include "montecarlo_asset.h"
#include "portfolio.h"
using namespace std;

int main() {
    srand(time(nullptr));
    constexpr double price = 44.06;
    constexpr double meanReturn = 0.000284685088744;
    constexpr double variance = 0.011551333339698;
    constexpr double number_of_trials = 1;
    constexpr double number_of_steps = 1000;
    std::vector<SoloAsset> all_assets;
    auto portfolio = AssetPortfolio(number_of_trials);
    portfolio.add_asset(SoloAsset(price, meanReturn, variance, "First"));
    portfolio.add_asset(SoloAsset(2*price, meanReturn, variance, "Second"));
    portfolio.run_simulations(number_of_steps);
    return 0;
}