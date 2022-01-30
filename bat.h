#pragma once
#include "SFML/Graphics.hpp"
class Bat {
protected:
	sf::RectangleShape rect;
	int width = 25;
	int height = 100;
	float speedy = 5.f;
public:
	Bat(float startx, float starty) {
		rect.setSize(sf::Vector2f(width,height));
        rect.setPosition(startx, starty);
		rect.setFillColor(sf::Color(255,242,140));
	}
	sf::RectangleShape getShape() { return rect; }
	sf::FloatRect getHitBox() { return rect.getGlobalBounds(); }
	sf::Vector2f getPosition() { return rect.getPosition(); }
	int getHeight() { return height; }
	int getWidth() { return width; }
 };
