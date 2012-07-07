%option noyywrap
%option nodefault //do not add default ignore rule
%{
#include <stdlib.h>
#include <stdio.h>
#include "json.tab.h"
%}

%%
\{ {return LBRACE;}
\}  {return RBRACE;}
:  {return COLON;}
\" { return QUOTE;}
, {return COMMA;}
([a-z]|[0-9]|[A-Z])+ {
    return STR;
    } 
%%

