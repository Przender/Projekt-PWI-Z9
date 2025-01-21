#include "raylib.h"
#include "structs.h"
#include "functions.h"
#include <stdio.h>
#include <stddef.h>

int main()
{
    InitAudioDevice(); 
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Pirackie Starcie");
    SetTargetFPS(60);

    PauseMenu *pauseMenu = InitPauseMenu();

    NewGame(pauseMenu);

    CloseAudioDevice();
}
