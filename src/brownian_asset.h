#ifndef MARKETPREDICTOR_BROWNIAN_ASSET_H
#define MARKETPREDICTOR_BROWNIAN_ASSET_H

class CoupledAsset {
    float price;
    float oldPrice;
    float drag;
    float velocity;
    float growthRate;
    float coupledRate;
    float fluctuationSize;

public:
    CoupledAsset() = default;
};

#endif //MARKETPREDICTOR_BROWNIAN_ASSET_H