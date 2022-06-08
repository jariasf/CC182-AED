#include <iostream>
using namespace std;

class TreeNode{
public:
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _key){
        key = _key;
        left = right = nullptr;
    }
};

class BST{
    public:
    BST();
    ~BST();
    bool search(int key);
    bool insert(int key);
 
    private:
    TreeNode* root;
    bool _search(TreeNode* node, int key);
    bool _insert(TreeNode* &node, int key);
    TreeNode* _insert2(TreeNode* node, int key);
    void destroyTree(TreeNode* node);
};

BST::BST(){
    root = nullptr;
}

BST::~BST(){
    destroyTree(root);
}

void BST::destroyTree(TreeNode *root){
    if( root == nullptr) return;
    destroyTree(root -> left);
    destroyTree(root -> right);
    delete root;
    root = nullptr;
}

bool BST::search(int key){
    return _search(root, key);
}

bool BST::_search(TreeNode* node, int key){
    if( node == nullptr ){
        return false;
    }else if( node -> key == key ){
        return true;
    }else if( node -> key > key ){
        return _search(node -> left, key);
    }
    return _search(node -> right, key);
}

bool BST::insert(int key){
    return _insert(root, key);
}

bool BST::_insert(TreeNode* &node, int key){

}

int main(){
    return 0;
}