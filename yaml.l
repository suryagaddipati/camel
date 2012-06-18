%{
#include <stdlib.h>
#include "yaml.tab.h"
%}

%%
[0-9]+|[0-9]*\.[0-9]+   { yylval.dvalue = atof((char *)yytext); 
                          return NUMBER; 
                        }

[a-z0-9]                   { yylval.varindex = yytext[0] - 'a'; 
                          return NAME; 
                        }

[ \t]                   ;

\n|.                    { return yytext[0]; 
                        }
%%

