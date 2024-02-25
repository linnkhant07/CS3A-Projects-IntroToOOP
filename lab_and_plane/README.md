# Work Report

## Name: <ins> Linn Khant Thuya </ins>

## Features:

- Not Implemented:
  - None

<br><br>

- Implemented:
  - All lower level functions in two_d_functions
  - All lab functions
  - All plane functions

<br><br>

- Partly implemented:
  - None

<br><br>

- Bugs
  - None

<br><br>

# Reflections:

- I am now confident in using two d pointers. There were some memory bugs which took me
  hours to debug, and it was a lesson.

# **output**

<pre>
<br/><br/><br/><br/>
</pre>

<br/><br/>

# basic_test.cpp output:

<pre>
<br/><br/>
----------running basic_test.cpp---------


[==========] Running 3 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 1 test from TWO_D_ARRAYS
[ RUN      ] TWO_D_ARRAYS.BasicTest
-1 -1 -1 -1 
-1 -1 -1 -1 -1 
-1 -1 -1 
-1 -1 -1 -1 -1 -1 

-1 -1 -1 3 
-1 -1 -1 -1 14 
-1 -1 -1 
-1 31 -1 -1 -1 -1 

[0][3]: 3
[1][4]: 14
[3][1]: 31
[3][4]: 34

found 33 at: [3][1]
td[3][4] is a valid location.
td[13][4] is NOT a valid location.
td[3][14] is NOT a valid location.
---- end test two d functions ----------
[       OK ] TWO_D_ARRAYS.BasicTest (12 ms)
[----------] 1 test from TWO_D_ARRAYS (13 ms total)

[----------] 2 tests from TEST_LAB_N_PLANE
[ RUN      ] TEST_LAB_N_PLANE.BasicTestLab
0 0 0
0 0 0 0
0 0 0 0 0
0
0 0 0
================ test login() =====================

logging in lab: << lab<<, station <<station<<:
0 0 0
0 0 0 0
0 2121 0 0 0
0
0 0 0

logging in lab: <<lab<<, station <<station<<:
0 0 0
0 0 0 0
0 2121 0 0 0
0
0 0 4242

logging in lab: <<lab<<, station <<station<<:
login() correctly refused to log in a new user into an already occupied station
0 0 0
0 0 0 0
0 2121 0 0 0
0
0 0 4242
================ test login() =====================

logging out user : 6666
logout() correctly refused to log out a user who was not logged in.
0 0 0
0 0 0 0
0 2121 0 0 0
0 
0 0 4242

logging out user: 4242
0 0 0
0 0 0 0
0 2121 0 0 0
0
0 0 0

Deallocating two-d array 'labs'


---------- D O N E ----------
[       OK ] TEST_LAB_N_PLANE.BasicTestLab (19 ms)
[ RUN      ] TEST_LAB_N_PLANE.BasicTestPlane
  | A B C D
------------
1 | X X X X
2 | X X X X
3 | X X X X
4 | X X X X
5 | X X X X
6 | X X X X
7 | X X X X


============ test reserve() =======================

