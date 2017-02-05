#include <iostream>
#include <ctime>
#include <sstream>
#include <cstdlib>
#include "Orc.h"
#include "player.h"

using namespace std;


void Encounter(Orc orc, Player player);
int main() {
	srand(time(0));
	cout << "ayy weclome to orc bash\n";
	Orc orc1(10, 5, 6);
	Player erdrick(15, 4, 7);
	Encounter(orc1, erdrick);

	cin.get();
	return 0;
}
void Encounter(Orc orc, Player player) {
	bool resolved = false, fled = false, defend = false, end = false, playerDefeated = false, playerWins = false;
	string input;
	orc.Status();
	player.Status();
	while (resolved == false) {
		end = false;
		while (end == false) {
			cout << "\nWhat will you do? \nAttack Defend Flee\n";
			getline(cin, input);
			if (input == "Attack" || input == "attack" || input == "a") {
				int tempHP = orc.getHP();
				orc.setHP(orc.getHP() - (player.getAT() - orc.getDF()));
				cout << "You dealt " << tempHP - orc.getHP() << " damage!";
				orc.Status();
				player.Status();
				end = true;
			}
			else if (input == "Defend" || input == "defend" || input == "d") {
				cout << "You brace yourself.";
				defend = true;
				end = true;
			}
			else if (input == "Flee" || input == "flee" || input == "f") {
				cout << "Erdrick fled.\n";
				resolved = true;
				fled = true;
				break;
			}
			else {
				cout << "\nI didn't understand that.";
			}
		}
		if (fled == true) {
			break;
		}
		if (orc.getHP() == 0) {
			cout << "\nThe orc has been slain!";
			resolved = true;
			playerWins = true;
			break;
		}
		end = false;
		while (end == false) {
			cout << "\nThe orc eyes you warily...";
			int action = rand() % 4;
			if (action < 2) {
				int tempHP = player.getHP();
				cout << "\nThe orc strikes!";
				player.Damage(orc.getAT(), defend);
				cout << "\nThe orc deals " << tempHP - player.getHP() << " damage!";
				orc.Status();
				player.Status();
				end = true;
			}
			else if (action >= 2){
				cout << "\nThe orc does nothing.";
				end = true;
			}
			else {
				cout << "\n\nSomething went wrong. action is " << action;
				end = true;
			}
			if (player.getHP() == 0) {
				cout << "\nOh no! Player has been defeated!";
				resolved = true;
				playerDefeated = true;
				break;
			}
			end = true;
		}
	}
}