#include<iostream>
#include<queue>
using namespace std;
class Node{
public:
int arr;
Node * curr ;
}
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
    this-> data = d;
    this-> left  = NULL;
    this-> right = NULL;
    }
   
};

void buildFromLevelOrder(node* &root){
    queue <node*> q;
    cout<<"enter the data for root"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        cout<<"enter data for left node"<< temp->data <<endl;
        int leftData;
        cin>>leftData;
        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }
         cout<<"enter data for right node"<< temp->data <<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
    }
}
}

int main(){
    node* root = NULL;
    buildFromLevelOrder(root);

    return 0;
}
