#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"
#include "proc.h"
#include "spinlock.h"

struct process {
    struct proc proc[NPROC];
#ifdef MLFQ
    struct proc_stat ps[NPROC];
#endif
    struct spinlock lock;
};

int main(int argc, char *argv[]) {
    struct process ptable = printStatus();
    acquire(&ptable.lock);
    struct proc *p;
    printf(1, "Create time\tRuntime\tState\tPriority\n");
    for (p = ptable.proc; p < &ptable.proc[NPROC]; p++) {
        if (p->state == RUNNING || p->state == RUNNABLE ||
            p->state == SLEEPING) {
            printf(1, "%d\t%d\t%d\t%d\n", p->ctime, p->rtime.p->state,
                   p->priority);
        }
    }
#ifdef MLFQ
    struct proc *p;
    struct proc_stat *pp;
    printf(1, "Pid\tRuntime\tNum run\tPriority\n");
    for (p = ptable.proc, pp = ptable.ps; p < &ptable.proc[NPROC]; p++, pp++) {
        if (p->state == RUNNING || p->state == RUNNABLE ||
            p->state == SLEEPING) {
            printf(1, "%d\t%d\t%d\t%d\n", pp->pid, (int)pp->runtime,
                   pp->num_run, pp->current_queue);
        }
    }
#endif
    release(&ptable.lock);
    exit();
}