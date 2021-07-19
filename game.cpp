#include <bits/stdc++.h>

using namespace std;

#define PLAYER1 1
#define PLAYER2 2

#define SIZE 3

#define PLAYER1MOVE 'X' 
#define PLAYER2MOVE 'O'

char arr[SIZE][SIZE]; 

void intoToShow() {
    cout << "\t\t     Tic Tac Toe - Game" << endl << endl;
    cout << "\t\t\t " << "1" << " | " << "2" << " | " << "3" << endl;
    cout << "\t\t\t --------- " << endl;
    cout << "\t\t\t " << "4" << " | " << "5" << " | " << "6" << endl;
    cout << "\t\t\t --------- " << endl;
    cout << "\t\t\t " << "7" << " | " << "8" << " | " << "9" << endl << endl;
}

void showBoard() {
    cout << "\t\t     Tic Tac Toe - Game" << endl << endl;
    cout << "\t\t\t " << arr[0][0] << " | " << arr[0][1]  << " | " << arr[0][2]  << endl;
    cout << "\t\t\t --------- " << endl;
    cout << "\t\t\t " << arr[1][0]  << " | " << arr[1][1] << " | " << arr[1][2] << endl;
    cout << "\t\t\t --------- " << endl;
    cout << "\t\t\t " << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << endl << endl;
}


void arrInitialization() {
    for(int i=0; i < SIZE; i++)
        for(int j=0; j < SIZE; j++)
            arr[i][j] = ' ';
}


bool winCheck() {
    if(arr[0][0]== arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')
        return true;

    if(arr[0][2]== arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != ' ')
        return true;

    for(int i=0; i < SIZE; i++){
        if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
            return true;
        if(arr[0][i]== arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ')
            return true;
    }
   
    return false;
}

bool checkAlreadyPresent(int input, int *x, int *y) {
    *x = (input-1)/SIZE; 
    *y = (input-1)%SIZE;
    if(arr[(*x)][(*y)] == ' ')
        return false;
    return true;
}

void getInputFromUser(int *player, int *x, int *y) {
    int input;
    cout << "Player " << *player << " Enter Number  : ";
    cin >> input;
    if(input > SIZE*SIZE && input < 0) {
        cout << "Enter Number betweeen : 1 - " << SIZE*SIZE << " : " ;
        getInputFromUser(player, x, y);
    } else if (checkAlreadyPresent(input, x, y)){
        cout << "Number "<<  input << " is already Present!!!" ;
        getInputFromUser(player, x, y);
    }
}

void game() {
    arrInitialization();
    int move = 0;
    int x , y , whoisTurn=PLAYER1;
    while(!winCheck()&& move != SIZE*SIZE) {
        getInputFromUser(&whoisTurn, &x, &y);
        if(whoisTurn == PLAYER1) {
            arr[x][y] =  PLAYER1MOVE;
            whoisTurn = PLAYER2;
        } else {
            arr[x][y] =  PLAYER2MOVE;
            whoisTurn = PLAYER1;
        }
        showBoard();
        move++;
    }
    showBoard();
    if(move == SIZE*SIZE) {
        cout << "Match Draw!!!" << endl;
    } else {
       if(whoisTurn == PLAYER1) 
           cout << "PLAYER 2 Win the Match!!!" << endl;
       else 
           cout << "PLAYER 1 Win the Match!!!" << endl;
    }
}

int main()
{
    intoToShow();
    game();
    return 0;
}

