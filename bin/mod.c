#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("%s [number] [mod]\n", argv[0]);
        return 1;
    }
    int num = atoi(argv[1]);
    int mod = atoi(argv[2]);
    printf("%d\n", num%mod);
    return 0;
}
