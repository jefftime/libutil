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

#include "util.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

/* The functions in util_core.c are to be supplied by the host environment */

int u_puts(char *s) {
  return puts(s);
}

void *u_memset(void *dst, int ch, size_t count) {
  return memset(dst, ch, count);
}

double u_log(double x) {
  return log(x);
}

double u_pow(double x, double y) {
  return pow(x, y);
}
