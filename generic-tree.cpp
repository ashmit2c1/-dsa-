#include<bits/stdc++.h>
using namespace std;

// CLASS FOR GENERIC TREE 
template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;
    // CREATING CONSTRUCTOR
    TreeNode(T data){
        this->data=data;
    }
};

// RECURSIVE FUNCTION TO PRINT TREE 
void printTreeData(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout << root->data << ": ";
    int n = root->children.size();
    for(int i = 0; i<n ; i++){
        cout << root->children[i]->data << " ";
    }
    cout << "\n";
    for(int i = 0; i<n ; i++){
        printTreeData(root->children[i]);
    }
}
// TAKING INPUT IN A TREE ( RECURSIVE )
TreeNode<int>* takeInput(){
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    int n;
    cin >> n;
    for(int i = 0; i<n ; i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}
// TAKING INPUT LEVEL WISE ITERATIVELY 
TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* front = q.front();
        q.pop();
        int n;
        cin >> n;
        for(int i = 1; i<=n ; i++){
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            q.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}
int main(){
    // CREATING NODES DYNAMICALLY 
    TreeNode<int>* root = new TreeNode<int>(1); // this is our root node
    TreeNode<int>* n1   = new TreeNode<int>(2);
    TreeNode<int>* n2   = new TreeNode<int>(3);
    // CREATING CONNECTION OF CHILDREN NODE WITH ROOT NODE 
    root->children.push_back(n1);
    root->children.push_back(n2);
    
}