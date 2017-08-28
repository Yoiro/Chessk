#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Models/board.h";

class NegaMax
{
public:
    NegaMax();

    void IA_play(Board* cases, int depth);
    int min(Board* cases, int depths);
    int max(Board* cases, int depths);
    int eval(Board* cases);
    int winner(Board* cases);

    int testMinMax(int depth, int nodeIndex, bool isMax, int scores[], int h);
};

#endif // GAMEENGINE_H
