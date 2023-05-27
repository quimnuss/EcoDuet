# EcoDuet

A dungeon-based roguelike with an ecology-based home. Based on Generalized Lotka Volterra on an growingly complex ecosystem.

## Description

You play as Noke, an ecology studient trying to restore a World to a dynamic ecosystem. You can mold the environment and properties of the species to try to find robust equilibriums and keep increasing the diversity of each world you visit.

## Next steps

[ ] Make an empty map where you get the Elder tree seed and you can plant it (and gain the plant hability).

### Fase 0

[ ] Make a help screen that opens with the key h
[ ] Let the player kill animals for now as a "debug"-ish tool to get the feel of the ecosystem dynamic
[ ] Update the rates

### Fase 1

[ ] Make a pig elder seed and a fox elder seed.

[ ] Build a change-map and make a dungeon map with the animal elder seeds in them.


### Fase 2

[ ] Add a way to modify species parameters. Should it be priority 1? Make Home really a sandbox?

Ideas for later: make the species gain abilities so that you can unlock a new source of nourishment

### Fase 3

[ ] Then maybe either make the dungeon better

or

[ ] Move to the N-species

or

* [ ] Improve ecosystem health feedback
	- Oracle: Computes N iterations and marks endangered elders

### Whenever

[ ] plant on raytrace or collision
[ ] Fix the python multihome to support edit-save parameters (and maybe species deletion?)
[ ] Check how to change character via config or something




## Thoughts

How could we measure successful ecosystem?

* Diversity
* Great interrelation with high densities
* Great cycles
* Robustness to outside perturbations?

## Troubleshooting

Visual Studio integration Tools is a third-party plugin so it might not be updated [in the marketplace](https://www.unrealengine.com/marketplace/en-US/product/362651520df94e4fa65492dbcba44ae2) as quickly as the unreal engine.
If so you can clone [the repo](https://github.com/microsoft/vc-ue-extensions#building-and-installing-the-plugin) directly.
