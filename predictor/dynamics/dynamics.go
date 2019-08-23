package dynamics

type asset struct {
	price float64
	drag float64
	velocity float64
	growthRate float64
	coupledRate float64
	fluctuationSize float64
}

func updateAsset(currentAsset asset, coupledVelocity float64) {
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
	var scale float64 = 0.0
	currentAsset.price += scale * currentAsset.fluctuationSize
}
