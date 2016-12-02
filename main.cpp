#include <iostream>
#include "Game/Game.h"
#include "Algorithms/WaveTracingAlgorithm.h"

int main() {

    Game* game = new Game();
    game->run();

    /* test Li algorithm */

    /* get reference to algorithm class */
    /*WaveTracingAlgorithm& algorithm = WaveTracingAlgorithm::Instance();
    *//*algorithm.findPath(1, 1, 23, 23);
    std::cout << algorithm.size << std::endl;
    *//*algorithm.findPath(1, 1, 11, 1);
    std::cout << algorithm.size << std::endl;

    for (int i = 0; i < 44; ++i) {
    std::cout << algorithm.px[i] << " | " << algorithm.py[i] << std::endl;
    }*/

    return 0;
}