/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* find_kth_node(struct ListNode* temp, int k) {
    while ((temp != NULL) && (k > 1)) {
        temp = temp->next;
        k--;
    }
    return temp;
}

void reverseList(struct ListNode* start, struct ListNode** end) {

    struct ListNode* stop = (*end)->next;
    struct ListNode* prev = NULL;
    struct ListNode* curr = start;
    struct ListNode* next = NULL;

    while (curr != stop) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *end = prev;

    return;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {

    struct ListNode* temp = head;
    struct ListNode* kthNode = NULL;
    struct ListNode* nextNode = NULL;
    struct ListNode* prevNode = NULL;

    while (temp != NULL) {

        kthNode = find_kth_node(temp, k);

        if (kthNode == NULL) {
            if (prevNode != NULL) {
                prevNode->next = temp;
            }
            break;
        }

        nextNode = kthNode->next;
        kthNode->next = NULL;

        reverseList(temp, &kthNode);

        if (head == temp) {
            head = kthNode;
        } else {
            prevNode->next = kthNode;
        }

        prevNode = temp;
        temp = nextNode;
    }
    return head;
}