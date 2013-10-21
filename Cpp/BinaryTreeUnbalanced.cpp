#include "BinaryTreeUnbalanced.h"

BinaryTreeUnbalanced::BinaryTreeUnbalanced()
{

}

bool BinaryTreeUnbalanced::search(string value)
{
    Node* nd = this->root;
    while(nd!=NULL)
    {

        if(value == nd->value)
        {
            return true;
        }
        else if(value > nd->value)
            nd = nd->left;
        else
            nd = nd->right;
    }
        return false;
}
bool BinaryTreeUnbalanced::insert(string value)
{
    Node* nd = this->root;
    while(nd != NULL)
    {
        if(value == nd->value)
        {
            return true;
        }
        else if(value < nd->value)
        {
            if(nd->left!=NULL)
                nd = nd->left;
            else
            {
                nd->left = new Node(value);
                nd->left->parent = nd;
                break;
            }
        }
        else
        {
            if(nd->right!=NULL)
                nd = nd->right;
            else
            {
                nd->right = new Node(value);
                nd->right->parent = nd;
                break;
            }
        }
    }
}
bool BinaryTreeUnbalanced::remove(string value)
{

    /* a SIMILITAR DOesEARCH aLGORITHM*/
    Node* nd = this->root;
    Node* nd1 = this->root;
    while(nd != NULL)
    {
        if(value == nd->value)
        {
            if(nd->left == NULL && nd->right == NULL)
            {
                if(nd->parent->left == nd)
                    nd->parent->left = NULL;
                else if(nd->parent->right == nd)
                    nd->parent->right = NULL;
                /*else
                 */
                delete(nd);
                return true;
            }
            else if(nd->right == NULL)
            {

                nd->left->parent = nd->parent;

                if(nd->parent->left == nd)
                    nd->parent->left = nd->left;
                else if(nd->parent->right == nd)
                    nd->parent->right = nd->left;
                delete(nd);
                return true;

            }
            else if(nd->left == NULL)
            {

                nd->right->parent = nd->parent;

                if(nd->parent->left == nd)
                    nd->parent->left = nd->right;
                else if(nd->parent->right == nd)
                    nd->parent->right = nd->right;
                delete(nd);

                return true;

            }
            else
            {

                nd1 = nd->right;
                while(nd1->left != NULL)
                    nd1 = nd1->left;
                nd->value = nd1->value;
                if(nd1->parent->left == nd1)
                    nd1->parent->left = NULL;
                else if(nd1->parent->right == nd1)
                    nd1->parent->right = NULL;
                delete(nd1);
            }


        }
        else if(value > nd->value)
            nd = nd->left;
        else
            nd = nd->right;
    }
        return false;
    /**/;
}
BinaryTreeUnbalanced::Node * BinaryTreeUnbalanced::getSuccessor(BinaryTreeUnbalanced::Node *node)
{
    /*Node* nd;

    nd = node->right;
    while(nd->left != NULL)
        nd = nd->left;
    return nd;*/
}
