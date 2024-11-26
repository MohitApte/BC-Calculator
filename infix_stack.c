#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "infix_stack.h"
#include <math.h>

int isOperator(char ch){

    return (ch == '+' || ch == '-' || ch == '/' || ch == '*');
}

int isOperand(char ch){
    return ('0'<=ch && ch<='9');
}


 
int stackTop(struct Stack* sp){
    return sp->arr[sp->top];
}
 
int isEMPTY(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFULL(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void PUSH(struct Stack* ptr, char val){
    if(isFULL(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
char POP(struct Stack* ptr){
    if(isEMPTY(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int precedence(char ch){
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}


char* infixToPostfix(char* infix){

    struct Stack * sp = (struct Stack *) malloc(sizeof(struct Stack));
    sp->size = 10; 
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition 
    while (infix[i]!='\0')
    {
        if (infix[i] == '('){
            PUSH(sp,infix[i]);
            i++;
        }
        else if (infix[i] == ')'){

            while((stackTop(sp))!='('){

                postfix[j] = POP(sp);
                j++;

            }

            POP(sp);

            i++;
        }
        if(isOperand(infix[i])){
            
            do{

            

            postfix[j] = infix[i];
            j++;
            i++;
            }
            while(isOperand(infix[i]));
            postfix[j]=' ';
            j++;
           
        }
        else if(isOperator(infix[i])){

            
            if(precedence(infix[i])> precedence(stackTop(sp))){
                PUSH(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = POP(sp);
                j++;
            }
        }

        else i++;
    }
    while (!isEMPTY(sp))    
    {
        postfix[j] = POP(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

