#include "Framework.h"
#include <Windows.h>

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	Framework::Initialize(WIDTH, HEIGHT, "SnakePlusPlus v1.2", sf::Style::Close);	// Initialize Framework
	Framework::Run();	// Enter program loop

	return 0;
}