/*
 *  RedEmu - events.c
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

#include "events.h"
#include "exception.h"
#include <stdlib.h>
#include "SDL2/SDL.h"

int eventNum;
event *eventArray;
static int eventIdCounter = 1;

void initEvents(void)
{
    eventNum = 20; //set to 20 initially
    eventArray = calloc(eventNum, sizeof(event));

    int res;
    if ((res = SDL_Init(SDL_INIT_EVENTS)) != 0)
    {
        throw(res);
    }
}

void cleanupEvents(void)
{
    free(eventArray);
}

void pollEvents(void)
{
    SDL_Event sdlEvent;
    while(SDL_PollEvent(&sdlEvent))
    {
        for (int i = 0; i < eventNum; i++)
        {
            event e = eventArray[i];
            if (e.id && sdlEvent.type == e.type)
            {
                (*e.handler)();
            }
        }
    }
}

unsigned int registerEvent(event *e)
{
    int i;
    for (i = 0; i < eventNum; i++)
    {
        if (eventArray[i].id == 0)
            break;
    }
    if (i == eventNum)
    {
        eventArray = realloc(eventArray, (eventNum + 10) * sizeof(event));
        memset(&eventArray[eventNum], 0, 10 * sizeof(event));
        eventNum += 10;
    }
    eventArray[i] = *e;
    eventArray[i].id = eventIdCounter;
    return eventIdCounter++;
}

BOOL unregisterEvent(unsigned int id)
{
    for (int i = 0; i < eventNum; i++)
    {
        if (eventArray[i].id == id)
        {
            eventArray[i].id = 0;
            return TRUE;
        }
    }
    return FALSE;
}
