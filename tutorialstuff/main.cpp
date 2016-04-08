#include "TicTacToeGame.h"
#include <iostream>
#include <string>

using namespace std;



int main() {
	bool isDone = false;
	char input;
	TicTacToeGame game;
	while (isDone == false) {
		game.playGame();
		cout << "Would you like to play again? (Y/N): ";
		cin >> input;
		if (input == 'N' || input == 'n') {
			isDone == true;
		}
		isDone == false;		
	}
	system("PAUSE");
	return 0;
}