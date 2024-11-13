#include <iostream>
#include <cmath>

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    void addToTheLast(Node* node) {
        if (head == nullptr) {
            head = node;
            tail = head;
        } else {
            tail->next = node;
            tail = node;
        }
    }
};

// Helper function to get the length of a linked list
int getLength(Node* head) {
    int length = 0;
    while (head != nullptr) {
        length++;
        head = head->next;
    }
    return length;
}

// Helper function to move a pointer forward by k nodes
Node* moveForwardByK(Node* head, int k) {
    while (k > 0 && head != nullptr) {
        head = head->next;
        k--;
    }
    return head;
}

// Function to find intersection point in Y shaped Linked Lists
int intersectPoint(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    // Calculate the difference in lengths
    int diff = abs(len1 - len2);

    // Adjust the starting point of the longer list
    if (len1 > len2) {
        head1 = moveForwardByK(head1, diff);
    } else {
        head2 = moveForwardByK(head2, diff);
    }

    // Traverse both lists together to find the intersection point
    while (head1 != nullptr && head2 != nullptr) {
        if (head1 == head2) {
            return head1->data; // Intersection point found
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return -1; // No intersection found
}

int main() {
    // Driver code to create lists and find intersection
    LinkedList llist1, llist2, llist3;

    // Add nodes to the lists and find intersection as per requirement
    // Use intersectPoint(llist1.head, llist2.head) to find intersection point
    return 0;
}
