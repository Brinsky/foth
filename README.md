_foth_ (or FOTH)
====

A game about a train and its track.

#### Build Instructions

Building _foth_ requires GNU Make and a version of `g++` supporting C++11. It also requires two external libraries (which were created with _foth_ in mind), [version 1.1 of SFML State Manager](https://github.com/Brinsky/sfml-states/releases/tag/v1.1) and [version 1.1 of SFML Resource Manager](https://github.com/else42/sfml-resources/releases/tag/v1.1). Once these two libraries are built, the resulting library files (`libsfml-res-man.a` and `libsfml-state-man.a`) must be copied into `lib/` within the _foth_ directory. Next, the directories `include/ResourceManager` (from the Resource Manager repository) and `include/StateManager` (from the State Manager repository) should be copied into matching paths within the _foth_ directory.

Finally, _foth_ can be built by running `make`.

Once the game is in a more complete state, compiled binaries will be made available online. 
