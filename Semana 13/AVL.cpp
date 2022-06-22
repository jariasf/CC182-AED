#include<iostream>
using namespace std;

class TreeNode{
public:
    int key;
    int height;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _key){
        key = _key;
        left = right = nullptr;
        height = 1;
    }
};

class AVL{
    public:
    AVL();
    ~AVL();
    bool insert(int key);
    bool deleteNode(int key);

    private:
    TreeNode* root;
    void destroyTree(TreeNode* node);
    bool insert(TreeNode* &node, int key);
    int getHeight(TreeNode* node);
    void balance(TreeNode* &node);
    int getBalance(TreeNode *node);
    void rightRotate(TreeNode* &node);
    void leftRotate(TreeNode* &node);
    bool deleteNode(TreeNode* &node, int key);
};

AVL::AVL(){
    root = nullptr;
}

AVL::~AVL(){
    destroyTree(root);
}

void AVL::destroyTree(TreeNode* node){
    if( node == nullptr)
        return;
    destroyTree(node -> left);
    destroyTree(node -> right);
    delete node;
}

int AVL::getHeight(TreeNode* node){
    if( node == nullptr )
        return 0;
    return node -> height;
}

bool AVL::insert(int key){
    return insert(root, key);
}

void AVL::rightRotate(TreeNode* &root){
    TreeNode* pleft = root -> left;
    root -> left = pleft ->right;
    pleft -> right = root;

    // Update heights
    root -> height = 1 + max(getHeight(root -> left), getHeight(root ->right));
    pleft -> height = 1 + max(getHeight(pleft -> left), getHeight(pleft ->right));

    root = pleft;    
}

void AVL::leftRotate(TreeNode* &root){
    // TODO: Implement this method
}

int AVL::getBalance(TreeNode* node){
    int left_height = getHeight(node -> left);
    int right_height = getHeight(node -> right);
    int balance_factor = left_height - right_height;
    return balance_factor;
}

void AVL::balance(TreeNode* &node){
    int balance_factor = getBalance(node);
    if( balance_factor > 1){
        // LL or LR
        if( getBalance(node -> left) >= 0 ){
            // LL: Left -> Left
            rightRotate(node);
        }else{
            // LR: Left -> Right
            leftRotate(node -> left);
            rightRotate(node);
        }
    }else if(balance_factor < -1){
        // RR o RL
        // TODO: Implement RR or RL rotations
        
    }
}

bool AVL::insert(TreeNode* &node, int key){
    if( node == nullptr ){
        node = new TreeNode(key);
        return true;
    }else if( node -> key == key ){
        return false;
    }else if( node -> key < key ){
        if( !insert(node -> right, key) )
            return false;
    }else{
        if( !insert(node -> left, key) )
            return false;        
    }

    // Update the height of the node
    node -> height = 1 + max(getHeight(node -> left), getHeight(node ->right));

    // Balance
    balance(node);
    return true;
}

bool AVL::deleteNode(int key){
    return deleteNode(root, key);
}

bool AVL::deleteNode(TreeNode* &node, int key){
    // TODO: Implement this method
    return false;
}

int main(){
    return 0;
}