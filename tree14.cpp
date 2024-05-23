#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;

    Node(){
        data=0;
        left=right=NULL;
    }
    Node(int data,Node* left, Node* right){
        this->data = data;
        this->left = left;
        this->right= right;
    }
};

int main(){

}