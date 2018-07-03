#include <bits/stdc++.h>
#include "front.hpp"

int main()
{
    int board[8][8] =
    {
        -2,-3,-4,-5,-6,-4,-3,-2,
        -1,-1,-1,-1,-1,-1,-1,-1,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1,
        2, 3, 4, 5, 6, 4, 3, 2
    };
    tabuleiro t1;

    while(t1.desenha_tabuleiro())
        {
            t1.setboard(board);
        }

    return 0;
}
