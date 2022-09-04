void SecondsToHours(int, int*, int*);
void DrawElapsedTime(int, int, Color);

void DrawElapsedTime(int y, int fontSize, Color color)
{
    int seconds = GetTime();
    int hoursRes, remainingSecondsRes;

    if (seconds <= 60)
    {
        DrawCenteredText(TextFormat("Elapsed time: %d seconds", (int) GetTime()), y, fontSize, color);
    }
    else if (seconds > 60)
    {
        SecondsToHours(seconds, &hoursRes, &remainingSecondsRes);
        DrawCenteredText(TextFormat("Elapsed time: %d minutes %d seconds", hoursRes, remainingSecondsRes), y, fontSize, color);
    }
    
}

void SecondsToHours(int seconds, int* hoursRes, int* remainingSecondsRes)
{
    *hoursRes = seconds / 60;
    *remainingSecondsRes = seconds % 60;
}