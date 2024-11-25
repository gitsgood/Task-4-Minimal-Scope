#include "Player.h"

void attack(Player array[], int size) {

	int attacker = rand() % size;
	int defender = 0;
	//we make sure the attacker doesn't feel suicidal, there is a one third chance that the attacker attacks himself without this check
	do {
		defender = rand() % size;
	} while (defender == attacker);

	array[defender].setHealth(array[defender].getHealth() - array[attacker].getDamage());
	cout << array[attacker].getType() << " attacks " << array[defender].getType() << " for " << array[attacker].getDamage() << " damage!\n";
	cout << array[defender].getType() << " has " << array[defender].getHealth() << " health left!\n";
}

int countLivingPlayers(Player array[3]) {
	int count = 0;
	for (int i = 0; i < 3; i++) {
		if (array[i].getHealth() > 0)
			count++;
	}
	return count;
}

void presentableStats(Player combatants[3]) {
	cout << "Stats:\n";
	cout << "Combatants\t" << combatants[0].getType() << "\t" << combatants[1].getType() << "\t" << combatants[2].getType() << endl;
	cout << "Health\t" << combatants[0].getHealth() << "\t" << combatants[1].getHealth() << "\t" << combatants[2].getHealth() << endl;
	cout << "Damage\t" << combatants[0].getDamage() << "\t" << combatants[1].getDamage() << "\t" << combatants[2].getDamage() << endl;
	cout << "Items\t";
	for (int i = 0; i < 3; i++) {
		for (int p = 0; p < 3; p++) {
			cout << combatants[i].getItems(p);
				if (i < 2)
					cout << ", ";
		}
		cout << "\t";
	}
}

void main() {
	srand(time(0)); //here we seed the rand function to time ellapsed since a set date
	Player combatants[3];
	
	string typeInput = "";
	int healthInput = 0;
	int damageInput = 0;
	string itemInput = "";

	//the user will create the 3 players
	for (int i = 0; i < 3; i++) {
		cout << "Create combatant " << i + 1 << "\n" << "Who is combatant " << i + 1 << " ?\n";
		getline(cin >> ws, typeInput);
		combatants[i].setType(typeInput);
		cout << "\nHow healthy is combatant " << i + 1 << " ?\n";
		cin >> healthInput;
		combatants[i].setHealth(healthInput);
		cout << "\nHow hard does combatant " << i + 1 << " hit?\n";
		cin >> damageInput;
		combatants[i].setDamage(damageInput);
		cout << "\nWhat junk is combatant " << i + 1 << " holding?\n" << "\tThey can't hold more than 3...\n";
		for (int y = 0; y < 3; y++) {
			cout << "Junk number " << y + 1 << " ?\n";
			getline(cin >> ws, itemInput);
			combatants[i].setItems(y, itemInput);
		}
		cout << endl;
	}

	cout << "\nThe battle royale commences...\n";
	while (countLivingPlayers(combatants) > 1) {
		attack(combatants, countLivingPlayers(combatants));
		
		//here we sort dead combatants on the last indices of the array
		int dead = 0;
		for (int i = 0; i < 3-dead; i++) {
			if (combatants[i].getHealth() <= 0) {
				swap(combatants[i], combatants[2 - dead]);
				dead++;
			}
		}
	}
	cout << "\nThe " << combatants[0].getType() << " is the sole survivor of this battle!\nThey won the chance to live another day!\n";
}
