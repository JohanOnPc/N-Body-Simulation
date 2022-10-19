#include "Body.h"

int main()
{
	VectorF idk{ 21.0, 21.0, 2.0 };
	std::cout << idk.Length() << '\n';
	std::cout << idk.LengthSquared();
}