bool UserClickedOnCell(Cell);
int CheckUserClickOnAllCells(Cell*, int);

bool UserClickedOnCell(Cell cell)
{
    return IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && 
           CheckCollisionPointCircle(GetMousePosition(), 
                                   (Vector2){cell.x, cell.y}, 
                                   cell.radius);
}

int CheckUserClickOnAllCells(Cell cells[], int maxCells)
{
    int i;

    for (i = 0; i < maxCells; i++)
    {
        if (UserClickedOnCell(cells[i]))
            return i;
    }

    return -1;
}