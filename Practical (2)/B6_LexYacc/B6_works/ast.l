%{
 #include "y.tab.h"
 extern int yylval;
%}
%%
[0-9]+ {yylval=atoi(yytext);return NUMBER;}
[\t\n]+ ;
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
"(" {return LP;}
")" {return RP;}
";" {return END;}
%%
int yywrap()
{
	return 1;
}
