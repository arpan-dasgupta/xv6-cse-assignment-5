# Sheduling Algorithm Comparison

## Timings

- Timings obtained using time function for each scheduling algorithm.

### Small (10 processes ~ 10 secs)

- `MLFQ` - 2164 ticks
- `RR` (default) - 2160 ticks
- `PBS` - 2152 ticks
- `FCFS` - 2175 ticks

### Large (20 processes ~ > 120 seconds)

- `MLFQ` - 16510 ticks
- `RR` (default) - 16551 ticks
- `PBS` - 16401 ticks
- `FCFS` - 17183 ticks

## Analysis

- The timings are not significantly different as each of them has their own best case performance
- Round Robin performs specifically well in general case.
- FCFS may penalize IO bound processes and cause convoy effect hence .
- MLFQ performs worst in this case due to high rate of queue change
- PBS is not much different from FCFS as priority is not used in timing analysis. However PBS in general is very useful.
