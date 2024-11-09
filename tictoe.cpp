#include <iostream>
using namespace std;

char player = 'O';
int turn = 0;
int n = 5;
char board[5][5];

int getPosition(){
    cout << "Enter the position: "<<endl;
    int position;
    cin >> position;
    return position;
}

int wins() {
    if(board[0][0]==player && board[2][2]==player && board[4][4]==player) {
        return 1;
    }else if(board[0][0]==player && board[0][2]==player && board[0][4]==player) {
        return 1;
    }else if(board[0][0]==player && board[2][0]==player && board[4][0]==player) {
        return 1;
    }else if(board[0][2]==player && board[2][2]==player && board[4][2]==player) {
        return 1;
    }else if(board[0][4]==player && board[2][4]==player && board[4][4]==player) {
        return 1;
    }else if(board[0][4]==player && board[2][2]==player && board[4][0]==player) {
        return 1;
    }else if(board[4][0]==player && board[4][2]==player && board[4][4]==player) {
        return 1;
    }else if(board[2][0]==player && board[2][2]==player && board[2][4]==player) {
        return 1;
    }

    return 0;
}

void play(int position) {
    int a,b;
    switch(position) {
        case 1:
        a = 0; b = 0;
        break;
        case 2:
        a = 0; b = 2;
        break;
        case 3: 
        a = 0; b = 4;
        break;
        case 4:
        a = 2; b = 0;
        break;
        case 5: 
        a = 2; b = 2;
        break;
        case 6:
        a = 2; b = 4;
        break;
        case 7:
        a = 4; b = 0;
        break;
        case 8: 
        a = 4; b = 2; 
        break;
        case 9:
        a = 4; b = 4;
        break;
    }
    if(board[a][b] == ' ') {
        board[a][b] = player;
    }else {
        cout <<"Wrong move!"<<endl<<endl;
        cout << "Try again!"<<endl;
        int pos = getPosition();
        play(pos);
    }
}

void display() {
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << board[i][j]<<" ";
        }
        cout << endl;
    }
}

int main() {

    for(int i=0; i<n;i++) {
        for(int j=0; j<n; j++) {
            if(j==1||j==3||i==1||i==3) {
                board[i][j] = '*';
            }else {
                board[i][j] = ' ';
            }
        }
    }

    while(true) {       
        
        turn++;
        player = (player == 'X') ? 'O' : 'X';
        int pos = getPosition();
        play(pos);
        display();

        if(wins()) {
            cout << endl<<"Player "<< player<<" won the game.";
        }else if(turn == 9 && !wins()) {
            cout <<endl<< "Match is draw.";
            return 0;
        }
    }
}