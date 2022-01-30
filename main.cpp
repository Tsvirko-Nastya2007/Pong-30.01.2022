#include <SFML/Graphics.hpp>
#include "const.h"
#include "ball.h"
#include "bat.h"
#include "left_bat.h"
#include "right_bat.h"
#include "text-obj.h"

using namespace sf;
int main()
{
	enum GameState{INTRO,PLAY,GAMEOVER};
	GameState game_state = INTRO;
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(
		VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), 
		"ITSteps SFML Pong"
	);
	window.setFramerateLimit(FPS);
	//�������� ������� ��������
	Ball ball;
	LeftBat left_bat(20, SCREEN_HEIGHT/2 - 50);
	RightBat right_bat(SCREEN_WIDTH - 40, SCREEN_HEIGHT / 2 - 50);
	TextObj left_score(SCREEN_WIDTH /5, 20);
	TextObj right_score(4*SCREEN_WIDTH /5, 20);
	TextObj intro_text(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		//1 ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Space) {
					game_state = PLAY;
				}
			}
		}
		//2 update
		switch (game_state) {
		case INTRO:
				intro_text.update("Pong");
				window.clear(Color(60, 60, 60));
				window.draw(intro_text.getText());
				window.display();
				break;
		case PLAY:
			ball.update();
			left_bat.update();
			right_bat.update();
			left_score.update(std::to_string(ball.getLeftScore()));
			right_score.update(std::to_string(ball.getRightScore()));
			//��������� ������������
			//���� ������������� ���� ������������ � ��������������� ����� ����
			if (ball.getHitBox().intersects(left_bat.getHitBox())) {
				//up
				if (left_bat.getHitBox().contains(ball.getMidBottom())) {

					ball.setPosition(sf::Vector2f(ball.getPosition().x,
						left_bat.getPosition().y - 2 * ball.getRadius()));
					ball.reboundVertical();
				}
				//right
				else if (left_bat.getHitBox().contains(ball.getMidLeft())) {
					ball.setPosition(sf::Vector2f(left_bat.getPosition().x+left_bat.getWidth(),
						ball.getPosition().y));
					ball.reboundHorizontal();
				}
				//bottom
				else if (left_bat.getHitBox().contains(ball.getMidTop())) {
					ball.setPosition(sf::Vector2f(ball.getPosition().x,
						left_bat.getPosition().y + left_bat.getHeight()));
					ball.reboundVertical();
				}
				ball.reboundHorizontal();
			}
			if (ball.getHitBox().intersects(right_bat.getHitBox())) {
				ball.reboundHorizontal();
			}
			// ��������� ����
			window.clear(Color(60, 60, 60));
			window.draw(ball.getShape());
			window.draw(left_bat.getShape());
			window.draw(right_bat.getShape());
			window.draw(left_score.getText());
			window.draw(right_score.getText());
			window.display();
			break;
		}
	}
	return 0;
}