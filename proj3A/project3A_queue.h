#ifndef PROJECT3A_QUEUE_H
#define PROJECT3A_QUEUE_H
#define MAX_LENGTH 256
#define INITIAL_SIZE 8


typedef struct {
	char** array;    // Queue array - pointer to a pointer to a char data type
	int front;       // Queue front index, initially 0
	int rear;        // Queue rear index, initially 0
	int capacity;    // Queue capacity, initially 8
	int size;        // Queue array populated count, initially 0
} Queue;


void initialize(Queue* q);
void cleanup(Queue* q);
int isFull(Queue* q);
int isEmpty(Queue* q);
void resize(Queue* q);
void enqueue(Queue* q, char* value);
char* dequeue(Queue* q);
void printQueue(Queue* q);

#endif 