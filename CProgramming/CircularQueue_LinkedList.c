#include <stdio.h>
#include <stdlib.h>

/*
	원형 큐 : 링크드리스트로 구현
*/

typedef struct _Node {
	int data;
	struct _Node * next;
}Node;

typedef struct _Queue {
	Node * front;
	Node * rear;
}Queue;

void InitQueue(Queue * q);
int IsEmpty(Queue * q);
void Enqueue(Queue * q, int data);
int Dequeue(Queue * q);

int main() {
	Queue  q1;
	InitQueue(&q1);
	printf("init queue \n");
	printf("is empty : %d \n", IsEmpty(&q1));

	Enqueue(&q1, 100);
	printf("enqueue data : %d \n", q1.rear->data);

	int data =  Dequeue(&q1);
	printf("dequeue: %d \n", data);

	return 0;
}

void InitQueue(Queue * q) {
	q->front = q->rear = NULL;
}

int IsEmpty(Queue * q) {
	if (q->front == NULL && q->rear == NULL)
		return 1;
	else
		return 0;
}

void Enqueue(Queue * q, int data) {
	Node * now = (Node *)malloc(sizeof(Node));
	now->data = data;
	now->next = NULL;

	if (IsEmpty(q))
		q->front = now;
	else
		q->rear->next = now;

	q->rear = now;
}

int Dequeue(Queue * q) {
	if (IsEmpty(q)) {
		printf("q is empty");
		return 0;
	}
	Node * node = q->front;
	int removData = node->data;

	q->front = node->next;
	free(node);
	return removData;
}