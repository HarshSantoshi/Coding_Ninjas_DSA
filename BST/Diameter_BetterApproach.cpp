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
int height (BinaryTreeNode<int>*root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->right), height(root->left));
}
int diameter (BinaryTreeNode<int>*root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left)+height(root->right) , max(diameter(root->right), diameter(root->left)));
}

pair<int ,int> heightDiameter(BinaryTreeNode<int>*root){
    if(root==NULL){
        pair<int , int > p;
        p.first = 0;
        p.second=0;
    }
    pair<int ,  int > leftAns = heightDiameter(root->left);
    pair<int ,  int > rightAns = heightDiameter(root->right);
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd=rightAns.second;
    int rh=rightAns.first;

    int height = 1+ max (lh , rh);
    int diameter = max (lh+rh , max(ld , rd));

    pair<int , int > p;
    p.first=height;
    p.second=diameter;
    return p;
}

int main(){
    BinaryTreeNode<int>* root = TakeInputLevelWise();
    pair<int , int > p = heightDiameter(root);
    cout<<"Height :"<<p.first<<endl;
    cout<<"Diameter :"<<p.second<<endl;
    delete root;
}