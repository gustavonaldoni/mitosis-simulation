#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "include/raylib.h"
#include "headers/utils.h"
#include "headers/cell.h"
#include "headers/userInteraction.h"

// Compile with: gcc main.c -o mitosisSimulator.exe -O1 -Wall -std=c99 -Wno-missing-braces -I include/ -L lib -lraylib -lopengl32 -lgdi32 -lwinmm

#define MAX_CELLS 200
#define INITIAL_CELLS MAX_CELLS / 4

int cellClickedIndex;

int main()
{
	Cell cells[MAX_CELLS];
	srand(time(NULL));

	int screenConstant = 300;
	InitWindow(4 * screenConstant, 3 * screenConstant, "Mitosis Simulator");

	SetTargetFPS(144);
	InitAudioDevice();

	CreateCells(cells, INITIAL_CELLS);

	while (!WindowShouldClose())
	{
		MoveCells(cells, INITIAL_CELLS);

		BeginDrawing();
		ClearBackground(RAYWHITE);

		cellClickedIndex = CheckUserClickOnAllCells(cells, INITIAL_CELLS);

		if (cellClickedIndex != -1)
			DrawCenteredText(TextFormat("Cell clicked index = %d", cellClickedIndex), 
							 GetScreenHeight() / 12,
							 20, 
							 DARKGRAY);
		
		else if (cellClickedIndex == -1)
			DrawCenteredText("No cell clicked now", 
							 GetScreenHeight() / 12,
							 20, 
							 DARKGRAY);


		DrawCells(cells, INITIAL_CELLS);

		EndDrawing();
	}

	CloseAudioDevice();
	CloseWindow();
}
