#include "Orc.h"
#include <iostream>

Orc::Orc(int level) { // Rolls a new Orc at a given level.
	HP = base_hp;
	DF = base_df;
	AT = base_at;
	Level(level);
}
void Orc::Level(int level) {
	if (level > LVL) {
		int increase = level - LVL;
		for (int i = LVL; i < LVL + increase; i++) {
			HP = HP_RATE*i + HP*1.0;
			AT = AT_RATE*i + AT*1.0;
			DF = DF_RATE*i + DF*1.0;
		}
	}
}
Orc::Orc(int h, int d, int a) {
	HP = h;
	max_hp = h;
	DF = d;
	AT = a;
}
void Orc::Status() {
	std::cout << "\nOrc: HP " << HP << ", Defense " << DF << ", Attack: " << AT;
}
void Orc::setHP(int h) {
	HP = h;
	if (HP < 0)
		HP = 0;
}
int Orc::getHP() {
	return HP;
}
void Orc::setDF(int d) {
	DF = d;
}
int Orc::getDF() {
	return DF;
}
void Orc::setAT(int a) {
	AT = a;
}
int Orc::getAT() {
	return AT;
}
void Orc::Damage(int inAT) { // Resolves incoming attack
	if (inAT > DF)
		HP = HP - (inAT - DF);
	if (HP < 0)
		HP = 0;
}
int Orc::expGain() {
	int tempEXP = LVL*BASE_EXP;
	return tempEXP;
}