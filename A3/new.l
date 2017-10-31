%{
#include<stdio.h>
int insert(char[]);
int cnt=0,line=1;
struct st{
int val;
char name[25];
}*symbol[50];
%}

%%
"+" |
"/" |
"-" |
"*" printf("%s is arithmetic operator\n",yytext);

"return" |
"if" |
"while" |
"do" |
"for" |
"switch" printf("%s is keyword\n",yytext);

"#include" printf("%s is Preprocessing directive\n",yytext);

"<"(.)*.h">" printf("%s is header file\n",yytext);

int|float|double|char|long|void printf("%s is data type\n",yytext);

[#%^&{};><()=",.] printf("%s is symbol\n",yytext);

scanf|printf|main printf("%s is library function\n",yytext) ;

"/*"(.|\n)*"*/" printf("%s is multiline comment\n",yytext);

"%d" |
"%c" |
"%s" |
"%f" |
"%u" printf("%s is format specifier\n",yytext);

\"[ a-zA-Z0-9\%\\\-]*\" printf("%s is STRING constant\n",yytext);

"//"(.)* printf("%s is single line comment\n",yytext);

[a-zA-Z_][a-zA-Z0-9]* printf("%s is identifier %d\n",yytext,insert(yytext));

\'[ a-zA-Z0-9]\' printf("%s is CHARACTER constant\n",yytext);

[0-9]+ printf("%s is INTEGER constant\n",yytext) ;

[0-9]+\.[0-9]+ printf("%s is REAL constant\n",yytext) ;

" " ;

"\n" {line++;}
%%

int main(){
yyin = fopen("myfile.c","r");
yylex();
fclose(yyin);
printf("NAME\t\tVALUE\n");
for(int i=0;i<cnt;i++){
	printf("%s\t\t%d\n",symbol[i]->name,symbol[i]->val);
}

}

int yywrap(){
	return 1;
}

int yyerror(){
printf("Error\n");
}
int insert(char name[]){

for(int i=0;i<cnt;i++){
	if(strcmp(name,symbol[i]->name)==0)
		return i;
}
	symbol[cnt]=(struct st*)malloc(sizeof(struct st));
	strcpy(symbol[cnt]->name,name);
	symbol[cnt]->val=0;

cnt++;
return cnt;
}




/*
OUTPUT


dell@dell-Inspiron-3542:~$ lex new.l
dell@dell-Inspiron-3542:~$ gcc lex.yy.c
dell@dell-Inspiron-3542:~$ ./a.out
#include is Preprocessing directive
<stdio.h> is header file
int is data type
main is library function
( is symbol
) is symbol
{ is symbol
int is data type
a1 is identifier 1
= is symbol
5 is INTEGER constant
; is symbol
int is data type
b is identifier 2
; is symbol
scanf is library function
( is symbol
"%d" is STRING constant
, is symbol
& is symbol
a is identifier 3
) is symbol
; is symbol
int is data type
c is identifier 4
= is symbol
a is identifier 2
* is arithmetic operator
b is identifier 1
; is symbol
int is data type
c is identifier 3
= is symbol
10 is INTEGER constant
; is symbol
while is keyword
( is symbol
2 is INTEGER constant
) is symbol
{ is symbol
	printf is library function
( is symbol
"HELLO\n" is STRING constant
) is symbol
; is symbol
} is symbol
return is keyword
0 is INTEGER constant
; is symbol
} is symbol
NAME		VALUE
a1		0
b		0
a		0
c		0


*/
