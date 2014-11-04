#include "Entity.h"
#include "Vector3.h"

Entity::Entity(const Vector3 & position) : _position(position)
{
}



Entity::~Entity()
{

}

Entity::Entity() : _position(Vector3(0.0f, 0.0f, 0.0f))
{

}
