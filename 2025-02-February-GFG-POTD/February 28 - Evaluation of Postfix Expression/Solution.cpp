#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    int evaluate(vector<string>& arr) {
        stack<int> stack;
        
        for (string& token : arr) {
            if (isOperator(token)) {
                int b = stack.top(); stack.pop(); // Second operand
                int a = stack.top(); stack.pop(); // First operand
                stack.push(applyOperation(a, b, token));
            } else {
                stack.push(stoi(token)); // Push operand to stack
            }
        }
        return stack.top(); // Final result
    }
    
private:
    bool isOperator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
    
    int applyOperation(int a, int b, const string& op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") return a / b; // Integer division rounds toward zero
        throw invalid_argument("Invalid operator: " + op);
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<string> arr;
        string token;
        while (ss >> token) {
            arr.push_back(token);
        }
        Solution solution;
        cout << solution.evaluate(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
