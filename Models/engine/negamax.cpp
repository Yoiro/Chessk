#include "negamax.h"

/*By convention, if board[i][j]
 * == 0: The case is unoccupied
 * == 1: Player 1 (Whites) occupies it
 * == 2: Player 2 (Blacks) occupies it
 */

using namespace std;

NegaMax::NegaMax()
{

}

void NegaMax::IA_play(QList<QList<Case*>> cases, int depth)
{
    QList<QList<Case*>> board = new QList<QList<Case*>>(cases);
    int max = - 10000;
    int tmp, maxi, maxj;
    for (int i = 0; i < 8; i ++){
        for (int j = 0; j < 8; j++){
            if(board->cases[i][j] == 0){
                board->cases[i][j] = 1;
                tmp = min(board, depth-1);

                if ( tmp > max ){
                    max = tmp;
                    maxi = i;
                    maxj = j;
                }
                board->cases[i][j] = 0;
            }
        }
    }
    board[maxi][maxj] = 1;
}

int NegaMax::negaMax(int depth){
    if (depth == 0){ return evaluate; }
    int max = -Q_INFINITY;

}

int max(QList<QList<Case*>> board, int depth){
    if(depth == 0){
        return eval(board);
    }
    int max = -Q_INFINITY;
    int tmp;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if(board[i][j] == 0){
                board[i][j] = 2;
                tmp = min(board, depth-1);

                if(tmp > max){
                    max = tmp;
                }
                board[i][j] = 0;
            }
        }
    }
    return 0;
}

int min(QList<QList<Case*>> board, int depth){
    if(depth == 0 || winner(board) !=0 ){
        return eval(board);
    }
    int min = 10000;
    int tmp;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if(cases[i][j] == 0){
                cases[i][j] = 1;
                tmp = max(board, depth-1);
                if( tmp < min ) {
                    min = tmp;
                }
                cases[i][j] = 0;
            }
        }
    }
    return 0;
}

int eval(QList<QList<Case*>> board){
    int winner, nbPieces = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if(board[i][j] != 0){
                nbPieces ++;
            }
        }
    }
    if (winner == 1){
        return 1000 - nbPieces;
    } else if (winner == 2){
        return -1000 + nbPieces;
    } else{
        return 0;
    }
}
