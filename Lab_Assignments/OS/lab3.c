#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESS 100

typedef struct {
    char *name;
    int arrival;
    int cpuburst;
    int turnaround;
    int wait;
} Process;

Process processtable[MAX_PROCESS];
int current_time;
int cpuburstcopy[MAX_PROCESS];
int first;

void ReadProcessTable(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Error opening file\n");
        return;
    }

    int i = 0;
    while (fscanf(fp, "%ms %d %d", &processtable[i].name, &processtable[i].arrival, &processtable[i].cpuburst) == 3) {
        i++;
    }
    int num_of_processes = i;
    fclose(fp);
}


void PrintProcessTable(int num_of_processes) {
    for (int i = 0; i < num_of_processes; i++) {
        printf("%s %d %d\n", processtable[i].name, processtable[i].arrival, processtable[i].cpuburst);
    }
}

void FCFS() {
    current_time = 0;
    int i;
    for (i = 0; i < MAX_PROCESS; i++)
    {
        processtable[i].turnaround = processtable[i].cpuburst + processtable[i].wait;
        processtable[i].wait = current_time - processtable[i].arrival;
        current_time += processtable[i].cpuburst;
    }
}

void PrintStatistics(int num_of_processes) {
    for (int i = 0; i < num_of_processes; i++) {
        printf("%s %d %d\n", processtable[i].name, processtable[i].turnaround, processtable[i].wait);
    }
}

void RR(int quantum) {
    current_time = 0;
    int i, j;
    for (i = 0; i < MAX_PROCESS; i++) {
        if (cpuburstcopy[i] > 0) {
            first = i;
            break;
        }
    }

    for (i = first; i < MAX_PROCESS; i = (i + 1) % MAX_PROCESS) {
        if (cpuburstcopy[i] > 0) {
            if (cpuburstcopy[i] >  quantum) {
                cpuburstcopy[i] -= quantum;
                current_time += quantum;
            }
            else {
                current_time += cpuburstcopy[i];
                processtable[i].turnaround = current_time - processtable[i].arrival;
                processtable[i].wait = processtable[i].turnaround - processtable[i].cpuburst;
                cpuburstcopy[i] = 0;
            }
        }
    }
}

void SRBF() {
    current_time = 0;
    int i, j;
    for (i = 0; i < MAX_PROCESS; i++) {
        int min_burst = -1, min_burst_index = -1;
        for (j = 0; j < MAX_PROCESS; j++) {
            if (processtable[j].arrival <= current_time && processtable[j].cpuburst > 0 && (min_burst == -1 || processtable[j].cpuburst < min_burst)) {
                min_burst = processtable[j].cpuburst;
                min_burst_index = j;
            }
        }
        if (min_burst_index != -1) {
            processtable[min_burst_index].cpuburst--;
            current_time++;
            if (processtable[min_burst_index].cpuburst == 0) {
                processtable[min_burst_index].turnaround = current_time - processtable[min_burst_index].arrival;
                processtable[min_burst_index].wait = processtable[min_burst_index].turnaround - cpuburstcopy[min_burst_index];
            }
        }
    }
}
int main() {
    char *filename = "process1.txt";
    ReadProcessTable(filename);
    PrintProcessTable(MAX_PROCESS);

    // FCFS
    FCFS();
    printf("\nFCFS Results\n");
    PrintStatistics(MAX_PROCESS);

    // RR
    memcpy(cpuburstcopy, processtable, sizeof(processtable)); // Make a copy of processtable for RR
    RR(4);
    printf("\nRR Results\n");
    PrintStatistics(MAX_PROCESS);

    // SRBF
    SRBF();
    printf("\nSRBF Results\n");
    PrintStatistics(MAX_PROCESS);

    return 0;
}

