#include <iostream>
#include "read_input.h"
using namespace std;

AssetPortfolio read_portfolio() {
    string dummy;
    unsigned int number_of_samples, number_of_steps, number_of_assets;
    cin >> dummy >> number_of_samples;
    cin >> dummy >> number_of_steps;
    auto full_portfolio = AssetPortfolio(number_of_samples, number_of_steps);
    cin >> dummy >> number_of_assets;
    for (int i=0; i<number_of_assets; i++) {
        string name;
        double price, mean_return, variance;
        cin >> dummy >> name;
        cin >> dummy >> price;
        cin >> dummy >> mean_return;
        cin >> dummy >> variance;
        full_portfolio.add_asset(SoloAsset(price, mean_return, variance, name));
    }
    return full_portfolio;
}
