#ifndef MARKETPREDICTOR_MONTECARLO_ASSET_H
#define MARKETPREDICTOR_MONTECARLO_ASSET_H

#include <cmath>
#include "base_asset.h"


class SoloAsset final : public Asset {
    double logMeanReturn;
    double standardDeviation;

    double calculate_jump() const {
        return standardDeviation * get_rand();
    }

    double calculate_drift() const {
        return logMeanReturn - (0.5 * standardDeviation * standardDeviation);
    }

public:
    SoloAsset(
        double const price, double const mean, double const variance, std::string const& asset_name="Price") {
        this->price = price;
        this->logMeanReturn = mean;
        this->standardDeviation = variance;
        this->name = asset_name;
    }

    void update_asset() override {
        auto const change = calculate_drift() + calculate_jump();
        price *= std::exp(change);
    }

    ~SoloAsset() override = default;
};

#endif //MARKETPREDICTOR_MONTECARLO_ASSET_H