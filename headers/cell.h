typedef struct
{
    int x, y;
    int radius;
    float speedX, speedY;
    Color color;
} Cell;

void CreateCell(Cell*, int, int, int);
void DrawCell(Cell);

void CreateCell(Cell cells[], int index, int x, int y)
{
    Cell cell;

    srand(time(NULL));

    cell.color = (Color){rand() % 256, rand() % 256, rand() % 256, 255};
    cell.radius = GenerateRandomNumber(20, 60);
    cell.speedX = GenerateRandomNumber(50, 100);
    cell.speedY = cell.speedX;
    cell.x = x;
    cell.y = y;

    cells[index] = cell;
}

void DrawCell(Cell cell)
{
    DrawCircle(cell.x, cell.y, (float)cell.radius, cell.color);
}

