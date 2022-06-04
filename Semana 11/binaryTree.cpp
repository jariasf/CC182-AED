#include <iostream>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val){
        val = _val;
        left = right = nullptr;
    }
};

class BinaryTree{
public:
    BinaryTree();
    void createTreeTest();
    int height();
private:
    TreeNode* root;
    int _height(TreeNode* node); 
};

void BinaryTree::createTreeTest(){
    root = new TreeNode(2);
    root -> left = new TreeNode(12);
    root -> right = new TreeNode(16);
    root -> left -> left = new TreeNode(-123);
    root -> left -> right = new TreeNode(65);
}

int BinaryTree::height(){
    return _height(root);
}

int BinaryTree::_height(TreeNode* node){
    
}

int main(){
    
    return 0;
}