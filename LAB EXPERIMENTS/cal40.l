
%{
#include <stdio.h>
#include <stdlib.h>

float op1, op2, ans;
char oper;
int count = 0;

void eval();
%}

DIGIT [0-9]
NUM {DIGIT}+(\.{DIGIT}+)?
OP [*/+-]

%%
{NUM} {
    if(count == 0)
    {
        op1 = atof(yytext);
        count = 1;
    }
    else
    {
        op2 = atof(yytext);
        eval();
        count = 0;
    }
}

{OP} {
    oper = yytext[0];
}

[ \t]+ ;

\n ;

. ;
%%

int main()
{
    printf("Enter mathematical expression:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}

void eval()
{
    switch(oper)
    {
        case '+':
            ans = op1 + op2;
            break;

        case '-':
            ans = op1 - op2;
            break;

        case '*':
            ans = op1 * op2;
            break;

        case '/':
            if(op2 == 0)
            {
                printf("ERROR: Division by zero\n");
                return;
            }
            ans = op1 / op2;
            break;

        default:
            printf("Operation not available\n");
            return;
    }

    printf("The answer is = %lf\n", ans);
}
