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