#include<iostream>
#include<queue>
using namespace std;
template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<int>*left ;
    BinaryTreeNode<int>*right ;
    BinaryTreeNode(T data){
        this ->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right ;
    }

};

BinaryTreeNode<int>* TakeInputLevelWise(){
    cout<<"Enter root Data"<<endl;
    int rootData;
    cin>>rootData;
    if(rootData ==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>*curr= pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter the left child of "<<curr->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData!=-1){
            BinaryTreeNode<int>*child = new BinaryTreeNode<int>(leftChildData);
             curr->left = child;
             pendingNodes.push(child);
        }
        cout<<"Enter the right child of "<<curr->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData!=-1){
            BinaryTreeNode<int>*child = new BinaryTreeNode<int>(rightChildData);
             curr->right = child;
             pendingNodes.push(child);
        }
       
    }
    return root;
}

void printLevelWise(BinaryTreeNode<int>*root){
    if(root==NULL){
        return ;
    }
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int>*curr = q.front();
        q.pop();
        int currData = curr->data, left =-1 ,right =-1;
        if(curr->left !=NULL){
            left = curr->left->data;
            q.push(curr->left);
        }
         if(curr->right !=NULL){
            right = curr->right->data;
            q.push(curr->right);
        }
    
    cout<<currData<<":L:"<<left<<",R:"<<right<<endl;
    }
}
//PostOrder = l r root
//InOrder = l root r 

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength){
    if(postLength==0 || postorder==NULL || inorder==NULL)
    {
        return NULL;
    }
    int rootValue =postorder[postLength-1];
    int leftcount ;
    for(int i=0;i<inLength;i++){
        if(inorder[i]==rootValue){
            leftcount =i;
        }
    }
    int rightCount = inLength-leftcount-1;
    BinaryTreeNode<int>*root= new BinaryTreeNode<int> (rootValue);
    root->left = buildTree(postorder,leftcount,inorder , leftcount);
    root->right = buildTree(postorder+leftcount,rightCount,inorder+leftcount+1,rightCount);
    return root;
}

int main(){
    
     int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> post[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(post, size, in, size);
    printLevelWise(root);
}