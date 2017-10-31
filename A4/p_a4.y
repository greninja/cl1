%{
#include<stdio.h>
#include<string.h>
extern FILE *yyin;
int yylex();
void yyerror();
int yyparse();
%}

%token MAIN IF FOR ID NUM DT REOP
%left '+' '-'
%left '*' '/'
%start prg

%%
prg : MAIN '('')''{' s '}'	{printf("Program is valid\n");}
	;
s : stmt s
    |
    ;
   
stmt : DT assignstmt
	| expr ';' {printf("It is a valid statement\n");}
	| ifstmt
	| forstmt	
	| ID '=' expr ';'{printf("It is a valid statement\n");}
	;

expr:	 expr '+' expr {}
	| expr '-' expr {}
	| expr '/' expr {}
	| expr '*' expr {}
	| ID 		{}
	;

ifstmt : IF '(' condition ')' '{' stmt '}' {printf("IF Statement\n");}
	;
	
condition:expr REOP expr {}
	;

forstmt: FOR '('assignstmt ';' condition ';' incdec ')' '{' stmt '}' {printf("FOR Statement\n");}
	;
incdec : ID '+''+' {}
	| ID '-''-' {}
	;
		

assignstmt : ID '=' expr {}
	    | ID '=' NUM {}	
	    ;
%%

int main(){
yyin =fopen("myfile.c","r");
yyparse();
return 0;
}
/*
int yyparse(){
	return 1;
}*/

void yyerror(){
	printf("Error\n");
}
