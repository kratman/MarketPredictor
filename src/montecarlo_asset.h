#ifndef MARKETPREDICTOR_MONTECARLO_ASSET_H
#define MARKETPREDICTOR_MONTECARLO_ASSET_H

#include <cmath>
#include "base_asset.h"


class SoloAsset : public Asset {
    double price;
    double logMeanReturn;
    double standardDeviation;

    double calculateJump() const {
        return standardDeviation * get_rand();
    }

    double calculateDrift() const {
        return logMeanReturn - (0.5 * standardDeviation * standardDeviation);
    }

public:
    SoloAsset() = default;

    SoloAsset(double const price, double const mean, double const variance) {
        this->price = price;
        this->logMeanReturn = mean;
        this->standardDeviation = variance;
    }

    void UpdateMonteCarlo() {
        auto const change = calculateDrift() + calculateJump();
        price *= std::exp(change);
    }

    double GetPrice() const {
        return price;
    }
};

#endif //MARKETPREDICTOR_MONTECARLO_ASSET_H