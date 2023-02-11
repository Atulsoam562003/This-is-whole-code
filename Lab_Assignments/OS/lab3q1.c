#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Process
{
    char *name;
    int arrival;
    int cpuburst;
    int turnaround;
    int wait;
    int complete;
    int available;
};
int nop = 0;
struct Process processtable[100];
void clearProcessTable()
{
    int i = 0;
    for (i = 0; i < nop; i++)
    {
        processtable[i].arrival = 0;
        processtable[i].cpuburst = 0;
        processtable[i].name = 0;
        processtable[i].turnaround = 0;
        processtable[i].wait = 0;
        processtable[i].complete = 0;
        processtable[i].available = 0;
    }
}
void ReadProcessTable(char *filename)
{
    nop = 0;
    FILE *ptr = fopen(filename, "r");
    if (ptr == NULL)
        printf("Couldnt open file");
    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), ptr) != NULL)
    {

        char *token = strtok(line, " ");

        i = 0;
        while (token != NULL)
        {

            // processtable[nop]=(struct Process *)malloc(sizeof(struct Process));
            if (i == 0)
            {
                processtable[nop].name = malloc(2 * sizeof(char));
                strcpy(processtable[nop].name, token);
            }
            if (i == 1)
            {
                processtable[nop].arrival = atoi(token);
            }
            if (i == 2)
            {
                processtable[nop].cpuburst = atoi(token);
            }
            i++;
            token = strtok(NULL, " ");
        }
        nop++;
    }
    for (int i = 0; i < nop; i++)
    {
        processtable[i].available = 1;
    }
}

void FCFS(struct Process processtable[])
{
    for (int i = 0; i < nop; i++)
    {
        int min = processtable[i].arrival;
        for (int j = i + 1; j < nop; j++)
        {

            if (processtable[j].arrival < min)
            {
                struct Process p = processtable[j];
                processtable[j] = processtable[i];
                processtable[i] = p;
            }
        }
    }
    int ct = 0;
    int k = 0;
    int index = 0;
    // sort(processtable);
    //  for(int i=0;i<nop;i++)
    //  {
    //      printf("%d-%d scheduling process %s\n",ct,ct+processtable[i].cpuburst,processtable[i].name);
    //      ct=ct+processtable[i].cpuburst;
    //      processtable[i].complete=ct;

    // }
    while (k < nop)
    {
        if (processtable[index].arrival <= ct)
        {
            printf("%d-%d scheduling process %s\n", ct, ct + processtable[index].cpuburst, processtable[index].name);
            ct = ct + processtable[index].cpuburst;
            processtable[index].complete = ct;
            k++;
            index++;
        }
        else
            ct++;
    }
    for (int i = 0; i < nop; i++)
    {
        printf("turnaround time of %s is %d\n", processtable[i].name, processtable[i].complete - processtable[i].arrival);
        processtable[i].turnaround = processtable[i].complete - processtable[i].arrival;
    }
    for (int i = 0; i < nop; i++)
    {
        printf("wait time of %s is %d\n", processtable[i].name, processtable[i].turnaround - processtable[i].cpuburst);
        processtable[i].wait = processtable[i].turnaround - processtable[i].cpuburst;
    }
    float avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < nop; i++)
    {
        avg_tat = avg_tat + processtable[i].turnaround;
    }
    printf("avg turnaround %f\n", (float)avg_tat / nop);
    for (int i = 0; i < nop; i++)
    {
        avg_wt = avg_wt + processtable[i].wait;
    }
    printf("avg wait %f\n", (float)avg_wt / nop);
}
void SRTF(struct Process processtable[])
{
    // printf("hii");
    int ct = 0;
    int k = 0;
    int bt[nop];
    for (int i = 0; i < nop; i++)
    {
        bt[i] = processtable[i].cpuburst;
    }
    while (k < nop)
    {
        // printf("k is %d\n",k);
        int min = 100;
        int index = 0;
        int f = 0;
        for (int i = 0; i < nop; i++)
        {
            if (processtable[i].cpuburst < min && processtable[i].available == 1 && processtable[i].arrival <= ct)
            {
                min = processtable[i].cpuburst;
                index = i;
                f = 1;
            }
        }
        if (f == 1)
        {
            printf("%d-%d scheduling %s\n", ct, ct + 1, processtable[index].name);
            ct = ct + 1;
            processtable[index].cpuburst--;
            if (processtable[index].cpuburst == 0)
            {
                processtable[index].available = 0;
                k++;
                processtable[index].complete = ct;
            }
        }
        else
            ct++;
    }
    for (int i = 0; i < nop; i++)
    {
        processtable[i].cpuburst = bt[i];
    }
    for (int i = 0; i < nop; i++)
    {
        printf("turnaround time of %s is %d\n", processtable[i].name, processtable[i].complete - processtable[i].arrival);
        processtable[i].turnaround = processtable[i].complete - processtable[i].arrival;
    }
    for (int i = 0; i < nop; i++)
    {
        printf("wait time of %s is %d\n", processtable[i].name, processtable[i].turnaround - processtable[i].cpuburst);
        processtable[i].wait = processtable[i].turnaround - processtable[i].cpuburst;
    }
    float avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < nop; i++)
    {
        avg_tat = avg_tat + processtable[i].turnaround;
    }
    printf("avg turnaround %f\n", (float)avg_tat / nop);
    for (int i = 0; i < nop; i++)
    {
        avg_wt = avg_wt + processtable[i].wait;
    }
    printf("avg wait %f\n", (float)avg_wt / nop);
}

