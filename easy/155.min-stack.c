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
    
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    
}

void minStackPush(MinStack* obj, int x) {
    
}

void minStackPop(MinStack* obj) {
    
}

int minStackTop(MinStack* obj) {
    
}

int minStackGetMin(MinStack* obj) {
    
}

void minStackFree(MinStack* obj) {
    
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

