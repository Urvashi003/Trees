#include<iostream>
#include<queue>
using namespace std;

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

Node* insertIntoBST(Node* root, int data){
    if(root==NULL){
        root= new Node(data);
        return root;
    }

    //its not the first node
    if(data>root->data){
        root->right= insertIntoBST(root->right, data);
    }
    else{
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void createBST(Node* &root){
    cout<<"Enter data"<<endl;
    int data;
    cin>>data;

    while(data != -1){
        root= insertIntoBST(root,data);
        cout<<"enter data"<<endl;
        cin>>data;
    }
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout<<temp->data<<" ";
            if(temp->left !=NULL){
                q.push(temp->left);
            }
            if(temp->right !=NULL){
                q.push(temp->right);
            }
        }
    }
}

void preorder(Node* root){
    //NLR
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    //LNR
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    //LRN
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

Node* minValue(Node* root){
    if(root==NULL){
        cout<<"NO MIN VALUE"<<endl;
        return NULL;
    }
    Node* temp = root;

    while(temp->left !=NULL){
        temp= temp->left;
    }
    return temp;
}

Node* maxValue(Node* root){
    if(root==NULL){
        cout<<"No max value"<<endl;
        return NULL;
    }
    Node* temp = root;
    while(temp->right !=NULL){
        temp= temp->right;
    }
    return temp;
}

bool searchInBST(Node* root, int target){
    //bc
    if(root==NULL){
        return false;
    }
    //1 case mujhe solve karna hau
    //left ya right
    bool leftAns = false;
    bool rightAns = false;

    if(target> root->data){
        //right
        rightAns = searchInBST(root->right, target);
    }
    else{
        leftAns = searchInBST(root->left, target);
    }
    return leftAns || rightAns;
}

Node* deleteFromBST(Node* root, int target){
    //target ko dhundo
    //target ko delete karo
    if(root==NULL){
        return NULL;
    }
    if(root->data == target){
        //ab delete karenge
        //4 cases
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left !=NULL && root->right==NULL){
            //2 case-> left non null and right null
            Node* childSubtree= root->left;
            delete root;
            return childSubtree;
        }
        else if(root->left==NULL && root->right != NULL){
            Node* childSubtree= root->right;
            delete root;
            return childSubtree;
        }
        else{
            Node* maxi = maxValue(root->left);
            //replace
            root->data = maxi->data;
            //delete maxi
            root->left= deleteFromBST(root->left, maxi->data);
            return root;
        }

    }

    else if(root->data >target){
        root->left= deleteFromBST(root->left, target);
    }
    else{
        //right
        root->right = deleteFromBST(root->right, target);
    }
    return root;
}

int main(){
    Node* root=NULL;
    createBST(root);

    levelOrderTraversal(root);

    cout << endl << "Inorder: " ;
	inorder(root);
	cout << endl << "Preorder: ";
	preorder(root);
	cout << endl << "PostOrder: ";
	postorder(root);

    cout<<endl;
    Node* minNode= minValue(root);
    if(minNode == NULL) {
		cout << "There is no node in tree, so no min value" << endl;
	}
	else {
		cout << "Min Value: " << minNode->data << endl;
	}

	cout << endl;
	Node* maxNode = maxValue(root);
	if(maxNode == NULL) {
		cout << "There is no node in tree, so no max value" << endl;
	}
	else {
		cout << "Max Value: " << maxNode->data << endl;
	}

    // int t;
	// cout << "Enter the target: " << endl;
	// cin >> t;

	// while(t != -1) {
	// 	bool ans = searchInBST(root, t);
	// 	if(ans == true) {
	// 		cout << "Found" << endl;
	// 	}
	// 	else {
	// 		cout << "Not Found" << endl;
	// 	}
        
	// 	cout << "Enter the target: " << endl;
	// 	cin >> t;
		
	// } 

    int target ;
	cout << "Enter the value of target: " << endl;
	cin >> target;

	while(target != -1) {
		root = deleteFromBST(root,  target);
		cout << endl << "Printing Level Order Traversal: " << endl;
		levelOrderTraversal(root);

		cout << "Enter the value of target: " << endl;
		cin >> target;
		
	}

    return 0;
}
