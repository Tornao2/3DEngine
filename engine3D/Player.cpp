#include "Player.h"

Player* Player::instance = nullptr;

Player::Player(float readSideLength, float readX, float readY, float readZ, std::vector <glm::vec4> readColors) : Cube(readSideLength, readX, readY, readZ, readColors) {
	instance = this;
	msX = msY = msZ = 0;
}

void Player::setMsX(float readMs) {
	msX = readMs;
}

void Player::setMsY(float readMs) {
	msY = readMs;
}

void Player::setMsZ(float readMs) {
	msZ = readMs;
}

float Player::getMsX() {
	return msX;
}

float Player::getMsY() {
	return msY;
}

float Player::getMsZ() {
	return msZ;
}

void Player::move() {
	instance->translate({ instance->msX, instance->msY, instance->msZ });
	instance->msX = instance->msY = instance->msZ = 0;
}

Player* Player::getInstance() {
	return instance;
}