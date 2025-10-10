#ifndef MARKETPREDICTOR_BROWNIAN_ASSET_H
#define MARKETPREDICTOR_BROWNIAN_ASSET_H

#include "base_asset.h"

class CoupledAsset final : public Asset {
    double oldPrice;
    double drag;
    double velocity;
    double growthRate;
    double coupledRate;
    double fluctuationSize;

    void update_price(double const coupledVelocity) {
        oldPrice = price;
        add_dynamics();
        add_coupling(coupledVelocity);
        add_fluctuation();
    }

    void add_dynamics() {
        auto const velocityUpdate = drag * velocity;
        auto const growthUpdate = growthRate * price;
        price += velocityUpdate + growthUpdate;
    }

    void add_coupling(double const coupledVelocity) {
        price += coupledRate * coupledVelocity;
    }

    void add_fluctuation() {
        price += fluctuationSize * get_rand();
    }

    void update_velocity() {
        velocity = price - oldPrice;
    }

public:
    CoupledAsset(double const price, double const drag, double const growth, double const coupling, double const flux) {
        this->price = price;
        this->oldPrice = price;
        this->drag = drag;
        this->velocity = 0;
        this->growthRate = growth;
        this->coupledRate = coupling;
        this->fluctuationSize = flux;
    }

    void update_asset() override {
        update_asset(0.0);
    }

    void update_asset(double const coupledVelocity = 0.0) {
        update_price(coupledVelocity);
        update_velocity();
    }

    double get_velocity() const {
        return velocity;
    }

    ~CoupledAsset() override = default;
};

#endif //MARKETPREDICTOR_BROWNIAN_ASSET_H