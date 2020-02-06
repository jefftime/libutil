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
#include <stdarg.h>

int u_sprintf(char *str, char *fmt, ...) {
  char *start;
  va_list args;

  start = str;
  va_start(args, fmt);
  while (*fmt) {
    if (*fmt == '%') {
      fmt++;
      switch (*fmt) {
      case 'd': {
        int val;
        int n_positions, total;

        val = va_arg(args, int);
        if (val < 0) {
          *str++ = '-';
          val = -val;
        }
        n_positions = (int) (u_log(val) / u_log(10)) + 1;
        total = 0;
        do {
          int n;

          n = val;
          n /= (int) u_pow(10, n_positions - 1);
          n -= total;
          total += n;
          total *= 10;
          *str++ = (char) ('0' + (char) n);
        } while (--n_positions);
        fmt++;
        break;
      }
      default:
        *str++ = '%';
        *str++ = *fmt++;
        break;
      }
    } else {
      *str++ = *fmt++;
    }
  }
  va_end(args);
  *str++ = '\0';
  return (int) (str - start);
}
