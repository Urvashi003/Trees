#include<bits/stdc++.h>
#include<queue>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this-> right = NULL;
    }
};

void preOrder(Node* root){
    //bc
    if(root==NULL){
        return;
    }
    // //NLR
    // cout<<root->data<<endl;
    // preOrder(root->left);
    // preOrder(root->right);

    Node* ptr;
    stack<Node*>st;
    st.push(root);
    while(!st.empty()){
        ptr = st.top();
        st.pop();
        cout<<ptr->data<<"\t";
        if(ptr->right !=NULL)
        st.push(ptr->right);
        if(ptr->left != NULL)
        st.push(ptr->left);
    }
}

void inOrder(Node* root){
    //bc
    if(root==NULL){
        return;
    }

    //LNR
    inOrder(root->left);
    cout<<root->data<<endl;
    inOrder(root->right);
}

void postOrder(Node* root){
    //bc
    if(root==NULL){
        return;
    }
    //LRN
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<endl;
}

Node* createTree(){
    cout<<"enter the value of node"<<endl;
    int data;
    cin>>data;

    if(data==-1){
        return NULL;
    }

    Node* root = new Node(data);

    cout<<"left of node  "<<root->data<<endl;
    root->left = createTree();
    cout<<"right of node "<<root->data<<endl;
    root->right = createTree();

    return root;
}

void levelOrderTraversal(Node* root) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	//asli traversal start krete h 

	while(!q.empty()) {
		Node* front = q.front();
		q.pop();

		if(front == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			//valid node wala case
			cout << front->data << " ";

			if(front->left != NULL) {
				q.push(front->left);
			}
			if(front->right != NULL) {
				q.push(front->right);
			}
		}
	}
}

int main(){
    Node* root = createTree();

    //call saare traversals
    // cout<<"printing preorder"<<endl;
    // preOrder(root);
    // cout<<endl;

    // cout<<"printing inorder"<<endl;
    // inOrder(root);
    // cout<<endl;

    // cout<<"printing postorder"<<endl;
    // postOrder(root);
    // cout<<endl;

    cout<<"preorder";
    preOrder(root);


    return 0;
    // cout<<root->data<<endl;
}