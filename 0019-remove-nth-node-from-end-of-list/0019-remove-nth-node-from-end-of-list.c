/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    int i = 0;
    struct ListNode* result;
    struct ListNode* start = (struct ListNode*)malloc(sizeof(struct ListNode));

    start->next = head;
    struct ListNode* slow = start;
    struct ListNode* fast = start;

    for (i = 0; i < n; i++) {
        fast = fast->next;
    }

    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    /* Incase head itself is the n'th node and is removed */
    result = start->next;

    free (start);

    return result;
}