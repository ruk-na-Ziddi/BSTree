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

int swap(Node* node,Node* rootNode) {
	int temp;
	temp = node->data;
	node->data = rootNode->data;
	rootNode->data = temp;
	return 0;
}



Node * deleteData(BSTree * tree , int data){
	Node_ptr node;
	BSTree childTree=createBSTree();
	if(tree->root ==  NULL) return NULL;
	if(tree->root->data == data){
		if(hasNoChild(tree->root)==1){
			node=tree->root; tree->root=NULL;
			return node;
		}
		if(tree->root->rightNode){
			swap(tree->root->rightNode,tree->root);
			childTree.root=tree->root->rightNode;
			node=deleteData(&childTree, data); 
		}
	}

	if(tree->root->rightNode!=NULL && tree->root->rightNode->data==data){
		if(hasNoChild(tree->root->rightNode)){
			node=tree->root->rightNode;
			tree->root->rightNode=NULL;
		}
	}

	if(tree->root->leftNode!=NULL && tree->root->leftNode->data==data){
		if(hasNoChild(tree->root->leftNode)){
			node=tree->root->leftNode;
			tree->root->leftNode=NULL;
		}
	}
	return node;
}