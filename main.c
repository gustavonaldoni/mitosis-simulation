#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "include/raylib.h"

// Compile with: gcc main.c -o mitosisSimulator.exe -O1 -Wall -std=c99 -Wno-missing-braces -I include/ -L lib -lraylib -lopengl32 -lgdi32 -lwinmm

#define MAX_CELLS 400
#define INITIAL_CELLS MAX_CELLS / 20

#define STATS_FONT_SIZE 25
#define GROWTH_FACTOR 1.0001
#define MAX_CELL_SIZE 60.0

#include "headers/utils.h"
#include "headers/cell.h"
#include "headers/userInteraction.h"
#include "headers/mitosis.h"
#include "headers/timeDraw.h"

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
		GrowCells(cells, totalCells, GROWTH_FACTOR, MAX_CELL_SIZE);

		//AutomaticSplitCellsIntoTwo(cells, MAX_CELLS, &totalCells, MAX_CELL_SIZE);

		BeginDrawing();
		ClearBackground(RAYWHITE);

		cellClickedIndex = CheckUserClickOnAllCells(cells, totalCells);

		if (cellClickedIndex != -1)
		{
			SplitCellIntoTwo(cells, cellClickedIndex);
			totalCells += 1;
		}

		DrawCells(cells, totalCells);

		DrawNumberOfCells(totalCells, GetScreenHeight() / 12, STATS_FONT_SIZE, DARKGRAY);
		DrawElapsedTime(1.5 * GetScreenHeight() / 12, STATS_FONT_SIZE, DARKGRAY);

		EndDrawing();
	}

	CloseAudioDevice();
	CloseWindow();
}
