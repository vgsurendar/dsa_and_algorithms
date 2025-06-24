/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    struct ListNode* temp = NULL;
    struct ListNode* res = NULL;

    /* To handle Corner case - Only one of the list is valid */
    if (list1 == NULL) {
        return list2;
    }

    /* To handle Corner case - Only one of the list is valid */
    if (list2 == NULL) {
        return list1;
    }

    /* Always have list1 as the smaller value holder for tracking purpose */
    if (list1->val > list2->val) {
        temp = list1;
        list1 = list2;
        list2 = temp;
    }

    /* Save result head as list1 as that is the starting point */
    res = list1;

    while (list1 != NULL && list2 != NULL) {

        /* Keep moving list1 head to next node while list1 val <= list2 val */
        while ((list1 != NULL) && (list1->val <= list2->val)) {
            temp = list1;
            list1 = list1->next;
        }

        /* temp holds the last small value pointed by list1
        So break chain and point temp->next as list2 as list2 holds the next
        smaller value. */
        temp->next = list2;

        /* Swap list1 & list2
        We should always have list1 as the smaller value holder */
        temp = list1;
        list1 = list2;
        list2 = temp;
    }

    return res;
}