#ifndef MARKETPREDICTOR_BROWNIAN_ASSET_H
#define MARKETPREDICTOR_BROWNIAN_ASSET_H

#include "base_asset.h"

class CoupledAsset : public Asset {
    double price;
    double oldPrice;
    double drag;
    double velocity;
    double growthRate;
    double coupledRate;
    double fluctuationSize;

    void updatePrice(double const coupledVelocity) {
        oldPrice = price;
        addDynamics();
        addCoupling(coupledVelocity);
        addFluctuation();
    }

    void addDynamics() {
        auto const velocityUpdate = drag * velocity;
        auto const growthUpdate = growthRate * price;
        price += velocityUpdate + growthUpdate;
    }

    void addCoupling(double const coupledVelocity) {
        price += coupledRate * coupledVelocity;
    }

    void addFluctuation() {
        price += fluctuationSize * get_rand();
    }

    void updateVelocity() {
        velocity = price - oldPrice;
    }

public:
    CoupledAsset() = default;

    CoupledAsset(double const price, double const drag, double const growth, double const coupling, double const flux) {
        this->price = price;
        this->oldPrice = price;
        this->drag = drag;
        this->velocity = 0;
        this->growthRate = growth;
        this->coupledRate = coupling;
        this->fluctuationSize = flux;
    }

    void updateAsset(double const coupledVelocity = 0.0) {
        updatePrice(coupledVelocity);
        updateVelocity();
    }

    double get_price() const {
        return price;
    }

    double get_velocity() const {
        return velocity;
    }
};

#endif //MARKETPREDICTOR_BROWNIAN_ASSET_H