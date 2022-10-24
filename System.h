#pragma once

#include <vector>

#include "Body.h"
#include "DifferentialEquationSolver.h"

class System
{
public:
	System();
	System(int InitialSize, double StepSize);
	System(int InitialSize, double StepSize, DifferentialEquationSolver* Solver);

	void AddPlanet(const Body& Planet);
	void AddPLanet(Body&& Planet);
	
	void Step(unsigned int Steps);
	void PrintCenterOfMass();

private:
	std::vector<Body> m_Planets;
	DifferentialEquationSolver* m_Solver;
	double m_StepSize;
};

