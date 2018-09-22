typedef struct {
    int current;
    int max_size;
    int *elements;
} MinStack;

/** initialize your data structure here. */
MinStack *minStackCreate(int maxSize) {
    MinStack *stack = (MinStack *)malloc(sizeof(MinStack));
    stack->current = 0;
    stack->max_size = maxSize;
    stack->elements = (int *)malloc(sizeof(int) * maxSize);
    return stack;
}

void minStackPush(MinStack *obj, int x) {
    if (obj->current > obj->max_size - 1) {
        return;
    }
    obj->elements[obj->current] = x;
    obj->current++;
}

void minStackPop(MinStack *obj) {
    if (obj->current == 0) {
        return;
    }
    obj->current--;
}

int minStackTop(MinStack *obj) {
    return obj->elements[obj->current - 1];
}

int minStackGetMin(MinStack *obj) {
    if (obj->current == 0) {
        return 0;
    }
    int min = obj->elements[0];
    for (int i = 0; i < obj->current; i++) {
        if (min > obj->elements[i]) {
            min = obj->elements[i];
        }
    }
    return min;
}

void minStackFree(MinStack *obj) {
    free(obj->elements);
    free(obj);
}