
#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    printStatus();
    struct proc_stat *ps;
    getpinfo(ps);
    // getpinfo();
    exit();
}