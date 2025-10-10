#ifndef MARKETPREDICTOR_ASSET_H
#define MARKETPREDICTOR_ASSET_H

#include <cstdlib>

class Asset {
public:
    Asset() = default;

    virtual ~Asset() = default;

    virtual void update_asset() = 0;

    virtual double get_price() const = 0;

    static double get_rand() {
        auto const rand_num = static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX);
        return 2.0 * (rand_num - 0.5);
    }
};

#endif //MARKETPREDICTOR_ASSET_H