#include <iostream>
#include "WaveTracingAlgorithm.h"

/*WaveTracingAlgorithm &WaveTracingAlgorithm::Instance() {
    static WaveTracingAlgorithm object;
    return object;
}*/

bool WaveTracingAlgorithm::findPath(int sx, int sy, int ex, int ey) {
    arrayCopy();
    int dx[4] = {1, 0, -1, 0}; // смещения (окрестность фон Неймона)
    int dy[4] = {0, 1, 0, -1};

    int d, x, y, k; // итерационные переменные
    bool stop;

    if (Grid[sy][sx] == WALL || Grid[ey][ex] == WALL) return false;

    // распространение волны
    d = 0;
    Grid[sy][sx] = 0;

    do {
        stop = true;
        for (y = 0; y < height; ++y) {
            for (x = 0; x < width; ++x) {
                if (Grid[y][x] == d) {
                    for (k = 0; k < 4; ++k) {
                        int iy = y + dy[k], ix = x + dx[k];
                        if (iy >= 0 && iy < height &&
                            ix >= 0 && ix < width &&
                                Grid[iy][ix] == BLANK) {
                            stop = false;
                            Grid[iy][ix] = d + 1;
                        }
                    }
                }
            }
        }
        d++;
    } while (!stop && Grid[ey][ex] == BLANK);

    if (Grid[ey][ex] == BLANK) return false; // путь не найден

    // восстановление пути
    length = Grid[ey][ex];
    x = ex;
    y = ey;

    d = length;
    size = length + 1;

    while (d > 0) {
        px[d] = x; // записали ячейку в путь
        py[d] = y;
        d--;

        for (k = 0; k < 4; ++k) {
            int iy = y + dy[k], ix = x + dx[k];
            if (iy >= 0 && iy < height &&
                ix >= 0 && ix < width &&
                Grid[iy][ix] == d) {
                x = x + dx[k];
                y = y + dy[k];
                break;
            }
        }
    }
    px[0] = sx;
    py[0] = sy;

    /*for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (Grid[i][j] < 10 && Grid[i][j] > -1) std::cout << " " <<  Grid[i][j] << "  ";
            else std::cout << Grid[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;*/
    return true;
}

/* затратно переписать */
void WaveTracingAlgorithm::arrayCopy() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Grid[i][j] = G[i][j];
        }
    }
}
