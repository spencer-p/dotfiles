/*
 * Trims the working directory
 * to however many diretories
 * you want. And some tildas
 * for home directories.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // 1 argument for the amount of directories to be shown
    // 1 argument of the current path. pipe pwd to to me please
    // 1 argument for your home directory
    if (argc != 4) {
        printf("error");
        return 1;
    }
    
    // If it's the home directory,
    // throw away all that garbage
    // and put in a tilda instead.
    int homelen = strlen(argv[3]); //for the length of our home directory. calling strlen 4 times is dumb
    if (strncmp(argv[2], argv[3], homelen) == 0) {
        argv[2][homelen-2] = '/';
        argv[2][homelen-1] = '~';
        argv[2] = &argv[2][homelen-2];
    }

    int directories = atoi(argv[1]);
    int i, count;
    // Starts at the end of the path.
    // Counts out amt of directories from argv[1]
    // OR if it runs out of directories
    //
    // Remembers where the third directory ended
    // sort of. some error checking later.
    for (i = strlen(argv[2]), count = 0; count < directories && i != 0; i--) {
        if (argv[2][i] == '/') {
            count++;
        }
        //if (i == 0) {
        //    break;
        //}
    }

    // Cuts off the /
    // for not top level directories
    if (i != 0) {
        i += 2;
    } 
    
    // Cuts off the slash for the home directory.
    // The slash was put in so as not to upset the for loop
    if (strncmp(&argv[2][i], "/~", 2) == 0) {
        i++;
    }

    // And now we've figured out where the important part of the path begins.
    printf("%s", &argv[2][i]);

    return 0;
}
