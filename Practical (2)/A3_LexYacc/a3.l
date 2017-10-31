%{
#include <stdio.h>
#include <string.h>
int lno=1;
FILE* opfile;
char name[20][20];
int cnt=0;
%}

%%

[0-9]+   {printf("%d   %s                 NUMBER\n",lno++,yytext); fprintf(opfile,"%d %s ",lno, yytext);}
[-+*/]   {printf("%d   %s                 OPERATOR\n",lno++,yytext); fprintf(opfile,"%d %s ",lno, yytext);}
=        {printf("%d   %s                 ASSIGNMENT\n",lno++,yytext); fprintf(opfile,"%d %s ",lno, yytext);}

%%

main()
{
char ifile[100],ofile[100];
printf("\nEnter input file name:     ");
scanf("%s",ifile);
yyin=fopen(ifile,"r");


printf("\nEnter output file name:     ");
scanf("%s",ofile);
opfile=fopen(ofile,"w");


printf("Line No     LEXEME                       Token\n");
fprintf(opfile, "LEXEME       Token\n");
yylex();


}
int yywrap()
{
return 1;
}

