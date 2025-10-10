#ifndef MARKETPREDICTOR_PORTFOLIO_H
#define MARKETPREDICTOR_PORTFOLIO_H

#include <iostream>
#include <vector>
#include "montecarlo_asset.h"

class AssetGroup {
    std::vector<SoloAsset> assets;

public:
    AssetGroup(SoloAsset const& original_asset, int const number_of_simulations) {
        for (int i=0; i<number_of_simulations; i++) {
            assets.push_back(original_asset);
        }
    }

    void update_group() {
        for (auto & sim : assets) {
            sim.update_asset();
        }
    }

    void print_names() const {
        for (int i=0; i<assets.size(); i++) {
            std::cout << ", " << assets[i].get_name() << " " << i;
        }
    }

    void print_prices() const {
        for (auto & sim : assets) {
            std::cout << ", " << sim.get_price();
        }
    }

    ~AssetGroup() = default;
};

class AssetPortfolio {
    int number_of_samples;
    std::vector<AssetGroup> all_assets;

public:
    explicit AssetPortfolio(int const number_of_samples) {
        this->number_of_samples = number_of_samples;
    }

    ~AssetPortfolio() = default;

    void add_asset(SoloAsset const& new_asset) {
        all_assets.emplace_back(new_asset, number_of_samples);
    }

    void run_simulations(int const number_of_steps) {
        std::cout << "Step";
        for (auto const & group : all_assets) {
            group.print_names();
        }
        std::cout << std::endl;

        std::cout << 0;
        for (auto const & group : all_assets) {
            group.print_prices();
        }
        std::cout << std::endl;

        for (int i=0; i < number_of_steps; i++) {
            std::cout << i+1;
            for (auto & group : all_assets) {
                group.update_group();
                group.print_prices();
            }
            std::cout << std::endl;
        }
    }
};

#endif //MARKETPREDICTOR_PORTFOLIO_H