**#######output sample#########**

**Enter the no of states:** 3

**Enter the states**
q1
q2
q3

**Enter the number of transitions:** 5    

**Enter the transitions (state1 input state2):**
q1  \t 0  \t q1
q1  \t e  \t q2
q2  \t 1  \t q2
q2  \t e  \t q3
q3  \t 0  \t q3

Epsilon closure of q1 = {  q1 q2 q3 }

Epsilon closure of q2 = {  q2 q3 } 

Epsilon closure of q3 = {  q3 }
