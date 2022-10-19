#pragma once

#include <string>

#include "Vector.h"

class Body
{
public:
	Body();
	Body(Vector Position, Vector Velocity, Vector Acceleration, double Mass, std::string Name);

	Body(const Body& other) = default;
	Body(Body&& other) noexcept;

	Body& operator= (const Body& other) = default;
	Body operator= (Body&& other) noexcept;

	void SetForce(Vector Force);

private:
	Vector m_Position;
	Vector m_Velocity;
	Vector m_Acceleration;
	Vector m_Force;

	double m_Mass;
	std::string m_Name;
};

