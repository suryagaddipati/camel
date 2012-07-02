%{ 
#include <stdio.h>
#include <stdlib.h>


extern int yylex();

// better error reporting
#define YYERROR_VERBOSE

// bison requires that you supply this function
void yyerror(const char *msg)
{
      printf("ERROR(PARSER): %s\n", msg);
}

%}
%union {
     char *str;
     char chr;
      }

%token<chr>  COLON LBRACE RBRACE QUOTE COMMA 
%token<str>   STR
%%
object : /*empty*/
       LBRACE key_value_pairs RBRACE { printf("parsed successfully");  }
          ;

key_value_pairs: key_value_pair | 
               key_value_pairs COMMA key_value_pair 
              ;
key_value_pair: str COLON str
              ;
str: QUOTE STR QUOTE  
   ;

%%

main()
{

        yyparse();
}
