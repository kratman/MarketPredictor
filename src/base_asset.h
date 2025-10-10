#ifndef MARKETPREDICTOR_ASSET_H
#define MARKETPREDICTOR_ASSET_H

#include <cstdlib>

class Asset {
protected:
    std::string name;
    double price;
    double shares;

public:
    Asset() {
        price = 0;
        shares = 0;
    }

    virtual ~Asset() = default;

    virtual void update_asset() = 0;

    static double get_rand() {
        auto const rand_num = static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX);
        return 2.0 * (rand_num - 0.5);
    }

    void set_price(double new_price) {
        price = new_price;
    }

    void set_shares(double const number_of_shares) {
        shares = number_of_shares;
    }

    double get_price() const {
        return price;
    }

    std::string get_name() const {
        return name;
    }

    void purchase_shares(double const investment) {
        shares += investment / price;
    }
};

#endif //MARKETPREDICTOR_ASSET_H