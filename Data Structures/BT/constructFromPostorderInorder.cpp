#include<iostream>
#include<queue>
#include "BinaryTree.h"
using namespace std;


void printlevelwise(BinaryTreeNode<int>* root){
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int>* front = q.front();
        if(front != NULL){
            q.pop();
            cout<<front->data<<":";
            if(front->left){
                q.push(front->left);
                cout<<"L"<<front->left->data;
            }
            if(front->right){
                q.push(front->right);
                cout<<"R"<<front->right->data;
            }
            cout<<endl;
            }
    }
        

}

BinaryTreeNode<int>* takeinputlevelwise(){
    int rootData;
    cout<<"Enter root data: "<<endl;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            q.push(child);
        }
        cout<<"Enter right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            q.push(child);
        }
    }
    return root;
}

void preorder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

BinaryTreeNode<int>* construct(int* postorder,int* inorder,int postlength,int inlength){
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(postorder[postlength-1]);
    if(postlength == 1){
        return root;
    }
    if(postlength == 0){
        return  NULL;
    }
    int rootIndex = 0;
    while(inorder[rootIndex] != postorder[postlength-1]){
        rootIndex++;
    }
    int leftlen = rootIndex;
    int rightlen = inlength - rootIndex -1;
    root->left = construct(postorder,inorder,leftlen,leftlen);
    root->right = construct(postorder + leftlen,inorder+leftlen+1,rightlen,rightlen);
    return root;

}

int main(){
    // BinaryTreeNode<int>* root = takeinputlevelwise();

    // mirror(root);
    // printlevelwise(root);
    int n;
    cin>>n;
    int* a = new int[n];
    int * b = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    BinaryTreeNode<int>* root = construct(a,b,n,n);
    printlevelwise(root);
    return 0;
}