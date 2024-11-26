#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "infix_stack.h"
#include "ll_stack.h"

int main(){
	char infix[200];
	char temp[200] = "0";
	char *postfix;
	ll_stack stk;
	init_stack(&stk, 1000);
	
	
	printf("Binary Calculator\n");
	while(1){
	scanf("%s",infix);
	if(!strcmp(infix,"quit")){
		return 0;
	
	}else{
		if(infix[0]=='-'){
			strcat(temp,infix);
			strcpy(infix,temp);
		}
		postfix = infixToPostfix(infix);
		
		eval(postfix, stk);
	
	}
		
	}

}
