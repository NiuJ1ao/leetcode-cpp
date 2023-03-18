#include <string>
using namespace std;

/*
You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.
*/

struct Page {
    string url;
    Page* prev;
    Page* next;
    Page(string url): url(url), prev(nullptr), next(nullptr) {};
    Page(string url, Page* prev): url(url), prev(prev), next(nullptr) {};
    Page(string url, Page* prev, Page* next): url(url), prev(prev), next(next) {};
};

class BrowserHistory {
private:
    Page *curr;

public:
    BrowserHistory(string homepage) {
        curr = new Page(homepage);
    }
    
    void visit(string url) {
        Page *x = curr;
        curr -> next = new Page(url, x);
        curr = curr -> next;
    }
    
    string back(int steps) {
        while (curr->prev && steps-- > 0) {
            curr = curr -> prev;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while (curr->next && steps-- > 0) {
            curr = curr -> next;
        }
        return curr->url;
    }
};

// more elegant
class BrowserHistory {
private:
    string stack[5005];
    int curr = 0, top = 0;

public:
    BrowserHistory(string homepage) {
        stack[curr] = homepage; 
    }
    
    void visit(string url) {
        stack[top = ++curr] = url;
    }
    
    string back(int steps) {
        return stack[curr = max(0, curr-steps)];
    }
    
    string forward(int steps) {
        return stack[curr = min(top, curr+steps)];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */