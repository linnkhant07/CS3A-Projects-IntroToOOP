# Work Report

## Name: <ins> Linn Khant Thuya </ins>

## Features:

- Not Implemented:
  - None

<br><br>

- Implemented:
  - adding 1, 10, 100, 1000 to the counter
  - is_error() that checks if count > 9000
  - ()reset to reset the counter to 0
  - test_MCounter to display the program in the main

<br><br>

- Partly implemented:
  - None

<br><br>

- Bugs
  - None

<br><br>

# Reflections:

- It was easy, and the process was just like counter_type assingment.

# **output**

# basic_test.cpp output:

<pre>
<br/><br/>
----------running basic_test.cpp---------


[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from TEST_BASIC_TEST
[ RUN      ] TEST_BASIC_TEST.BasicTest
count after add 1:     1
count after add 10:    11
count after add 100:   111
count after add 1000:  1111
count: 1111
no error yet
error state: false

adding another 1000: 8111
no error yet
adding another 1000: 9111
no error yet
adding another 1000: -9999
an error occured:

error state: true
adding another 1000: -9999

counter reset: 0
error state: false


--------------- D O N E ---------------
[       OK ] TEST_BASIC_TEST.BasicTest (8 ms)
[----------] 1 test from TEST_BASIC_TEST (10 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (11 ms total)
[  PASSED  ] 1 test.
<br/><br/>
</pre>

# testB.cpp output:

<pre>
<br/><br/>
----------running testB.cpp---------


[==========] Running 4 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 4 tests from TEST_CLASS
[ RUN      ] TEST_CLASS.TestCTOR
[       OK ] TEST_CLASS.TestCTOR (0 ms)
[ RUN      ] TEST_CLASS.TestAdd
[       OK ] TEST_CLASS.TestAdd (0 ms)
[ RUN      ] TEST_CLASS.TestCountReset
[       OK ] TEST_CLASS.TestCountReset (0 ms)
[ RUN      ] TEST_CLASS.TestError
[       OK ] TEST_CLASS.TestError (0 ms)
[----------] 4 tests from TEST_CLASS (1 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test suite ran. (1 ms total)
[  PASSED  ] 4 tests.
<br/><br/>
</pre>

# main.cpp output:

<pre>
<br/><br/>
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
A
-------
 1000
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
s
-------
 1100
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
d
-------
 1110
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
f
-------
 1111
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
a
-------
 2111
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
a
PS C:\Users\lkty0\CS003A\lab_moms_counter\build\bin> ."C:/Users/lkty0/CS003A/lab_moms_counter/build/bin/main.exe"



[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
A
-------
 1000
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
s
-------
 1100
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
d
-------
 1110
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
f
-------
 1111
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
a
-------
 2111
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
a
-------
 3111
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
a
-------
 4111
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
a
-------
 5111
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
a
-------
 6111
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
a
-------
 7111
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
a
-------
 8111
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
a
-------
 9111
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
a
-------
|ERROR|
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
s
-------
|ERROR|
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
d
-------
|ERROR|
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
f
-------
|ERROR|
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
r
-------
 0000
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
a
-------
 1000
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
s
-------
 1100
-------
[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it
x
END OF PROGRAM



=====================
<br/><br/>
</pre>
