#include <iostream>
using namespace std;

class TicTacToe {
   public:
    TicTacToe() {
        player = 1;
    }

    void run() {
        printTicTacToe();
        while (isWin != 1) {
            setGame();
            printf("\n");
            printTicTacToe();
            checkWin();
        }
    }

   private:
    bool player;
    bool isWin = false;
    int count = 0;
    char game_array[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    void printTicTacToe() {
        printf("-- Tic Tac Toe -- CSIE@CGU\n");
        printf("Player 1 (X)  -  Player 2 (O)\n\n");
        printf("     █     █     \n");
        printf("  %c  █  %c  █  %c  \n", game_array[0], game_array[1], game_array[2]);
        printf("     █     █     \n");
        printf("▄▄▄▄▄█▄▄▄▄▄█▄▄▄▄▄\n");
        printf("     █     █     \n");
        printf("  %c  █  %c  █  %c  \n", game_array[3], game_array[4], game_array[5]);
        printf("     █     █     \n");
        printf("▀▀▀▀▀█▀▀▀▀▀█▀▀▀▀▀\n");
        printf("     █     █     \n");
        printf("  %c  █  %c  █  %c  \n", game_array[6], game_array[7], game_array[8]);
        printf("     █     █     \n\n");
    }

    void setGame() {
        int number;
        if (player == 1) {
            printf("Player 1, ");
        } else {
            printf("Player 2, ");
        }
        printf("請輸入『1-9』的數字: ");
        cin >> number;

        if (number < 1 || number > 9 || game_array[number - 1] == 'O' || game_array[number - 1] == 'X') {
            printf("請重新輸入下一步\n");
        } else {
            game_array[number - 1] = (player) ? 'X' : 'O';
            count++;
            player = !player;
        }
    }

    void checkWin() {
        for (int i = 0; i < 3; i++) {  // 垂直線
            if (game_array[i] == ((!player) ? 'X' : 'O') && game_array[i + 3] == ((!player) ? 'X' : 'O') && game_array[i + 6] == ((!player) ? 'X' : 'O')) {
                printf("==>%s Win", (!player) ? "Player 1" : "Player 2");
                isWin = 1;
                return;
            }
        }
        for (int i = 0; i < 9; i = i + 3) {  // 水平線
            if (game_array[i] == ((!player) ? 'X' : 'O') && game_array[i + 1] == ((!player) ? 'X' : 'O') && game_array[i + 2] == ((!player) ? 'X' : 'O')) {
                printf("==>%s Win", (!player) ? "Player 1" : "Player 2");
                isWin = 1;
                return;
            }
        }

        if (game_array[0] == ((!player) ? 'X' : 'O') && game_array[4] == ((!player) ? 'X' : 'O') && game_array[8] == ((!player) ? 'X' : 'O')) {  // 左上右下
            printf("==>%s Win", (!player) ? "Player 1" : "Player 2"); 
            isWin = 1;
            return;
        }
        if (game_array[2] == ((!player) ? 'X' : 'O') && game_array[4] == ((!player) ? 'X' : 'O') && game_array[6] == ((!player) ? 'X' : 'O')) {  // 右上左下
            printf("==>%s Win", (!player) ? "Player 1" : "Player 2");
            isWin = 1;
            return;
        }

        if (count > 8) {
            printf("==>Game draw");
            isWin = 1;
            return;
        }
    }
};

int main() {
    TicTacToe game;
    game.run();
    return 0;
}