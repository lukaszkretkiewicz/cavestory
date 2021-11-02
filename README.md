# Cave Story (better version)

## Authors:
- marcindus - https://github.com/marcindus
- lukaszkretkiewicz - https://github.com/lukaszkretkiewicz

## Preparing SFML first
1. Install SFML dependencies according to https://www.sfml-dev.org/tutorials/2.5/compile-with-cmake.php
2. Clone SFML lib ```git clone https://github.com/SFML/SFML.git```
3. Go to SFML directory ```cd SFML```
4. ```mkdir build && cd build```
5. ```cmake .. && make```
6. ```sudo make install```

## Running
1. Clone repository to your computer.
2. Create build directory ```mkdir build```
3. Go to the build ```cd build```
4. Create CMake files ```cmake ..```
5. Build ```make```
6. Run ```./src/CaveStory```

## Directories
- data - assets from the original game,
- lib - libraries that keep the game running,
- src - main function,
- tst - Google Tests.
