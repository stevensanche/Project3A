#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project3A_queue.h"


int main(int argc, char* argv[]) {
	if (argc < 3) {
		printf("Please provide a file name and delimiter");
		exit(EXIT_FAILURE);
	}

	char *tokenizer;
	char* filename = argv[1];
	char* delimiter = argv[2];

	FILE* ifile = fopen(argv[1], "r");
	if (ifile == NULL) {
		printf("Could not open file %s\n", filename);
		fclose(ifile);
	}

	fseek(ifile, 0, SEEK_END);
	int size = ftell(ifile);
	fseek(ifile, 0, SEEK_SET);
	char* buffer = malloc(size * sizeof(char));
	fread(buffer, 1, size, ifile);

	int j = 0;
	tokenizer = strtok(buffer, delimiter);
	char* token[100];

	while (tokenizer != NULL) {
		token[j] = tokenizer;
		j++;
		tokenizer = strtok(NULL, delimiter);
	}

	Queue* q = (Queue*) malloc(sizeof(Queue));
	initialize(q);

	printf("=> First enqueuing pass\n");
    int i;
    for (i = 0; i < j; i++) {
        enqueue(q, token[i]);
    }

    printf("\n=> Dequeueing all elements\n");
    while (!isEmpty(q)) {
        dequeue(q);
    }

    printf("\n=> Second enqueuing pass\n");
    for (int z = 0; z < j; z++) {
        enqueue(q, token[z]);
    }

    printf("\n=> Printing queue\n");
    printQueue(q);

    printf("\n=> Calling Queue Cleanup\n");
    cleanup(q);
    printf("Cleaning up queue\n");

    free(buffer);

    fclose(ifile);
    return 0;

}








