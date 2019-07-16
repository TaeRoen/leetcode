/*
 * @lc app=leetcode id=155 lang=c
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (35.85%)
 * Total Accepted:    286.5K
 * Total Submissions: 786.7K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * 
 * 
 * pop() -- Removes the element on top of the stack.
 * 
 * 
 * top() -- Get the top element.
 * 
 * 
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 */
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

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */

