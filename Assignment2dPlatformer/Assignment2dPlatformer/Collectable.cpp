#include "Collectable.h"

//sf::RectangleShape Coin;





sf::RectangleShape colliderCoin;
Collectable::Collectable(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation, sf::Color colour) {
	
	b2BodyDef l_bodyDef;
	b2PolygonShape l_shape;
	b2FixtureDef l_fixtureDef;

	
	colliderCoin.setSize(sf::Vector2f(size.x, size.y));
	colliderCoin.setFillColor(colour);
	

	l_bodyDef.position.Set(position.x, position.y);
	l_bodyDef.angle = orientation * DEG2RAD;

	m_body = world->CreateBody(&l_bodyDef);
	m_body->SetUserData(this); // used by our contact listener

	l_shape.SetAsBox(size.x * 0.5f, size.y * 0.5f);
	l_shape.m_radius = 0.0f;


	l_fixtureDef.isSensor = true;
	l_fixtureDef.density = mk_fDensity;
	l_fixtureDef.friction = mk_fFriction;
	l_fixtureDef.restitution = mk_fRestitution;
	l_fixtureDef.shape = &l_shape;

	m_body->CreateFixture(&l_fixtureDef);

	setPosition(position);
	setSize(size);
	setOrigin(size * 0.5f);
	setRotation(orientation);
	setOutlineThickness(0.f);
	setFillColor(colour);

	

}








/*Collectable::Collectable(float posX, float posY)
{
	
	Coin.setSize(sf::Vector2f(1.f, 1.f));
	Coin.setFillColor(sf::Color::Yellow);
	Coin.setPosition(sf::Vector2f(posX, posY));


}*/


