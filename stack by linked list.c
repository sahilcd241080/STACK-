
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} node;

typedef struct stack{
	node* top;
} stack;

node* createnode(int data){
	node* n = (node*) malloc(sizeof(node));
	n->data=data;
	n->next = NULL;
	return n;
}

void intial(stack* s){
	s->top = NULL;
}
/*
int isempty(stack* s){
	if(s->top==NULL){
		return 1;
	}
	return 0;
}*/
 
void push(stack* s,int data){
	node* n = createnode(data);
	if(s->top==NULL){
		s->top=n;
		return;
	}
	n->next=s->top;
	s->top=n;
	
}

void pop(stack* s){
	if(s->top==NULL){
		return;
	}
	node* temp = s->top;
	s->top = s->top->next;
	free(temp);
}

int peak(stack* s){
	if(s->top==NULL){
		return 0;
	}
	return   s->top->data;
	
}

int main(){
	stack s;
	intial(&s);
	push(&s,40);
	push(&s,30);
	push(&s,20);
	push(&s,10);
	
	printf("%d\n",peak(&s));
	pop(&s);
	printf("%d\n",peak(&s));
	pop(&s);
	printf("%d\n",peak(&s));
	
	
	

}
