/*
 *  RedEmu::GFX - GFX_init.c
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

#ifndef REDEMU_EXCEPTION_H
#define REDEMU_EXCEPTION_H

#define FATAL_ERROR(code) throw(code)

void throw(int code);

#endif //REDEMU_EXCEPTION_H
