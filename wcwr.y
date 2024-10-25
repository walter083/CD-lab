%{
#include<stdio.h>
#include<stdlib.h>
int yylex(void);
void yyerror(char *s);
%}
%token A B C
%%
input:S '\n'{
	printf("the expression is valid\n");
	return 0;
};
S:A S A
  |B S B
  |C
  ;
%%
#include "lex.yy.c"
int main(){
	printf("enter the expression:");
	return yyparse();
}
void yyerror(char *s){
	printf("%s \n",s);
}
