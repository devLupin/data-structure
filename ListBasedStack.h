#ifndef __LB_STACK_H___
#define __LB_STACK_H___

#include "Linkedlist.h"

typedef int Data;
typedef List Stack;

int top;			//스택의 개수 저장하는 전역변수

/* 스택의 초기화 */
void SInit(Stack *sp);
/* LIFO 구조에 따른 값을 삽입 */
void Spush(Stack **sp, int data);
/* LIFO 구조에 따른 값의 제거 */
int Spop(Stack **sp);
/* 스택의 현재 상태 출력 */
void stackPrint(Stack *sp);

#endif // !__LB_STACK_H___
