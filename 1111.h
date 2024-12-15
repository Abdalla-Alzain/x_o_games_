#include "BoardGame_Classes.h"

template <typename T>
class p1_Board:public Board<T> {
public:
    p1_Board ();
    bool update_board (int x , int y , T symbol);
    void display_board ();
    bool is_win() ;
    bool is_draw();
    bool game_is_over();
};

template <typename T>
class P1_Player : public Player<T> {
public:
    P1_Player (string name, T symbol);
    void getmove(int& x, int& y) ;

};

template <typename T>
class p1_Random_Player : public RandomPlayer<T>{
public:
    p1_Random_Player (T symbol);
    void getmove(int &x, int &y) ;
};


#include <iostream>
#include <iomanip>
#include <cctype>  

using namespace std;

template <typename T>
p1_Board<T>::p1_Board() {
    this->rows = 3;
    this->columns=5;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool p1_Board<T>::update_board(int x, int y, T mark) {
    
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0) &&
        (!(x == 0 && y!=0) && !(x == 1 && y > 2))) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }

        return true;
    }
    return false;
}

template <typename T>
void p1_Board<T>::display_board() {
    cout << endl;
    cout << "                    | (0,0) "<< this->board[0][0] << " |" << endl << "          -------------------------------" << endl ;
    cout << "          | (1,0) "<< this->board[1][0]  << " | (1,1) "<< this->board[1][1]<< " | (1,2) "<< this->board[1][2] << " |" << endl << "--------------------------------------------------" << endl;
    cout << "| (2,0) "<< this->board[2][0]  << " | (2,1) "<< this->board[2][1] << " | (2,2) "<< this->board[2][2] << " | (2,3) "<< this->board[2][3] << " | (2,4) "<< this->board[2][4] << " |" ;
    cout << endl << endl;

}
template <typename T>
bool p1_Board<T>::is_win() {
    if ((this->board[0][0] == this->board[1][0] && this->board[1][0] == this->board[2][0] && this->board[0][0] != 0) || )
        (this->board[0][0] == this->board[1][2] && this->board[1][2] == this->board[2][4] && this->board[0][0] != 0) || 
        (this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 0) || 
        (this->board[1][0] == this->board[1][1] && this->board[1][1] == this->board[1][2] && this->board[1][0] != 0) || 
        (this->board[2][0] == this->board[2][1] && this->board[2][1] == this->board[2][2] && this->board[2][0] != 0) || 
        (this->board[2][1] == this->board[2][2] && this->board[2][2] == this->board[2][3] && this->board[2][1] != 0) || 
        (this->board[2][2] == this->board[2][3] && this->board[2][3] == this->board[2][4] && this->board[2][2] != 0) {
        return true;
    }

    return false;
}

template <typename T>
bool p1_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool p1_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

template <typename T>
P1_Player<T>::P1_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void P1_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
}


template <typename T>
p1_Random_Player<T>::p1_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  
}

template <typename T>
void p1_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  
    y = rand() % this->dimension;
}