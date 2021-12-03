#include <climits>
class MinStack {
   public:
    /** initialize your data structure here. */
    MinStack() { array = new int[SHRT_MAX]; }

    void push(int x) {
        array[p++] = x;
        minVal = x < minVal ? x : minVal;
    }

    void pop() {
        p--;
        if (array[p] == minVal) findMin();
    }

    int top() { return array[p - 1]; }

    int getMin() { return minVal; }

   private:
    int minVal = INT_MAX;
    int* array;
    int p = 0;

    void findMin() {
        minVal = INT_MAX;
        for (int i = 0; i < p; i++)
            minVal = array[i] < minVal ? array[i] : minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
