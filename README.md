# EcoDuet

A dungeon-based roguelike with an ecology-based home. Based on Generalized Lotka Volterra on an growingly complex ecosystem.

## Description

You play as Noke, an ecology student trying to restore a World to a dynamic ecosystem. You can mold the environment and properties of the species to try to find robust equilibriums and keep increasing the diversity of each world you visit.

## Next steps

### Immediate

- [ ] Maintain player toolbox and home seeds between server travel
- [ ] Check that elder data is saved and loaded
- [ ] Switch to environmental actions to change GLV parameters instead of cubes

- [ ] Finish intro cinematic:
- [ ] animal scene
- [ ] skip button
- [ ] Crowd

- [ ] Copy the mixamo retargetter from another project or fix it. Then fix sadwalk retarget.

### Fase 0 : Basics

- [x] Game Over Logic and menu
- [x] Make a help screen that opens with the key h
- [x] Actually write a help
- [x] Show GLV parameters (at help?)
- [x] Let the player kill animals for now as a "debug"-ish tool to get the feel of the ecosystem dynamic
- [x] Update the rates
- [x] Fix missing rate cube / self-impact
- [x] Fix float overflow - forced 200 but they still give birth -- it works correctly but spawner spawns max 1 per second

### Fase 1 : Sandbox

- [x] Add a way to modify species parameters. Should it be priority 1? Make Home really a sandbox?
- [x] Add an interaction cube to modify r
- [x] Change cube material color or light to show predation vs simbiosis
- [x] Feedback on selected cube. E.g. turn on/off light to selected cube

### Fase 2 : Empty start

- [x] Fase 2: Begin Empty start Fase
- [x] Create a Tutorial Level
- [x] Add a Tree Elder
- [-] Add visual instructions to the Tutorial level on what to do
- [x] Make a pig elder seed, a fox elder seed and a stag elder seed.
- [x] Make an empty map where you get the Elder tree seed and you can plant it (and gain the plant hability).
- [x] Add a Level select menu
- [x] Make the elder with extinction rates and the player has to do something to the environment so that it survives

The trees go extinct as-is. To prevent that, the ecologist can throw compost to the area. The compost dissolves into the ground and gives a temporary +0.1 at the birth rate of the trees. The problem is that after the period, they start dying again. To fix this, we will teach the player (how?) that a pig/deer would provide the same function and be stable.

To get the deer seed we could either spawn it in the level or do the dungeon already. Might be good to spawn it in the level to introduce dungeoning later on.

### Fase 2.5: Ship Alpha

- [x] Add a Level select menu
- [ ] Ship a demo of the game
- [ ] Add a demo video
- [ ] Create socials

### Fase 3 : Dungeoning

- [-] Add map travel with state conservation
- [x] Make a procedural map for the tree Elder
- [~] Add three pedestal actors, if the player places three trees there, the tree seed will appear and or the tree Elder will appear. Or maybe the Elder tree should be there already.
- [ ] Build a change-map and make a dungeon map with the animal elder seeds in them.

### Fase 3.5: Flying birds dungeon

- [ ] Add the flying bird dungeon

### Fase 4

- [ ] Make the Tutorial levels better
- [ ] Then maybe either make the dungeon better
- [x] Move to the N-species
- [ ] Improve ecosystem health feedback. e.g. Oracle: Computes N iterations and marks endangered elders

- [ ] Switch to environmental actions to change GLV parameters instead of cubes
- [x] Rain
- [x] Weather system

### Fase 5 : Some Polishing

