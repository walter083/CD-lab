#include<stdio.h>
#include<string.h>
char inp[50];
int i=0,error=0;

void E();
void E_();
void T();
void T_();
void F();


int main(){
	printf("enter the string:");
	scanf("%s",inp);
	E();
	if(error==0 && inp[i]=='\0'){
		printf("valid expression\n");
	}
	else{
			printf("invalid expression\n");
	}	
	return 0;
}

void E(){
	T();    //1
	E_();
}
void E_(){
	if(inp[i]=='+'||inp[i]=='-'){
		i++;
		T();
		E_();
	}
}
void T(){
	F(); //2
	T_();//3
}
void T_(){
	if(inp[i]=='*'||inp[i]=='/'){
		i++;
		F();
		T_();
	}
}
void F(){
	if(inp[i]>='A' && inp[i]<='Z'|| inp[i]>='0' && inp[i]<='9'){
		i++;
	}
	else if( inp[i]=='('){
		i++;
		E();
		if( inp[i]==')'){
			i++;
		}
		else{
			error=1;
		}
	}
	else{
		error=1;
	}
}
