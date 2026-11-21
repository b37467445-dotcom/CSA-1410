
%{
#include <stdio.h>
%}

%%
[A-Z]+      { printf("%s is a capital word\n", yytext); }
[ \t\n]+    ;
.           ;
%%

int main()
{
    printf("Enter String:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}