- [x] Change the environtment from desert to field even more according to ecosystem state
- [ ] Animals slope orientation](https://www.youtube.com/watch?v=YbPgJNSazec)
- [ ] Improve animal selection feedback (both elder and killing)k
- [ ] Seasons system
- [ ] Make weather changes gradual


- [ ] Rethink interactions to be more consistent on less actions
- [x] Remove old densities code
- [ ] Use EcoNone for rate instead of R?
- [ ] AddElder should be handled by species manager instead of gamemode

- [x] Lobby and character select

- [ ] Low End PC version

### Fase 6 : Step up

- [ ] Variations of Elders.

We can have GLV paramaters mutations that use the same relation in the counterpart. E.g. Fox1 Fox2 but only Pig1 which is affected by Fox1+Fox2

### Fase 7 : Intro cinematic

- [ ] Finish intro cinematic:
- [ ] animal scene
- [ ] skip button
- [ ] Crowd

### Quality Assurance

- [ ] Death animation for the tree
- [ ] Animal turning movement
- [ ] Check that all game mode casts are to GameModeHome (since we created Tutorial and Survival Modes)
- [ ] changing GLV in menu should change cube size in Elders (should it?)

- [x] on restart, second player controller is disconnected

- [ ] Find out what is requiring more texture budget than usual. [Increased to 3000](https://www.youtube.com/watch?v=ahAX3w5ovts) with `r.Streaming.PoolSize 3000`
	- Looks like it's Koikos Hair

- [ ] Copy the mixamo retargetter from another project or fix it. Then fix sadwalk retarget.

### Whenever

- [ ] Change elder parameters by posessing
- [ ] plant on raytrace or collision
- [ ] Fix the python multihome to support edit-save parameters (and maybe species deletion?)
- [x] Check how to change character via config or something
- [ ] On equilibrium no Individual dies nor is born, since births compensate deaths in density only. It'd be nice to somehow still birth-die even if density stays constant.
- [ ] Birds
- [ ] Use a [smart material](https://docs.unrealengine.com/4.26/en-US/RenderingAndGraphics/Materials/HowTo/EmissiveGlow/) instead of lights
- [ ] Spawner only spawns 1 per second (check it with float overflow)
- [x] Add a pre-screen asking how many players to set the number of ecoplayers if auto-detecting doesn't work

### Nice to have

- [ ] Thunder or some effect on killing a species member

## UE Tips

To record gameplay the fastest is:

Click on the viewport -> F11 for quasi-fullscreen -> Shift+F11 for real fullscreen -> Alt+P to play

To revert:

Stop Game -> F11

It will remember the real fullscreen the next time, so you only need to press F11 to come in and out of real fullscreen

I didn't need this in the end, but might be valuable to know: F10 to hide menus

## Thoughts

### Ideas for later

make the species gain abilities so that you can unlock a new source of nourishment

Would it be nice that instead of being a human, you could swap between species and that's how you select which "tool" you're using?

### Game design

How could we measure successful ecosystem?

* Diversity
* Great interrelation with high densities
* Great cycles
* Robustness to outside perturbations?

### About dungeons

Dungeons strong point is their repeatibility and low commitment on good design. We need to get procedural dungeons so that we can play many levels we never got before and have high replayability. The problem is doing that without enemy-based dungeons. Puzzles must be handcrafted probably.

One option is that puzzles are ecosystems with random species and variables. We might need a wave function so that we can guarantee it's solvable. We also must find a way to purposely create extinction starting conditions with a path to coexistence at design time. Or we could NOT do this and assume some puzzles will be unsolvable as part of the mechanic (hence the low commitment), you can restart the dungeon if it's unsolvable.

Procedural levels in UE5 are mostly thought for ambience, but might also work for puzzles maybe? The point of that generation is that given a seed you get a different level, so let's ensure we use that! ideally NOT only for ambience. Might need a wave function collapse instead for our purposes?

### About home

Consider making a sandbox version of the game without dungeons nor limited spieces trees where the player can control all parameters of the r and interaction matrix.

** UIs ideas **

The Elders could have an icon over their head on approach that you can make smaller or bigger to represent 0.1 increments on predation. Grey=disabled when interaction is 0, red-green on predator-prey. The player can increase by raytracing and right-left clicking.

The Elders have strikes, when their population gets below a certain density they get a strike. If the player doesn't solve the situation the Elder will go extinct. The player can artifically give nourishment to the Elder to get it temporarely out of pverty line, so the strikes should stay for a certain period of time to avoid cyclical manual survival -- or maybe it is ok, no player will want to manually maintain their species for long, or he might be free to do so.

We could even add an Elder that _needs_ to be manually fed to survive. The player becomes its prey effectivelly (in a kind of simbiotic relationship). 

Reaching certain populations in a stable manner might trigger choreagraphies to the animals, like crows banding toghether or something.

The number of individuals can be tuned by a density multiplier which might be useful in low-end computers if the numbers become too great.

Add an ecosystem diversity number stating the number of species and also the connectivity (e.g. how many NxN species have values > 0.05 in the interaction matrix, or directly how many elements of matrix A are >abs(0.05))

## Troubleshooting

Visual Studio integration Tools is a third-party plugin so it might not be updated [in the marketplace](https://www.unrealengine.com/marketplace/en-US/product/362651520df94e4fa65492dbcba44ae2) as quickly as the unreal engine.
If so you can clone [the repo](https://github.com/microsoft/vc-ue-extensions#building-and-installing-the-plugin) directly.

# Design

Each Elder has an GLVActor Component that holds the GLV multiplication function. The EcoSpeciesWatcher is the one with the two timers that compute the next GLV densities and another that Spawns/kills each species children.

The GameMode holds a Map with a SpeciesName and its density. **Important** Each Elder GLVComponent has a Tag with its name which must be the same as the Elder EcoName. I couldn't find a way to have a unique Name in Blueprint accessible from C++. I have to create a baseElderActor C++ class with it, but seemed like an overkill to do a reparent just to have a name accessible to a c++ function.

# Typical mistakes to remember

Animal childs have to be set to auto-possess when placed into the world or spawned

## Some credits

[GlacialIndifference](https://fontlibrary.org/en/font/glacial-indifference)

An ai stable diffusion prompt I used for animal icons: four colors, crow, stylized, sketch, bird, flat, sunlit from the side, high contrast, few colors, thumbnail, cartoon crow open wings, organic painting, cartoon, matte painting, bold shapes, hard edges, app icon, trending on artstation, by sachin teng, artgerm, rossdraws.

With one of the base images being a dog of the stilized animals.


[keyboard iconkeys](https://www.flaticon.com/search?type=icon&search-group=all&word=keyboard+button+tab&license=&color=&shape=&current_section=&author_id=&pack_id=&family_id=&style_id=&type=)


[Pebbles](https://blendswap.com/blend/22885)