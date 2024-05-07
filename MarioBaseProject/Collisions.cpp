#include "Collisions.h"
#include "Character.h"

using namespace std;

//initialise instance to nullptr
Collisions* Collisions::m_instance = nullptr;

Collisions::Collisions()
{

}

Collisions::~Collisions()
{
	m_instance = nullptr;
}

void Collisions::Collisions* m_instance()
{
	if (!m_instance)
	{
		m_instance = new Collisions;
	}
	return m_instance;
}