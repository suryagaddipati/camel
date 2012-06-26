%{
#include <stdlib.h>
#include <stdio.h>
#include "json.tab.h"
%}

%%
\{  {return LBRACE;}
\}  {return RBRACE;}
(.)+ {
     yytext;
    return TXT;
    } 
%%

