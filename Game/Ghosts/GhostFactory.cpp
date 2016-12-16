#include "GhostFactory.h"
#include "Blinky.h"
#include "Pinky.h"
#include "Clyde.h"
#include "Inkey.h"

Enemy* GhostFactory::getEnemy(std::string ghost) {
    if (ghost == "blinky") return new Blinky(264, 264, 24, 24);
    if (ghost == "pinky") return new Pinky(264, 312, 24, 24);
    if (ghost == "inkey") return new Inkey(312, 264, 24, 24);
    if (ghost == "clyde") return new Clyde(312, 312, 24, 24);
}

GhostFactory::GhostFactory() {}
