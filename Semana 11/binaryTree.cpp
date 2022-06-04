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
    ~BinaryTree();
    void createTreeTest();
    void createTreeFromArray(int *A, int n);
    int height();
    void inorder();
    void preorder();
    void postorder();
    int countNodes();
    int sumOfValues();

private:
    TreeNode* root;
    TreeNode* _createTreeFromArray(TreeNode* node, int *A, int pos, int n);
    int _height(TreeNode* node); 
    void _preorder(TreeNode* node);
    void _inorder(TreeNode* node);
    void _postorder(TreeNode* node);
    int _countNodes(TreeNode* node);
    int _sumOfValues(TreeNode* node);
    void destroyTree(TreeNode* node);
};

BinaryTree::BinaryTree(){
    root = nullptr;
}

void BinaryTree::createTreeTest(){
    root = new TreeNode(2);
    root -> left = new TreeNode(12);
    root -> right = new TreeNode(16);
    root -> left -> left = new TreeNode(-123);
    root -> left -> right = new TreeNode(65);
}

BinaryTree::~BinaryTree(){
    destroyTree(root);
}

void BinaryTree::destroyTree(TreeNode *root){
    if( root == nullptr) return;
    destroyTree(root -> left);
    destroyTree(root -> right);
    delete root;
    root = nullptr;
}

int BinaryTree::height(){
    return _height(root);
}

int BinaryTree::_height(TreeNode* node){
    if( node == nullptr )
        return 0;
    int height_left = _height(node -> left);
    int height_right = _height(node -> right);
    return 1 + max(height_left, height_right);
    //return 1 + max(_height(node ->left), _height(node->right));
}

void BinaryTree::inorder(){
    _inorder(root);
}

void BinaryTree::_inorder(TreeNode* node){
    
}

void BinaryTree::preorder(){
    _preorder(root);
}

void BinaryTree::_preorder(TreeNode* node){
    
}

void BinaryTree::postorder(){
    _postorder(root);
}

void BinaryTree::_postorder(TreeNode* node){
    
}

int BinaryTree::countNodes(){
    return _countNodes(root);
}

int BinaryTree::_countNodes(TreeNode* root){
    
}

int BinaryTree::sumOfValues(){
    return _sumOfValues(root);
}

int BinaryTree::_sumOfValues(TreeNode* root){
    
}

int main(){
    
    return 0;
}
