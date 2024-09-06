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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mp;

        for(auto it: nums)
        mp[it]++;

        bool f=0,h=0;
        ListNode* temp = new ListNode();
        temp->next=head;

        ListNode* start= new ListNode();
        // start=NULL;

        ListNode* dummy= new ListNode();

        while(temp->next!=NULL){
            int v= temp->next->val;
            if(mp.count(v)){
                if(f!=0){
                        dummy->next=dummy->next->next;
                }
            }
            else{
                if(f==0){
                    start=temp->next;
                    dummy=start;
                    f=1;
                     temp->next=temp->next->next;
                     continue;
                }
               dummy->next=temp->next;
               dummy=dummy->next;
               if(h==0){
                start->next=dummy;
                h=1;
               }
            }
            temp->next=temp->next->next;
        }

    return start;
    }
};