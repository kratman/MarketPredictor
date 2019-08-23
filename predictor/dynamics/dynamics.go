package dynamics

import "math/rand"

type asset struct {
	price float64
	oldPrice float64
	drag float64
	velocity float64
	growthRate float64
	coupledRate float64
	fluctuationSize float64
}

func NewAsset(price float64, drag float64, growth float64, coupling float64, flux float64) asset {
	return asset {price, price, drag, 0.0, growth, coupling, flux}
}

func updateAsset(currentAsset asset, coupledVelocity float64) {
	updatePrice(currentAsset, coupledVelocity)
	updateVelocity(currentAsset)
}

func updatePrice(currentAsset asset, coupledVelocity float64) {
	currentAsset.oldPrice = currentAsset.price
	addDynamics(currentAsset)
	addCoupling(currentAsset, coupledVelocity)
	addFluctuation(currentAsset)
}

func addDynamics(currentAsset asset) {
	var velocityUpdate = currentAsset.drag * currentAsset.velocity
	var growthUpdate = currentAsset.growthRate * currentAsset.price
	currentAsset.price += velocityUpdate + growthUpdate
}

func addCoupling(currentAsset asset, coupledVelocity float64) {
	currentAsset.price += currentAsset.coupledRate * coupledVelocity
}

func addFluctuation(currentAsset asset) {
	var scale = 2.0 * rand.Float64() - 1.0
	currentAsset.price += scale * currentAsset.fluctuationSize
}

func updateVelocity(currentAsset asset) {
	currentAsset.velocity = currentAsset.price - currentAsset.oldPrice
}
