/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/




class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        if (!head->next) {
            Node* newHead = new Node(head->val);
            if (head->random == head)
                newHead->random = newHead;
            return newHead;
        }

        unordered_map<Node*, Node*> mp;


        Node* temp = head;

        //
        Node* newHead = new Node(temp->val);
        mp[head] = newHead;

        Node* newTemp = newHead;
        temp = temp->next;

        while (temp) {
            
            Node* curr = new Node(temp->val);
            newTemp->next = curr;
            newTemp = curr;
            mp[temp] = newTemp;
            temp = temp->next;
        }

        temp = head;
        newTemp = newHead;

        while (temp) {
            newTemp->random = mp[temp->random];
            temp = temp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};