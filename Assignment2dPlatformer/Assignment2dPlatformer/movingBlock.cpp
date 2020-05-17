#include "movingBlock.h"



movingBlock::movingBlock(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation, sf::Color colour )
{
	b2BodyDef l_bodyDef;
	b2PolygonShape l_shape;
	b2FixtureDef l_fixtureDef;

	l_bodyDef.position.Set(position.x, position.y);
	l_bodyDef.angle = orientation * DEG2RAD;
	l_bodyDef.type = b2_kinematicBody;

	m_body = world->CreateBody(&l_bodyDef);
	m_body->SetUserData(this); // used by our contact listener

	l_shape.SetAsBox(size.x * 0.5f, size.y * 0.5f);
	l_shape.m_radius = 0.0f;

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


	
	
	
	m_body->SetLinearVelocity(b2Vec2(0.07f, 0.0f));
	

	
}

void movingBlock::moveBlock() {


	m_body->ApplyForceToCenter(b2Vec2(-0.25f, 0.0f), false);

}

void movingBlock::update() {
	b2Vec2 pos = m_body->GetPosition();
	
	setPosition(pos.x, -0.5f);
	float angle = m_body->GetAngle()* RAD2DEG;
	setRotation(0);
	


	/*shape.move(1 + speed, 0.0);
	if (speed > 0 && shape.getPosition().x > size.x)
	{
		shape.setPosition(sf::Vector2f(-shape.getSize().x, originalPosY));
	}*/

}
