cmake_minimum_required(VERSION 3.20)

project(MarketPredictor)

add_executable(portfolio_sim
        src/base_asset.h
        src/brownian_asset.h
        src/montecarlo_asset.h
        src/portfolio_sim_main.cpp
        src/base_asset.h
        src/portfolio.h
        src/read_input.h
        src/read_input.cpp
)
