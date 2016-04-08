#pragma once
class TicTacToeGame
{
public:
	TicTacToeGame();
	void playGame();
private:
	bool placeMarker(int x, int y, char currentPlayer);
	bool checkVictoy(char currentPlayer);
	void clearBoard();
	void printBoard();
	int getXCoord();
	int getYCoord();
	char board[3][3];
};

