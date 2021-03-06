// CPP AVLTree by
// Ikram Maulana
// 1930511075
// Teknik Informatika 3B

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
  int key;
  int height;
  struct node *left;
  struct node *right;
};

struct node *newNode(int x)
{
  struct node *curr = (struct node *)malloc(sizeof(struct node));
  curr->key = x;
  curr->height = 1;
  curr->left = NULL;
  curr->right = NULL;
  return curr;
}

int max(int left, int right)
{
  if (right > left)
    return right;
  else
    return left;
}

int getHeight(struct node *root)
{
  if (root == NULL)
    return 0;
  else
    return root->height;
}

int getBF(struct node *root)
{
  if (root == NULL)
    return 0;
  else
    getHeight(root->left) - getHeight(root->right);
}

struct node *rightRotate(struct node *root)
{
  struct node *newRoot = root->left;
  struct node *B = newRoot->right;

  newRoot->right = root;
  root->left = B;

  root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
  newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

  return newRoot;
}

struct node *leftRotate(struct node *root)
{
  struct node *newRoot = root->right;
  struct node *B = newRoot->left;

  newRoot->left = root;
  root->right = B;

  root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
  newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

  return newRoot;
}

void print(struct node *root)
{
  if (root == NULL)
    return;
  print(root->left);
  printf(" ");
  printf("%d", root->key);
  printf(" ");
  print(root->right);
}

// successor
// Right subtree, get the smallest
// predecessor
// left subtree, get the highest
struct node *predecessor(struct node *root)
{
  struct node *curr = root->left;
  while (curr->right)
  {
    curr = curr->right;
  }
  return curr;
}

struct node *insert(struct node *root, int key)
{
  if (root == NULL)
    return newNode(key);
  else if (key < root->key)
  {
    root->left = insert(root->left, key);
  }
  else
  {
    root->right = insert(root->right, key);
  }

  root->height = max(getHeight(root->left), getHeight(root->right));
  int bFactor = getBF(root);

  if (bFactor > 1 && key < root->left->key)
  {
    return rightRotate(root);
  }
  if (bFactor < -1 && key > root->right->key)
  {
    return leftRotate(root);
  }
  if (bFactor > 1 && key > root->left->key)
  {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  if (bFactor < -1 && key < root->right->key)
  {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  return root;
}

struct node *deleteVal(struct node *root, int key)
{
  if (root == NULL)
    return NULL;
  else if (key < root->key)
    root->left = deleteVal(root->left, key);
  else if (key > root->key)
    root->right = deleteVal(root->right, key);
  else
  {
    if (root->left == NULL || root->right == NULL)
    {
      struct node *temp;
      if (root->left)
        temp = root->left;
      else
        temp = root->right;

      if (temp == NULL)
      {
        temp = root;
        root = NULL;
      }
      else
      {
        *root = *temp;
      }
      free(temp);
    }
    else
    {
      struct node *temp = predecessor(root);
      root->key = temp->key;
      root->left = deleteVal(root->left, temp->key);
    }
  }

  // AVL Tree
  if (root == NULL)
    return root;

  root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
  int bFactor = getBF(root);

  if (bFactor > 1 && getBF(root->left) >= 0)
    return rightRotate(root);
  if (bFactor < -1 && getBF(root->right) <= 0)
    return leftRotate(root);
  if (bFactor > 1 && getBF(root->left) < 0)
  {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  if (bFactor < -1 && getBF(root->right) > 0)
  {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

struct node *freeAll(struct node *root)
{
  if (root == NULL)
    return NULL;
  root->left = freeAll(root->left);
  root->right = freeAll(root->right);
  free(root);
  return NULL;
}

int main()
{
  struct node *root = NULL;

  /*
  *       40
  *      /  \
  *     21   60
  *    /  \
  *  NULL  35
  **/

  printf("AVL Tree With Delete By Ikram Maulana");
  printf("\n");
  printf("=====================================");
  printf("\n");
  root = insert(root, 40);
  root = insert(root, 21);
  root = insert(root, 60);
  root = insert(root, 35);
  // print(root); //35 40 50 65
  root = deleteVal(root, 60);
  print(root);
  printf("\n");
  printf("=====================================");
  printf("\n");

  /*
  *       35
  *      /  \
  *     21   40
  **/

  root = freeAll(root);
  return 0;
}