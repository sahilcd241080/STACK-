#include<stdio.h>
#define SIZE 5

 
typedef struct stack{
	int data[SIZE];
	int top;
} stack;

void intial(stack* s){
	s->top =-1;
}

void push(stack* s,int num){
	if(s->top==SIZE-1){
		printf("stack is full\n");
		return;
	}
	s->data[++s->top]=num;
	return;
}

void pop(stack* s){
	if(s->top==-1){
		printf("stack is empty\n");
		return;
	}
	s->top--;
	return;
}

int peak(const stack* s){
	if(s->top==-1){
		printf("stack is empty\n");
		return -1;
	}
	return s->data[s->top];
}


int main(){
	stack s;
	intial(&s);
	push(&s,40);
	push(&s,30);
	push(&s,20);
	push(&s,10);
	push(&s,5);
	push(&s,2);
	
	printf("%d\n",peak(&s));
	pop(&s);
	printf("%d\n",peak(&s));
	pop(&s);
	printf("%d\n",peak(&s));
	pop(&s);
	printf("%d\n",peak(&s));
	pop(&s);
	printf("%d\n",peak(&s));
	pop(&s); // stack is empty
	printf("%d\n",peak(&s)); 
}






