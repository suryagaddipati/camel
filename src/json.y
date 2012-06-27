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

%token<chr>  COLON LBRACE RBRACE QUOTE 
%token<str>   STR
%%
object : /*empty*/
       LBRACE STR              { printf("parsed successfully");  }
          ;

%%

main()
{

        yyparse();
}
