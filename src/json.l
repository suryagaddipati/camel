%{
#include <stdlib.h>
#include <stdio.h>
#include "json.tab.h"
%}

%%
\{ {return LBRACE;}
\}  {return RBRACE;}
:  {return COLON;}
([a-z]|[0-9]|[A-Z])+ {
    return STR;
    } 
%%

