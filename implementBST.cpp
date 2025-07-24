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
  cout<<"Printing BST : "<<endl;
  levelwiseTraversal(root);
}