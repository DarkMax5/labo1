#include "tic_tac_toe.hpp"
#include <iostream>

using namespace std;

// ����������� � ������������� ����
TicTacToe::TicTacToe() {
    initializeBoard();
}

// ������������� �������� ����
void TicTacToe::initializeBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' ';  // ������ ������
        }
    }
}

// ������ �������� ����
void TicTacToe::printBoard() const {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "--|---|--" << endl;
    }
}

// �������� �� ������
bool TicTacToe::checkWinner(char player) const {
    // �������� ������������ � ����������
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }

    // �������� ����������
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;

    return false;
}

// �������� �� ������������� ����
bool TicTacToe::isFull() const {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

// ���������� ����
bool TicTacToe::makeMove(int row, int col, char player) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
        return false;  // �������� ���
    }

    board[row][col] = player;  // ���������� ����
    return true;
}
