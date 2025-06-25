/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* new_node = NULL;
    struct ListNode* temp = dummy;
    int carry = 0, sum = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {

        sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
        
        new_node->val = sum % 10;
        new_node->next = NULL;

        temp->next = new_node;
        temp = temp->next;
    }

    return dummy->next;
}