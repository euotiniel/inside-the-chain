#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int *data;
	size_t size;
	size_t capacity;
} Vector;


void vector_inic(Vector *v) {
	v->data = NULL;
	v-> size = 0;
	v-> capacity = 0;
}


void vector_push(Vector *v, int x) {
	if (v->size == v->capacity) {
		size_t new_capacity;
		
		if (v->capacity == 0) {
			new_capacity = 4;
		} else {
			new_capacity = v->capacity * 2;
		}

		int *new_data = realloc(v->data, new_capacity * sizeof(int));

		if (new_data == NULL) {
			printf("Memory allocation faild\n");
			exit(1);
		}

		v->data = new_data;
		v->capacity = new_capacity;
	}

	v->data[v->size] = x;
	v->size++;
}

int vector_get(Vector * v, size_t index) {
	if (index >= v->size) {
		printf("Index out of bounds\n");
		exit(1);
	}

	return v->data[index];
}

int main () {
	return 0;
}
