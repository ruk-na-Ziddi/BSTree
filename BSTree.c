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