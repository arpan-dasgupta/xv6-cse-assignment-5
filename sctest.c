
#include "types.h"
#include "stat.h"
#include "user.h"
#include "procstat.h"

unsigned short lfsr = 0xACE1u;
unsigned bit;

unsigned rand() {
    bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
    return lfsr = (lfsr >> 1) | (bit << 15);
}
int plot[20][20] = {0};

int main(int argc, char *argv[]) {
    int pid[20];
    for (int i = 0; i < 15; i++) {
        pid[i] = fork();
        if (pid[i] < 0) {
            printf(1, "Fork error\n");
            exit();
        } else if (pid[i] == 0) {
            volatile int j = 0;
            int pp = getpid();
            for (j = 0; j < 10000000 * (i + 1); j++) {
                if (j % 10000000 == 0) {
                    printf(1, "\nPID- %d\t Part- %d", pp, j / 10000000);
#ifdef MLFQ
                    struct proc_stat *psp =
                        (struct proc_stat *)malloc(sizeof(struct proc_stat));
                    getpinfo(psp, pp);
                    printf(1, "\tCQ- %d\t RT- %d\t NR- %d", psp->current_queue,
                           psp->runtime, psp->num_run);
#endif
                    // printStatus();
                }
                if (j == 3e7) {
                    set_priority((100 - pp), pp);
                }
                j++;
                --j;
            }
            exit();
        }
    }
    // sleep(5);
    for (int i = 0; i < 15; i++) {
        int x = wait();
        printf(1, "\n%d Ended - \n", x);
    }
    exit();
}