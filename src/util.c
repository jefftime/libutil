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

#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

void u_puts(char *s) {
  puts(s);
}

int u_sprintf(char *str, char *fmt, ...) {
  va_list args;

  va_start(args, fmt);
  while (*fmt) {
    if (*fmt == '%') {
      fmt++;
      switch (*fmt) {
      case 'd': {
        int val;
        unsigned int n_positions;
        unsigned long total;

        val = va_arg(args, int);
        n_positions = (unsigned int) (log(val) / log(10)) + 1;
        total = 0;
        printf("n_positions: %u\n", n_positions);
        do {
          unsigned long n;

          n = (unsigned long) val;
          n /= (unsigned long) pow(10, n_positions - 1);
          n -= total;
          total += n;
          total *= 10;
          *str++ = '0' + (char) n;
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
  return 0;
}
