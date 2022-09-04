typedef struct
{
    int x, y;
    int radius;
    float speedX, speedY;
    Color color;
} Cell;

void CreateCell(Cell*, int, int, int, int, int, int);
void CreateCells(Cell*, int);
void DrawCell(Cell);
void DrawCells(Cell*, int);

void CreateCell(Cell cells[], int index, int x, int y, int speedX, int speedY, int radius)
{
    Cell cell;

    cell.color = (Color){GenerateRandomNumber(0, 255), GenerateRandomNumber(0, 255), GenerateRandomNumber(0, 255), 255};
    cell.radius = radius;
    cell.speedX = speedX;
    cell.speedY = speedY;
    cell.x = x;
    cell.y = y;

    cells[index] = cell;
}

void CreateCells(Cell cells[], int maxCells)
{
    int i, radius;
    int speedX, speedY;

    for (i = 0; i < maxCells; i++)
    {
        radius = GenerateRandomNumber(20, 40);

        speedX = GenerateRandomNumber(200, 500);
        speedY = GenerateRandomNumber(200, 500);
        
        if (RandomProbabilityManipulation(50))
            speedX = -speedX;

        if (RandomProbabilityManipulation(50))
            speedY = -speedY;
        
        CreateCell(cells, 
                   i,
                   GenerateRandomNumber(radius, GetScreenWidth() - radius),
                   GenerateRandomNumber(radius, GetScreenWidth() - radius),
                   speedX,
                   speedY,
                   radius);
    }
}

void DrawCell(Cell cell)
{
    DrawCircle(cell.x, cell.y, (float)cell.radius, cell.color);
}

void DrawCells(Cell cells[], int maxCells)
{
    int i;

    for (i = 0; i < maxCells; i++)
    {
        DrawCell(cells[i]);
    }
}

void MoveCells(Cell cells[], int maxCells)
{
    int i;

    for (i = 0; i < maxCells; i++)
    {
        cells[i].x += cells[i].speedX * GetFrameTime();
        cells[i].y += cells[i].speedY * GetFrameTime();

        if (cells[i].x >= GetScreenWidth())
            cells[i].speedX *= -1;

        if (cells[i].x <= 0)
            cells[i].speedX *= -1;

        if (cells[i].y >= GetScreenHeight())
            cells[i].speedY *= -1;

        if (cells[i].y <= 0)
            cells[i].speedY *= -1;
    }
}
