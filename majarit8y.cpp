// #include <iostream>
// #include <vector>

// using namespace std;

// struct Node {
//     int value;
//     int count;
//     Node* left;
//     Node* right;

//     Node(int val) : value(val), count(1), left(nullptr), right(nullptr) {}
// };

// Node* insertNode(Node* root, int value) {
//     if (root == nullptr) {
//         return new Node(value);
//     }

//     if (value < root->value) {
//         root->left = insertNode(root->left, value);
//     } else if (value > root->value) {
//         root->right = insertNode(root->right, value);
//     } else {
//         root->count++;
//     }

//     return root;
// }

// int findMajorityElement(Node* root, int size) {
//     int candidate = -1;
//     int count = 0;
//     vector<Node*> stack;
//     Node* current = root;

//     while (current != nullptr || !stack.empty()) {
//         while (current != nullptr) {
//             stack.push_back(current);
//             current = current->left;
//         }

//         current = stack.back();
//         stack.pop_back();

//         if (current->count > count) {
//             candidate = current->value;
//             count = current->count;
//         }

//         if (count > size / 2) {
//             return candidate;
//         }

//         current = current->right;
//     }

//     return -1; 
// }

// int main() {
//     int size;
//     cout << "Enter the number of elements: ";
//     cin >> size;

//     vector<int> cards(size);
//     cout << "Enter the elements: ";
//     for (int i = 0; i < size; i++) {
//         cin >> cards[i];
//     }

//     Node* root = nullptr;
//     for (int i = 0; i < size; i++) {
//         root = insertNode(root, cards[i]);
//     }

//     int majorityElement = findMajorityElement(root, size);

//     if (majorityElement != -1) {
//         cout << "A majority element exists: " << majorityElement << endl;
//     } else {
//         cout << "No majority element found." << endl;
//     }


//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int value;
    int count;
    Node* left;
    Node* right;
    Node(int val): value(val),count(1),left(nullptr),right(nullptr) {}
};
Node* insert(Node* root, int value){
    if(root==nullptr){
        return new Node(value);
    }
    if(value<root->value){
        root->left=insert(root->left,value);
    }
    else if(value>root->value){
        root->right=insert(root->right,value);
    }
    else{
        root->count++;
    }
    return root;
}
int findmajele(Node* root, int size){
    int candidate=-1;
    int count=0;
    vector<Node*> stack;
    Node* current=root;
    while(current!=nullptr||!stack.empty()){
        while(current!=nullptr){
            stack.push_back(current);
            current=current->left;
        }
        current=stack.back();
        stack.pop_back();
        if(current->count>count){
            candidate=current->value;
            count=current->count;
        }
        if(count>size/2){
            return candidate;
        }
        current=current->right;
    }
    return -1;
}

int main(){
    int size;
    cin>>size;
    vector<int> cards(size);
    for(int i=0;i<size;i++) cin>>cards[i];
    Node* root=nullptr;
    for(int i=0;i<size;i++) root=insert(root,cards[i]);
    int majele=findmajele(root,size);
    if(majele!=-1)
    cout<<"A majority element exist: "<<majele<<endl;
    else cout<<"No majority element found."<<endl;
    return 0;
}
    
    
    
    
    
    
    

