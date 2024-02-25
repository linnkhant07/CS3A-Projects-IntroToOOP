# Work Report

## Name: <ins> Linn Khant Thuya </ins>

## Features:

- Not Implemented:
  - None

<br><br>

- Implemented:
  - all functions in the instructions:
  - CTORs, setters, getters with error checkers for Rational
  - error handling functions
  - friend operators for Rational
  - test_Rational() in main for display purposes

<br><br>

- Partly implemented:
  - None

<br><br>

- Bugs
  - None

<br><br>

# Reflections:

- I learnt about friend functions, operators, i/ostreams and classes.

# **output**

<pre>
<br/><br/><br/><br/>
</pre>

<br/><br/>

# basic_test.cpp output:

----------running basic_test.cpp---------

[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from TEST_BASIC_TEST
[ RUN ] TEST_BASIC_TEST.BasicTest
4/6 + 3/8 = 50/48
4/6 - 3/8 = 14/48
4/6 \* 3/8 = 12/48
4/6 / 3/8 = 32/18
r3: 6/3
r3 is now: UNDEFINED
r3 error state: 1
r3 error descr: Denominator is zero!
r3.reset():
r3 is now: 0/1
[ OK ] TEST_BASIC_TEST.BasicTest (4 ms)
[----------] 1 test from TEST_BASIC_TEST (4 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (15 ms total)
[ PASSED ] 1 test.

<pre>
<br/><br/><br/><br/>
</pre>

# testB.cpp output:

----------running testB.cpp---------

[==========] Running 6 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 6 tests from TEST_RATIONAL
[ RUN ] TEST_RATIONAL.TestCTOR
[ OK ] TEST_RATIONAL.TestCTOR (3 ms)
[ RUN ] TEST_RATIONAL.TestSetGetNum
[ OK ] TEST_RATIONAL.TestSetGetNum (0 ms)
[ RUN ] TEST_RATIONAL.TestSetGetDenom
[ OK ] TEST_RATIONAL.TestSetGetDenom (0 ms)
[ RUN ] TEST_RATIONAL.TestErrors
[ OK ] TEST_RATIONAL.TestErrors (0 ms)
[ RUN ] TEST_RATIONAL.TestReset
[ OK ] TEST_RATIONAL.TestReset (0 ms)
[ RUN ] TEST_RATIONAL.TestOpeators
[ OK ] TEST_RATIONAL.TestOpeators (0 ms)
[----------] 6 tests from TEST_RATIONAL (4 ms total)

[----------] Global test environment tear-down
[==========] 6 tests from 1 test suite ran. (6 ms total)
[ PASSED ] 6 tests.
PS C:\Users\lkty0\CS003A\lab_rational\build\bin>

<pre>
<br/><br/><br/><br/>
</pre>

# main.cpp output:

A: 3/4 B:5/9
3/4 + 5/9 = 47/36
3/4 - 5/9 = 7/36
3/4 _ 5/9 = 15/36
3/4 / 5/9 = 27/20
============================================
[A] [B] e[X]it
a
a: 1/2
A: 1/2 B:5/9
1/2 + 5/9 = 19/18
1/2 - 5/9 = -1/18
1/2 _ 5/9 = 5/18
1/2 / 5/9 = 9/10
============================================
[A] [B] e[X]it
b
b: 1/3
A: 1/2 B:1/3
1/2 + 1/3 = 5/6
1/2 - 1/3 = 1/6
1/2 _ 1/3 = 1/6
1/2 / 1/3 = 3/2
============================================
[A] [B] e[X]it
a
a: 0/1
A: 0/1 B:1/3
0/1 + 1/3 = 1/3
0/1 - 1/3 = -1/3
0/1 _ 1/3 = 0/3
0/1 / 1/3 = 0/1
============================================
[A] [B] e[X]it
b
b: 1/0
A: 0/1 B:UNDEFINED
0/1 + UNDEFINED = UNDEFINED
0/1 - UNDEFINED = UNDEFINED
0/1 \* UNDEFINED = UNDEFINED
0/1 / UNDEFINED = UNDEFINED
============================================
[A] [B] e[X]it
x

=====================

<pre>
<br/><br/><br/><br/>
</pre>
