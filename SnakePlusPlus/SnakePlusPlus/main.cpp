#include "Framework.h"
#include <Windows.h>

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{

	Framework::Initialize(WIDTH, HEIGHT, "SnakePlusPlus v1.0", sf::Style::Close);
	Framework::Run();

	return 0;
}