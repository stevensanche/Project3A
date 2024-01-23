#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "project3A_queue.h"

void initialize(Queue* q) {
	q->capacity = INITIAL_SIZE;
	q->array = (char**)malloc(q->capacity * sizeof(char*));
	q->front = 0;
	q->rear = 0;
	q->size = 0;
}

void cleanup(Queue* q) {
    for (int j = 0; j < q->size; j++) {
        free(q->array[j]);
    }
    
    free(q->array);
    free(q);
}

int isFull(Queue* q) {
	return q->size >=  q->capacity;
}

int isEmpty(Queue* q) {
	return q->front == q->rear;
}

void resize(Queue* q) {
	 q->capacity = q->capacity * 2;
    char** new = malloc(q->capacity * sizeof(char*));
    int i;
    int j;
    if (q->front <= q->rear) {
        for (i = 0; i < q->rear; i++) {
            new[i] = q->array[i];
        }
    }
     else {
        for (i = q->front; i < q->capacity; i++) {
            new[i] = q->array[i];
        }

        for (j = 0; j < q->rear; j++) {
            new[i] = q->array[j];
            i++;
        }
    }

    for (int i = q->rear; i < q->capacity; i++) {
        new[i] = (char*)malloc(sizeof(char) * MAX_LENGTH);
    }

    if (q->rear < q->front) {
        for (int i = 0; i < q->front; i++) {
            new[i] = (char*)malloc(sizeof(char) * MAX_LENGTH);
        }
    }

    free(q->array);
    q->array = new;
}

void enqueue(Queue* q, char* value) {
	if (isFull(q)) {
        resize(q);
    }

    if (q->rear == q->capacity) {
        q->rear = 0;
    }

    q->array[q->rear] = malloc((strlen(value) + 1) * sizeof(char));
    strcpy(q->array[q->rear], value);  

    printf("Enqueued (%d): %s\n", q->rear, value);

    q->rear++;
    q->size++;
}

char* dequeue(Queue* q) {
	char* word = q->array[q->front];
    printf("Dequeued (%d): %s\n", q->front, word);
    if (q->front == q->capacity - 1) {
        q->front = 0;
    } else {
        q->front++;
    }
    q->size--;
    return word;
}

void printQueue(Queue *q) {
	printf("printing queue:\n");
	int index = q->front;
	for (int i = 0; i < q->size; i++) {
		printf("%d: %s\n", index, q->array[index]);
		index = (index + 1) % q->capacity;
	}
}