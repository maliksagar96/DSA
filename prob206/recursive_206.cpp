/*
    This is element by element reversing of the linkedlists.
    0-10-20-30
    1) Top of the call stack will be with a 20. Then 20->next->next which was null is now 20. That means 30->next is 20. 20->next is null. 
    2) Look what do we got. 0->10->20->null and 30->20. So 2 nodes are pointing to 20. This is an intermediate state.
    3) Then 10->next->next was 30 initially. Now after the previous recursion gets resolved then 10->next = 20 still, but 10->next->next = 10 now. and 10->next is null now. 
    4) What do we have now. We have 0->10->null. 30->20->10. So again, since this is intermediate. We have 2 pointers pointing to 10. 
    5) Finally we have 30->20->10->0 as the last call stack is resolved. 
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* newHead = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;

        return newHead;

    }
};