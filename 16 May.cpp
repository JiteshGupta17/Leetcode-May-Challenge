class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
    
        ListNode* posi= head;
        
        ListNode* oddHead = new ListNode(0);
        ListNode* odd = oddHead;
        
        ListNode* evenHead = new ListNode(0);
        ListNode* even = evenHead;
        
        while(posi && posi->next)
        {
            odd->next = posi;
            odd = odd->next;
            
            posi = posi->next;
            
            even->next = posi;
            even = even->next;
            
            posi = posi->next;
        }
        
        // Important step
        even->next = NULL;
        
        // when odd number of nodes
        if(posi){
            odd->next = posi;
            odd = odd->next;
        }
        
        odd->next = evenHead->next;
        
        return oddHead->next;
    }
};
