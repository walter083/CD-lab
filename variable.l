%{
    #include<stdio.h>
%}
%%
(int|float|bool|char)(" ")+("*")*([A-Za-z_][_A-Za-z0-9]*)(([)([0-9])*(]))*((",")(" ")*+("*")*([A-Za-z_][_A-Za-z0-9]*)(([)([0-9])*(]))*)*(;) {printf("valid"); exit(0);}
(.)* {printf("invalid"); exit(0);}    
%%

int yywrap(){
    return 0;
}

int main(){
    printf("enter the string: ");
    yylex();
}

