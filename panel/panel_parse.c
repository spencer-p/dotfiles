#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include "config.h"

#define SPACESLEN 128
#define STATUSLEN 256

char spaces[128];
char status[256];

int write(char *str, int *i, const char *format, ...) {
    int index = *i;
    int num = 0;
    for (int r = 0; format[r] != '\0'; r++) {
        if (format[r] == '%') {
            num += (format[++r] != '%') ? 1 : 0;
        }
    }
    va_list args;
    if (num != 0) {
        va_start(args, num);
    }
    for (int r = 0; format[r] != '\0'; r++) {
        switch (format[r]) {
            case '%':
                if (format[++r] != '%') {
                    //NOTE ^^^ THE ++R
                    str[index++] = (char) va_arg(args, int);
                }
                break;
            default:
                str[index++] = format[r];
        }
    }
    *i = index;
    if (num != 0) {
        va_end(args);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    char c;
    while (1) {
        c = getchar();
        switch (c) {
            case 'S': {
                //s for status
                getchar();
                int i = 0;
                while ((c=getchar()) != '\n' && i < STATUSLEN-1) {
                    status[i++] = c;
                }
                status[i] = '\0';
                break;
            }
            case 'W': {
                int i = 0;
                do {
                    c = getchar();
                    switch (c) {
                        case 'L':
                            //no more info
                            //without this case the word Monocle breaks everything
                            do {
                                c = getchar();
                            } while (c != '\n' && c != ':');
                            break;
                        case 'O':
                        case 'F':
                        case 'U':
                            //"\f%c", ACTIVE_FG
                            if (ACTIVE_OVERLINE) {
                                write(spaces, &i, "\\u%c", ACTIVE_OVERLINE_COLOR);
                            }
                            write(spaces, &i, "\\f%c\\b%c ", ACTIVE_FG, ACTIVE_BG);
                            while ((c=getchar()) != ':') {
                                write(spaces, &i, "%c", c);
                            }
                            write(spaces, &i, " \\ur");
                            break;
                        case 'o':
                            write(spaces, &i, "\\f%c\\b%c ", OCCUPIED_FG, OCCUPIED_BG);
                            while ((c=getchar()) != ':') {
                                write(spaces, &i, "%c", c);
                            }
                            write(spaces, &i, " ");
                            break;
                        case 'f':
                            if (SHOW_EMPTY) {
                                write(spaces, &i, "\\f%c\\b%c ", EMPTY_FG, EMPTY_BG);
                                while ((c=getchar()) != ':') {
                                    write(spaces, &i, "%c", c);
                                }
                                write(spaces, &i, " ");
                            }
                            break;
                        case 'u':
                            if (URGENT_OVERLINE) {
                                write(spaces, &i, "\\u%c", URGENT_OVERLINE_COLOR);
                            }
                            write(spaces, &i, "\\f%c\\b%c ", URGENT_FG, URGENT_BG);
                            while ((c=getchar()) != ':') {
                                write(spaces, &i, "%c", c);
                            }
                            write(spaces, &i, " \\ur");
                            break;
                    }
                } while (c != '\n' && i < SPACESLEN-1);
                spaces[i] = '\0';
                //write(spaces, &i, "\0");
                break;
            }
        }
        printf("\\l%s%s\n", spaces, status);
        //just for a slight delay
        system("");
        fflush(stdout);
    }
}
