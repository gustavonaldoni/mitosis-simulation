void SplitCellIntoTwo(Cell *, int);
void GrowCell(Cell *, float, float);
void GrowCells(Cell *, int, float, float);

void SplitCellIntoTwo(Cell cells[], int cellIndex)
{
    float radius1;
    int speedX, speedY;
    int index1, index2;

    // Cell 1
    radius1 = cells[cellIndex].radius / 2;

    speedX = GenerateRandomNumber(200, 250);
    speedY = GenerateRandomNumber(200, 250);

    if (cells[cellIndex].speedY < 0)
        speedY = -speedY;

    index1 = cellIndex;

    CreateCell(cells,
               index1,
               cells[cellIndex].x - 10,
               cells[cellIndex].y,
               speedX,
               speedY,
               radius1);

    // Cell 2
    speedX = -speedX;

    index2 = GetNextEmptyCellIndex(cells, MAX_CELLS);

    if (index2 != -1)
    {
        printf("index2 = %d\n", index2);

        CreateCell(cells,
                   index2,
                   cells[cellIndex].x - 10,
                   cells[cellIndex].y,
                   speedX,
                   speedY,
                   radius1);
    }
}

void GrowCell(Cell* cell, float growthFactor, float maxSize)
{
    if (cell->radius <= maxSize)
        cell->radius *= growthFactor;
}

void GrowCells(Cell cells[], int maxCells, float growthFactor, float maxSize)
{
    int i;

    for (i = 0; i < maxCells; i++)
    {
        GrowCell(&cells[i], growthFactor, maxSize);
    }
}