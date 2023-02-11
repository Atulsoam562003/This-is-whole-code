#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char name[3];
    int arrival;
    int cpuburst;
    int start;
    int finish;
    int temp;
    int turnaround;
    int wait;
} Process;

int maximum(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

void PrintStatistics(int record, char *names[], int wait[], int turnaround[]) {
    int wt = 0, tat = 0;
    for (int i = 0; i < record; i++) {
        wt = wt + wait[i];
        tat = tat + turnaround[i];
        printf("%s, WT: %d, TAT: %d", names[i], wait[i], turnaround[i]);
    }
    printf("\nAvg wait time: %f\n", (float)wt / (float)record);
    printf("Avg turnaround time: %f\n", (float)tat / (float)record);
}

void fcfsWait(int record, int burst[], int wait[]) {
    wait[0] = 0;
    for (int i = 1; i < record; i++) {
        wait[i] = wait[i - 1] + burst[i - 1];
    }
}

void fcfsTurnaround(int record, int burst[], int wait[], int turnaround[]) {
    for (int i = 0; i < record; i++)
        turnaround[i] = burst[i] + wait[i];
}

void fcfs(Process processes[], int record) {
    char *names[record];
    int burst[record];
    int wait[record], turnaround[record];
    for (int i = 0; i < record; i++) {
        names[i] = processes[i].name;
        burst[i] = processes[i].cpuburst;
    }
    fcfsWait(record, burst, wait);
    fcfsTurnaround(record, burst, wait, turnaround);
    PrintStatistics(record, names, wait, turnaround);
}

void srbfWaiting(Process processes[], int record, int wait[]) {
    int rt[record];
    for (int i = 0; i < record; i++)
        rt[i] = processes[i].cpuburst;

    int complete = 0, t = 0, minm = 10000;
    int shortest = 0, finish_time;
    bool check = false;
    while (complete != record) {
        for (int j = 0; j < record; j++) {
            if ((processes[j].arrival <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }
        if (check == false) {
            t++;
            continue;
        }
        rt[shortest]--;

        minm = rt[shortest];
        if (minm == 0) {
            minm = 10000;
        }
        if (rt[shortest] == 0) {
            complete++;
            check = false;

            finish_time = t + 1;
            wait[shortest] = finish_time - processes[shortest].cpuburst - processes[shortest].arrival;

            if (wait[shortest] < 0)
                wait[shortest] = 0;
        }
        t++;
    }
}

void srbfTurnAround(Process processes[], int record, int wait[], int turnaround[]) {
    for (int i = 0; i < record; i++)
        turnaround[i] = processes[i].cpuburst + wait[i];
}

void srbfAverage(Process processes[], int record) {
    int wait[record], turnaround[record];
    char *names[record];
    for (int i = 0; i < record; i++)
        names[i] = processes[i].name;

    srbfWaiting(processes, record, wait);
    srbfTurnAround(processes, record, wait, turnaround);
    PrintStatistics(record, names, wait, turnaround);
}

void PrintStatistics1(Process processes[], int count) {
    int wait = 0, turnaround = 0;
    printf("id      at     bt      ct       turnaround    wait\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d", processes[i].name, processes[i].arrival, processes[i].cpuburst, processes[i].finish, processes[i].turnaround, processes[i].wait);
        wait += processes[i].wait;
        turnaround += processes[i].turnaround;
    }
    printf("\nAvg wait time: %f", (float)wait / (float)count);
    printf("\nAvg turnaround time: %f", (float)turnaround / (float)count);
}

void sort(int *a, int *b, int n) {
    int k, j, key1, key2;
    for (int i = 0; i < n; i++) {
        j = i - 1;
        k = i - 1;
        key1 = a[i];
        key2 = b[i];
        while (j >= 0 && key1 < a[j]) {
            a[j + 1] = a[j];
            b[k + 1] = b[k];
            j--;
            k--;
        }
        a[j + 1] = key1;
        b[k + 1] = key2;
    }
}

void roundrobin(Process processes[], int no_of_processes) {

    int *at = (int *)malloc(no_of_processes * sizeof(int));
    int *bt = (int *)malloc(no_of_processes * sizeof(int));
    int *bt1 = (int *)malloc(no_of_processes * sizeof(int));
    int *ct = (int *)malloc(no_of_processes * sizeof(int));
    int index, tq, c, r = 0, f = 0;
    int rq[100][2];

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    for (int i = 0; i < no_of_processes; i++) {
        at[i] = processes[i].arrival;
        bt[i] = processes[i].cpuburst;
        bt1[i] = bt[i];
    }
    printf("\n");

    sort(at, bt, no_of_processes);

    for (int i = 0; i < no_of_processes; i++)
        bt1[i] = bt[i];

    for (int j = 0; j < no_of_processes; j++)
        printf("%d %d\n", at[j], bt[j]);
    printf("\n");

    if (bt[0] > tq) {
        c = at[0] + tq;
        bt[0] = bt[0] - tq;
        ct[0] = c;
        rq[r][0] = c;
        rq[r][1] = 0;
        r++;
    }
    else {
        c = at[0] + bt[0];
        ct[0] = c;
    }
    int i = 1;
    while (i < no_of_processes) {
        if (r != 0 && at[i] <= rq[f][0]) {
            if (bt[i] > tq) {
                c = c + tq;
                ct[i] = c;
                bt[i] = bt[i] - tq;
                rq[r][0] = c;
                rq[r][1] = i;
                r++;
            }
            else {
                c = c + bt[i];
                ct[i] = c;
            }
            i++;
        }
        else if (r == 0) {
            if (bt[i] > tq) {
                c = c + tq;
                bt[i] = bt[i] - tq;
                rq[r][0] = ct[i];
                rq[r][1] = i;
                r++;
            }
            else {
                c = c + bt[i];
                ct[i] = c;
            }
            i++;
        }
        else {
            index = rq[f][1];
            f++;
            if (bt[index] > tq) {
                c = c + tq;
                ct[index] = c;
                bt[index] = bt[index] - tq;
                rq[r][0] = ct[index];
                rq[r][1] = index;
                r++;
            }
            else {
                c = c + bt[index];
                ct[index] = c;
            }
        }
    }
    while (f < r) {
        index = rq[f][1];
        f++;
        if (bt[index] > tq) {
            c = c + tq;
            ct[index] = c;
            bt[index] = bt[index] - tq;
            rq[r][0] = ct[index];
            rq[r][1] = index;
            r++;
        }
        else {
            c = c + bt[index];
            ct[index] = c;
        }
    }

    int *turnaround = (int *)malloc(no_of_processes * sizeof(int));
    for (int i = 0; i < no_of_processes; i++) {
        processes[i].finish = ct[i];
        if ((ct[i] - at[i]) <= 0)
            turnaround[i] = 0;
        else
            turnaround[i] = ct[i] - at[i];

        processes[i].turnaround = turnaround[i];
        // turnaround[i]=maximum(0, ct[i]-at[i]);
    }

    int *wait = (int *)malloc(no_of_processes * sizeof(int));
    for (int i = 0; i < no_of_processes; i++) {
        if ((turnaround[i] - bt1[i]) <= 0)
            wait[i] = 0;
        else
            wait[i] = turnaround[i] - bt1[i];

        processes[i].wait = wait[i];
    }
    PrintStatistics1(processes, no_of_processes);
    printf("\n");
}

int main(int argc, char *argv[]) {
    char *str = argv[1];
    FILE *file = fopen(str, "r");
    if (!file) {
        printf("Error opening file");
        exit(0);
    }
    Process processes[10];
    int read = 0, record = 0;
    do {

        read = fscanf(file, "%5[^,],%d,%d", processes[record].name,&processes[record].arrival,&processes[record].cpuburst);

        if (read == 3)
            record++;
        else if (read != 3 && !feof(file)) {
            printf("Incompatible file format");
            return 1;
        }
        if  (ferror(file)) {
            printf("Error reading file");
            return 1;
        }

    } while (!feof(file));
    fclose(file);
    printf("%d records read\n", record);
    for (int i = 0; i < record; i++)
        printf("%s, %d, %d\n", processes[i].name, processes[i].arrival, processes[i].cpuburst);

    int var, quantum;
    printf("Ready\n");
    while (true) {

        printf("1. FCFS\n2. SRBF\n3. RR\n4. Exit\n>> ");
        scanf("%d", &var);
        switch (var) {
        case 1:
            fcfs(processes, record);
            break;
        case 2:
            srbfAverage(processes, record);
            break;
        case 3:
            roundrobin(processes, record);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid input");
            break;
        }
    }
    return 0;
}