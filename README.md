Some game using LiquidFun and SFML

Work in progress

Gameplay
========
* 2D levels with platforms, wasd movement and jumping
* levels contain pipes which are leaking fluid
* the player is tasked to patch the leaks with superglue
* superglue is moderately viscous and sticky
* the superglue can be thrown, dries instantly and is repulsed by any fluid in the pipes
* incorrectly placed superglue can be dissolved by antiglue
* antiglue has low viscosity and does not stick to anything, i.e. redundantly placed antiglue just drips into oblivion
* antiglue and superglue reacts with each other and on contact, both dissolve quickly into a mixture with very low viscosity that evaporates quickly


TODO
====
1. Create level with horizontal pipe
2. Add fluid moving inside the pipe
3. Create counter for counting what percentage of the fluid particles initialized at the start reaches the other side
4. Test counter with leak