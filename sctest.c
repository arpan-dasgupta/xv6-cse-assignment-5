
#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    int pid[10];
    for (int i = 0; i < 10; i++) {
        pid[i] = fork();
        if (pid[i] < 0) {
            printf(1, "Fork error\n");
            exit();
        } else if (pid[i] == 0) {
            volatile int j = 0;
            int pp = getpid();
            for (j = 0; j < 100000000; j++) {
                if (j % 10000000 == 0)
                    printf(1, "%d %d\n", pp, j / 10000000);
                if (j == 5e7) {
                    set_priority((100 - pp), pp);
                }
                j++;
                --j;
            }
            exit();
        } else {
            // #ifdef PBS
            //             set_priority((100 - pid[i]), pid[i]);
            // #endif
        }
    }
    // sleep(5);
    for (int i = 0; i < 10; i++) {
        int x = wait();
        printf(1, "%d - \n", x);
    }
    exit();
}