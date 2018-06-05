#include "Framework.h"

int main()
{

	Framework::Initialize(WIDTH, HEIGHT, "SnakePlusPlus v1.0", sf::Style::Close);
	Framework::Run();

	return 0;
}