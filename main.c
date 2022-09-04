#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "include/raylib.h"
#include "headers/utils.h"
#include "headers/cell.h"

// Compile with: gcc main.c -o mitosisSimulator.exe -O1 -Wall -std=c99 -Wno-missing-braces -I include/ -L lib -lraylib -lopengl32 -lgdi32 -lwinmm

#define MAX_CELLS 200

int main()
{
	Cell cells[MAX_CELLS];
	srand(time(NULL));

	int screenConstant = 300;
	InitWindow(4 * screenConstant, 3 * screenConstant, "Mitosis Simulator");

	SetTargetFPS(144);
	InitAudioDevice();

	CreateCells(cells, MAX_CELLS / 2);

	while (!WindowShouldClose())
	{
		MoveCells(cells, MAX_CELLS / 2);

		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawCells(cells, MAX_CELLS / 2);

		EndDrawing();
	}

	CloseAudioDevice();
	CloseWindow();
}
