#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    
    int c;
    bool repeat = false;

    while ((c = getopt(argc, argv, "r")) != -1) {
        switch (c) {
            case 'r':
                repeat = true;
                break;
        }
    }

    while (1) {

        int i = 0;
        c = getchar();
        while (c != '\n') {
            i++;
            c = getchar();
        }
        printf("%d\n", i);

        if (!repeat) {
            break;
        }
    }

    return 0;
}
