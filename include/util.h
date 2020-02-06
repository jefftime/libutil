/* Copyright 2020, Jeffery Stager
 *
 * This file is part of libutil
 *
 * libutil is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libutil is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libutil.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef UTIL_H
#define UTIL_H

#include <stddef.h>             /* size_t */

/* The functions in util_core.c are to be supplied by the host environment. On
 * most platforms this will be libc, but in cases such as wasm, the functions
 * will be imported from JavaScript
 */

/* **************************************** */
/* util_core.c */
int u_puts(char *s);
void *u_memset(void *dst, int ch, size_t count);
double u_log(double x);
double u_pow(double x, double y);
/* **************************************** */

/* The functions in util_common.c are platform-agnostic */

/* **************************************** */
/* util_common.c */
int u_sprintf(char *str, char *fmt, ...);
/* **************************************** */

#endif
