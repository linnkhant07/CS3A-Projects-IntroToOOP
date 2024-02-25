# Work Report

## Name: <ins> Linn Khant Thuya </ins>

## Features:

- Not Implemented:
  - None

<br><br>

- Implemented:
  - node class
  - linked_list functions
  - list_simple.h classes
  - testing interface in main

<br><br>

- Partly implemented:
  - None

<br><br>

- Bugs
  - None

<br><br>

# Reflections:

- I learnt about linked lists. This is a lot easier than polynomials.

# basic_test.cpp output:

<pre>
<br/><br/>
----------running testA.cpp---------


[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from BASIC_TEST
[ RUN      ] BASIC_TEST.BasicTest
list.empty(): true
[100]->[1]->[10]->|||

[200]->[2]->[20]->[100]->[1]->[10]->|||

[300]->[3]->[30]->[200]->[2]->[20]->[100]->[1]->[10]->|||

[400]->[4]->[40]->[300]->[3]->[30]->[200]->[2]->[20]->[100]->[1]->[10]->|||

[500]->[5]->[50]->[400]->[4]->[40]->[300]->[3]->[30]->[200]->[2]->[20]->[100]->[1]->[10]->|||

found 4: [4]->
previous to 4: [400]->
deleted the prev: [500]->[5]->[50]->[4]->[40]->[300]->[3]->[30]->[200]->[2]->[20]->[100]->[1]->[10]->|||


iterating all the nodes:
[500]-> [5]-> [50]-> [4]-> [40]-> [300]-> [3]-> [30]-> [200]-> [2]-> [20]-> [100]-> [1]-> [10]->
list.empty(): false


-------- DONE ---------


[       OK ] BASIC_TEST.BasicTest (15 ms)
[----------] 1 test from BASIC_TEST (16 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (17 ms total)
[  PASSED  ] 1 test.
<br/><br/>
</pre>

# testB.cpp output:

<pre>
<br/><br/>
----------running testB.cpp---------


[==========] Running 10 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 10 tests from TEST_STUB
[ RUN      ] TEST_STUB.TestNodeInsertion
[       OK ] TEST_STUB.TestNodeInsertion (0 ms)
[ RUN      ] TEST_STUB.TestInsertHead
[       OK ] TEST_STUB.TestInsertHead (0 ms)
[ RUN      ] TEST_STUB.TestInsertAfter
[       OK ] TEST_STUB.TestInsertAfter (0 ms)
[ RUN      ] TEST_STUB.TestPreviousNode
[       OK ] TEST_STUB.TestPreviousNode (0 ms)
[ RUN      ] TEST_STUB.TestDeleteNode
[       OK ] TEST_STUB.TestDeleteNode (0 ms)
[ RUN      ] TEST_STUB.TestInsertBefore
[       OK ] TEST_STUB.TestInsertBefore (0 ms)
[ RUN      ] TEST_STUB.TestCopyList
[       OK ] TEST_STUB.TestCopyList (0 ms)
[ RUN      ] TEST_STUB.TestCopyList2
[       OK ] TEST_STUB.TestCopyList2 (0 ms)
[ RUN      ] TEST_STUB.TestPrintBackwards
[       OK ] TEST_STUB.TestPrintBackwards (0 ms)
[ RUN      ] TEST_STUB.TestInsertSorted
Before inserting 21: [9]->[13]->[22]->[23]->[24]->[77]->|||
[21]-> was inserted
[9]->[13]->[21]->[22]->[23]->[24]->[77]->|||
Before inserting 8: [9]->[13]->[21]->[22]->[23]->[24]->[77]->|||
[8]-> was inserted
[8]->[9]->[13]->[21]->[22]->[23]->[24]->[77]->|||
Before inserting 99: [8]->[9]->[13]->[21]->[22]->[23]->[24]->[77]->|||
[99]-> was inserted
[8]->[9]->[13]->[21]->[22]->[23]->[24]->[77]->[99]->|||
[       OK ] TEST_STUB.TestInsertSorted (18 ms)
[----------] 10 tests from TEST_STUB (23 ms total)

[----------] Global test environment tear-down
[==========] 10 tests from 1 test suite ran. (25 ms total)
[  PASSED  ] 10 tests.
<br/><br/>
</pre>

# main.cpp output:

<pre>
<br/><br/>
=====================



{19}->[0]->[34]->[17]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd b
: 1
{1}->[19]->[0]->[34]->[17]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd p
{1}->[19]->[0]->[34]->[17]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd n
[1]->{19}->[0]->[34]->[17]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd n
[1]->[19]->{0}->[34]->[17]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd n
[1]->[19]->[0]->{34}->[17]->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd n
[1]->[19]->[0]->[34]->{17}->[41]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd n
[1]->[19]->[0]->[34]->[17]->{41}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd n
[1]->[19]->[0]->[34]->[17]->{41}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd d
{1}->[19]->[0]->[34]->[17]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd d
{19}->[0]->[34]->[17]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd d
{0}->[34]->[17]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd e
[0]->[34]->{17}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd d
{0}->[34]->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd d
{34}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd d
|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd d
|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd n
|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd p
|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd r
{24}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd d
|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd a
: 33
{33}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd d
|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd b
: 30
{30}->|||
[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd x



=====================
<br/><br/>
