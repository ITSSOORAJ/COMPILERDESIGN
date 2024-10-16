Parser Simulation
Overview

This program simulates a parser for a given grammar, demonstrating how it processes input strings through a stack-based approach. The grammar used is:

mathematica

E -> E + E
E -> E * E
E -> (E)
E -> id

Input Example 1
Input String: id + id * id + id

Processing Steps:


stack      input          action
-----------------------------------
$id        +id*id+id$    SHIFT -> id
$E         +id*id+id$    REDUCE TO E
$E +       id*id+id$     SHIFT -> symbol +
$E + id    *id+id$       SHIFT -> id
$E + E     *id+id$       REDUCE TO E
$E         *id+id$       REDUCE TO E
$E *       id+id$        SHIFT -> symbol *
$E * id    +id$          SHIFT -> id
$E * E     +id$          REDUCE TO E
$E         +id$          REDUCE TO E
$E +       id$           SHIFT -> symbol +
$E + id    $             SHIFT -> id
$E + E     $             REDUCE TO E
$E         $             REDUCE TO E


 STRING ACCEPTED

Input Example 2
Input String: id * \

Processing Steps:

stack      input          action
-----------------------------------
$id        *\$           SHIFT -> id
$E         *\$           REDUCE TO E
$E *       \$            SHIFT -> symbol *
$E * \     $             SHIFT -> symbol \


 STRING REJECTED
