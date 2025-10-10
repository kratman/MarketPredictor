#ifndef MARKETPREDICTOR_PORTFOLIO_H
#define MARKETPREDICTOR_PORTFOLIO_H

#include <vector>
#include "montecarlo_asset.h"


class AssetPortfolio {
    std::vector<SoloAsset> all_assets;

    AssetPortfolio() = default;

    ~AssetPortfolio() = default;

    void add_asset(SoloAsset const& new_asset) {
        all_assets.push_back(new_asset);
    }
};

#endif //MARKETPREDICTOR_PORTFOLIO_H