#include<stdlib.h>
#include<stdio.h>

typedef struct LINKED_STACK_NODE_s *LINKED_STACK_NODE;
typedef struct LINKED_STACK_NODE_s {
	LINKED_STACK_NODE next;
	void *data;
} LINKED_STACK_NODE_t[1];

typedef struct LINKED_STACK_s {
	LINKED_STACK_NODE head;
} LINKED_STACK_t[1], *LINKED_STACK;

LINKED_STACK linked_stack_init()
{
	LINKED_STACK stack = NULL;
	stack = (LINKED_STACK)malloc(sizeof(LINKED_STACK_t));
	if(stack != NULL) {
		stack->head = NULL;
	}
	return stack;
}

void linked_stack_free(LINKED_STACK stack)
{
	free(stack);
}

/*
void linked_stack_push(LINKED_STACK stack, void *data){
	LINKED_STACK_NODE node = (LINKED_STACK_NODE)malloc(sizeof(LINKED_STACK_NODE_t));
	if(node != NULL){
		node->data = data;
		node->next = stack->head;
		stack->head = node;
	}
	else{
		printf("Error @ linked_stack_push: Cannot allocate memory.\n");
	}
}
*/
int linked_stack_push(LINKED_STACK stack, void *data)
{
	LINKED_STACK_NODE node = (LINKED_STACK_NODE)malloc(sizeof(LINKED_STACK_NODE_t));
	if(node != NULL){
		node->data = data;
		node->next = stack->head;
		stack->head = node;
		return 1;
	}
	else{
		return 0;
	}
}
/*
void *linked_stack_pop(LINKED_STACK stack){
	LINKED_STACK_NODE node;
	void *res = NULL;
	
	if(stack->head != NULL){
		node = stack->head;
		res = node->data;
		stack->head = node->next;
		free(node);
	}
	else{
		printf("Error @ linked_stack_pop: Empty stack is popped.\n");
	}
	return res;
}*/
void *linked_stack_pop(LINKED_STACK stack){
	LINKED_STACK_NODE node;
	void *res = NULL;
	
	if(stack->head != NULL){
		node = stack->head;
		res = node->data;
		stack->head = node->next;
		free(node);
	}
	
	return res;
}

void *linked_stack_top(LINKED_STACK stack)
{
	void *res = NULL;
	
	if(stack->head != NULL){
		res = stack->head->data;
	}

	return res;
}

int linked_stack_is_empty(LINKED_STACK stack)
{
/*	if(stack->head == NULL) {
		return 1;
	}
	else {
		return 0;
	}
*/	
	return (stack->head == NULL);
}

