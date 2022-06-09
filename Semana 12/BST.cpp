#include <iostream>
#include <queue>
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
    //BST(function<int(T,T)> compare);
    ~BST();
    bool search(int key);
    bool insert(int key);
    void inorder();
    void preorder();
    void postorder();
    bool deleteNode(int key);
    TreeNode* inorderSuccessor(TreeNode* node);
    void levelOrderTraversal();

    private:
    TreeNode* root;
    //function<int(T,T)> compare;
    bool search(TreeNode* node, int key);
    bool insert(TreeNode* &node, int key);
    void inorder(TreeNode* node);
    bool deleteNode(TreeNode* &node, int key);
    TreeNode* successor(TreeNode* node);
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
    return search(root, key);
}

bool BST::search(TreeNode* node, int key){
    if( node == nullptr ){
        return false;
    }else if( node -> key == key ){
        return true;
    }else if( node -> key > key ){
        return search(node -> left, key);
    }
    return search(node -> right, key);
}

bool BST::insert(int key){
    return insert(root, key);
}

bool BST::insert(TreeNode* &node, int key){
    if( node == nullptr ){
        node = new TreeNode(key);
        return true;
    }
    if( key == root -> key ){
        return false;
    }else if( key < node -> key ){
        return insert(node -> left, key);
    }
    return insert(node -> right, key);
}

void BST::inorder(){
    inorder(root);
    cout<<endl;
}

void BST::inorder(TreeNode* node){
    if( node == nullptr )
        return ;
    inorder(node -> left);
    //process(node -> key);
    cout<<node -> key<<" ";
    inorder(node -> right);
}

bool BST::deleteNode(int key){
    return deleteNode(root, key);
}

TreeNode* BST::successor(TreeNode* node){
    TreeNode* current = node -> right;
    while( current && current -> left ){
        current = current -> left;
    }
    return current;
}

bool BST::deleteNode(TreeNode* &node, int key){
    if( node ==nullptr ){
        return false;
    }else if( node -> key > key){
        return deleteNode(node -> left, key);
    }else if( node -> key < key ){
        return deleteNode(node -> right, key);
    }else{
        // Case 1: Leaf
        if( node -> left == nullptr && node -> right == nullptr){
            delete node;
            node = nullptr;
            return true;
        }else if( node -> left == nullptr ){
            // Case 2: Only right child
            TreeNode* tmp = node;
            node = node -> right;
            delete tmp;
            return true;
        }else if( node -> right == nullptr){
            // Case 2: Only left child
            TreeNode* tmp = node;
            node = node -> left;
            delete tmp;
            return true;
        }
        // Case 3: Two children
        TreeNode* next = successor(node);
        node -> key = next -> key;
        return deleteNode(root -> right, next -> key);
    }
}

void BST::levelOrderTraversal(){
    queue<TreeNode*> Q;
    Q.push(root);
    while(!Q.empty()){
        TreeNode* current = Q.front(); Q.pop();
        cout<<current -> key<<" ";
        if( current -> left ){
            Q.push(current -> left);
        }
        if( current -> right){
            Q.push(current -> right);
        }
    }
    cout<<endl;
}

int main(){
    BST *tree = new BST();
    int n = 6;
    int a[6] = {5,10,1,14,-1,6};
    for(int i = 0 ; i < 6 ; ++i ){
        tree -> insert(a[i]);
    }
    cout<<"Level order traversal"<<endl;
    tree -> levelOrderTraversal();
    cout<<"\nInorder traversal"<<endl;
    tree -> inorder();
    tree -> deleteNode(5);
    tree -> deleteNode(-1);
    tree -> deleteNode(10);
    tree -> inorder();    
    delete tree;
    return 0;
}
