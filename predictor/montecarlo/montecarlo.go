package montecarlo

import (
	"math"
	"math/rand"
)

type SoloAsset struct {
	price           float64
	logMeanReturn   float64
	standardDeviation float64
}

func New(price float64, mean float64, variance float64) SoloAsset {
	return SoloAsset{price, mean, variance}
}

func UpdateMonteCarlo(currentAsset SoloAsset) SoloAsset {
	var change = calculateDrift(currentAsset)
	change += calculateJump(currentAsset)
	currentAsset.price *= math.Exp(change)
	return currentAsset
}

func calculateJump(currentAsset SoloAsset) float64 {
	var scale = 2.0*rand.Float64() - 1.0
	return currentAsset.standardDeviation * scale
}

func calculateDrift(currentAsset SoloAsset) float64 {
	return currentAsset.logMeanReturn - (0.5*currentAsset.standardDeviation*currentAsset.standardDeviation)
}

func GetPrice(currentAsset SoloAsset) float64 {
	return currentAsset.price
}