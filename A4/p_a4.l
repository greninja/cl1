%{
#include "y.tab.h"
%}

%%
[ \t\n]+	;
main	{return MAIN;}
int|float|char|double	{return DT;}
for	{return FOR;}
if 	{return IF;}
[0-9]+	{return NUM;}
[a-zA-Z][a-zA-Z0-9]*    {return ID;}
\<|\>|\=\=|\>\=|\<\=	{return REOP;}
. {return yytext[0];}
%%
