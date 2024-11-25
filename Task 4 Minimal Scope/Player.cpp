#include "Player.h"

string Player::getType() {
	return type;
}
void Player::setType(string newType) {
	type = newType;
}

int Player::getHealth() {
	return health;
}
void Player::setHealth(int newHealth) {
	health = newHealth;
}

int Player::getDamage() {
	return damage;
}
void Player::setDamage(int newDamage) {
	damage = newDamage;
}

string Player::getItems(int i) {
	return items[i];
}
void Player::setItems(int i, string newItem) {
		items[i] = newItem;
}