#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include "config.h"

#define SPACESLEN 256
#define STATUSLEN 512

char spaces[SPACESLEN];
char status[STATUSLEN];

int write(char *str, int *i, const char *format, ...) {
    int index = *i;
    int num = 0;
    for (int r = 0; format[r] != '\0'; r++) {
        if (format[r] == '%') {
            r++;
            num += (format[r] == 'c' || format[r] == 's') ? 1 : 0;
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
                    switch(format[r]) {
                        case 'c':
                            str[index++] = (char) va_arg(args, int);
                            break;
                        char *insert; //no definitions inside switches is dumb
                        case 's':
                            insert = (char*) va_arg(args, char*);
                            for (int i = 0; insert[i] != '\0'; i++) {
                                str[index++] = insert[i];
                            }
                            break;
                    }
                }
                else {
                    str[index++] = format[r];
                }
                break;
            default:
                str[index++] = format[r];
                break;
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
	spaces[0] = '\0';
	status[0] = '\0';
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
						case 'T':
						case 'G':
                            //no more info
                            //without this case the word Monocle breaks everything
                            do {
                                c = getchar();
                            } while (c != '\n' && c != ':');
                            break;
                        case 'O':
                        case 'F':
                        case 'U':
                            write(spaces, &i, "%s ", ACTIVE);
                            while ((c=getchar()) != ':') {
                                spaces[i++] = c;
                            }
                            spaces[i++] = ' ';
                            break;
                        case 'o':
                            write(spaces, &i, "%s ", OCCUPIED);
                            while ((c=getchar()) != ':') {
                                spaces[i++] = c;
                            }
                            spaces[i++] = ' ';
                            break;
                        case 'f':
                            if (SHOW_EMPTY) {
                                write(spaces, &i, "%s ", EMPTY);
                                while ((c=getchar()) != ':') {
                                    spaces[i++] = c;
                                }
                                spaces[i++] = ' ';
                            }
                            break;
                        case 'u':
                            write(spaces, &i, "%s ", URGENT);
                            while ((c=getchar()) != ':') {
                                spaces[i++] = c;
                            }
                            spaces[i++] = ' ';
                            break;
						default: //If we don't recognize the block, dump it all
                            do {
                                c = getchar();
                            } while (c != '\n' && c != ':');
                            break;
                    }
                } while (c != '\n' && i < SPACESLEN-1);
                write(spaces, &i, "%%{F- B- -o -u}");
                spaces[i] = '\0';
                break;
            }
        }
		if (spaces[0] != '\0' && status[0] != '\0') {
			printf("%%{l}%s%s\n", spaces, status);
			system(""); //for a slight delay
			fflush(stdout);
		}
    }
}
