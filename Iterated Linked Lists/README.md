# Work Report

## Name: <ins> Linn Khant Thuya </ins>

## Features:

- Not Implemented:
  - None

<br><br>

- Implemented:
  - iterator class nested inside list class
  - new list functions
  - tweaked old simple list functions

<br><br>

- Partly implemented:
  - None

<br><br>

- Bugs
  - None

<br><br>

# Reflections:

- It was an easy assignment. I learnt about nested classes.

<br/><br/>

# basic_test.cpp output:

<pre>
<br/><br/>


----------running basic_test.cpp---------


[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from ITERATED_LIST
[ RUN      ] ITERATED_LIST.TestInsertHead
list.empty(): true
[100]->[1]->[10]->|||

[200]->[2]->[20]->[100]->[1]->[10]->|||

[300]->[3]->[30]->[200]->[2]->[20]->[100]->[1]->[10]->|||

[400]->[4]->[40]->[300]->[3]->[30]->[200]->[2]->[20]->[100]->[1]->[10]->|||

[500]->[5]->[50]->[400]->[4]->[40]->[300]->[3]->[30]->[200]->[2]->[20]->[100]->[1]->[10]->|||

found 4: 4
previous to 4: 400
deleted the prev: [500]->[5]->[50]->[4]->[40]->[300]->[3]->[30]->[200]->[2]->[20]->[100]->[1]->[10]->|||


iterating all the nodes:
500 5 50 4 40 300 3 30 200 2 20 100 1 10
list.empty(): false


--------- D O N E ----------------
[       OK ] ITERATED_LIST.TestInsertHead (29 ms)
[----------] 1 test from ITERATED_LIST (31 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (32 ms total)
[  PASSED  ] 1 test.
<br/><br/>
</pre>

# testB.cpp output:

<pre>
<br/><br/>

----------running testB.cpp---------


[==========] Running 3 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 3 tests from TEST_LIST
[ RUN      ] TEST_LIST.testCTOR
[       OK ] TEST_LIST.testCTOR (0 ms)
[ RUN      ] TEST_LIST.testInsert
[       OK ] TEST_LIST.testInsert (0 ms)
[ RUN      ] TEST_LIST.testOperators
[       OK ] TEST_LIST.testOperators (0 ms)
[----------] 3 tests from TEST_LIST (1 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test suite ran. (11 ms total)
[  PASSED  ] 3 tests.
<br/><br/>
</pre>

# main.cpp output:

<pre>
<br/><br/>

=====================

{19}->[0]->[34]->[17]->[41]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P] Previous [N] Next [H]ome [E]nd b
: 1
{1}->[19]->[0]->[34]->[17]->[41]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P] Previous [N] Next [H]ome [E]nd d
{19}->[0]->[34]->[17]->[41]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P] Previous [N] Next [H]ome [E]nd n
[19]->{0}->[34]->[17]->[41]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P] Previous [N] Next [H]ome [E]nd n
[19]->[0]->{34}->[17]->[41]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P] Previous [N] Next [H]ome [E]nd n
[19]->[0]->[34]->{17}->[41]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P] Previous [N] Next [H]ome [E]nd n
[19]->[0]->[34]->[17]->{41}->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P] Previous [N] Next [H]ome [E]nd n
[19]->[0]->[34]->[17]->{41}->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P] Previous [N] Next [H]ome [E]nd d
{19}->[0]->[34]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P] Previous [N] Next [H]ome [E]nd d
{0}->[34]->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P] Previous [N] Next [H]ome [E]nd d
{34}->[17]->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P] Previous [N] Next [H]ome [E]nd d
{17}->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P] Previous [N] Next [H]ome [E]nd d
|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P] Previous [N] Next [H]ome [E]nd d
|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P] Previous [N] Next [H]ome [E]nd b
: 33
{33}->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P] Previous [N] Next [H]ome [E]nd d
|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P] Previous [N] Next [H]ome [E]nd a
: 5
{5}->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P] Previous [N] Next [H]ome [E]nd d
|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P] Previous [N] Next [H]ome [E]nd r
{24}->|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P] Previous [N] Next [H]ome [E]nd d
|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P] Previous [N] Next [H]ome [E]nd n
|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P] Previous [N] Next [H]ome [E]nd p
|||
[R]andom [A]fter [B]efore [D]elete [S]earch [P] Previous [N] Next [H]ome [E]nd x

=====================
<br/><br/>
</pre>
