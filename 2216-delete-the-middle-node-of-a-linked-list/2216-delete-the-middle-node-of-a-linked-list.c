/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {

    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = NULL;

    if (head == NULL || head->next == NULL) {
        free(head);
        return NULL;
    }

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    prev->next = slow->next;

    free(slow);

    return head;
}