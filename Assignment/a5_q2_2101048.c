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
    int i = 0;
    while(temp->front != NULL){
        i++;
    printf("The %d person got the number: %d\n",i,temp->front->key);
        deQueue(temp);
    }
}


int main(){
    
    struct Queue* q1 = createQueue();
    
    enQueue(q1, 1);
    enQueue(q1, 2);
    enQueue(q1, 3);
    
    printQ(q1);
    
    return 0;
}
