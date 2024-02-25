# Work Report

## Name: <ins> Linn Khant Thuya </ins>

## Features:

- Not Implemented:
  - Everything in the assignment guidelines has been implemented

<br><br>

- Implemented:
  - RPN, ShuntingYard
  - draws functions (trig, two argument functions, unary)
  - draws axis
  - history panel to keep record of functions
  - click history functions to redraw
  - stores and fetches equations from the text file
  - clear function history
  - help box that can be toggled

<br><br>

- Partly implemented:
  - After this, I would change the background color when functions in history are hovered

<br><br>

- Bugs
  - Program is clear of bugs

<br><br>

# Reflections:

- The algorithms and data structures were really educative. Plotting was interesting. SFML part was tedious and a lot of busy work. The challenging part was structuring the classes and keeping everything intact.

I would try to improve the program a lot more in the summer.

# **output**

<pre>
<br/><br/>

Youtube Link: https://www.youtube.com/watch?v=qVVcj4K4_Bo&feature=youtu.be

<br/><br/>
# testB.cpp output:

<pre>
<br/><br/>
----------running testB.cpp---------


[==========] Running 5 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 1 test from TEST
[ RUN      ] TEST.FreeTest
[       OK ] TEST.FreeTest (0 ms)
[----------] 1 test from TEST (3 ms total)

[----------] 4 tests from TEST_RPN
[ RUN      ] TEST_RPN.TestShuntingYard
5.00 3.00 2.00 *1.00 -+4.00 2.00 -/3.00 /
[       OK ] TEST_RPN.TestShuntingYard (5 ms)
[ RUN      ] TEST_RPN.TestRPN
(5 + 3 * 2 - 1) / (4 - 2) / 3 = 1.67
[       OK ] TEST_RPN.TestRPN (0 ms)
[ RUN      ] TEST_RPN.TestFunc
sin (4 + 2) / tan (pow(2,3)) = 0.04
sin -3.14 = -0.00
tan sin 1.07 = 1.20
[       OK ] TEST_RPN.TestFunc (3 ms)
[ RUN      ] TEST_RPN.TestTokenizer
Enter a function y = 1/x
[1.00 ]->[/]->[X]->||| size: [3]
[       OK ] TEST_RPN.TestTokenizer (8407 ms)
[----------] 4 tests from TEST_RPN (8419 ms total)

[----------] Global test environment tear-down
[==========] 5 tests from 2 test suites ran. (8423 ms total)
[  PASSED  ] 5 tests.
<br/><br/>
</pre>
</pre>

<br/><br/>
