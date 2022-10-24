#include "Body.h"

Body::Body() 
	: m_Position{ 0.0, 0.0, 0.0 }, m_Velocity{ 0.0, 0.0, 0.0 }, m_Force{ 0.0, 0.0, 0.0 }, m_Mass { 0.0 }
{
}

Body::Body(Vector Position, Vector Velocity, double Mass, std::string Name) 
	: m_Position{ Position }, m_Velocity{ Velocity }, m_Force{ 0.0, 0.0, 0.0 }, m_Mass { Mass }, m_Name{ Name }
{
}

Body::Body(Body&& other) noexcept
{
	m_Position = other.m_Position;
	m_Velocity = other.m_Velocity;
	m_Force = other.m_Force;
	m_Mass = other.m_Mass;
	m_Name = std::move(other.m_Name);
}

Body Body::operator=(Body&& other) noexcept
{
	m_Position = other.m_Position;
	m_Velocity = other.m_Velocity;
	m_Force = other.m_Force;
	m_Mass = other.m_Mass;
	m_Name = std::move(other.m_Name);

	return *this;
}

bool Body::operator==(const Body& Other) const
{
	return m_Name == Other.m_Name;
}

bool Body::operator!=(const Body& Other) const
{
	return m_Name != Other.m_Name;
}
