#include "System.h"
#include "DifferentialEquationSolver.h"

int main()
{
	ForwardEulerSolver Solver;
	RungeKuttaSolver Rk4Solver;
	System SolarSystem(10, 0.01, &Rk4Solver);

	SolarSystem.AddPLanet({ {}, {}, 1.9855e30, "Sun" });
	SolarSystem.AddPLanet({ {57909175000.0, 0.0, 0.0}, {0.0, 47872.5}, 3.302e23, "Mercury" });
	SolarSystem.AddPLanet({ {-108209930000.0, 0.0, 0.0}, {0.0, -35021.4}, 4.869e24, "Venus" });
	SolarSystem.AddPLanet({ {149597890000.0, 0.0, 0.0}, {0.0, 29785.9}, 5.972e24, "Earth" });
	SolarSystem.AddPLanet({ {-227936640000.0, 0.0, 0.0}, {0.0, -24130.9}, 6.4191e23, "Mars" });
	SolarSystem.AddPLanet({ {778412010000.0, 0.0, 0.0}, {0.0, 13069.7}, 1.8987e27, "Jupiter" });
	SolarSystem.AddPLanet({ {-1426725400000.0, 0.0, 0.0}, {0.0, -9672.4}, 5.6851e26, "Saturn" });
	SolarSystem.AddPLanet({ {2870972200000.0, 0.0, 0.0}, {0.0, 6835.2}, 8.6849e25, "Uranus" });
	SolarSystem.AddPLanet({ {-4498252900000.0, 0.0, 0.0}, {0.0, -5447.8}, 1.0244e26, "Neptune" });
	

	while (true)
	{
		SolarSystem.Step(100 * 60 * 60 * 24);
		SolarSystem.PrintCenterOfMass();
	}
}

