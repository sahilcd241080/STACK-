#include <stdio.h>
#include<string.h>
#define SIZE 100

int stack[SIZE];
int top=-1;

void push(int val){
    stack[++top]=val;
}

int pop(){
   return stack[top--];
}


int main(){
    char postfix[SIZE] = "23*54*+9-";
    int i ,a,b,result;
    
    for(i=0;postfix[i]!='\0';i++){
        char ch = postfix[i];
        
        if(isdigit(ch)){
            push(ch-'0');
        }else{
            b=pop();
            a=pop();
            
            switch(ch){
                case '+' : result=a+b;
                break;
                case '-': result = a-b;
                break;
                case '*': result = a*b;
                break;
                case '/': result = a/b;
                break;
                case '%': result = a%b;
                break;
            }
            push(result);
            
        }
    }
    
    
    printf("postfix %s :\n",postfix);
    printf("%d\n",result);
    return 0;
    
}























