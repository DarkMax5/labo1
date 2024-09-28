#include "tic_tac_toe.hpp"
#include <iostream>

using namespace std;

int main() {
    TicTacToe game;
    char players[2] = { 'X', 'O' };
    int turn = 0;
    int row, col;

    while (true) {
        game.printBoard();
        char currentPlayer = players[turn % 2];
        cout << "��� ������ " << currentPlayer << ": ������� ������ � ������� (0, 1 ��� 2): ";
        cin >> row >> col;

        // ���������� ����
        if (!game.makeMove(row, col, currentPlayer)) {
            cout << "������������ ���. ���������� �����." << endl;
            continue;
        }

        // �������� �� ������
        if (game.checkWinner(currentPlayer)) {
            game.printBoard();
            cout << "����� " << currentPlayer << " �������!" << endl;
            break;
        }

        // �������� �� �����
        if (game.isFull()) {
            game.printBoard();
            cout << "�����!" << endl;
            break;
        }

        turn++;
    }

    return 0;
}
