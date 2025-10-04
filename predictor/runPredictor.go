package main

import (
	"fmt"

	"./montecarlo"
)

func main() {
	price := 44.06
	meanReturn := 0.000284685088744
	variance := 0.011551333339698
	numberOfTrials := 10
	numberOfSteps := 1000
	var a []montecarlo.SoloAsset

	for i := 0; i < numberOfTrials; i++ {
		a = append(a, montecarlo.New(price, meanReturn, variance))
	}

	fmt.Printf("%v", "Day")
	for i := 0; i < numberOfTrials; i++ {
		fmt.Printf("%v", ", Price ")
		fmt.Printf("%v", i)
	}
	fmt.Printf("%v", "\n")

	fmt.Printf("%v", 0)
	for _, asset := range a {
		fmt.Printf("%v", ", ")
		fmt.Printf("%v", montecarlo.GetPrice(asset))
	}
	fmt.Printf("%v", "\n")

	for i := 0; i < numberOfSteps; i++ {
		fmt.Printf("%v", i+1)
		for j, _ := range a {
			var asset *montecarlo.SoloAsset = &a[j]
			montecarlo.UpdateMonteCarlo(asset)
			fmt.Printf("%v", ", ")
			fmt.Printf("%v", montecarlo.GetPrice(*asset))
		}
		fmt.Printf("%v", "\n")
	}
}
