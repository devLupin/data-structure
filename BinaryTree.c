#include <stdlib.h>
#include <stdio.h>
#include "BinaryTree.h"

/*
	왼쪽, 오른쪽 자식은 없음을 표기
	데이터는 따로 초기화해주지 않는다.
*/
void TreeInit(TreeNode * tp)
{
	tp->leftChild = tp->rightChild = NULL;
}

/*
	새로운 트리원소를 만든다.
	만들고 나서 초기화 과정을 거치고 그 원소포인터를 반환.
*/
TreeNode * NewNode(void)
{
	TreeNode *nNode = (TreeNode *)malloc(sizeof(TreeNode));
	TreeInit(nNode);

	return nNode;
}

void MakeLeftSubTree(TreeNode * tp)
{
	if (tp->leftChild != NULL) {	//왼쪽 서브트리가 있다면
		fprintf(stderr, "leftChild already exist !");
		free(tp->leftChild);	//제거를 한다.
	}

	tp->leftChild = NewNode();
}

void MakeRightSubTree(TreeNode * tp)
{
	if (tp->rightChild != NULL) {	//오른쪽 서브트리가 있다면
		fprintf(stderr, "leftChild already exist !");
		free(tp->rightChild);	//제거를 한다.
	}

	tp->rightChild = NewNode();
}

void DeleteTree(TreeNode *tp) {
	if (tp == NULL) {		//삭제할 트리원소가 없다면
		fprintf(stderr, "Tree don't exist !");
		exit(EXIT_FAILURE);		//강제종료
	}

	free(tp);
}

void DeleteLeftSubTree(TreeNode * tp)
{
	DeleteTree(tp->leftChild);
}

void DeleteRightSubTree(TreeNode * tp)
{
	DeleteTree(tp->rightChild);
}

void TreePushData(TreeNode * tp, int data)
{
	if (tp == NULL) {		//해당 트리가 존재하지 않는다면
		fprintf(stderr, "Tree don't exist");
		tp = NewNode();		//새로운 트리원소를 만든다.
	}
	
	tp->data = data;		//데이터 저장
}

int TreePopData(TreeNode * tp)
{
	int rData;		//해당 트리의 데이터 값

	if (tp == NULL) {	//트리가 없다면
		fprintf(stderr, "Tree don't exist");
		exit(EXIT_FAILURE);		//강제종료를 시킨다.
	}
	rData = tp->data;		//트리가 존재하면 값을 저장해서
	free(tp);				//해당 트리 원소를 제거하고

	return rData;			//값을 반환.
}