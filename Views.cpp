#include<iostream>
#include<queue>
#include<map>
using namespace std;

class Node{
   public:
   int data;
   Node* left;
   Node* right;

   Node(int val){
    this->data = val;
    this->left= NULL;
    this->right = NULL;
   }

};

Node* createTree(){
   cout<<"enter the value of Node: ";
   int value;
   cin>>value;

   if(value==-1){
    return NULL;
   }

   //create node
   Node* root= new Node(value);
   cout<<"enter the left "<<value<<endl;
   root->left= createTree();
   cout<<"enter the right "<<value<<endl;
   root->right= createTree();

   return root;
}

void preOrder(Node* root){
    //nlr
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    //lnr
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root){
    //lrn
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void levelOrderTraversal(Node* root){
    //queue banao
    queue<Node*>qt;
    qt.push(root);
    qt.push(NULL);
    cout<<endl;

    while(!qt.empty()){
        Node* temp= qt.front();
        qt.pop();

        if(temp==NULL){
            cout<<endl;
            if(!qt.empty()){
                qt.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                qt.push(temp->left);
            }
            if(temp->right != NULL){
                qt.push(temp->right);
            }
            

        }
    }

}

void printLeftView(Node* root, int level, vector<int> &leftView){
    if(root==NULL){
        return;
    }
    if(level==leftView.size()){
        //iska matlab leftnode mil gyi
        //store karenge
        leftView.push_back(root->data);
    }
    //left call
    printLeftView(root->left, level+1, leftView);
    //right call
    printLeftView(root->right, level+1, leftView);
}

void printRightView(Node* root, int level, vector<int> &rightview){
    if(root==NULL){
        return;
    }
    if(level==rightview.size()){
        rightview.push_back(root->data);
    }
    printRightView(root->right,level+1,rightview);
    printRightView(root->left, level+1, rightview);
}
void printTopView(Node* root){
    map<int,int> NodeMap;
    queue<pair<Node*,int> > q;
    q.push(make_pair(root,0)); //root and level 0 push kar diya

    while(!q.empty()){
        pair<Node* , int> temp= q.front();
        q.pop();

        Node* frontNode = temp.first;
        int dist= temp.second;

        //agar koi entry mhi level ki toh create karo entry
        if(NodeMap.find(dist)== NodeMap.end()){
            NodeMap[dist]= frontNode->data;
        }
        //child ko dekhna hai
        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left, dist-1));
        }
        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right, dist+1));
        }
    }
    cout<<"printing top view: "<<endl;
    for(auto i:NodeMap){
        cout<<i.second <<" ";
    }

}

void printBottomView(Node* root){
   map<int,int> NodeMap;
    queue<pair<Node*,int> > q;
    q.push(make_pair(root,0)); //root and level 0 push kar diya

    while(!q.empty()){
        pair<Node* , int> temp= q.front();
        q.pop();

        Node* frontNode = temp.first;
        int dist= temp.second;

        //over write
        NodeMap[dist]= frontNode->data;
        //child ko dekhna hai
        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left, dist-1));
        }
        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right, dist+1));
        }
    }
    cout<<"printing top view: "<<endl;
    for(auto i:NodeMap){
        cout<<i.second <<" ";
    }

}

void printLeftBoundary(Node* root){
    if(root==NULL){
        return;
    }
    if(root->left == NULL && root->right==NULL){
        return;
    }
    cout<<root->data<<" ";
    if(root->left != NULL){
        printLeftBoundary(root->left);
    }
    else{
        printLeftBoundary(root->right);
    }
}

void printRightBoundary(Node* root) {
	if(root == NULL) {
		return;
	}
	if(root->left == NULL && root->right == NULL) {
		return;
	}
	
	if(root->right != NULL) {
			printRightBoundary(root->right);
	}
	else {
			printRightBoundary(root->left);
	}
	cout << root->data << " ";
}

void printLeafBoundary(Node* root) {
	if(root == NULL )
		return;

	if(root->left == NULL && root->right == NULL) {
		cout << root->data <<" ";
	}
	printLeafBoundary(root->left);
	printLeafBoundary(root->right);
}
void boundaryTraversal(Node* root ) {
	if(root == NULL)
		return;
	cout << root->data << " ";
	printLeftBoundary(root->left);
	printLeafBoundary(root->left);
	printLeafBoundary(root->right);
	printRightBoundary(root->right);
}

int main(){
    Node* root= createTree();
    levelOrderTraversal(root);


//     vector<int>leftView;
//     printLeftView(root,0,leftView);
//     cout<<"printing left view"<<endl;
//     for(int i=0; i<leftView.size(); i++) {
// 	  cout << leftView[i] << " ";
//    }

//    vector<int> rightview;
//    printRightView(root,0,rightview);
//    cout<<"printing right view"<<endl;
//    for(int i=0; i<rightview.size();i++){
//     cout<<rightview[i]<<" ";
//    }
// printTopView(root);
// printBottomView(root);
boundaryTraversal(root);

    return 0;

}
