#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>

BSTree createBSTree(){
	BSTree tree={NULL};
	return tree;
};

Node_ptr createNode(int data){
	Node_ptr node=malloc(sizeof(Node));
	(*node).data=data;
	(*node).leftNode=NULL;
	(*node).rightNode=NULL;
	return node;
}

int insert(BSTree * tree, int data){
	Node_ptr node=createNode(data);
	BSTree childTree=createBSTree();
	if((*tree).root==NULL) (*tree).root=node;
	if((*(*tree).root).data > data){
		if((*(*tree).root).leftNode==NULL){
			(*(*tree).root).leftNode=node;
		}else{
			childTree.root=(*(*tree).root).leftNode;
			insert(&childTree, data);
		}
	}
	if((*(*tree).root).data < data){
		if((*(*tree).root).rightNode==NULL){
			(*(*tree).root).rightNode=node;
		}else{
			childTree.root=(*(*tree).root).rightNode;
			insert(&childTree, data);
		}
	}
	return 1;
}

Node * find(BSTree tree, int data){
	BSTree childTree=createBSTree();
	if(tree.root==NULL)  return NULL;
	if(tree.root->data==data) return tree.root;
	if(tree.root->data > data){
		if(tree.root->leftNode!=NULL) childTree.root=tree.root->leftNode;
	}
	if(tree.root->data < data){
		if(tree.root->rightNode!=NULL) childTree.root=tree.root->rightNode;
	}
	return find(childTree, data);
}


int hasNoChild(Node_ptr node){
	if(node->rightNode==NULL && node->leftNode==NULL) return 1;
	return 0;
}

Node_ptr findMin(Node *node){
	if(node==NULL){
		return NULL;
	}
	if(node->leftNode)
		return findMin(node->leftNode);
	else 
		return node;
}


Node * deleteData(BSTree * tree , int data){
	Node_ptr temp=NULL;
	BSTree childTree=createBSTree();

	if(tree->root==NULL) return NULL;

	if(data<tree->root->data){
		childTree.root=tree->root->leftNode;
		return deleteData(&childTree, data);
	} 
	
	if(data>tree->root->data){
		childTree.root=tree->root->rightNode;
		return deleteData(&childTree, data);
	}

	if(tree->root->rightNode && tree->root->leftNode){
		temp=findMin(tree->root->rightNode);
		tree->root->data=temp->data;
		childTree.root=tree->root->rightNode;
		return deleteData(&childTree, data);
	}else{
		temp=tree->root;
		if(tree->root->leftNode==NULL) tree->root=tree->root->rightNode;
		if(tree->root->rightNode==NULL) tree->root=tree->root->leftNode;
	}
	
	return temp;
}