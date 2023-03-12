#include <stdio.h>
#define loop(i, a, b) for (int i = a; i < b; i++)
int main() {

    int n, m, i, j, k;
    scanf("%d %d", &n, &m);     // n processes with m kinds of resources
    int alloc[n][m];
    // allocation matrix
    loop(i, 0, n)
        loop(j, 0, m)
            scanf("%d", &alloc[i][j]);

    int avail[m];               // array of no of available resources of m types
    loop(i, 0, m)
        scanf("%d", &avail[i]);


    int f[n], answer[n], index = 0;
    loop(k, 0, n)
        f[k] = 0;
    int need[n][m];
    loop(i, 0, n)
        loop(j, 0, m)
            scanf("%d", &need[i][j]);
    int y = 0;
    loop(k, 0, n) {
        loop(i, 0, n) {
            // ith process not yet executed
            if (f[i] == 0)  {
                // flag 1 indicates process cannot be executed
                int flag = 0;
                loop(j, 0, m) {
                    // if needs cannot be fulfilled
                    if (need[i][j] > avail[j])  {
                        flag = 1;               // mark as unexecutable
                        break;
                    }
                }
                // if needs are fulfilled
                if (flag == 0)  {
                    answer[index++] = i;        // add process to safe sequence
                    loop(y, 0, m) {
                        avail[y] += alloc[i][y];    // take back what is allocated
                    }
                    f[i] = 1;       // ith process executed
                }
            }
        }
    }

    int flag = 1;
    loop(i, 0, n) {
        if (f[i] == 0) {
            flag = 0;
            printf("Unsafe");
            break;
        }
    }

    if (flag == 1) {
        // printf("Following is the SAFE Sequence\n");
        loop(i, 0, n - 1) {
            printf("P%d -> ", answer[i]);
        }
        printf(" P%d", answer[n - 1]);
    }
}
/*

5 3
0 1 0
1 0 2
1 3 1
0 0 1
4 2 3
3 5 2
1 1 0
1 2 3
3 1 1
0 0 1
3 2 2

Output: P0 -> P2 -> P3 -> P4 ->  P1

5 3
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
3 3 2
7 4 3
1 2 2
6 0 0
0 1 1
4 3 1

Output: P1 -> P3 -> P4 -> P0 ->  P2

*/