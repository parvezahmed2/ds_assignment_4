 #include<bits/stdc++.h>
 using namespace std;
 class Node{
 public:
 int val;
 Node* left;
 Node* right;
 Node(int val){
     this->val=val;
      this->left=NULL;
      this->right=NULL;
      
 }
 };
 Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        // 1. ber kore ano
        Node *p = q.front();
        q.pop();

        // 2. jabotiyo ja kaj ache
        int l, r;
        cin >> l >> r;
        Node *myLeft;
        Node *myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);
        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;

        // 3. children gulo ke push koro
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}

  void level_order(Node* root){
     vector<int> v;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {   

        //1. ber kore ana 
        Node* f=q.front();
        q.pop();

        //2. jabotiyo ja kaj ache 
        // cout<<f->val<<" ";
        if(f->left==NULL && f->right == NULL){
            v.push_back(f->val);
        }

        
        
        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
    }
    cout<<*max_element(v.begin(),v.end())<<" "<<*min_element(v.begin(),v.end());
 }

 int main(){
    
     Node *root = input_tree();
    level_order(root);
     
     return 0;
 }