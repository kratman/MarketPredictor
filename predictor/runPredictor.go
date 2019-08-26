package main

import (
	"./montecarlo"
	"fmt"
)

func main() {
	a := []montecarlo.SoloAsset{
		montecarlo.New(44.06, 0.000375244825726, 0.010565121103501),
		montecarlo.New(44.06, 0.000375244825726, 0.010565121103501),
		montecarlo.New(44.06, 0.000375244825726, 0.010565121103501),
		montecarlo.New(44.06, 0.000375244825726, 0.010565121103501),
		montecarlo.New(44.06, 0.000375244825726, 0.010565121103501),
	}

	fmt.Printf("%v", 0)
	for _, asset := range a {
		fmt.Printf("%v", ", ")
		fmt.Printf("%v", montecarlo.GetPrice(asset))
	}
	fmt.Printf("%v", "\n")

	for i := 0; i < 200; i += 1 {
		fmt.Printf("%v", i+1)
		for _, asset := range a {
			asset = montecarlo.UpdateMonteCarlo(asset)
			fmt.Printf("%v", ", ")
			fmt.Printf("%v", montecarlo.GetPrice(asset))
		}
		fmt.Printf("%v", "\n")
	}
}
