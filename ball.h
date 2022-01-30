#pragma once
#include "SFML/Graphics.hpp"

class Ball {
private:
	sf::CircleShape circle;
	sf::FloatRect hitbox;
	float radius = 20.f;
	float speedx = 2.5f;
	float speedy = -2.5f;
	size_t left_score = 0;
	size_t right_score = 0;
	sf::Vector2f midtop;
	sf::Vector2f midleft;
	sf::Vector2f midbottom;
	sf::Vector2f midright;
public:
	Ball();
	sf::CircleShape getShape();
	sf::Vector2f getPosition();
	void update();
	sf::FloatRect getHitBox();
	void reboundHorizontal();
	void reboundVertical();
	size_t getLeftScore();
	size_t getRightScore();
	sf::Vector2f getMidTop();
	sf::Vector2f getMidLeft();
	sf::Vector2f getMidBottom();
	sf::Vector2f getMidRight();
	void setPosition(sf::Vector2f);
	float getRadius();
};
