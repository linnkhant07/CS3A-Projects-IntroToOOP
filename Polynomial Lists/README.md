# Work Report

## Name: <ins> Linn Khant Thuya </ins>

## Features:

- Not Implemented:
  - None

<br><br>

- Implemented:
  - Polynomial Class - terms stored in linked list
  - Arithmetic Operators for Poly and Poly / Poly and Term

<br><br>

- Partly implemented:
  - None

<br><br>

- Bugs
  - None

<br><br>

# Reflections:

- I had so many seg faults and this one closed circuit error took me a long time. The fact that we could delete terms of 0 coef unlike arrays was very interesting.

# **output**

<pre>
<br/><br/>
</pre>

<br/><br/>

# basic_test.cpp output:

<pre>
<br/><br/>

----------running testA.cpp---------


[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from BASIC_TEST
[ RUN      ] BASIC_TEST.BasicTest
p: [ +5.0X^6 +4.0X^4 +2.0X^3 +2.0 ] [6]
q: [ +6.0X^3 +5.0X^2 +4.0X +3.0 ] [3]
----------------------------------
p + q: [ +5.0X^6 +4.0X^4 +8.0X^3 +5.0X^2 +4.0X +5.0 ] [6]
p - q: [ +5.0X^6 +4.0X^4 -4.0X^3 -5.0X^2 -4.0X -1.0 ] [6]
p * q: [ +30.0X^9 +25.0X^8 +44.0X^7 +47.0X^6 +26.0X^5 +20.0X^4 +18.0X^3 +10.0X^2 +8.0X +6.0 ] [9]
p / q: [ +0.8X^3 -0.7X^2 +0.7X -0.2 ] [3]
p % q: [ +0.3X^2 -1.3X +2.6 ] [2]
q / p: [ +0.8X^3 -0.7X^2 +0.7X -0.2 ] [3]
q % p: [ +0.3X^2 -1.3X +2.6 ] [2]
p != p: false
(p+q)-q == p? true
10.0/3 == 20.0/6: true


-------- DONE ---------


[       OK ] BASIC_TEST.BasicTest (42 ms)
[----------] 1 test from BASIC_TEST (42 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (48 ms total)
[  PASSED  ] 1 test.
<br/><br/>
</pre>

# testB.cpp output:

<pre>
<br/><br/>


----------running testB.cpp---------


[==========] Running 8 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 8 tests from TEST_STUB
[ RUN      ] TEST_STUB.TestTermOperators
[       OK ] TEST_STUB.TestTermOperators (0 ms)
[ RUN      ] TEST_STUB.TestCTOR
p: 
[]->|||
order is: 0

p1: [ +6.0X^6 +4.0X^4 +2.0X^3 +2.0X +7.0 ] [6]
[+6.0X^6 ]->[+4.0X^4 ]->[+2.0X^3 ]->[+2.0X ]->[+7.0 ]->|||
order is: 6

p2: [ +6.0X^6 +4.0X^4 +2.0X^3 +2.0X +7.0 ] [6]
[+6.0X^6 ]->[+4.0X^4 ]->[+2.0X^3 ]->[+2.0X ]->[+7.0 ]->|||
order is: 6

p3: [ +5.0X^4 +7.0X^2 +6.0X +5.0 ] [4]
[+5.0X^4 ]->[+7.0X^2 ]->[+6.0X ]->[+5.0 ]->|||
order is: 4

[       OK ] TEST_STUB.TestCTOR (13 ms)
[ RUN      ] TEST_STUB.TestAssignment
p:
[]->|||
order is: 0

p1: [ +5.0X^6 +4.0X^4 +2.0X^3 +2.0 ] [6]
[+5.0X^6 ]->[+4.0X^4 ]->[+2.0X^3 ]->[+2.0 ]->|||
order is: 6

p3: [ +9.0X^4 +7.0X^2 +6.0X +5.0 ] [4]
[+9.0X^4 ]->[+7.0X^2 ]->[+6.0X ]->[+5.0 ]->|||
order is: 4

p after p = p1: [ +5.0X^6 +4.0X^4 +2.0X^3 +2.0 ] [6]
p new order is 6

p2 after p2 = p: [ +5.0X^6 +4.0X^4 +2.0X^3 +2.0 ] [6]
p3 new order is 6

p1 after self assignment: [ +5.0X^6 +4.0X^4 +2.0X^3 +2.0 ] [6]
p1 new order is 6

p1 after p1 = p4: [ ] [0]
p1 new order is 0

[       OK ] TEST_STUB.TestAssignment (16 ms)
[ RUN      ] TEST_STUB.TestPlus
p1: [ +5.0X^6 +4.0X^4 +2.0X^3 +2.0 ] [6]
[+5.0X^6 ]->[+4.0X^4 ]->[+2.0X^3 ]->[+2.0 ]->|||
order is: 6

p3: [ +9.0X^4 +7.0X^2 +6.0X +5.0 ] [4]
[+9.0X^4 ]->[+7.0X^2 ]->[+6.0X ]->[+5.0 ]->|||
order is: 4

p4: [ +5.0X^6 +13.0X^4 +2.0X^3 +7.0X^2 +6.0X +7.0 ] [6]
[+5.0X^6 ]->[+13.0X^4 ]->[+2.0X^3 ]->[+7.0X^2 ]->[+6.0X ]->[+7.0 ]->|||
order is: 6

p1 after p1+=p3: [ +5.0X^6 +13.0X^4 +2.0X^3 +7.0X^2 +6.0X +7.0 ] [6]
[+5.0X^6 ]->[+13.0X^4 ]->[+2.0X^3 ]->[+7.0X^2 ]->[+6.0X ]->[+7.0 ]->|||
order is: 6

p5: [ +7.0X^3 +9.0X^2 +2.0 ] [3]
[+7.0X^3 ]->[+9.0X^2 ]->[+2.0 ]->|||
order is: 3

p6: [ -7.0X^3 -9.0X^2 +1.0X -2.0 ] [3]
[-7.0X^3 ]->[-9.0X^2 ]->[+1.0X ]->[-2.0 ]->|||
order is: 3

p8 after p5 + p6: [ +1.0X ] [1]
[+1.0X ]->|||
order is: 1

p9 is now: [ ] [0]
[       OK ] TEST_STUB.TestPlus (27 ms)
[ RUN      ] TEST_STUB.TestMinus
p1: [ +5.0X^6 +4.0X^4 +2.0X^3 +2.0 ] [6]
[+5.0X^6 ]->[+4.0X^4 ]->[+2.0X^3 ]->[+2.0 ]->|||
order is: 6

p2: [ -5.0X^6 -4.0X^4 -2.0X^3 -2.0 ] [6]
[-5.0X^6 ]->[-4.0X^4 ]->[-2.0X^3 ]->[-2.0 ]->|||
order is: 6

p3: [ +9.0X^4 +7.0X^2 +6.0X +5.0 ] [4]
[+9.0X^4 ]->[+7.0X^2 ]->[+6.0X ]->[+5.0 ]->|||
order is: 4

p4 after p1 - p3: [ +5.0X^6 -5.0X^4 +2.0X^3 -7.0X^2 -6.0X -3.0 ] [6]
[+5.0X^6 ]->[-5.0X^4 ]->[+2.0X^3 ]->[-7.0X^2 ]->[-6.0X ]->[-3.0 ]->|||
order is: 6

p4 after p1 + p2: [ ] [0]
[]->|||
order is: 0

p1 after p1-=p3: [ +5.0X^6 -5.0X^4 +2.0X^3 -7.0X^2 -6.0X -3.0 ] [6]
[+5.0X^6 ]->[-5.0X^4 ]->[+2.0X^3 ]->[-7.0X^2 ]->[-6.0X ]->[-3.0 ]->|||
order is: 6

[       OK ] TEST_STUB.TestMinus (19 ms)
[ RUN      ] TEST_STUB.TestMultiply
p1: [ +5.0X^6 +4.0X^4 +2.0X^3 +2.0 ] [6]
[+5.0X^6 ]->[+4.0X^4 ]->[+2.0X^3 ]->[+2.0 ]->|||
order is: 6

p3: [ +9.0X^4 +7.0X^2 +6.0X +5.0 ] [4]
[+9.0X^4 ]->[+7.0X^2 ]->[+6.0X ]->[+5.0 ]->|||
order is: 4

p4: [ +45.0X^10 +71.0X^8 +48.0X^7 +53.0X^6 +38.0X^5 +50.0X^4 +10.0X^3 +14.0X^2 +12.0X +10.0 ] [10]
[+45.0X^10 ]->[+71.0X^8 ]->[+48.0X^7 ]->[+53.0X^6 ]->[+38.0X^5 ]->[+50.0X^4 ]->[+10.0X^3 ]->[+14.0X^2 ]->[+12.0X ]->[+10.0 ]->||| 
order is: 10

p1 after p1*=p3: [ +45.0X^10 +71.0X^8 +48.0X^7 +53.0X^6 +38.0X^5 +50.0X^4 +10.0X^3 +14.0X^2 +12.0X +10.0 ] [10]
[+45.0X^10 ]->[+71.0X^8 ]->[+48.0X^7 ]->[+53.0X^6 ]->[+38.0X^5 ]->[+50.0X^4 ]->[+10.0X^3 ]->[+14.0X^2 ]->[+12.0X ]->[+10.0 ]->||| 
order is: 10

p5: [ ] [0]
[]->|||
order is: 0

p1 after p1*=p5: [ ] [0]
[]->|||
order is: 0

[       OK ] TEST_STUB.TestMultiply (21 ms)
[ RUN      ] TEST_STUB.TestDivide
p1: [ +2.0X +2.0 ] [1]
[+2.0X ]->[+2.0 ]->|||
order is: 1

p3: [ +2.0 ] [0]
[+2.0 ]->|||
order is: 0

p1: [ +1.0X +1.0 ] [1]
[+1.0X ]->[+1.0 ]->|||
order is: 1

p4: [ ] [0]
[]->|||
order is: 0

p4 after p4 = p5/p6: [ +3.0X^3 +2.0X^2 +1.0X +5.0 ] [3]
[+3.0X^3 ]->[+2.0X^2 ]->[+1.0X ]->[+5.0 ]->|||
order is: 3

[       OK ] TEST_STUB.TestDivide (8 ms)
[ RUN      ] TEST_STUB.TestMajorOperators
[       OK ] TEST_STUB.TestMajorOperators (0 ms)
[----------] 8 tests from TEST_STUB (108 ms total)

[----------] Global test environment tear-down
[==========] 8 tests from 1 test suite ran. (119 ms total)
[  PASSED  ] 8 tests.
<br/><br/>
</pre>
