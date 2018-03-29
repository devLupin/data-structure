#ifndef __LINKEDLIST_H___
#define __LINKEDLIST_H___

#define TRUE	1
#define FALSE	0

typedef struct _list {
	int data;
	struct _list *next;
}List;

/* list Initialized */
void listInit(List **plist);

/* list Insert(push) */
void Insert(List **head, int data);

/* list Delete(pop) */
void Delete(List **head, int data);

void print(List *head);

#endif // !__LINKEDLIST_H___