void RR(int tq, struct Process processtable[])
{
    for (int i = 0; i < nop; i++)
    {
        int min = processtable[i].arrival;
        for (int j = i + 1; j < nop; j++)
        {

            if (processtable[j].arrival < min)
            {
                struct Process p = processtable[j];
                processtable[j] = processtable[i];
                processtable[i] = p;
            }
        }
    }
    int bt[nop];
    for (int i = 0; i < nop; i++)
    {
        bt[i] = processtable[i].cpuburst;
    }
    int ct = 0;
    int k = 0;
    int index = 0;
    while (k < nop)
    {
        // printf("hii");
        // int f = 0;
        // printf("index is %d\n",index);
        if (processtable[index].arrival <= ct && processtable[index].available == 1)
        {
            // printf("case1\n");

            if (processtable[index].cpuburst > tq)
            {
                printf("%d-%d scheduling %s\n", ct, ct + tq, processtable[index].name);
                ct = ct + tq;
                processtable[index].cpuburst = processtable[index].cpuburst - tq;
            }
            else
            {
                printf("%d-%d scheduling %s\n", ct, ct + processtable[index].cpuburst, processtable[index].name);
                ct = ct + processtable[index].cpuburst;
                processtable[index].cpuburst = 0;
                processtable[index].available = 0;
                k++;
                processtable[index].complete = ct;
            }
            index = (index + 1) % nop;
        }
        else if (processtable[index].available == 0 && processtable[index].arrival <= ct)
        {
            // printf("case2\n");
            index = (index + 1) % nop;
        }
        else if (processtable[index].arrival > ct)
        {
            // printf("case3\n");
            // printf("hello\n");
            int ret = index;
            index = 0;
            int p = 0;
            while (p == 0)
            {
                //  printf("index is %d\n",index);
                //  printf("avaialability is %d\n",processtable[index].available);
                //  printf("current time is %d\n",ct);
                if (processtable[index].arrival <= ct && processtable[index].available == 1)
                {
                    // printf("yoooooooo\n");
                    if (processtable[index].cpuburst > tq)
                    {
                        printf("%d-%d scheduling %s\n", ct, ct + tq, processtable[index].name);
                        ct = ct + tq;
                        processtable[index].cpuburst = processtable[index].cpuburst - tq;
                        p = 1;
                        // break;
                        // index = (index + 1) % nop;
                    }
                    else
                    {
                        printf("%d-%d scheduling %s\n", ct, ct + processtable[index].cpuburst, processtable[index].name);
                        ct = ct + processtable[index].cpuburst;
                        processtable[index].cpuburst = 0;
                        processtable[index].available = 0;
                        k++;
                        processtable[index].complete = ct;
                        p = 1;
                        // break;
                        // index = (index + 1) % nop;
                    }
                }
                else if (processtable[index].available == 0 && processtable[index].arrival <= ct)
                {
                    // printf("nooooooo\n");
                    index = (index + 1) % nop;
                }
                else
                    ct++;
            }
            if (ret == index)
                index = ret + 1;
            else
                index = ret;
        }
        else
        {
            ct++;
            // printf("case4\n");
        }
    }
    for (int i = 0; i < nop; i++)
    {
        processtable[i].cpuburst = bt[i];
    }
    for (int i = 0; i < nop; i++)
    {
        printf("turnaround time of %s is %d\n", processtable[i].name, processtable[i].complete - processtable[i].arrival);
        processtable[i].turnaround = processtable[i].complete - processtable[i].arrival;
    }
    for (int i = 0; i < nop; i++)
    {
        printf("wait time of %s is %d\n", processtable[i].name, processtable[i].turnaround - processtable[i].cpuburst);
        processtable[i].wait = processtable[i].turnaround - processtable[i].cpuburst;
    }
    float avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < nop; i++)
    {
        avg_tat = avg_tat + processtable[i].turnaround;
    }
    printf("avg turnaround %f\n", (float)avg_tat / nop);
    for (int i = 0; i < nop; i++)
    {
        avg_wt = avg_wt + processtable[i].wait;
    }
    printf("avg wait %f\n", (float)avg_wt / nop);
}
int main(int argc, char const *argv[])
{

    // ReadProcessTable("process1.txt");
    //  printf("%d",nop);
    //  FCFS();
    //  SRTF();
    // RR(2);
    int a = 0;
    while (a != 4)
    {

        printf("1->FCFS\n");
        printf("2->RR\n");
        printf("3->SRTF\n");
        printf("4->exit\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
        {
            clearProcessTable();
            ReadProcessTable(argv[1]);

            FCFS(processtable);
            break;
        }

        case 2:
        {
            clearProcessTable();
            ReadProcessTable(argv[1]);
            int tq;
            printf("enter time quantum ");
            scanf("%d", &tq);
            RR(tq, processtable);
            break;
        }

        case 3:
        {
            clearProcessTable();
            ReadProcessTable(argv[1]);
            SRTF(processtable);
            break;
        }

        case 4:
        {
            break;
        }
        }
    }

    return 0;
}
