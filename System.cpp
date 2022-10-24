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

void System::Step(unsigned int Steps)
{
	while (Steps != 0)
	{
		m_Solver->Step(m_Planets, m_StepSize);
		Steps--;
	}
}

void System::PrintCenterOfMass()
{
	Vector Centre{};
	double Mass = 0;

	for (auto& Planet : m_Planets)
	{
		Centre += Planet.m_Position * Planet.m_Mass;
		Mass += Planet.m_Mass;
	}

	static int i = 0;

	std::cout << i++ << " > Center of mass: " << Centre * (1 / Mass) << '\n';
}
