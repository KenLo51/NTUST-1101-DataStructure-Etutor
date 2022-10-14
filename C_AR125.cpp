#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
typedef union node{//store numbers and operation.
	float num;
	unsigned long sign;//if a Node store an operation than it num is NaN
}Node;
void swap(char *a, char *b){
	*b = *a ^ *b;
	*a = *a ^ *b;
	*b = *a ^ *b;
}

#define charIsNum(x) ((x>='0')&&(x<='9'))
float str2float(char *ch, char *len){
	char ch_ptr,temp;
	float result,exp;
	temp = ch_ptr = 0 ;
	result = 0 ;
	while( (ch[ch_ptr] != '\0')&&charIsNum(ch[ch_ptr]) ){
		result = (result*10) + (ch[ch_ptr]-'0');
		ch_ptr = ch_ptr + 1;//next character
	}//compute the part of integer
	if( ch[ch_ptr] == '.' ){//if the string has decimal point
		ch_ptr = ch_ptr + 1;//next character
		exp = 1 ;
		while( (ch[ch_ptr] != '\0')&&charIsNum(ch[ch_ptr]) ){
			exp = exp * 10 ;
			result = result + ( (float)(ch[ch_ptr]-'0') / exp ) ;
			ch_ptr = ch_ptr + 1;//next character
		}//compute the part of decimal
	}
	*len = ch_ptr;//return the length of this number in the string
	return result;//return the number
}
void float2str(float f,char *ch,char len) {//unuse in this project
	char i,ch_ptr;
	float temp;
	temp = f;
	for(;temp>=1;temp=temp/10)
		i++;
	if(i==0){
		ch[0] = '0';
		ch_ptr = 1;
	}
	else{
		ch_ptr = i;
		temp = f;
		for(;i>0;i--){
			ch[i-1] = (int)(temp)%10 +'0';
			temp = temp/10;
		}
	}
	ch[ch_ptr] = '.';
	temp = f;
	ch_ptr++;
	len = len - ch_ptr;
	for(i=0;i<len;i++){
		temp = temp*10;
		ch[ch_ptr] = ((int)(temp)%10) +'0';
		ch_ptr++;
	}
	for(i=len+2;ch[i]=='0';i--)
		ch[i]=' ';
	ch[len] = '\0';
}


char getPriority(char ch){
	switch(ch){
		case '+':
		case '-':
			return 0;
		case '*':
		case '/':
			return 1;
	}
	return 0;
}
#define Stack_Size 9
Node stack[Stack_Size];
char formula2postorder(char *ch, char op_ptr_max, char num_ptr_min){//return the pointer of num_stack
	char ch_ptr;
	char l;//to store the string length that functions which called are already processed

	char op_ptr,num_ptr;
	ch_ptr = 0;
	op_ptr = op_ptr_max ;	num_ptr = num_ptr_min ;//stack initalize
	while( ch[ch_ptr]!='\0' ){
		if( charIsNum(ch[ch_ptr]) ){
			num_ptr = num_ptr + 1;
			stack[num_ptr].num = str2float(&ch[ch_ptr], &l);//push a float number to the postOrder_stack 
			ch_ptr = ch_ptr + l;//pointer jump to the next character
		} 
		else if( ch[ch_ptr] == ')' ){
			while( (stack[op_ptr].sign&0xff) != '(' ){
				num_ptr = num_ptr + 1 ;
				stack[num_ptr] = stack[op_ptr] ;
				op_ptr = op_ptr + 1;
			}
			op_ptr = op_ptr + 1;
			ch_ptr = ch_ptr + 1;
		}
		else if( ch[ch_ptr] == '(' ){
			op_ptr = op_ptr - 1 ;
			stack[op_ptr].sign = 0xffffff00 |  ch[ch_ptr] ;
			ch_ptr = ch_ptr + 1;
		}
		else if( (ch[ch_ptr] == '+')||(ch[ch_ptr] == '-')||(ch[ch_ptr] == '*')||(ch[ch_ptr] == '/') ){
			while( (getPriority(stack[op_ptr].sign&0xff) >= getPriority(ch[ch_ptr])) && (op_ptr != op_ptr_max) && ((stack[op_ptr].sign&0xff)!='(') ){//if stack
				num_ptr = num_ptr + 1 ;
				stack[num_ptr] = stack[op_ptr] ;
				op_ptr = op_ptr + 1 ;
			}
			if(((ch_ptr == 0)||(ch[ch_ptr-1] == '('))&&(ch[ch_ptr] == '-')){
				num_ptr = num_ptr + 1;
				stack[num_ptr].num = 0;
			}
			op_ptr = op_ptr - 1 ;
			stack[op_ptr].sign = 0xffffff00 |  ch[ch_ptr] ;
			ch_ptr = ch_ptr + 1;//next character
		}
		else{
			ch_ptr = ch_ptr + l;
		}
	}
	while( op_ptr != op_ptr_max ){
		num_ptr = num_ptr + 1;
		stack[num_ptr] = stack[op_ptr];
		op_ptr = op_ptr + 1;
	}//push the remaining Node from op_stack to postOrder_stack 
	return num_ptr;
}

