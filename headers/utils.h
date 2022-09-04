int GenerateRandomNumber(int, int);
bool RandomProbabilityManipulation(int);
void DrawCenteredText(char *, int, int, Color);
void DrawNumberOfCells(int, int, int, Color);

int GenerateRandomNumber(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}

bool RandomProbabilityManipulation(int percentage)
{
    int n;

    n = (rand() % 100) + 1;

    return n <= percentage;
}

void DrawCenteredText(char *text, int y, int fontSize, Color color)
{
    int x = (GetScreenWidth() - MeasureText(text, fontSize)) / 2;

    DrawText(text, x, y, fontSize, color);
}

void DrawNumberOfCells(int totalCells, int y, int fontSize, Color color)
{
    DrawCenteredText(TextFormat("Number of cells: %d", totalCells), y, fontSize, color);
}
