/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
           if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;

        while (true) {
            // Check if k nodes exist
            ListNode* kth = prevGroupEnd;
            for (int i = 0; i < k; i++) {
                kth = kth->next;
                if (!kth) return dummy.next;
            }

            // Reverse k nodes
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* curr = groupStart;
            ListNode* prev = kth->next;

            for (int i = 0; i < k; i++) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // Connect with previous part
            prevGroupEnd->next = prev;
            prevGroupEnd = groupStart;
        }
        
    }
};