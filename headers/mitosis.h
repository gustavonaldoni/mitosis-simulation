void SplitCellIntoTwo(Cell *, int);

void SplitCellIntoTwo(Cell cells[], int cellIndex)
{
    float radius1;
    int speedX, speedY;
    int index1, index2;

    // Cell 1
    radius1 = cells[cellIndex].radius / 2;

    speedX = GenerateRandomNumber(200, 250);
    speedY = GenerateRandomNumber(200, 250);

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
    speedX = -speedY;

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