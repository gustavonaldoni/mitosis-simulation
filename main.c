#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "include/raylib.h"

// Compile with: gcc main.c -o mitosisSimulator.exe -O1 -Wall -std=c99 -Wno-missing-braces -I include/ -L lib -lraylib -lopengl32 -lgdi32 -lwinmm

#define MAX_CELLS 200
#define INITIAL_CELLS MAX_CELLS / 20

#include "headers/utils.h"
#include "headers/cell.h"
#include "headers/userInteraction.h"
#include "headers/mitosis.h"

int cellClickedIndex;
int totalCells = INITIAL_CELLS;

int main()
{
	Cell cells[MAX_CELLS];
	srand(time(NULL));

	int screenConstant = 300;
	InitWindow(4 * screenConstant, 3 * screenConstant, "Mitosis Simulator");

	SetTargetFPS(144);
	InitAudioDevice();

	ResetCellsValidations(cells, MAX_CELLS);
	CreateCells(cells, totalCells);

	while (!WindowShouldClose())
	{
		MoveCells(cells, totalCells);

		BeginDrawing();
		ClearBackground(RAYWHITE);

		cellClickedIndex = CheckUserClickOnAllCells(cells, totalCells);

		if (cellClickedIndex != -1)
		{
			SplitCellIntoTwo(cells, cellClickedIndex);
			totalCells += 1;
		}

		DrawCells(cells, totalCells);
		DrawCenteredText(TextFormat("Number of cells: %d", totalCells), GetScreenHeight() / 12, 30, DARKGRAY);

		EndDrawing();
	}

	CloseAudioDevice();
	CloseWindow();
}
