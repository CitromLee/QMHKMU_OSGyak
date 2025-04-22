#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define PARENT "./QMHKMU_parent.c"
#define CHILD "QMHKMU_child.c"

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork hiba");
        exit(1);
    } else if (pid == 0) {
        // Gyermek processz
        execl("./"CHILD,CHILD, NULL);
        perror("Execl hiba");
        exit(1);
    } else {
        // Szülő processz
        cwait(NULL); // Várakozás a gyermek befejeződésére
        printf("A gyermek processz befejeződött.\n");
    }
    return 0;
}