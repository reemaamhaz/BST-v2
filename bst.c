#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
/*
	This program completes commands and functions for a BST.
    
	Author: Reema Amhaz
*/

/**
    * Adds the specified element to this set if it is not already present.
    * This method recursively finds the position to add the node in respect to its root.
    * Parameters: The root of the BST and the word data for the new node
    * Return value: 
    * none
    * */
void add ( bst_node ** root, char * word ) {

    struct bst_node *addElement =  (struct bst_node *)malloc(sizeof(struct bst_node)); 
    addElement->data = word; 
    addElement->left = addElement->right = NULL; 

    // base case
    if((*root) == NULL)
    {
        *root = addElement;
        return;
    } 
    // it's smaller so traverse left
    if(strcmp(word, (*root)->data) < 0)   
    {
        add(&((*root)->left), word);
    }
    // it's bigger so traverse right
    else if(strcmp(word, (*root)->data) > 0) 
    {
        add(&((*root)->right), word);
    }
    else //it's a duplicate so we don't add it
    {
        return;
    }
    
}

 
/**
    * Prints the nodes using an inorder traversal through the tree
    * Parameters: The root of the BST
    * Return value: 
    * none
    * */
void inorder ( bst_node * root ) {
    if (root == NULL) return;
    inorder(root->left); 
    printf("%s ", root->data); 
    inorder(root->right); 
}


 /**
    * Finds the smallest node in the tree and removes it. 
    * Parameters: The root of the BST and the word data for the new node
    * Return value: 
    * the data of the removed node
    * */
char * removeSmallest (  bst_node ** root ){
    if  (root == NULL) return NULL;  
    if  ((*root) == NULL) return NULL; //checking if it's pointing to a null

    if ((*root)->left != NULL)
    {
        // go left to find the smallest node
        return removeSmallest(&((*root)->left));
    }
    // both leaves
    else if((*root)->right == NULL && (*root)->left == NULL)
    {
        struct bst_node *temp = *root; // points to the root
        char *s = temp->data; // gets data
        (*root) = NULL; // now root points to null
        free(*root);
        return(s);
    } 
    // found smallest
    else if((*root)->left == NULL) //
    {
        struct bst_node *temp = *root; // points to the root
        char *s = temp->data; // gets data
        (*root) = temp->right; // now root points to the right
        free(temp); //remove the node
        temp = NULL; //set to  null 
        return(s);
    } 
    else 
    { 
        struct bst_node *temp = *root; // points to the root
        char *s = temp->data; // gets data
        (*root) = temp->left; // now root points to the left
        free(temp); //remove the node
        temp = NULL; //set to  null 
        return(s);
    } 
}

 /**
    * Finds the largest node in the tree and removes it. 
    * Parameters: The root of the BST and the word data for the new node
    * Return value: 
    * the data of the removed node
    * */
char * removeLargest (  bst_node ** root ){
    if  (root == NULL) return NULL;  
    if  ((*root) == NULL) return NULL; //checking if it's pointing to a null

    if ((*root)->right != NULL)
    {
        // go right to find the largest node
        return removeLargest(&((*root)->right));
    }
    // both leaves
    else if((*root)->right == NULL && (*root)->left == NULL)
    {
        struct bst_node *temp = *root; // points to the root
        char *s = temp->data; // gets data
        (*root) = NULL; // now root points to null
        free(*root);
        return(s);
    } 
    //only left node
    else if((*root)->right == NULL)
    {
        struct bst_node *temp = *root; // points to the root
        char *s = temp->data; // gets data
        (*root) = temp->left; // now root points to the left
        free(temp); //remove the node
        temp = NULL; //set to  null 
        return(s);
    } 
    //only right node
    else 
    { 
        struct bst_node *temp = *root; // points to the root
        char *s = temp->data; // gets data
        (*root) = temp->right; // now root points to the right
        free(temp); //remove the node
        temp = NULL; //set to  null 
        return(s);
    } 
}