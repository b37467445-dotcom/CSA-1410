
%{
#include <stdio.h>
%}

%%
^(https?|ftp):\/\/[a-zA-Z0-9-]+(\.[a-zA-Z0-9-]+)+(:[0-9]+)?(\/[a-zA-Z0-9._~:/?#\[\]@!$&'()*+,;=%-]*)?\r?$ {
    printf("\nURL Valid\n");
}

^.*$ {
    printf("\nURL Invalid\n");
}
%%

int main()
{
    printf("\nEnter URL : ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
