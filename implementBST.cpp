#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
  int data;
  Node *left;
  Node *right;

  Node(int d)
  {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

void levelwiseTraversal(Node *root)
{
  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty())
  {
    Node *temp = q.front();
    q.pop();

    if (temp == NULL)
    {
      cout << endl;
      if (!q.empty())
      {
        q.push(NULL);
      }
    }
    else
    {
      cout << temp->data << " ";
      if (temp->left)
      {
        q.push(temp->left);
      }

      if (temp->right)
      {
        q.push(temp->right);
      }
    }
  }
}

Node *minval(Node *root)
{
  Node *temp = root;

  while (temp->left != NULL)
  {
    temp = temp->left;
  }
  return temp;
}

Node *deleteFromBST(Node *root, int val)
{
  // base case
  if (root == NULL)
    return root;

  if (root->data == val)
  {
    // 0 child
    if (root->left == NULL && root->right == NULL)
    {
      delete root;
      return NULL;
    }
    // 1 child
    // left child exists
    if (root->left != NULL && root->right == NULL)
    {
      Node *temp = root->left;
      delete root;
      return temp;
    }
    // right child exists
    if (root->left == NULL && root->right != NULL)
    {
      Node *temp = root->right;
      delete root;
      return temp;
    }
    // 2 child
    if (root->left != NULL && root->right != NULL)
    {
      int mini = minval(root->right)->data;
      root->data = mini;
      root->right = deleteFromBST(root->right, mini);
    }
  }
  else if (root->data > val)
  {
    root->left = deleteFromBST(root->left, val);
    return root;
  }
  else
  {
    root->right = deleteFromBST(root->right, val);
    return root;
  }
}

void inorderTraversal(Node *root)
{
  if (root == NULL)
    return;
  // LNR
  // Recursion
  // Inorder of BST is sorted
  inorderTraversal(root->left);
  cout << root->data << " ";
  inorderTraversal(root->right);
}

Node *insertIntoBST(Node *root, int d)
{
  // base case
  if (root == NULL)
  {
    root = new Node(d);
    return root;
  }

  if (d > root->data)
  {
    root->right = insertIntoBST(root->right, d);
  }
  else
  {
    root->left = insertIntoBST(root->left, d);
  }
  return root;
}

void TakeInput(Node *&root)
{
  int data;
  cin >> data;

  while (data != -1)
  {
    root = insertIntoBST(root, data);
    cin >> data;
  }
}

int main()
{
  Node *root = NULL;
  cout << "Enter the Data: " << endl;
  TakeInput(root);
  cout << "Printing BST : " << endl;
  levelwiseTraversal(root);

  cout << "Inorder BST : " << endl;
  inorderTraversal(root);
  cout<<"\n";

  cout<<"Min Value is: "<<minval(root)->data<<endl;

  // Deletion
  root = deleteFromBST(root , 30);

  cout << "Printing BST : " << endl;
  levelwiseTraversal(root);
}
