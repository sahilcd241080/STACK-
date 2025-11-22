#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    char data;
    struct Node* next;
} node;

typedef struct stack{
    node* top;
} stack;

node* createnode(char data){
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

void init(stack* s){
    s->top = NULL;
}

void push(stack* s, char num){
    node* n = createnode(num);
    n->next = s->top;
    s->top = n;
}



char pop(stack* s){
    if(s->top == NULL){
        return 0;
    }
    node* temp = s->top;
    char val = temp->data;
    s->top = s->top->next;
    free(temp);
    return val;
}

int ismatch(char open , char close){
    return (open=='(' && close==')') ||
           (open=='{' && close=='}') ||
           (open=='[' && close==']');
}

int isbalance(char* exp){
    stack s;
    init(&s);

    for(int i = 0; exp[i]; i++){
        char c = exp[i];

        if(c=='(' || c=='{' || c=='['){
            push(&s, c);
        }
        else if(c==')' || c=='}' || c==']'){
            char open = pop(&s);
            if(!ismatch(open, c)){
                return 0;
            }
        }
    }

    return s.top == NULL;
}

int main(){
    char exp[100];
    printf("Enter expression: ");
    scanf("%s", exp);

    if(isbalance(exp)){
        printf("Parenthesis is matched\n");
    } else {
        printf("Parenthesis is not matched\n");
    }
    return 0;
}

