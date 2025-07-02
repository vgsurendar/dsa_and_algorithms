/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA,
                                     struct ListNode* headB) {

    struct ListNode* head1 = headA;
    struct ListNode* head2 = headB;
    int len1 = 0, len2 = 0, i = 0;

    /* Find the length of head1 */
    while (head1 != NULL) {
        len1++;
        head1 = head1->next;
    }

    /* Find the length of head2 */
    while (head2 != NULL) {
        len2++;
        head2 = head2->next;
    }

    /* If the length are not same, move the head with longer length in adjacent
     * with the head with shorter length */
    if (len1 != len2) {
        if (len2 > len1) {
            for (i = 0; i < (len2 - len1); i++) {
                headB = headB->next;
            }
        } else {
            for (i = 0; i < (len1 - len2); i++) {
                headA = headA->next;
            }
        }
    }

    /* Corner Case - If the length of both lists are 1 */
    if ((len1 == 1) && (len2 == 1)) {
        if (headA == headB) {
            return headA;
        }
    }

    /*Now the starting points of both heads are adjacent to each other, Start
     * traversing in parallel and find the intersection */
    while ((headA != NULL) && (headB != NULL)) {

        if (headA == headB) {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }

    /* Return NULL if no intersection is found */
    return NULL;
}