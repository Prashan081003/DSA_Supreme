// GFG :- Diagonal Traversal of Binary Tree

// Given a Binary Tree, print the diagonal traversal of the binary tree.

// Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
// If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree. 

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// A binary tree node
struct Node
{
    int data;
    Node* left, * right;
};
// This is method 1 using map data structure as an extra space for storing data : 
void solve(Node* root, int d, map<int, vector<int>>& mp) {
    if (root == NULL) return;
    
    // Traverse left subtree, increase diagonal level by 1
    solve(root->left, d + 1, mp);
    
    // Store the current node's value in the corresponding diagonal level
    mp[d].push_back(root->data); // Store root->data instead of root
    
    // Traverse right subtree, maintain the same diagonal level
    solve(root->right, d, mp);
}

vector<int> diagonal(Node* root) {
    map<int, vector<int>> mp;
    solve(root, 0, mp);
    
    vector<int> ans;
    
    // Iterate over the map to collect diagonal elements into ans
    for (auto& pair : mp) {
        for (auto value : pair.second) {
            ans.push_back(value);
        }
    }
    
    return ans;
}



//This is method 2 more optimised in storage 
vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if(root == NULL) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        while(temp != NULL){
            ans.push_back(temp->data);
            if(temp->left != NULL){
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }
    return ans;
}
