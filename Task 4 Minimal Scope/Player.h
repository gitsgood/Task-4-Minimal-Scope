#pragma once
#ifndef Player_H
#define Player_H

#include <iostream>
#include <cstdlib> //rand function
#include <ctime> //seeding rand to time
#include <string>

using namespace std;

class Player {
private:
	string type;
	int health;
	int damage;
	string items[3];
public:

	Player(const string& newType = "", const int& newHealth = 0, const int& newDamage = 0, const string newItems[3] = nullptr)
		:type(newType), health(newHealth), damage(newDamage) {
		if (newItems != nullptr) {
			for (int i = 0; i < 3; i++) {
				items[i] = newItems[i];
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				items[i] = "";
			}
		}
	}

	string getType();
	void setType(string newType);

	int getHealth();
	void setHealth(int newHealth);

	int getDamage();
	void setDamage(int newDamage);

	string getItems(int i);
	void setItems(int i, string newItem);
};

void attack(Player array[], int size);
int countLivingPlayers(Player array[3]);
void presentableStats(Player combatants[3]);

#endif // !Player_H