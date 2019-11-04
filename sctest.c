
#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    int pid[10];
    for (int i = 0; i < 10; i++) {
        pid[i] = fork();
        if (pid[i] < 0) {
            printf(1, "Forkerror\n");
            exit();
        } else if (pid[i] == 0) {
        }
    }
    for (int i = 0; i < 10; i++) {
        wait();
    }
    exit();
}