//! Brute force

/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
}; */

class Solution {
  public:
    vector<vector<int>> givenSumPairs(Node* head, int target) {
        Node* temp1 = head;
        vector<vector<int>> result;
        
        while(temp1 != nullptr){
            Node* temp2 = temp1->next;
            
            while(temp2 != nullptr){
                if(temp1->data + temp2->data == target){
                    result.push_back({temp1->data , temp2->data});
                } 
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        
        return result;
    }
};


//! Optimal approach 

