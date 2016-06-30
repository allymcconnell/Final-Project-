//
//  main.cpp
//  Final Project
//
//  Created by Ally McConnell on 6/27/16.
//  Copyright © 2016 Ally McConnell. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
#include <cctype>
#include <cstdlib>

struct game {
    char p1;
    char p2;
    char **board = new char*[10];
        for (int i = 0; i < 10; i++){
            board[i] = new char[10];
    }
};

void print_board(game p, int r, int c);
bool play(game p, bool gamewon, int r, int c, int pieces);
bool check(int a, int b, game p, int r, int c, int peices);
int drop(int b, char player, game p, int c);

int main(int argc, char *argv[]){
    game p;
    int r, c, pieces;
    bool gamewon = false;
    if (argc == 7) {
        for(int i = 1, i < argc, i += 2){
            if(argv[i][0]=='-'&&[i][1]=='r')
                r = atoi(argv[i+1]);
            else if(!strcmp(argv[i], "-c"))
                c = atoi(argv[i+1]);
            else if(!strcmp(argv[i], "-p"))
                pieces = atoi(argv[i+1]);
            while (pieces < 1){
                cout << "You cannot have 0 peices to connect" << endl;
                cout << "Please enter a positive, non-zero integer"
                << " for the number of pieces to connect: ";
                cin >> pieces;
            }
            
        }
        else
            cout << "Error." << endl;
    }


r = 6;
c = 7;
pieces = 4;
p.board = new char*[r];
for (int i=0, i < r, i++){
    p.board[i] = new char[c];
}
for (int a = 0, a < r, a++){
    for (int b = 0, b < c, b++){
        p.board[a][b] = ' ';
    }
}
print _board(p, r, c);
    gamewon = play(p, gamewon, r, c, pieces);
return 0;
}

bool play(game p, bool gamewon, int r, int c, int pieces){
    int col, hold = 0, charsPlaced = 0;
    char player = 'y';
    while (!gamewon){
        if(hold != -1){
            cout << "Playe 1, what column do you want to put your piece? ";
            player = 'r';
        }
        else{
            cout << "Player 2, what column do you want to put your piece? ";
            player = 'y';
        }
    }
    while(true){
        if(charsPlaced == r*c) break;
        cin >> col;
        col --;
        if (col <= r && col >= 0)break;
        else cout << "\nPlease enter a value between 1 and " << c << ":";
        if(cin.fail()){
            cin.clear();
            char d;
            cin >> d;
        }
    }
    if (charsPlaced == r*c) break;
    hold = drop(col, player, p, c);
    if(hold == -1) cout << "Column is full!\nPlease enter another number between 1 and " << c << "; ";
    else {
        gamewon = check (hold, col, p, r, c, pieces);
        charsPlaced ++;
        print_board(p, r, c);
    }
}
if(charsPlaced == r*c){
    cout << "No Winner! Game is a draw\n";
    return true;
}
if (player == 'y')
    cout << "Player 2 is the winner!\n";
else cout << "Player 1 is the winner!\n";
    return true;
    

}

    void print_board(game p, int r, int c){
        cout << endl;
        for (int a = 0, a < r, a++){
            for (int b = 0, b < c, b++)
                cout << "|" << p.board[a][b];
            cout << "|";
            cout << endl;
            
        }
    }

    bool check (int a, int b, game p, int r, int c, int pieces){
        int vertical = 1, horizontal = 1, diagonalone = 1, diagonaltwo = 1, i, j;
        cout << i << " " << b << " " << a << endl;
        char player = p.board[a][b];
        cout << player << endl;
        for (i = a + 1; p.board[i][b] == player && i < r; i++, vertical++);
        for (i = a - 1; p.board[i][b] == player && i >= 0; i--, vertical++);
        if (vertical >= pieces)
            return true;
        for (j = b - 1; p.board[a][j] == player && j >= 0; j--; horizontal++);
        for (j = b + 1; p.board[a][j] == player && j < c; j++, horizontal++);
        if (horizontal >= pieces)
            return true;
        for (i = a - 1; j = b - 1; p.board[i][j] == player && i >= 0 && j >= 0; diagonalone++, i--, j--);
        for (i = a + 1; j = b + 1; p.board[i][j] == player && i <= r && j <= c; diagonalone++, i++, j++);
        if (diagonalone >= pieces)
            return true;
        for (i = a - 1, j = b + 1; p.board[i][j] == player && i > 0 && j <= c; diagonaltwo++, i--, j++);
        for (i = a + 1, j = b - 1; p.board[i][j] == player && i <= r && j >= 0; diagonaltwo++, i++, j--);
        if (diagonaltwo >= pieces)
            return true;
        return false;
    }

    int drop (int b, char player, game p, int c) {
        if (b >= 0 && b <= c){
            if (p.board[0][b] == ' '){
                int i;
                for (i = 0; p.board[i][b] == ' '; i++)
                    if (i == 5){
                        p.board[i][b] = player;
                        return i;
                    }
                i--;
                p.board[i][b] = player;
                return i;
            }
            else {
                return -1;
            }
        }
        else {
            return -1;
        }
    }