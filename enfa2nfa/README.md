### e-NFA TO NFA
** enter the number of alphabets? **

3

NOTE:- [ use letter e as epsilon]

NOTE:- [e must be last character ,if it is present]



Enter alphabets?

a

b

e

Enter the number of states?

5

Enter the start state?

1

Enter the number of final states?

1

Enter the final states?

3

Enter no of transition?

7

NOTE:- [Transition is in the form--> qno   alphabet   qno]

NOTE:- [States number must be greater than zero]


Enter transition?

1 a 2

1 e 3

2 a 1

3 b 4

4 b 3

3 a 5

5 b 3

Equivalent NFA without epsilon
-----------------------------------

start state:{q1,}	

Alphabets:a b e 

States :{q1,}	{q2,}	{q3,}	{q4,}	{q5,}	

Transitions are...:


{q1,}	a	{q2,q5,}

{q1,}	b	{q4,}

{q2,}	a	{q1,q3,}

{q2,}	b	{}

{q3,}	a	{q5,}

{q3,}	b	{q4,}

{q4,}	a	{}

{q4,}	b	{q3,}

{q5,}	a	{}

{q5,}	b	{q3,}

Final states:{q1,}	{q3,}	 
