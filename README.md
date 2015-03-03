_foth_ (or FOTH)
====

A game about a train. Just kidding, a game about track. Or maybe a little of both, plus or minus some religious iconography.

#### Build Instructions

Building _foth_ requires SCons, a Python-based, cross-platform build tool. Once _foth_ is complete, compiled binaries will be made available online.

_foth_ also requires two libraries (which were created with foth in mind), [version 1.1 of SFML State Manager](https://github.com/Brinsky/sfml-states/releases/tag/v1.1) ~~and [version 1.0 of SFML Resource Manager](https://github.com/else42/sfml-resources/releases/tag/v1.0)~~ *(Currently, SFML Resource Manager is built into _foth_ and requires no external libraries)*. Once these two libraries are built (also using SCons), the resulting library files (`libsfml-res-man.a` and `libsfml-state-man.a`) must be copied into `lib/` within the _foth_ directory. Next, the directories `include/ResourceManager` (from the Resource Manager repository) and `include/StateManager` (from the State Manager repository) should be copied into include/ within the _foth_ directory.

Finally, foth can be built by running `scons`.
