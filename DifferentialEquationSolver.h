#pragma once

#include <vector>

#include "Vector.h"

class DifferentialEquationSolver
{
public:
	virtual ~DifferentialEquationSolver() = default;
	virtual void Step(std::vector<Body>& Planets, double StepSize) = 0;
};

class RungeKuttaSolver : DifferentialEquationSolver
{
	virtual void Step(std::vector<Body>& Planets, double StepSize) override
	{

	}
};

class ForwardEulerSolver : DifferentialEquationSolver
{
	virtual void Step(std::vector<Body>& Planets, double StepSize) override
	{
		for (auto Planet : Planets)
		{
			
		}
	}

private:
	Vector CalculateForce(std::vector<Body>& Planets, Body Current)
	{
		return Vector{};
	}
};

