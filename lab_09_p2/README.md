# Work Report

## Name: <ins> Linn Khant Thuya </ins>

## Features:

- Not Implemented:
  - None

<br><br>

- Implemented:
  - Take an array and delete every duplicate element in that array (by using shift_left function)

<br><br>

- Partly implemented:
  - None

<br><br>

- Bugs
  - None

<br><br>

# Reflections:

- Using the shift_left function to delete duplicates was a lot harder than expected. I had to be very careful with two pointers, the pointer to compared element and the pointer that walks down the array to check duplicates. I also had many logic errors on the way, and finally, they got solved.

# **output**

<pre>
<br/><br/><br/><br/>
</pre>

<br/><br/>

# basic_test.cpp output:

<pre>
<br/><br/>----------running testB.cpp---------


[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from TEST_STUB
[ RUN      ] TEST_STUB.TestStub
[       OK ] TEST_STUB.TestStub (0 ms)
[ RUN      ] TEST_STUB.TestDeleteRepeats


original list: [1|1|1|1|0|1|]



unique values: [1|0|]



original list: [a|a|b|a|b|c|a|b|c|d|a|b|c|d|e|f|]



unique values: [a|b|c|d|e|f|]

The size of unique valued array is: 6

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (27 ms total)
[  PASSED  ] 2 tests.<br/><br/>
</pre>

# testB.cpp output:

<pre>
<br/><br/>

<br/><br/>
</pre>
