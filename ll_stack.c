#include<stdio.h>
#include<stdlib.h>
#include "ll_stack.h"
#include "infix_stack.h"

void print_LL(node *head){

    while(head){
        printf("%d",head->data);
        head = head->next;
    }
    printf("\n");
    return;
}

void print_rev_LL(node *tail){

    while(tail){
        printf("%d",tail->data);
        tail = tail->prev;
    }
    printf("\n");
    return;
}

node* ReverseLL(node*head){
    if (!head || !head->next) return head;
    node*temp = head->next;
    node*smallhead = ReverseLL(head->next);
    temp->next = head;
    head->next = NULL;
    return smallhead;

}

int length(node *head){
    if (!head) return 0;
    return 1+length(head->next);
}


void init_stack(ll_stack *s, int size){

    s->arr = (num**)malloc(sizeof(num*) * size);

    s->size = size;
    
    s->top = -1;
}

int isEmpty(ll_stack s){

   return (s.top == -1); 
}

int isFull(ll_stack s){

    return (s.top == (s.size - 1));
}

void push(ll_stack *s,num *operand){

    if (isFull(*s)) return;
    s->top++;
    s->arr[s->top] = operand;
    //print_LL(s->arr[s->top]->head);

    return;
        
}

num** pop(ll_stack *s){
    num **dob =  (num**)malloc(sizeof(num*));
    if (isEmpty(*s)) return NULL;
    *dob = s->arr[s->top];
   
   s->arr[s->top] = NULL; 
   
   s->top--;
   //print_LL(operand->head);
   //printf("%p %p\n",operand->head,operand->tail);
   return dob;
    
}



num **add(num **op1, num **op2){

	num *ans = (num*)malloc(sizeof(num));
	ans->sign = 0;
	ans->head = NULL;
	ans->tail = NULL;
	//ReverseLL((*op1)->head);
	//ReverseLL((*op2)->head);

	int carry = 0;
	int digit = 0;

	node* temp1 = (*op1)->tail;
	node* temp2 = (*op2)->tail;
	

	while(temp1 || temp2){

	
		if(!temp1){
			digit = temp2->data+carry;
			temp2 = temp2->prev;

		}
		else if(!temp2){
			digit = temp1->data+carry;
			temp1 = temp1->prev;

		}else{
			digit = temp1->data + temp2->data+carry;
			temp1 = temp1->prev;
			temp2 = temp2->prev;

		}
		
		
		
		node *dig = (node*)malloc(sizeof(node));
		dig->next = NULL;
		dig->prev = NULL;
		if(digit>9){
			int temp = digit;
			digit = digit%10;
			carry = temp/10;
		}

		
		dig->data = digit;
		if(!ans->head){
			ans->head = dig;
			ans->tail = dig;
			
		}else{
			dig->prev = ans->tail;
			ans->tail->next = dig;
			ans->tail = ans->tail->next;
		
		}
		//printf("%d\n",dig->data);
		
		
	
	}
	if (carry!= 0){
		node *dig = (node*)malloc(sizeof(node));
		dig->data = carry;
		if(!ans->head){
			ans->head = dig;
			ans->tail = dig;
		}else{
			dig->prev = ans->tail;
			ans->tail->next = dig;
			ans->tail = dig;
			
		}
	
	}
	
	num** answer = (num**)malloc(sizeof(num*));
	*answer = ans;
	//print_LL(ans->head);
	return answer;
	


}


void eval(char *postfix, ll_stack stk){
	int i =0;
	
	while(postfix[i]!='\0'){
		
		if(isOperator(postfix[i])){
			num **op2 = (node**)malloc(sizeof(node*));
			num **op1 = (node**)malloc(sizeof(node*));
			num **ans = (node**)malloc(sizeof(node*));
			op2 = pop(&stk);	
			op1 = pop(&stk);
			
			ans = add(op1,op2);
			print_rev_LL((*ans)->tail);
			push(&stk, ans);
			i++;
		}else if(isOperand(postfix[i])){
			num *number = (num*)malloc(sizeof(num));
			number->sign = 0;
			number->head = NULL;
			number->tail = NULL;
			do{
				node *digit = (node*)malloc(sizeof(node));
				digit->data = (postfix[i])-'0';
				digit->next = NULL;
				digit->prev = NULL;
				if(!number->head){
					number->head = digit;
					number->tail = digit;
				
				}else{
					digit->prev = number->tail;
					number->tail->next = digit;
					
					number->tail = digit;
				}
				i++;
			}while(isOperand(postfix[i]));
			//print_LL(number->head);
			push(&stk, number);
			i++;
			
		
		}else{
		
			i++;
		
		}
			

	}
	return;
	

}




