// #include <iostream>

// using namespace std;

// // Định nghĩa một nút trong cây nhị phân tìm kiếm
// struct Node {
//     int data;
//     Node* left;
//     Node* right;
//     Node(int value) : data(value), left(nullptr), right(nullptr) {}
// };

// // Hàm chèn một phần tử vào cây nhị phân tìm kiếm
// Node* insert(Node* root, int value) {
//     if (root == nullptr) {
//         return new Node(value);
//     }

//     if (value < root->data) {
//         root->left = insert(root->left, value);
//     } else if (value >= root->data) {
//         root->right = insert(root->right, value);
//     }

//     return root;
// }

// // Hàm tính bậc của cây nhị phân tìm kiếm
// int calculateHeight(Node* root) {
//     if (root == nullptr) {
//         return -1;
//     }

//     int leftHeight = calculateHeight(root->left);
//     int rightHeight = calculateHeight(root->right);

//     return max(leftHeight, rightHeight) + 1;
// }

// int main() {
//     int n;
//     cin >> n;

//     Node* root = nullptr;
//     int value;
//     for (int i = 0; i < n; ++i) {
//         cin >> value;
//         root = insert(root, value);
//     }

//     int height = calculateHeight(root);
//     cout<< height << endl;

//     return 0;
// } 

#include<iostream>


struct Node{
    int data;
    Node* left;
    Node * right;
    Node(int value): data(value),left(nullptr),right(nullptr){}
};

Node* insert(Node*root,int value){
    if(root == nullptr){
        return new Node(value);
    }

    if(value < root->data)
        root->left = insert(root->left,value);
    else root->right = insert(root->right,value);
    return root;
}

int countLevel(Node* root){
    if(root == nullptr)
        return -1;
    
    int heightleft = countLevel(root->left);
    int heightright = countLevel(root->right);

    return std::max(heightleft,heightright) + 1;
}

bool isAVL(Node*root){
    int heightleft = countLevel(root->left);
    int heightright = countLevel(root->right);
    if (abs(heightleft - heightright ) > 1)
        return false;
    return true;
}

Node* turnRight(Node*root){
    Node* b = root->left;
    Node* d = b->right;
    root->left = d;
    b->right = root;
    return b;
}


Node* turnLeft(Node* root){
    Node* b = root->right;
    Node* d = b->left;
    root->right = d;
    b->left = root;
    return b;
}

Node* updateRoot(Node* t){
    if(isAVL(t) == false){
        if(countLevel(t->left) > countLevel(t->right)){
            Node* p = t->left;
            if(countLevel(p->left) > countLevel(p->right))
                t = turnRight(t);
            
            else {
                t->left = turnLeft(t->left);
                t = turnRight(t);
            }
        }
        else {
            Node* p = t->right;
            if(countLevel(p->left) < countLevel(p->right))
                t = turnLeft(t);
            else {
                t->right = turnRight(t->right);
                t = turnLeft(t);
            }
        }
    }
    if(t->left != nullptr) t->left = updateRoot(t->left);
    if(t->right != nullptr) t->right = updateRoot(t->right);
    return t;

}
int main(){
    Node* root = nullptr;
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++){
        int key;
        std::cin>>key;
        root = insert(root,key);
    }
    while(isAVL(root) == false)
        root = updateRoot(root);
    std::cout<<countLevel(root);
}