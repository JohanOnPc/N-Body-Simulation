#pragma once

#include <string>

#include "Vector.h"

class Body
{
public:
	Body();
	Body(Vector Position, Vector Velocity, double Mass, std::string Name);

	Body(const Body& other) = default;
	Body(Body&& other) noexcept;

	Body& operator= (const Body& other) = default;
	Body operator= (Body&& other) noexcept;

	Vector m_Position;
	Vector m_Velocity;
	Vector m_Force;

	double m_Mass;
	std::string m_Name;
};

