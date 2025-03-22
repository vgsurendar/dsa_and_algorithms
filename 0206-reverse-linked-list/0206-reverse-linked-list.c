/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {

    struct ListNode* temp = head;
    struct ListNode *curr = head, *prev = NULL, *next = NULL;

    while (curr != NULL) {

        next = curr->next; // Save the next node
        curr->next = prev; // Flip the arrow (or) Reverse the list

        prev = curr; // Move prev node to current node
        curr = next; // Move current node to next node
    }

    return prev; // New head of reversed linkedlist 
                 // Last element of the original linked list
}