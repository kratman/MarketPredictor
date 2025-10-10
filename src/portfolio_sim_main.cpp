#include <iostream>
#include <vector>

#include <cstdlib>
#include "brownian_asset.h"
#include "montecarlo_asset.h"
using namespace std;

int main() {
    srand(time(nullptr));
    constexpr double numberOfTrials = 10;
    constexpr double numberOfSteps = 1000;
    std::vector<SoloAsset> all_assets;

    for (int i=0; i < numberOfTrials; i++) {
        constexpr double price = 44.06;
        constexpr double meanReturn = 0.000284685088744;
        constexpr double variance = 0.011551333339698;
        all_assets.emplace_back(price, meanReturn, variance);
    }
    
    cout << "Step";
    for (int i=0; i < numberOfTrials; i++) {
        cout << ", Price " <<  i;
    }
    cout << endl;

    cout << 0;
    for (const auto & an_asset : all_assets) {
        cout << ", " << an_asset.get_price();
    }
    cout << endl;

    for (int i=0; i < numberOfSteps; i++) {
        cout << i+1;
        for (auto & an_asset : all_assets) {
            an_asset.update_asset();
            cout << ", " << an_asset.get_price();
        }
        cout << endl;
    }
    return 0;
}