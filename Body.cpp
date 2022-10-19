#include "Body.h"

Body::Body() 
	: m_Position{ 0.0, 0.0, 0.0 }, m_Velocity{ 0.0, 0.0, 0.0 }, m_Acceleration{ 0.0, 0.0, 0.0 }, m_Force{ 0.0, 0.0, 0.0 }, m_Mass { 0.0 }
{
}

Body::Body(Vector Position, Vector Velocity, Vector Acceleration, double Mass, std::string Name) 
	: m_Position{ Position }, m_Velocity{ Velocity }, m_Acceleration{ Acceleration }, m_Force{ 0.0, 0.0, 0.0 }, m_Mass { Mass }, m_Name{ Name }
{
}

Body::Body(Body&& other) noexcept
{
	m_Position = other.m_Position;
	m_Velocity = other.m_Velocity;
	m_Acceleration = other.m_Acceleration;
	m_Force = other.m_Force;
	m_Mass = other.m_Mass;
	m_Name = std::move(other.m_Name);
}

Body Body::operator=(Body&& other) noexcept
{
	m_Position = other.m_Position;
	m_Velocity = other.m_Velocity;
	m_Acceleration = other.m_Acceleration;
	m_Force = other.m_Force;
	m_Mass = other.m_Mass;
	m_Name = std::move(other.m_Name);

	return *this;
}

void Body::SetForce(Vector Force)
{
	m_Force = Force;
}
