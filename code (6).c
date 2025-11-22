#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char arr[MAX];
    int top;
} stack;


// Stack Functions
void init(stack *s) {
    s->top = -1;
}

int isEmpty(stack *s) {
    return s->top == -1;
}

int isFull(stack *s) {
    return s->top == MAX - 1;
}

void push(stack *s, char ch) {
    if (!isFull(s)) {
        s->arr[++s->top] = ch;
    }
}

char pop(stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top--];
    }
    return '\0';
}

char peek(stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    return '\0';
}


// Precedence function
int preced(char ch) {
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '^') return 3;
    return 0;
}

// Check alphabet
int isalphabet(char a) {
    if((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
        return 1;
    return 0;
}


int main() {
    char infix[] = "A+B-C/E*F^G^H";
    int size = strlen(infix);

    char postfix[size + 1];
    stack s;
    init(&s);

    int pfidx = 0;

    for(int i = 0; i < size; i++) {
        char curr = infix[i];

        if(isalphabet(curr)) {
            postfix[pfidx++] = curr;
        }
        else if(curr == '(') {
            push(&s, curr);
        }
        else if(curr == ')') {
            while(!isEmpty(&s) && peek(&s) != '(') {
                postfix[pfidx++] = pop(&s);
            }
            pop(&s); // remove '('
        }
        else {
            while(!isEmpty(&s) && preced(curr) <= preced(peek(&s))) {
                if(curr == '^' && peek(&s) == '^')
                    break; // Right associative power
                postfix[pfidx++] = pop(&s);
            }
            push(&s, curr);
        }
    }

    while(!isEmpty(&s)) {
        postfix[pfidx++] = pop(&s);
    }

    postfix[pfidx] = '\0';

    printf("Infix  : %s\n", infix);
    printf("Postfix: %s\n", postfix);

    return 0;
}
