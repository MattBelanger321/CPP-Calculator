#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <cmath>

#define MAX 10

//Prototypes
void compute(char eqn[]);
void populate(int *num1,char *op,int *num2,char eqn[]);
int getInt(char num[]);
int power = 0;

using namespace std;
int main(){
  	cout << "Welcome to Calculator 1.0\n";
  	while(true){
	  	cout << "Enter a two integer equation (+,-,*,/)> ";
	  	char equation[MAX];
		cin.getline(equation,10,'\n');
		
		compute(equation);
	}
}

void compute(char eqn[]){
	int num1,num2;	//equation argumentsd
	char op;	//equation operation
	
	populate(&num1,&op,&num2,eqn);
	double aws;
	switch(op){
		case '+':
			aws = num1 + num2;
			break;
		case '-':
			aws = num1 - num2;
			break;
		case '*':
			aws = num1*num2;
			break;
		case '/':
			if(num2 == 0){
				cerr<<"Divison by 0";
				exit(EXIT_FAILURE);
			}
			aws = num1/num2;
			break;
		default:
			cerr << "INVALID OPERATION";
			exit(EXIT_FAILURE);
			break;
	}
	
	cout << eqn << " = " << aws << '\n';
}

void populate(int *num1,char *op,int *num2,char eqn[]){
	*num1 = 0;
	*num2 = 0;
	*op = ' ';
	int offset = 0;
	int flip = 0;
	if(eqn[0] == '-'){
		offset++;
	}
	if(isdigit(eqn[offset])){
		*num1 = getInt(eqn+offset);
		power = 0;
		if(offset != 0){
			*num1 *= -1;
			flip = 1;
		}
	}else{
		cerr << "Illegal Integer Format";
		exit(EXIT_FAILURE);
	}
	offset = (*num1!=0?floor(log10(abs(*num1))) + 1:1) + flip;
	
	
	if(eqn[offset] == ' '){
		offset++;
	}
	
	*op = eqn[offset++];
	
	if(eqn[offset] == ' '){
		offset++;
	}
	offset += (flip = eqn[offset] == '-')?1:0;
	
	char *num = eqn + offset;
	if(isdigit(num[0])){
		*num2 = getInt(num);
		*num2 *= flip?-1:1;
		power = 0;
	}else{
		cerr << "Illegal Integer Format";
		exit(EXIT_FAILURE);
	}
	
}

int getInt(char num[]){
	if(isdigit(num[0])){
		return getInt(num + 1) + pow(10,power++)*(num[0] - 48);
	}else{
		return 0;
	}
}

