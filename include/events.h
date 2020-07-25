/*
 *  RedEmu - events.h
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

#ifndef REDEMU_EVENTS_H
#define REDEMU_EVENTS_H

#include <stdint.h>
#include "types.h"

typedef struct
{
    uint32_t type;
    void (*handler)(void);
    unsigned int id;
} event;

void initEvents(void);
void cleanupEvents(void);
void pollEvents(void);
unsigned int registerEvent(event *e);
BOOL unregisterEvent(unsigned int id);

#endif //REDEMU_EVENTS_H
