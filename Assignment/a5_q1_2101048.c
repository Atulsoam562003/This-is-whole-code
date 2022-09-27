#include <stdio.h>
#include <stdlib.h>

struct QNode{
    int key;
    struct QNode* next;
};

struct Queue{
    struct QNode *front, *rear;
};

struct QNode* newNode(int k){
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

struct Queue* createQueue(){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue* q, int k){
    struct QNode* temp = newNode(k);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

void deQueue(struct Queue* q){
    if (q->front == NULL)
        return;
    struct QNode* temp = q->front;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

int isQueueSame(struct Queue *q1,struct Queue *q2){
    while(q1->front != NULL && q2->front != NULL){
        if(q1->front->key != q2->front->key) return 0;
        deQueue(q1),deQueue(q2);
    }
    return 1;
}
void printQ(struct Queue * q){
    struct Queue * temp = q;
    while(temp->front != NULL){
        printf("%d ",temp->front->key);
        deQueue(temp);
    }
    puts("");
}


int main(){
    
    struct Queue* q1 = createQueue();
    struct Queue* q2 = createQueue();
    
    enQueue(q1, 10);
    enQueue(q1, 20);
    enQueue(q1, 50);
    enQueue(q2, 20);
    enQueue(q2, 20);
    enQueue(q2, 50);
    
    printQ(q1);
    printQ(q2);  
    
    
    int is = isQueueSame(q1,q2);
    if(is) puts("They are same");
    else puts("They are not same");    
    
    return 0;
}
