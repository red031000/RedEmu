/*
 *  RedEmu - main.c
 *  Copyright (C) 2020 red031000
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "types.h"
#include "events.h"
#include "GFX/GFX_init.h"
#include <stdio.h>

#define SDL_QUIT 0x100 //can't include SDL.h here, breaks main

BOOL running = TRUE;

static void quit(void);

int main() {
    int res;
    if ((res = GFX_Init()) != 0)
    {
        return res;
    }
    printf("Debug mode detected!\n");
    initEvents();
    {
        event e;
        e.type = SDL_QUIT;
        e.handler = quit;
        registerEvent(&e);
    }
    while (running)
    {
        pollEvents();
    }
    GFX_Cleanup();
    cleanupEvents();
    return 0;
}

static void quit(void)
{
    running = FALSE;
}
