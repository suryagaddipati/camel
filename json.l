%{
#include <stdlib.h>
#include <stdio.h>
%}

%x COLON LBRACE RBRACE QUOTE TXT
%%
\{  {return LBRACE;}
\}  {return RBRACE;}
[a-z]+ {return TXT;} 
%%

