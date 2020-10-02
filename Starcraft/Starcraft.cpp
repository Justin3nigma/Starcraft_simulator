#include <iostream>

using namespace std;
class Marine {
	static int total_unit;
	const static int i = 0;

	int idnum;             //id num
	int hp;                // Marine hp
	int xaxis, yaxis;  // Marine coordinance
	bool dead;

	const int dmg;  // default dmg

public:
	Marine();              // constructor
	Marine(int x, int y);  // spawn on this location
	Marine(int id, int x, int y, int dmg);

	int attack() const;                    // return dmg
	Marine& damaged(int damage_earn);  // decrease (dmg) amount of hp 
	void oscar_mike(int x, int y);               // move to new coordinance

	void status_report();  // hp and coordinance report
	static void show_unitnum();
	~Marine() { total_unit--; }
};

int Marine::total_unit = 0;

void Marine::show_unitnum() {
	cout << "Number of Units : " << total_unit << endl;
}

Marine::Marine()
	: idnum(0),hp(50), xaxis(0), yaxis(0), dmg(5), dead(false) {
	total_unit++;
}

Marine::Marine(int x, int y)
	: xaxis(x),
	  yaxis(y),
	idnum(0),
	  hp(50),
	  dmg(5),
	  dead(false) {
	  total_unit++;
	  idnum = total_unit;
}

Marine::Marine(int id, int x, int y, int dmg)
	: idnum(id),
	xaxis(x),
	yaxis(y),
	hp(50),
	dmg(dmg),
	dead(false) {
	total_unit++;
}

int Marine::attack() const {
	return dmg;
}

Marine& Marine::damaged(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) dead = true;

	return *this;
}

void Marine::oscar_mike(int x, int y) {
	xaxis = x;
	yaxis = y;
}

void Marine::status_report() {
	cout << "----------------------------" << endl;
	cout << "=-=Marine"<<idnum<<"=-="<< endl;
	cout << " Location : ( " << xaxis << " , " << yaxis << " ) "<< endl;
	cout << " HP : " << hp << std::endl;
	cout << " Number of deployed Units : " << total_unit << endl;
	cout << "----------------------------" << endl;
	cout << "|" << endl;
}

int main() {
	Marine marine1(1,1,1, 5);
	marine1.status_report();

	Marine marine2(2,3, 2, 10);
	marine2.status_report();

	Marine marine3(3,1, 5, 10);
	marine3.status_report();

	cout << endl << "Marine2 is attacked by Marine1 twice" << endl;
	marine2.damaged(marine1.attack()).damaged(marine1.attack());
	marine1.status_report();
	marine2.status_report();

	cout << endl << "Marine3 attacks Marine2" << endl << endl;
	marine2.damaged(marine3.attack());
	marine3.status_report();
	marine2.status_report();
}