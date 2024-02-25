# Work Report

## Name: <ins> Linn Khant Thuya </ins>

## Features:

- Not Implemented:
  - Everything required for the assignment has been implemented.

<br><br>

- Implemented:
  - Allocate, Deallocate dynamic Arrays
  - Shift left or right at particular indexes in the arrays
  - Print the elements of the array
  - Search for an element in the array and returns the pointer or index
  - Copy the elements of an array to another array
  - Produce a string version of the array

<br><br>

- Partly implemented:
  - None

<br><br>

- Bugs
  - None

<br><br>

# Reflections:

- I am a lot more confident with using pointers now. Also, a bug took me almost the whole day to debug, and it turned out to be off-by-one. It was in the shift_left function, and the error wasn't visible on the output since the pointer was swapping garbage with garbage. I have learnt my lesson to pay more attention to loops, especially, when they are paired with pointers.

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


[==========] Running 12 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 12 tests from TEST_ARRAY
[ RUN      ] TEST_ARRAY.TestAllocate

---------------testing allocate-------------------
[1|2|3|4|5|]
[       OK ] TEST_ARRAY.TestAllocate (1 ms)
[ RUN      ] TEST_ARRAY.TestReallocate

---------------testing reallocate-------------------
[1|2|2|2|3|4|5|]
[       OK ] TEST_ARRAY.TestReallocate (2 ms)
[ RUN      ] TEST_ARRAY.TestShiftLeft

---------------testing shift_left-------------------
Original size of the array is 7
g o o d b y e
Shift left at 0:
o o d b y e
^
o o d b y e
Shift left at 5:
o o d b y
          ^
Size of the array is now 5
o o d b y
Shift left at 3:
o o d y
      ^
Size of the array is now 4
[       OK ] TEST_ARRAY.TestShiftLeft (10 ms)
[ RUN      ] TEST_ARRAY.TestShiftLeft2

---------------testing shift_left ver 2 -------------------
0 1 2 3 4 5 6
Shift left at 0:
1 2 3 4 5 6
^
Size of the array is now 6
1 2 3 4 5 6
Shift left at 5:
1 2 3 4 5
          ^
Size of the array is now 5
1 2 3 4 5
Shift left at 3:
1 2 3 5
      ^
Size of the array is now 4
[       OK ] TEST_ARRAY.TestShiftLeft2 (8 ms)
[ RUN      ] TEST_ARRAY.TestShiftRight

---------------testing shift_right-------------------
g o o d b y e
Shift right at 0:
g g o o d b y e
^
g g o o d b y e
Shift right at 7:
g g o o d b y e e
              ^
g g o o d b y e e
Shift right at 3:
g g o o o d b y e e 
      ^
[       OK ] TEST_ARRAY.TestShiftRight (8 ms)
[ RUN      ] TEST_ARRAY.TestShiftRight2

---------------testing shift_right ver 2-------------------
0 1 2 3 4 5 6
Shift right at 0:
0 0 1 2 3 4 5 6
^
0 0 1 2 3 4 5 6
Shift right at 7:
0 0 1 2 3 4 5 6 6
              ^
0 0 1 2 3 4 5 6 6
Shift right at 3:
0 0 1 2 2 3 4 5 6 6
      ^
[       OK ] TEST_ARRAY.TestShiftRight2 (6 ms)
[ RUN      ] TEST_ARRAY.TestPrintArray

---------------testing print_array-------------------
[10|8|18|1|21|49|]
[10|8|1|21|49|]

[       OK ] TEST_ARRAY.TestPrintArray (2 ms)
[ RUN      ] TEST_ARRAY.TestSearchArray

---------------testing search-------------------
Element not found in the array
[       OK ] TEST_ARRAY.TestSearchArray (2 ms)
[ RUN      ] TEST_ARRAY.TestSearchEntryArray

---------------testing search_entry-------------------
Element not found in the array
[       OK ] TEST_ARRAY.TestSearchEntryArray (0 ms)
[ RUN      ] TEST_ARRAY.TestCopyArray

---------------testing copy_array-------------------
Source array: [0|1|2|3|4|5|]
Destination array: [0|1|2|3|4|5|]

[       OK ] TEST_ARRAY.TestCopyArray (4 ms)
[ RUN      ] TEST_ARRAY.TestCopyArray2

---------------testing copy_array2 (pointer return)-------------------
Source array: [0|1|2|3|4|5|]
Destination array: [0|1|2|3|4|5|]

[       OK ] TEST_ARRAY.TestCopyArray2 (2 ms)
[ RUN      ] TEST_ARRAY.TestArrayString

---------------testing array_string-------------------
T H U Y A
0 1 2 3 4
1.000000 2.000000 3.000000 4.000000 5.000000

[       OK ] TEST_ARRAY.TestArrayString (1 ms)
[----------] 12 tests from TEST_ARRAY (52 ms total)

[----------] Global test environment tear-down
[==========] 12 tests from 1 test suite ran. (63 ms total)
[  PASSED  ] 12 tests.
<br/><br/>
</pre>