float calculate(char stack_ptr){//calculate the formula that has cvt to postorder
	char i,j;
	i = 0 ;
	while(stack_ptr>0){
		if((stack[i].sign>>8)==0xffffff){//stack[i] is an operation
			switch(stack[i].sign&0xff){
				case '+':
					stack[i-2].num = stack[i-2].num + stack[i-1].num;
					break;
				case '-':
					stack[i-2].num = stack[i-2].num - stack[i-1].num;
					break;
				case '*':
					stack[i-2].num = stack[i-2].num * stack[i-1].num;
					break;
				case '/':
					stack[i-2].num = stack[i-2].num / stack[i-1].num;
					break;
			}
			for(j=i-1;j<=stack_ptr-2;j++){
				stack[j] = stack[j+2];
			}
			stack_ptr = stack_ptr - 2;
			i--;
		}
		else
			i++;
	}
	return stack[0].num;
}

void StrAddChar(char *ch1, char ch2){//add a character to the last of string
	char i;
	for(i=0;ch1[i]!='\0';i++);//find the length of string
	ch1[i] = ch2;
	i++;
	ch1[i]='\0';
}
void StrPopChar(char *ch1){//remove a character to the last of string
	char i;
	for(i=0;ch1[i]!='\0';i++);//find the length of string
	i--;
	ch1[i]='\0';
}
#define charIsNum(x) ((x>='0')&&(x<='9'))



void clearStr(char*str,char len){
	char i;
	for(i=0;i<len;i++){
		str[i]=' ';
	}
	str[i]='\0';
}

void stringAdj(char *ch){//remove lase character '0' or '.' if it was float, and the output of sprintf always has '.'
	char i;
	for(i=0;ch[i]!='\0';i++);
	i--;
	for(;(ch[i]=='0')||(ch[i]==' ');i--)
		ch[i] = '\0';
	if(ch[i]=='.')
		ch[i] = '\0';
}
int main(){
	char in_matrix[3][3];
	for(int row=0; row<3; row++){
		for(int col=0; col<3; col++){
			cin>>in_matrix[row][col];
		}
	}
	/*for(int row=0; row<3; row++){
		for(int col=0; col<3; col++){
			printf("(%d, %d):%c\n", row, col, in_matrix[row][col]);
		}
	}*/
	
	int result = 0;
	for(int i=0; i<4;i++){
		//roatation matrix
		//printf("\nrotating matrix\n");
		swap(&(in_matrix[0][0]), &(in_matrix[0][2]));
		swap(&(in_matrix[2][0]), &(in_matrix[0][0]));
		swap(&(in_matrix[2][2]), &(in_matrix[2][0]));
		
		swap(&(in_matrix[0][1]), &(in_matrix[1][2]));
		swap(&(in_matrix[1][0]), &(in_matrix[0][1]));
		swap(&(in_matrix[2][1]), &(in_matrix[1][0]));
		
		//for(int row=0; row<3; row++){
		//	printf("%c %c %c\n", in_matrix[row][0], in_matrix[row][1], in_matrix[row][2]);
		//}
		
		bool break_flag=0;
		char formula[10]={'\0'};
		for(int j=0; j<9; j++){
			formula[j] = in_matrix[j%3][j/3];
			if(!charIsNum(formula[j]) && !charIsNum(formula[j-1])) break_flag = 1;
		}
		//printf("%d, %s", break_flag, formula);
		if(!charIsNum(formula[0]) || !charIsNum(formula[8])) break_flag = 1;
		if(break_flag) continue;

		char p = formula2postorder(formula,Stack_Size,-1);
		int result_temp = int(calculate(p));
		//printf("=%d", result_temp);
		if(result_temp > result)	result = result_temp;
	}
	printf("%d\n", result);
	//char p = formula2postorder("2/2/2",Stack_Size,-1);
	//printf("%f", calculate(p));
}
