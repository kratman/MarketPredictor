#include <iostream>
#include "read_input.h"

int main() {
    srand(time(nullptr));
    constexpr unsigned int number_of_steps = 1000;
    auto portfolio = read_portfolio();
    portfolio.run_simulations(number_of_steps);
    return 0;
}