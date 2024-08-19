class BrowserHistory {
public:
    stack<string> browserStack, fwdStack; 

    // Constructor initializes the browser with the homepage
    BrowserHistory(string homepage) {
        browserStack.push(homepage); 
    }
    
    // Visit a new URL and clear the forward history
    void visit(string url) {
        while (!fwdStack.empty()) {
            fwdStack.pop();
        }
        browserStack.push(url); 
    }
    
    // Go back by a certain number of steps
    string back(int steps) {
        while (steps--) {
            if (browserStack.size() > 1) {
                fwdStack.push(browserStack.top()); 
                browserStack.pop();
            } else {
                break;
            }
        }
        return browserStack.top(); 
    }
    
    // Move forward by a certain number of steps
    string forward(int steps) {
        while (steps--) {
            if (!fwdStack.empty()) {
                browserStack.push(fwdStack.top()); 
                fwdStack.pop();
            } else {
                break;
            }
        }
        // Return the current URL after moving forward
        return browserStack.top(); 
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
