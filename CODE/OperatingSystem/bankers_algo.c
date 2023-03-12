#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,m;
    printf("please enter the no. of procedures and instances respectively : ");
    scanf("%d%d",&n,&m);
    int lockidea[n];
    for(int i=0;i<n;i++) lockidea[i]=1;

    int p_table[n][m];
    int pr_table[n][m];
    int max_resource[m];
    int avl_resource[m];

    // enter the max resource and make avl resource 0
    for(int i=0;i<m;i++) {
        int c=i;
        printf("\nenter max resource no.%d: ",++c);
        scanf("%d",&max_resource[i]);
        avl_resource[i]=0;
    }



    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {  // allocated resource table
            int k = j;
            printf("\nenter procedure %d allocated resource no. %d: ",i,++k );
            scanf("%d",&p_table[i][j]);
            avl_resource[j]+=p_table[i][j];
        }
    }
    for(int j=0;j<m;j++)
        avl_resource[j]=max_resource[j]-avl_resource[j];  //calculating resource available


     for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {  // requested resource table
            int k=j;
            printf("\nenter procedure %d requested resource no. %d: ",i,++k );
            scanf("%d",&pr_table[i][j]);
        }
    }
    int subchanga = n;
    while (subchanga) {              // runs the loop n time so that every one is consumed
        subchanga--;
        for(int i=0;i<n;i++){
        int entry=1;
        for(int a=0;a<n;a++){
            if(pr_table[i][a]==-1)
            entry=0;
        }
        if(entry) {
         int count = 0;
         for(int j=0;j<m;j++) {
            if(pr_table[i][j] <= avl_resource[j]) // checks if requested resource is less than max resource
            count++;
         }
         if(count==m) {
         for(int j=0;j<m;j++){
            avl_resource[j]+=p_table[i][j];          // completes the process and add req resources
            pr_table[i][j]=-1;
         }
         printf("procedure P%d will be completed ",i);
         lockidea[i] = 0;
         printf("\n");
         }

        }

        }
    }
        int deadlock = 1;
        for(int j=0;j<n;j++) {
            if(pr_table[j][0]!=-1) {
                deadlock=0;
                printf("DEADLOCK EXISTS");
                printf("\nthe road bock are the procedures ");
                for(int c=0;c<n;c++) {
                    if(lockidea[c])
                    printf(" P%d ",c);
                }
                exit(0);
            }
        }
        if(deadlock)
            printf("no deadlock occurs");
}