



**#######output sample#########**
 **Enter the no of states:** 3

 **Enter the states** 
q1
q2
q3

 **Enter the number of transitions:** 5   

**Enter the transitions (state1 input state2):**
q1 0 q1
q1 e q2
q2 1 q2
q2 e q3
q3 0 q3

 Epsilon closure of q1 = {  q1 q2 q3 } 

 Epsilon closure of q2 = {  q2 q3 } 

 Epsilon closure of q3 = {  q3 } 


**BRIEF**

**Input Phase**
>Number of states: The user is prompted to enter the total number of states in the Finite Automata (FA).
>.State names: The user is prompted to enter the names of the states.
>Number of transitions: The user is prompted to enter the total number of transitions in the FA.
>Transitions: The user is prompted to enter the transitions in the format state1 input state2.
**Epsilon Closure Calculation**
>Iterate over each state: The process iterates through each state in the FA.
>Initialize epsilon closure: For the current state, an empty set is initialized to store the epsilon closure.
>Add initial state: The current state is added to the epsilon closure set.
>Explore epsilon transitions: The code checks for epsilon transitions from the current state. If found, the destination state is added to the epsilon closure and the process is recursively applied to the new state.
>Print epsilon closure: Once all epsilon transitions are explored, the epsilon closure for the current state is printed.
