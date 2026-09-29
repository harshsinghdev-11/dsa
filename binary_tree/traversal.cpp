#include <iostream>
#include <vector>
#include <queue>

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = right = nullptr;
    }
};

// l root right
void inOrder(Node* node , std::vector<int>&res){
    if(node==nullptr){
        return;
    }
    inOrder(node->left,res);
    res.push_back(node->data);
    inOrder(node->right,res);
    return;
}


// preorder -> root left right
// postorder -> left right root

//level order by recursion
void levelOrderRec(Node* node,std::vector<std::vector<int>>&res,int level){
    if(node==nullptr){
        return;
    }
    if(res.size()<=level){
        res.push_back({});
    }
    res[level].push_back(node->data);
    levelOrderRec(node->left,res,level+1);
    levelOrderRec(node->right,res,level+1);
}

std::vector<std::vector<int>> levelOrder(Node* node){
    std::queue<Node*>q;
    std::vector<std::vector<int>>ans;
    if(node == nullptr){
        return ans;
    }

    q.push(node);
    int curr_level = 0;
    while(!q.empty()){
        int len = q.size();
        ans.push_back({});
        for(int i=0;i<len;i++){
            Node* front_node = q.front();
            q.pop();
            ans[curr_level].push_back(front_node->data);

            if(node->left!=nullptr){
                q.push(node->left);
            }
            if(node->right!=nullptr){
                q.push(node->right);
            }
        }
        curr_level++;

    }
    return ans;
    
}

