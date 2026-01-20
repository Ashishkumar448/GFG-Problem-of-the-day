#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    string document;
    stack<char> redoStack;

public:
    void append(char x) {
        document.push_back(x);
        while (!redoStack.empty())
            redoStack.pop(); // clear redo history
    }

    void undo() {
        if (!document.empty()) {
            char removed = document.back();
            document.pop_back();
            redoStack.push(removed);
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            document.push_back(redoStack.top());
            redoStack.pop();
        }
    }

    string read() {
        return document;
    }
};
