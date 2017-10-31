//http://vipinnpillai.blogspot.in/2011/10/recursive-descent-parser-using-c_17.html

//E -> E+T | T
//T -> T*F | F
//F -> (E) | id


//a+(a*a), a+a*a , (a), a , a+a+a*a+a....

//E -> TE'
//E' -> +TE' | ε
//T -> FT'
//T' -> *FT' | ε
//F -> (E) | id



#include<stdio.h> 
#include<string.h> 
#include<ctype.h> 

char input[10]; 
int i,error; 

void E(); 

void T(); 

void Eprime(); 

void Tprime(); 

void F(); 

 main() 
{ 

i=0; 
error=0 ;
	  printf("Enter an arithmetic expression   :  "); 
	   scanf("%s",&input[i]); 
	   E(); 
	   if(strlen(input)==i&&error==0) 
		printf("\n Accepted..!!!\n"); 
		else printf("\n Rejected..!!!\n"); 
  } 
void E() 
{ 

     T(); 
    Eprime(); 
} 

void Eprime(){ 
    if(input[i]=='+'){ 
        i++; 
        T(); 
        Eprime(); 
    } 
} 

void T(){ 

    F(); 
    Tprime(); 
} 

void Tprime(){ 

     if(input[i]=='*'){ 
          i++; 
          F(); 
          Tprime(); 
      } 
} 

void F(){ 
    if(isalnum(input[i]))i++; 

    else if(input[i]=='(') 
    { 
    	 i++; 
    	 E(); 

              if(input[i]==')') 
    	           i++; 
    	       else 
                 error=1; 
    } 
    else 
      error=1; 
} 
 
