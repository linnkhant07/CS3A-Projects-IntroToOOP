# Work Report

## Name: <ins> Linn Khant Thuya </ins>

## Features:

- Not Implemented:
  - None

<br><br>

- Implemented:
  - Stack & Queue classes using linked lists

<br><br>

- Partly implemented:
  - None

<br><br>

- Bugs
  - None

<br><br>

# Reflections:

- Fairly easy. Understanding the concept in the class helped.

<br/><br/>

# basic_test.cpp output:

<pre>
<br/><br/>

----------running testA.cpp---------


[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from ITERATED_LIST
[ RUN      ] ITERATED_LIST.TestInsertHead
stack.push(): 
[0]->||| size: [1]
[1]->[0]->||| size: [2]
[2]->[1]->[0]->||| size: [3]
[3]->[2]->[1]->[0]->||| size: [4]
[4]->[3]->[2]->[1]->[0]->||| size: [5]
top of stack: 4
pop stack: 4
[3]->[2]->[1]->[0]->||| size: [4]
size of the stack: 4
is stack empty? false
stack top to bottom:
<3>
<2>
<1>
<0>



queue.push():
[0]->||| size: [1]
[0]->[1]->||| size: [2]
[0]->[1]->[2]->||| size: [3]
[0]->[1]->[2]->[3]->||| size: [4]
[0]->[1]->[2]->[3]->[4]->||| size: [5]
front of queue: 0
rear of queue: 4
pop queue: 0
[1]->[2]->[3]->[4]->||| size: [4]
size of the queue: 4
is queue empty? false
queue top to bottom:
<1>
<2>
<3>
<4>


--------- D O N E ----------------


[       OK ] ITERATED_LIST.TestInsertHead (34 ms)
[----------] 1 test from ITERATED_LIST (35 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (37 ms total)
[  PASSED  ] 1 test.
<br/><br/>
</pre>

# testB.cpp output:

<pre>
<br/><br/>


----------running testB.cpp---------


[==========] Running 6 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 6 tests from TEST_STUB
[ RUN      ] TEST_STUB.TestStackCTOR
[       OK ] TEST_STUB.TestStackCTOR (0 ms)
[ RUN      ] TEST_STUB.TestStackAssign
[       OK ] TEST_STUB.TestStackAssign (0 ms)
[ RUN      ] TEST_STUB.TestStackPushPop
[       OK ] TEST_STUB.TestStackPushPop (0 ms)
[ RUN      ] TEST_STUB.TestQueueCTOR
[       OK ] TEST_STUB.TestQueueCTOR (0 ms)
[ RUN      ] TEST_STUB.TestQueueAssign
[       OK ] TEST_STUB.TestQueueAssign (0 ms)
[ RUN      ] TEST_STUB.TestQueuePushPop
[       OK ] TEST_STUB.TestQueuePushPop (0 ms)
[----------] 6 tests from TEST_STUB (3 ms total)

[----------] Global test environment tear-down
[==========] 6 tests from 1 test suite ran. (5 ms total)
[  PASSED  ] 6 tests.
<br/><br/>
</pre>
