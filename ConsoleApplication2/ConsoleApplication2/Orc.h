#pragma once
class Orc {
public:
	Orc();
	Orc(int level);
	Orc(int h, int d, int a);
	void Level(int level);
	void Status();
	void setHP(int h);
	int getHP();
	void setDF(int d);
	int getDF();
	void setAT(int a);
	int getAT();
	void Damage(int inAT);
	int expGain();
private:
	int HP;
	double HP_RATE = 1.25;
	int max_hp;
	int base_hp = 5;
	int DF;
	double DF_RATE = 1.1;
	int base_df = 1;
	int AT;
	double AT_RATE = 1.1;
	int base_at = 2;
	int LVL = 1;
	int BASE_EXP = 5;
};