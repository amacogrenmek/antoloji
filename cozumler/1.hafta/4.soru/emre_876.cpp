//
//  main.cpp
//  lc_876_Middle of the Linked List
//
//  Created by Emre Biyikli on 12/5/18.
//  Copyright © 2018 Emre Biyikli. All rights reserved.
//

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *lastNode = head;
        ListNode *middleNode = head;
        bool isEven = false;
        while (lastNode->next) {
            lastNode = lastNode->next;
            isEven = !isEven;
            if (isEven) middleNode = middleNode->next;
        }
        return middleNode;
    }
};

int main(int argc, const char * argv[]) {
    Solution sln;
    {
        ListNode* head = new ListNode(1);
        ListNode* lastNode = head;
        for (int i=2; i<=5; i++) {
            lastNode->next = new ListNode(i);
            lastNode = lastNode->next;
        }
        lastNode = head;
        while (lastNode->next) {
            cout << lastNode->val << " ";
            lastNode = lastNode->next;
        }
        cout << lastNode->val << endl;
        ListNode* middleNode = sln.middleNode(head);
        cout << middleNode->val << endl;
    }
    {
        ListNode* head = new ListNode(1);
        ListNode* lastNode = head;
        for (int i=2; i<=6; i++) {
            lastNode->next = new ListNode(i);
            lastNode = lastNode->next;
        }
        lastNode = head;
        while (lastNode->next) {
            cout << lastNode->val << " ";
            lastNode = lastNode->next;
        }
        cout << lastNode->val << endl;
        ListNode* middleNode = sln.middleNode(head);
        cout << middleNode->val << endl;
    }
    {
        ListNode* head = new ListNode(1);
        ListNode* lastNode = head;
        lastNode = head;
        while (lastNode->next) {
            cout << lastNode->val << " ";
            lastNode = lastNode->next;
        }
        cout << lastNode->val << endl;
        ListNode* middleNode = sln.middleNode(head);
        cout << middleNode->val << endl;
    }
    return 0;
}
