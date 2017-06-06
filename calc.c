#include <stdio.h>
#include "operators.h"
#include "my_fscanf.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	int result, line = 0;
	int i;	

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		my_fscanf(fp, "%d", &line);
		for(i=0; i<line && !feof(fp); i++) {
			my_fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				result = add(operand1, operator);
				break;
				case '-':
				result = minus(operand1, operator);
				break;
				case '*':
				result = mul(operand1, operator);
				case '/':
				result = div(operand1, operator);
				break;
			}		
			printf("%d %c %d = %d\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

