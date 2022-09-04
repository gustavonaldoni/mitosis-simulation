#include <stdlib.h>
#include <stdbool.h>
#include "include/raylib.h"

// Compile with: gcc main.c -o mitosisSimulator.exe -O1 -Wall -std=c99 -Wno-missing-braces -I include/ -L lib -lraylib -lopengl32 -lgdi32 -lwinmm

int playerLine, playerColumn;
int turn = 1;
int totalPlays = 0;

int main()
{
	int screenConstant = 300;
	InitWindow(4 * screenConstant, 3 * screenConstant, "Mitosis Simulator");

	SetTargetFPS(144);
	InitAudioDevice();

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		EndDrawing();
	}

	CloseAudioDevice();
	CloseWindow();
}
