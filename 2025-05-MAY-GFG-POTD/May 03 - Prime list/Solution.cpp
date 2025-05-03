#include <bits/stdc++.h>
using namespace std;

const int MAX = 100010;
bool isPrime[MAX];

// Sieve of Eratosthenes
void sieve() {
    fill(isPrime, isPrime + MAX, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < MAX; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

struct Node {
    int val;
    Node* next;
    Node(int data) : val(data), next(nullptr) {}
};

int nearestPrime(int num) {
    if (isPrime[num]) return num;
    int left = num - 1;
    int right = num + 1;
    while (left >= 2 || right < MAX) {
        if (left >= 2 && isPrime[left]) return left;
        if (right < MAX && isPrime[right]) return right;
        left--;
        right++;
    }
    return 2;
}

Node* primeList(Node* head) {
    Node* curr = head;
    while (curr) {
        curr->val = nearestPrime(curr->val);
        curr = curr->next;
    }
    return head;
}