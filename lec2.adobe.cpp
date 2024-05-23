#include<iostream>
#include<map>
using namespace std;
// create node class
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data= val;
        this->left= NULL;
        this->right= NULL;

    }
};

//it returns root of the created tree
Node* createTree(){
    cout<<"enter the value of node"<<endl;
    int data;
    cin>>data;

    if(data==-1){
        return NULL;
    }
    //step1: create node
    Node* root= new Node(data);
    //step2: create left subtree
    root->left = createTree();
    //step 3: create right subtree
    root->right = createTree();
    return root;
}
//o(1)
void createMapping(int inorder[], int size, map<int,int> &valueToIndexMap){
    for(int i=0; i<size; i++){
        int element= inorder[i];
        int index =i;
        valueToIndexMap[element]= index;
    }
}
//o(n)
int searchInorder(int inorder[], int size, int target){
    for(int i=0; i<size; i++){
        if(inorder[i]==target){
            return i;
        }
    }
    //vaise aaisa hoga nhi coz element toh milega
    return -1;
}


int main(){
   int inorder[]= {10,8,6,2,4,12};
   int preorder[]={2,8,10,6,4,12};
   int size= 6;
   int preorderIndex= 0;
   int inorderStart= 0;
   int inorderEnd= 5;
//    map<int,int> valueToIndexMap;
//    createMapping(inorder,size,valueToIndexMap);

   

}