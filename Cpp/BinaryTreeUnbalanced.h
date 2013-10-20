#ifndef BINARYTREEUNBALANCED_H
#define BINARYTREEUNBALANCED_H
#include <string>

using  std::string;


class BinaryTreeUnbalanced
{
private:
    int size;
    //int (*cmp)(void*, void*);

    class Node
    {
    public:
        string value;
        Node* left;
        Node* right;
        Node* parent;
        Node(string value)
        {
            this->parent = NULL;
            this->left = NULL;
            this->right = NULL;
            this->value = value;

        }
        Node(string value, Node* parent)
        {
            this->parent = parent;
            this->left = NULL;
            this->right = NULL;
            this->value = value;
        }
    };
    Node* root;
    Node* getSuccessor(Node* node);

public:
    bool search(string value);
    bool insert(string value);
    bool remove(string value);
    BinaryTreeUnbalanced();

};

#endif // BINARYTREEUNBALANCED_H
