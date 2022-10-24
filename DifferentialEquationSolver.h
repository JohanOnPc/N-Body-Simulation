#pragma once

#include <vector>

#include "Vector.h"

class DifferentialEquationSolver
{
public:
	virtual ~DifferentialEquationSolver() = default;
	virtual void Step(std::vector<Body>& Planets, double StepSize) = 0;

	const double c_Gravity = 6.674e-11;
};

class RungeKuttaSolver : public DifferentialEquationSolver
{
public:
	void Step(std::vector<Body>& Planets, double StepSize) override
	{

	}
};

class ForwardEulerSolver : public DifferentialEquationSolver
{
public:
	void Step(std::vector<Body>& Planets, double StepSize) override
	{
		std::vector<Body> PlanetsCopy = Planets;

		for (auto& Planet : Planets)
		{
			Planet.m_Force = CalculateForce(PlanetsCopy, Planet);
			Planet.m_Velocity.Rate(Planet.m_Force * ( 1 / Planet.m_Mass ), StepSize);
			Planet.m_Position.Rate(Planet.m_Velocity, StepSize);
		}
	}

private:
	Vector CalculateForce(std::vector<Body>& Planets, Body& Current)
	{
		Vector Force {};
		Vector ForceNormal {};
		for (auto& Planet : Planets)
		{
			if (Planet != Current)
			{
				ForceNormal = Planet.m_Position - Current.m_Position;
				ForceNormal.Normalize();
				Force += ForceNormal * ((c_Gravity * Current.m_Mass * Planet.m_Mass) / (Current.m_Position - Planet.m_Position).LenghtSquared());
			}
		}

		return Force;
	}
};

