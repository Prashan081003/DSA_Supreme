#include <stack>
#include <utility> // For std::pair
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st; // Stack to store pairs of (price, span)

    /**
     * Constructor for StockSpanner.
     * Initializes an empty stack.
     */
    StockSpanner() {
        // No initialization needed since the stack is empty by default
    }
    
    /**
     * Function to calculate the stock span for the given price.
     * @param price: The current price of the stock.
     * @return The stock span for the current price.
     */
    int next(int price) {
        int span = 1; // Initialize span for the current price

        // Calculate span for the current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second; // Add the span of the price on top of the stack
            st.pop(); // Remove the price from the stack
        }

        // Push the current price and its span onto the stack
        st.push({price, span});

        return span; // Return the calculated span
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
