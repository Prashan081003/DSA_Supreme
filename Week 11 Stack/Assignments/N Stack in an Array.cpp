#include <iostream>
using namespace std;

class NStack {
private:
    int *arr, *top, *next; // Arrays to store stack elements, top indices, and next indices
    int n; // Number of stacks
    int freespot; // Index of the next free spot in the array
    int size; // Size of the array

public:
    /**
     * Constructor to initialize N stacks in a single array.
     * @param _n: Number of stacks.
     * @param _s: Size of the array.
     */
    NStack(int _n, int _s) : n(_n), size(_s) {
        arr = new int[size];
        top = new int[n];
        next = new int[size];

        // Initialize all stacks as empty
        for (int i = 0; i < n; i++) {
            top[i] = -1;
        }

        // Initialize all spaces as free and set up the next array
        for (int i = 0; i < size; i++) {
            next[i] = i + 1;
        }
        next[size - 1] = -1; // Last element of next array is -1 to indicate the end
        freespot = 0; // Initialize the first free spot
    }

    /**
     * Function to push an element onto a specific stack.
     * @param x: Element to be pushed.
     * @param sn: Stack number (1-based index).
     * @return True if the operation is successful, otherwise false.
     */
    bool push(int x, int sn) {
        if (freespot == -1) {
            // No free spot available
            return false;
        }

        int index = freespot; // Get the first free spot
        freespot = next[index]; // Update the freespot to the next available spot
        arr[index] = x; // Insert the element into the array
        next[index] = top[sn - 1]; // Update next to the previous top
        top[sn - 1] = index; // Update top to the new index

        return true;
    }

    /**
     * Function to pop an element from a specific stack.
     * @param sn: Stack number (1-based index).
     * @return The popped element if the stack is not empty, otherwise -1.
     */
    int pop(int sn) {
        if (top[sn - 1] == -1) {
            // Stack is empty
            return -1;
        }

        int index = top[sn - 1]; // Get the current top index
        top[sn - 1] = next[index]; // Update top to the next element
        int poppedElement = arr[index]; // Get the popped element
        next[index] = freespot; // Update next to the free spot
        freespot = index; // Update freespot to the current index

        return poppedElement;
    }

    /**
     * Destructor to free allocated memory.
     */
    ~NStack() {
        delete[] arr;
        delete[] top;
        delete[] next;
    }
};

int main() {
    NStack st(3, 6);
    cout << st.push(10, 1) << endl; // Push 10 onto stack 1
    cout << st.pop(1) << endl; // Pop from stack 1
    return 0;
}
