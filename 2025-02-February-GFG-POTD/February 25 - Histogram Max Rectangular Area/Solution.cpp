#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
    static int getMaxArea(std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> leftSmall(n);
        std::vector<int> rightSmall(n);
        std::stack<int> stack;

        // Find the first smaller bar on the left for each bar
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && arr[stack.top()] >= arr[i]) {
                stack.pop();
            }
            leftSmall[i] = stack.empty() ? -1 : stack.top();
            stack.push(i);
        }

        stack = std::stack<int>(); // Clear the stack for reuse

        // Find the first smaller bar on the right for each bar
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.empty() && arr[stack.top()] >= arr[i]) {
                stack.pop();
            }
            rightSmall[i] = stack.empty() ? n : stack.top();
            stack.push(i);
        }

        // Calculate the maximum area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = rightSmall[i] - leftSmall[i] - 1;
            int area = arr[i] * width;
            maxArea = std::max(maxArea, area);
        }

        return maxArea;
    }
};

int main() {
    int t;
    std::cin >> t;

    while (t-- > 0) {
        int n;
        std::cin >> n;
        std::vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }

        Solution obj;
        int res = obj.getMaxArea(arr);

        std::cout << res << std::endl;
        std::cout << "~" << std::endl;
    }

    return 0;
}
