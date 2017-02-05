#include "player.h"
#include <iostream>

Player::Player(int h, int d, int a) {
	HP = h;
	max_hp = h;
	DF = d;
	AT = a;
	EXP = 0;
}
Player::Player(int h, int d, int a, int exp) {
	HP = h;
	max_hp = h;
	DF = d;
	AT = a;
	EXP = exp;
}
void Player::Status() {
	std::cout << "\nPlayer: HP " << HP << ", Defense " << DF << ", Attack: " << AT;
}
void Player::setHP(int h) {
	HP = h;
}
int Player::getHP() {
	return HP;
}
void Player::setDF(int d) {
	DF = d;
}
int Player::getDF() {
	return DF;
}
void Player::setAT(int a) {
	AT = a;
}
int Player::getAT() {
	return AT;
}
void Player::Damage(int inAT, bool defending) { // Resolves incoming attack
	if (defending == false) {
		if (inAT > DF)
			HP = HP - (inAT - DF);
	}
	else if (defending == true) {
		if (inAT > DF*1.25)
			HP = HP - (inAT - DF*1.25);
	}
	if (HP < 0)
		HP = 0;
}