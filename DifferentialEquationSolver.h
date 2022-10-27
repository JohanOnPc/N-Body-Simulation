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
		Vector K1x, K1v, K2x, K2v, K3x, K3v, K4x, K4v;
		std::vector<Body> PlanetsCopy = Planets;

		for (auto& Planet : Planets)
		{
			K1x = Planet.m_Velocity;
			K1v = CalculateForce(PlanetsCopy, Planet, {}, 0) * (1 / Planet.m_Mass);
			K2x = Planet.m_Velocity + (K1v * (StepSize / 2));
			K2v = CalculateForce(PlanetsCopy, Planet, K1x, StepSize / 2) * (1 / Planet.m_Mass);
			K3x = Planet.m_Velocity + (K2v * (StepSize / 2));
			K3v = CalculateForce(PlanetsCopy, Planet, K2x, StepSize / 2) * (1 / Planet.m_Mass);
			K4x = Planet.m_Velocity + (K3v * (StepSize));
			K4v = CalculateForce(PlanetsCopy, Planet, K3x, StepSize) * (1 / Planet.m_Mass);

			Planet.m_Position.Rate(K1x + K2x * 2 + K3x * 2 + K4x, StepSize / 6);
			Planet.m_Velocity.Rate(K1v + K2v * 2 + K3v * 2 + K4v, StepSize / 6);
		}
	}

private:
	Vector CalculateForce(std::vector<Body>& Planets, Body& Current, Vector Kx, double h)
	{
		Vector Force{};
		Vector ForceNormal{};
		for (auto& Planet : Planets)
		{
			if (Planet != Current)
			{
				ForceNormal = (Planet.m_Position + Planet.m_Velocity * h) - (Current.m_Position + Kx * h);
				ForceNormal.Normalize();
				Force += ForceNormal * ((c_Gravity * Current.m_Mass * Planet.m_Mass) / ((Current.m_Position + Kx * h) - (Planet.m_Position + Planet.m_Velocity * h)).LenghtSquared());
			}
		}

		return Force;
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

