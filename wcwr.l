%{
%}
%%
a	{return A;}
b	{return B;}
c	{return C;}
\n	{return '\n';}
.	{return yytext[0];}
%%
int yywrap(){return 1;}
