❯ ./a.out

GRAMMAR is 
 E->E+E 
 E->E*E 
 E->(E) 
 E->id 

Enter input string : id+id*id+id

stack      input     action

$id        +id*id+id$    SHIFT->id

$E         +id*id+id$    REDUCE TO E

$E+         id*id+id$    SHIFT->symbol +

$E+id        *id+id$    SHIFT->id

$E+E         *id+id$    REDUCE TO E

$E           *id+id$    REDUCE TO E

$E*           id+id$    SHIFT->symbol *

$E*id           +id$    SHIFT->id

$E*E            +id$    REDUCE TO E

$E              +id$    REDUCE TO E

$E+              id$    SHIFT->symbol +

$E+id              $    SHIFT->id

$E+E               $    REDUCE TO E

$E                 $    REDUCE TO E


STRING ACCEDPTED

GRAMMAR is 

 E->E+E 
 
 E->E*E 
 
 E->(E) 
 
 E->id 


Enter input string : id*\

stack 	 input 	 action


$id	  *\$	SHIFT->id

$E	  *\$	REDUCE TO E

$E*	   \$	SHIFT->symbol *

$E*\	    $	SHIFT->symbol \

STRING REJECTED
