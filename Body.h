#pragma once

#include <string>

#include "Vector.h"

class Body
{
public:
	Body();
	Body(Vector Position, Vector Velocity, double Mass, std::string Name);

	Body(const Body& Other) = default;
	Body(Body&& Other) noexcept;

	Body& operator= (const Body& Other) = default;
	Body operator= (Body&& Other) noexcept;

	bool operator== (const Body& Other) const;
	bool operator!= (const Body& Other) const;

	Vector m_Position;
	Vector m_Velocity;
	Vector m_Force;

	double m_Mass;
	std::string m_Name;
};