reserved 1A([0][0]
  | A B C D
------------
1 | A X X X
2 | X X X X
3 | X X X X
4 | X X X X
5 | X X X X 
6 | X X X X
7 | X X X X

reserved 4C([3][2]
  | A B C D
------------
1 | A X X X
2 | X X X X
3 | X X X X
4 | X X C X
5 | X X X X
6 | X X X X
7 | X X X X

reserved 7D([6][3]
  | A B C D
------------
1 | A X X X
2 | X X X X
3 | X X X X
4 | X X C X
5 | X X X X
6 | X X X X
7 | X X X D 

reserved 7D([6][3]
   reserve() correctly refused to reserve an already occupied seat.
  | A B C D
------------
1 | A X X X
2 | X X X X
3 | X X X X
4 | X X C X
5 | X X X X
6 | X X X X
7 | X X X D


============ test cancel() =======================

cancelled 4D([3][3]
   cancel() correctly refused to cancel unoccupied seat.
  | A B C D
------------
1 | A X X X
2 | X X X X 
3 | X X X X
4 | X X C X
5 | X X X X
6 | X X X X
7 | X X X D

cancelled 4C([3][2]
  | A B C D
------------
1 | A X X X
2 | X X X X
3 | X X X X
4 | X X X X
5 | X X X X
6 | X X X X
7 | X X X D

Deallocating two-d array 'plane'


---------- D O N E ----------
[       OK ] TEST_LAB_N_PLANE.BasicTestPlane (52 ms)
[----------] 2 tests from TEST_LAB_N_PLANE (72 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 2 test suites ran. (91 ms total)
[  PASSED  ] 3 tests.
<br/><br/>
</pre>

# testB.cpp output:

<pre>
<br/><br/>
----------running testB.cpp---------


[==========] Running 17 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 17 tests from TEST_TWOD
[ RUN      ] TEST_TWOD.TestAllocateTwoD
[       OK ] TEST_TWOD.TestAllocateTwoD (0 ms)
[ RUN      ] TEST_TWOD.TestDeallocateTwoD
[       OK ] TEST_TWOD.TestDeallocateTwoD (0 ms)
[ RUN      ] TEST_TWOD.TestInitTwoD
[       OK ] TEST_TWOD.TestInitTwoD (0 ms)
[==========] 17 tests from 1 test suite ran. (18 ms total)
[  PASSED  ] 17 tests.
<br/><br/>
</pre>

# main.cpp output:

<pre>
<br/><br/>
----------lab demo---------

Enter a program [L]ab or [P]lane: L
----------Lab Menu ----------
Currently available lab stations: 
0 0 0 0 
0 0 0 
0 0 

log[i]n    log[o]ut      e[x]it
input: i
---- LOG IN: ------
labs:          4 3 2 
id: 712
lab: 1
station: 1
you are logged in in lab 1, station: 1
712 0 0 0 
0 0 0 
0 0

log[i]n    log[o]ut      e[x]it
input: i
---- LOG IN: ------
labs:
id: 712
lab: 2
station: 2
you are logged in in lab 2, station: 2
712 0 0 0
0 712 0
0 0

log[i]n    log[o]ut      e[x]it
input: i
---- LOG IN: ------
lab: 999
station: 999
[999][999] is invalid.

log[i]n    log[o]ut      e[x]it
input: o

---- LOG OUT: ------
id: 712
you have successfully logged out
0 0 0 0
0 0 0
0 0

log[i]n    log[o]ut      e[x]it
input: x



=====================

----------plane demo---------
Enter a program [L]ab or [P]lane: P
----------Plane Menu ----------
Currently available seats: 
  | A B C D 
------------
1 | X X X X 
2 | X X X X 
3 | X X X X 
4 | X X X X 
5 | X X X X 
6 | X X X X 
7 | X X X X 

[r]eserve    [c]ancel      e[x]it
input: r
---- RESERVE: ------
available seats:
  | A B C D
------------
1 | X X X X
2 | X X X X
3 | X X X X
4 | X X X X
5 | X X X X
6 | X X X X
7 | X X X X
row: 7
seat: D
you reserved the seat D at row 7
  | A B C D
------------
1 | X X X X
2 | X X X X
3 | X X X X
4 | X X X X
5 | X X X X
6 | X X X X
7 | X X X D

[r]eserve    [c]ancel      e[x]it
input: r
---- RESERVE: ------
available seats:
  | A B C D
------------
1 | X X X X
2 | X X X X
3 | X X X X
4 | X X X X
5 | X X X X
6 | X X X X
7 | X X X D
row: 0
seat: A
Seat A at row 0 is invalid. 

[r]eserve    [c]ancel      e[x]it
input: c
---- CANCEL: ------
seats:
  | A B C D
------------
1 | X X X X
2 | X X X X
3 | X X X X
4 | X X X X
5 | X X X X
6 | X X X X
7 | X X X D
row: 7
seat: D
you have successfully cancelled the booking for seat D at row 7
  | A B C D
------------
1 | X X X X
2 | X X X X
3 | X X X X
4 | X X X X 
5 | X X X X
6 | X X X X
7 | X X X X

[r]eserve    [c]ancel      e[x]it
input: c
---- CANCEL: ------
seats:
  | A B C D
------------
1 | X X X X
2 | X X X X
3 | X X X X
4 | X X X X
5 | X X X X
6 | X X X X
7 | X X X X
row: 7
seat: D
The seat D at row 7 is not booked.

[r]eserve    [c]ancel      e[x]it
input: x
<br/><br/>
</pre>
