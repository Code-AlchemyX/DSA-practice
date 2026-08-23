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

//! Better approach

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
        unordered_set<int> visited;
        vector<vector<int>> result;
        Node* curr = head;
        
        while(curr != nullptr){
            int complement = target - curr->data;
            
            if(visited.find(complement) != visited.end()){
                result.push_back({complement , curr->data});
            }
            
            visited.insert(curr->data);
            curr = curr->next;
        }
        
        // sort is applied acc to gfg's requirement.
        sort(result.begin() , result.end());
        return result;
    }
};

//! Optimal approach 

