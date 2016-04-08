#include "TicTacToeGame.h"
#include <iostream>

using namespace std;


TicTacToeGame::TicTacToeGame()
{
	
}

void TicTacToeGame::playGame()
{
	clearBoard();

	char player1 = 'X';
	char player2 = 'Y';
	char currentPlayer = player1;
	bool isDone = false;
	int turn = 0;
	int x, y;
	//game loop
	while (isDone == false) {
		printBoard();
		x = getXCoord();
		y = getYCoord();
		cout << "\nIt is " << currentPlayer << " turn\n";
		if (placeMarker(x, y, currentPlayer) == false) {
			cout << "****Try Again****";
		} else {
			turn++;
			if (checkVictoy(currentPlayer) == true) {
				cout << "\nPlayer " << currentPlayer << " has won!\n";
				isDone = true;
			}
			else if(turn == 9) {
				cout << "Tie game!\n";
				isDone = true;
			}

			if (currentPlayer == player1) {
				currentPlayer = player2;
				} else {
					currentPlayer = player1;
				}
			}
	}	
}


bool TicTacToeGame::placeMarker(int x, int y, char currentPlayer)
{
	if (board[y][x] != ' ') {
		cout << "\n****There is already a marker there.****\n";
		return false;
	}

	board[y][x] = currentPlayer;
	return true;
}

bool TicTacToeGame::checkVictoy(char currentPlayer)
{
	//check rows for win
	for (int i = 0; i < 3; i++) {
		if ((board[i][0] == currentPlayer) && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
			return true;
		}
	}
	//check colums for win
	for (int i = 0; i < 3; i++) {
		if ((board[0][i] == currentPlayer) && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
			return true;
		}
	}
	//check top left diagonal
	if ((board[0][0] == currentPlayer) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
		return true;
	}
	//check top right diagonal
	if ((board[2][0] == currentPlayer) && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2])) {
		return true;
	}
	return false;
}

void TicTacToeGame::clearBoard() {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			board[y][x] = ' ';
		}
	}
}

void TicTacToeGame::printBoard() {

	cout << endl;
	cout << " |1 2 3|\n";
	for (int i = 0; i < 3; i++) {
		cout << " -------\n";
		cout << i+1 << "|" << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << "|\n";
		
	}
	cout << " -------\n";
}

int TicTacToeGame::getXCoord()
{
	bool isInputBad = true;
	int x;
	while (isInputBad == true) {		
		cout << "Enter the X coordinate\n";
		cin >> x;
		
		if (x < 1 || x > 3) {
			cout << "invalid coordinate!\n";
		} else {
			isInputBad = false;
		}
	}
	return x - 1;
}

int TicTacToeGame::getYCoord()
{
	bool isInputBad = true;
	int y;
	while (isInputBad == true) {
		cout << "Enter the Y coordinate\n";
		cin >> y;

		if (y < 1 || y > 3) {
			cout << "invalid coordinate!\n";
		}
		else {
			isInputBad = false;
		}
	}
	return y - 1;
}


