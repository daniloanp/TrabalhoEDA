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

                break;
            }
        }
    }
}
bool BinaryTreeUnbalanced::remove(string value)
{

    /* a SIMILITAR DOesEARCH aLGORITHM*/
    Node* nd = this->root;
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
            else if(nd->left != NULL)
            {

                nd->left->parent = nd->parent;

                if(nd->parent->left == nd)
                    nd->parent->left = nd->left;
                else if(nd->parent->right == nd)
                    nd->parent->right = nd->left;
                delete(nd);
                return true;

            }
            else if(nd->right != NULL)
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


            }


        }
        else if(value > nd->value)
            nd = nd->left;
        else
            nd = nd->right;
    }
        return false;
    /**/;
};
