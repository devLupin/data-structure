#include <stdio.h>
#include "BinaryTree.h"

int main(void) {
	TreeNode *head = NewNode();
	TreeNode *travel = head;	// 해당 위치를 가리킬 트리포인터.
	TreeNode *presentNode = NULL;

	int i;


	/* 왼쪽 하위트리를 5개 추가한다.
		ㅁ
	   /  \
	  ㅁ   ㅁ
     /  \
    ㅁ   ㅁ
    .......
	*/
	for (i = 0; i < 5; i++) {
		MakeLeftSubTree(travel);
		MakeRightSubTree(travel);

		travel = travel->leftChild;
	}

	MakeLeftSubTree(travel);
	DeleteLeftSubTree(travel);

	return 0;
}