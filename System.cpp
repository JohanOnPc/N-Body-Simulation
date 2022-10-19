#include "System.h"

System::System()
	: m_StepSize{0.01}, m_Solver{ nullptr }
{
	m_Planets.reserve(20);
}

System::System(int InitialSize, double StepSize) 
	: m_StepSize{ StepSize }, m_Solver{ nullptr }
{
	m_Planets.reserve(InitialSize);
}

System::System(int InitialSize, double StepSize, DifferentialEquationSolver* Solver)
	: m_StepSize{ StepSize }, m_Solver{ Solver }
{
	m_Planets.reserve(InitialSize);
}

void System::AddPlanet(const Body& Planet)
{
	m_Planets.push_back(Planet);
}

void System::AddPLanet(Body&& Planet)
{
	m_Planets.push_back(std::move(Planet));
}
