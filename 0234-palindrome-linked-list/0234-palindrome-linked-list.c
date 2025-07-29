/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    int size = 0, i = 0;
    struct ListNode* temp = head;

    while (temp != NULL) {
        size++ ;
        temp = temp->next;
    }

    int *arr = (int *)malloc(size * sizeof(int));

    temp = head;

    for (i = 0; i < size; i++) {
        arr[i] = temp->val;
        temp = temp->next;
    }

    temp = head;
    i = (size - 1);

    while (temp != NULL) {
        if (temp->val != arr[i]) {
            free(arr);
            return false;
        }
        temp = temp->next;
        i-- ;
    }

    free(arr);
    return true;
}