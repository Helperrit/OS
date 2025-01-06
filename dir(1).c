// PROGRAM FOR SYSTEM CALLS OF UNIX OPERATING SYSTEMS (OPENDIR, READDIR CLOSEDIR)
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    char dirName[100];
    struct dirent *entry;
    DIR *dir;

    printf("Enter directory name: ");
    scanf("%s", dirName);

    if ((dir = opendir(dirName)) == NULL) {
        printf("Directory does not exist.\n");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}
