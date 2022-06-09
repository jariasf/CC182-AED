#include <iostream>
#include <vector>
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
    void createTreeFromArray(vector<string> &A);
    int height();
    void inorder();
    void preorder();
    void postorder();
    int countNodes();
    int sumOfValues();

private:
    TreeNode* root;
    TreeNode* _createTreeFromArray(TreeNode* node, int pos, vector<string> &A);
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

void BinaryTree::createTreeFromArray(vector<string> &A){
    root = _createTreeFromArray(root, 0, A);    
}

TreeNode* BinaryTree::_createTreeFromArray(TreeNode* node, int pos, vector<string> &A){
    if(pos >= A.size() || A[pos] == "null") return nullptr;
    node = new TreeNode(stoi(A[pos]));
    node -> left = _createTreeFromArray(node -> left, 2 * pos + 1, A);
    node -> right = _createTreeFromArray(node -> right, 2 * pos + 2, A);  
    return node;
}

BinaryTree::~BinaryTree(){
    destroyTree(root);
}

void BinaryTree::destroyTree(TreeNode *node){
    if( node == nullptr) return;
    destroyTree(node -> left);
    destroyTree(node -> right);
    delete node;
    node = nullptr;
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
    cout<<endl;
}

void BinaryTree::_preorder(TreeNode* node){
    if( node == nullptr )
        return;
    cout<<node -> val <<" "; 
    _preorder(node -> left);
    _preorder(node -> right);
}

void BinaryTree::postorder(){
    _postorder(root);
}

void BinaryTree::_postorder(TreeNode* node){
    
}

int BinaryTree::countNodes(){
    return _countNodes(root);
}

int BinaryTree::_countNodes(TreeNode* node){
    if( node == nullptr )
        return 0;
    int nodos_left = _countNodes(node -> left);
    int nodos_right = _countNodes(node -> right);
    return 1 + nodos_left + nodos_right;
}

int BinaryTree::sumOfValues(){
    return _sumOfValues(root);
}

int BinaryTree::_sumOfValues(TreeNode* node){
    if( node == nullptr )
        return 0;
    int sum_left = _sumOfValues(node -> left);
    int sum_right = _sumOfValues(node -> right);
    return node -> val + sum_left + sum_right;
}

int main(){
    BinaryTree* tree = new BinaryTree();
    vector<string> A = {"5", "1", "-4", "12", "null", "34", "null"};
    tree -> createTreeFromArray(A);
    cout<<"Preorder traversal"<<endl;
    tree -> preorder();

    cout<<"\nNumber of nodes: "<<tree -> countNodes()<<endl;
    cout<<"Sum of values: "<<tree -> sumOfValues()<<endl;
    delete tree;
    return 0;
}
