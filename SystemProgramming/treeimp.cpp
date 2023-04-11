#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left, * right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class BST {
public:
    Node* root;
    BST() {
        root = NULL;
    }
    Node* insert(Node* pnode, int val) {
        if (pnode == NULL) {
            Node* newNode = new Node(val);
            pnode = newNode;
        }
        else if (pnode->data > val)
            pnode->left = insert(pnode->left, val);

        else
            pnode->right = insert(pnode->right, val);

        return pnode;
    }
    void insert(int val) {
        root = insert(root, val);
    }
    Node* search(Node* r, int key) {
        if (r == NULL)
            return NULL;
        else if (key == r->data)
            return r;
        else if (key < r->data)
            return search(r->left, key);
        else
            return search(r->right, key);

    }
    bool search(int key) {
        Node* r = search(root, key);
        if (r == NULL)
            return false;
        else
            return true;
    }
    Node* findMin(Node* r) {
        if (r == NULL)
            return NULL;
        else if (r->left == NULL)
            return r;
        else
           return findMin(r->left);
    }
    Node* findMax(Node* r) {
        if (r == NULL)
            return NULL;
        else if (r->right == NULL)
            return r;
        else
            return findMax(r->right);
    }
    int findMin() {
        Node* f = findMin(root);
        if (f == NULL)
            return NULL;
        else
            return f->data;
    }
    int findMax(){
        Node* f = findMax(root);
        if (f == NULL)
            return NULL;
        else
            return f->data;
    }
    Node* deleteNode(Node* r,int key) {
        if (r == NULL)
            return NULL;
        else if (key < r->data)
            r->left = deleteNode(r->left, key);
        else if (key > r->data)
            r->left = deleteNode(r->left, key);
        else {
            if (r->right == NULL && r->left == NULL)//leaf node
                r = NULL;
            else if (r->right == NULL && r->left != NULL) {
                r->data = r->left->data;
                delete r->left;
                r->left = NULL;
            }
            else if (r->right != NULL && r->left == NULL) {
                r->data = r->right->data;
                delete r->right;
                r->right = NULL;
            }
            else{
                Node* max = findMax(r->left);
                r->data = max->data;
                r->left=deleteNode(r->left,max->data);
            }
              
        }
        return r;
    }
    void deleteKey(int key) {
        Node* r=deleteNode(root, key);
        if (r == NULL)
            cout << "null";
        else
            cout << "the delete is done";
    }
    void preOreder(Node* r) {
        if (r == NULL)
            return;
        cout << r->data << "\n";
        preOreder(r->left);
        preOreder(r->right);
    }
    void inOrder(Node* r) {
        if (r == NULL)
            return;
        cout << "left: \n";
        preOreder(r->left);
        cout << r->data << "\n";
        cout << "right: \n";
        preOreder(r->right);
    }
    void postOrder(Node* r) {
        if (r == NULL)
            return;
        cout << "left: \n";
        preOreder(r->left);
        cout << "right: \n";
        preOreder(r->right);

        cout << r->data << "\n";
    }
};

void mainTreeImp() {
    //int val = 8;
    //Node* e =new Node(4);
    //BST r = BST();
    //r.insert(val);
    //r.insert(9);
    //r.insert(10);
    //r.insert(1);
    //r.insert(3);
    //r.inOrder(r.root);
    //if (r.search(3) == true)
    //    cout << "yes\n";
    //else
    //    cout << "no\n";
    //cout << r.findMax()<<"\t"<<r.findMin()<<"\n";
    //r.deleteKey(3);
    //r.inOrder(r.root);
}