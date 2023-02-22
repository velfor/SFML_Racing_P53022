#pragma once
#include "settings.h"

struct Obstacle {
	sf::Texture texture;
	sf::Sprite sprite;
};

void obstacleInit(Obstacle& obs, std::string fileName) {
	obs.texture.loadFromFile(fileName);
	obs.sprite.setTexture(obs.texture);
	int posx = rand() % 301 + 100;
	posx = posx - posx % 100;
	int posy = rand() % 201 - 1000;
	obs.sprite.setPosition(posx, posy);
}
void obstcleUpdate(Obstacle& obs) {
	obs.sprite.move(0.f, 2.f);
	if (obs.sprite.getPosition().y >= WINDOW_HEIGHT) {
		int posx = rand() % 301 + 100;
		posx = posx - posx % 100;
		int posy = rand() % 201 - 1000;
		obs.sprite.setPosition(posx, posy);
	}
}

void obstacleDraw(sf::RenderWindow& window, const Obstacle& obs) {
	window.draw(obs.sprite);
}