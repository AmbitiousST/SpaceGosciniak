#include "utility.h"

button::button(Vector2 pos, std::string txt, Vector2 size, std::vector<sf::Drawable*>& vect) : _pos(pos), _size(size), _txt(txt)
{
	_box = sf::RectangleShape(_size);
	_box.setPosition(pos);
	_box.setFillColor(sf::Color(170, 170, 170, 0));
	_text = sf::Text(txt, font, 40);
	_text.setFillColor(sf::Color(0, 0, 0, 255));
	_text.setOutlineColor(sf::Color(255, 255, 255, 255));
	_text.setOutlineThickness(2);
	auto bounds = _text.getLocalBounds();
	_text.setPosition(pos.x + (_size.x - bounds.width - bounds.left) / 2, pos.y + (_size.y - bounds.height - bounds.top) / 2);	//Center
	_text.setFillColor(sf::Color(0, 0, 0, 255));
	vect.push_back(&_box);
	vect.push_back(&_text);
}

cursor::cursor(Vector2 pos, std::vector<sf::Drawable*>& vect) : _pos(pos)
{
	_texture.loadFromFile("../img/cursor.png");
	_leftSprite.setTexture(_texture);
	_leftSprite.setPosition(pos);
	_leftSprite.setScale(2, 2);
	_rightSprite.setTexture(_texture);
	_rightSprite.scale(-2, 2);
	_rightSprite.setPosition(pos.x + 250, pos.y);
	vect.push_back(&_leftSprite);
	vect.push_back(&_rightSprite);
}

void cursor::render(bool a)
{
	//Smieszny patent na pokazywanie/chowanie sprite'�w
	_leftSprite.setColor(sf::Color(255, 255, 255, a ? 255 : 0));
	_rightSprite.setColor(sf::Color(255, 255, 255, a ? 255 : 0));
}

void cursor::setPos(Vector2 pos)
{
	_pos = pos;
	_leftSprite.setPosition(pos);
	_rightSprite.setPosition(pos.x + 250, pos.y);
}