#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Error al crear el proceso.\n");
        return 1;
    } else if (pid == 0) {
        for (int i = 10000; i >= 1; i--) {
            printf("Hijo: %d\n", i);
        }
    } else {
        for (int i = 1; i <= 10000; i++) {
            printf("Padre: %d\n", i);
        }
        wait(NULL);
    }
    return 0;
}
