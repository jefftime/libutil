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
#include <stdarg.h>             /* va_list, va_start, va_end */
#include <stddef.h>             /* size_t */

/* stdio */
int puts(const char *s);
int vprintf(const char *format, va_list args);
int fgetc(FILE *stream);

/* string */
void *memset(void *s, int c, size_t n);

/* math */
double log(double x);
double pow(double x, double y);

/* The functions in util_core.c are to be supplied by the host environment */

int u_puts(char *s) {
  return puts(s);
}

int u_printf(const char *format, ...) {
  int result;
  va_list args;

  va_start(args, format);
  result = vprintf(format, args);
  va_end(args);
  return result;
}

int u_fgetc(FILE *stream) {
  return fgetc(stream);
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
