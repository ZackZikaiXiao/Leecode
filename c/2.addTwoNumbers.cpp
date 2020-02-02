#include<iostream>
#include<stdio.h>
using namespace std;
// Definition for singly-linked list.
//example:(2 -> 4 -> 3) + (5 -> 6 -> 4 -> 9)
//pay attention to example:5  5
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode *start = new ListNode(0);       //init a null list
        struct ListNode *ptr = start;
        int carry = 0;                    //carry-out flag
        while(l1 != NULL || l2 != NULL || carry){      //either l1 or l2 dont't go over

            if(l1 == NULL && l2 != NULL){
                ptr->val = (l2->val + carry)%10;
                carry = (l2->val + carry)>=10? 1 : 0;
                ptr->next = (l2->next || carry)?new ListNode(0):NULL;
                ptr = ptr->next;
                l2 = l2->next;
            }
            else if(l1 != NULL && l2 == NULL){
                ptr->val = (l1->val + carry)%10;
                carry = (l1->val + carry)>=10? 1 : 0;
                ptr->next = (l1->next || carry)?new ListNode(0):NULL;
                ptr = ptr->next;
                l1 = l1->next;
            }
            else if(l1 != NULL && l2 != NULL){
                ptr->val = (l1->val + l2->val + carry)%10;
                carry = (l1->val + l2->val + carry)>=10? 1 : 0;
                ptr->next = (l1->next != NULL || l2->next != NULL || carry)?new ListNode(0):NULL;
                ptr = ptr->next;
                l1 = l1->next;
                l2 = l2->next;
                }
            else{ptr->val = carry;return start;}
            }

        return start;
        }
};

int main(){
    struct ListNode ls1(2);
    struct ListNode ls2(4);
    struct ListNode ls3(3);
    struct ListNode ls4(5);
    struct ListNode ls5(6);
    struct ListNode ls6(4);
    struct ListNode ls7(9);
    ls1.next = &ls2;
    ls2.next = &ls3;
    ls4.next = &ls5;
    ls5.next = &ls6;
    ls6.next = &ls7;


    ListNode *out;
    Solution obj;
    out = obj.addTwoNumbers(&ls1, &ls4);

    //test
    while(out != NULL){
        cout<<out->val;
        out = out->next;
    }
    return 0;
}