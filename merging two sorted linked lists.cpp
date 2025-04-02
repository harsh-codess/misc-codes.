#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Function to merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0); // Dummy node to simplify the merging process
        ListNode* current = &dummy;
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        
        // Append the remaining nodes of list1 or list2
        current->next = (list1 != nullptr) ? list1 : list2;
        return dummy.next;
    }
};

// Helper function to print the linked list
void printList(ListNode* node) {
    while (node) {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << "nullptr" << endl;
}

int main(int, char *[]) {
    // Example usage
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    
    Solution solution; // Create an instance of Solution
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);
    
    // Print the merged list
    cout << "Merged List:" << endl;
    printList(mergedList);
    
    // Free the memory allocated for the merged list
    // (Add a function to delete the list if needed)
    
    return 0;
}