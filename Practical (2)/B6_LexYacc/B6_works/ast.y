//input (2+3+5*1-2);

%{
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #define YYSTYPE node*
 typedef struct node
 {
	struct node *left,*right;
	char *token;
 }node;
 node* mknode(node *left,node*right,char*token);
 void printTree(node *tree);
%}
%token NUMBER
%token PLUS MINUS MUL DIV
%token LP RP
%token END

%left PLUS MINUS
%left MUL DIV
%%
line1 : exp END {printf("The AST is:");
		 printTree($1);printf("\n");}
;
exp :  	term	{$$=$1;}
	| exp PLUS term     {$$=mknode($1,$3,"+");}
	| exp MINUS term    {$$=mknode($1,$3,"-");}
;
term : factor	{$$=$1;}
	| term MUL factor    {$$=mknode($1,$3,"*");}
	| term DIV factor    {$$=mknode($1,$3,"/");}
;
factor : NUMBER {char buf[10];snprintf(buf,sizeof(buf),"%d",yylval);$$=mknode(0,0,buf);}
	| LP exp RP {$$=$2;}
;
%%
int main()
{
	yyparse();
}
node* mknode(node *left,node*right,char* token)
{
	node* newNode=(node*)malloc(sizeof(node));
	char *newStr=(char*)malloc(sizeof(token)+1);
	strcpy(newStr,token);
	newNode->left=left;
	newNode->right=right;
	newNode->token=newStr;
	return (newNode);
}
void printTree(node *tree)
{
	if(tree->left||tree->right)
		printf("(");
	printf("%s ",tree->token);
	if(tree->left)
		printTree(tree->left);
	if(tree->right)
		printTree(tree->right);
	if(tree->left||tree->right)
		printf(")");
}
int yyerror(char *s)
{
	fprintf(stderr,"%s",s);
}
