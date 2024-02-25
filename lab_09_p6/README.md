# Work Report

## Name: <ins> Linn Khant Thuya </ins>

## Features:

- Not Implemented:
  - None

<br><br>

- Implemented:
  - Functions for arrays:
  - pushing an element
  - popping an element
  - inserting an element at a desired index
  - removing an element at a desired index
  - removing the first instance of an element
    (Capacity of the array will automatically increase or decrease if the size becomes full or too small )

<br><br>

- Partly implemented:
  - None

<br><br>

- Bugs
  - All the functions are bug free.

<br><br>

# Reflections:

- It was a fairly easy assignment compared to array_pointer_functions.

# **output**

<pre>
<br/><br/><br/><br/>
</pre>

<br/><br/>

# basic_test.cpp output:

<pre>
<br/><br/><br/><br/>
</pre>

# testB.cpp output:

<pre>
<br/><br/>
----------running testB.cpp---------


[==========] Running 6 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 1 test from TEST_STUB
[ RUN      ] TEST_STUB.TestStub
[       OK ] TEST_STUB.TestStub (0 ms)
[----------] 1 test from TEST_STUB (1 ms total)

[----------] 5 tests from TEST_ARRAY
[ RUN      ] TEST_ARRAY.TestAddEntry

---------------test_add_entry()---------------

Capacity is now doubled to 4
(3/4)[0|1|2|]

[       OK ] TEST_ARRAY.TestAddEntry (1 ms)
[ RUN      ] TEST_ARRAY.TestRemoveEntry

---------------test_remove_entry()---------------

Capacity is now doubled to 4

Capacity is now doubled to 8
(4/8)[0|1|3|2|]

[       OK ] TEST_ARRAY.TestRemoveEntry (1 ms)
[ RUN      ] TEST_ARRAY.TestRemoveLastEntry

---------------test_remove_last_entry()---------------

Capacity is now doubled to 4

Capacity is now doubled to 8
2 was popped!
3 was popped!

 Capacity is now reduced to 4
2 was popped!
(2/4)[0|1|]

[       OK ] TEST_ARRAY.TestRemoveLastEntry (2 ms)
[ RUN      ] TEST_ARRAY.TestInsertEntry

---------------test_insert_entry()---------------

Capacity is now doubled to 4

Capacity is now doubled to 8
(7/8)[2023|0|1|711|2|3|4|]

[       OK ] TEST_ARRAY.TestInsertEntry (1 ms)
[ RUN      ] TEST_ARRAY.TestEraseEntry

---------------test_erase_entry()---------------

Capacity is now doubled to 4

Capacity is now doubled to 8
(3/8)[0|2|2|]

[       OK ] TEST_ARRAY.TestEraseEntry (1 ms)
[----------] 5 tests from TEST_ARRAY (9 ms total)

[----------] Global test environment tear-down
[==========] 6 tests from 2 test suites ran. (10 ms total)
[  PASSED  ] 6 tests.
<br/><br/>
</pre>
