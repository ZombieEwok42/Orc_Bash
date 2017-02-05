#pragma once
class Player {
public:
	Player();
	Player(int h, int d, int a);
	Player(int h, int d, int a, int exp);
	void Status();
	void setHP(int h);
	int getHP();
	void setDF(int d);
	int getDF();
	void setAT(int a);
	int getAT();
	void Damage(int inAT, bool defending);
private:
	int HP;
	int max_hp;
	int DF;
	int AT;
	int EXP;
};
