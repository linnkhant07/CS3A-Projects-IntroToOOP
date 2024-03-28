# Work Report

## Name: <ins> Linn Khant Thuya </ins>

## Features:

- Not Implemented:
  - None

<br><br>

- Implemented:
  - A program that allows Polynomials to perform arithmetic functions

<br><br>

- Partly implemented:
  - None

<br><br>

- Bugs
  - The program is bug free.

<br><br>

# Reflections:

- The multiply and division operators were a bit tricky. Took me a long time to spot bugs.

# **output**

<br/><br/>

# basic_test.cpp output:

<pre>
<br/><br/>
----------running basic_test.cpp---------


[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from TEST_BASIC_TEST
[ RUN      ] TEST_BASIC_TEST.BasicTest
p: [ +4.0X^4 +6.0X^2 +5.0X +8.0 ] 
q: [ +9.0X^5 +1.0X^4 +3.0X^2 +7.0X +2.0 ] 
--------------------------------
p + q   : [ +9.0X^5 +5.0X^4 +9.0X^2 +12.0X +10.0 ] 
p - q   : [ -9.0X^5 +3.0X^4 +3.0X^2 -2.0X +6.0 ] 
p * q   : [ +36.0X^9 +4.0X^8 +54.0X^7 +63.0X^6 +105.0X^5 +34.0X^4 +57.0X^3 +71.0X^2 +66.0X +16.0 ] 
p / q   : [ ]
p % q   : [ +4.0X^4 +6.0X^2 +5.0X +8.0 ]
q / p   : [ +2.2X +0.2 ]
q % p   : [ -13.5X^3 -9.8X^2 -12.2X ]

(p+q) - p == q? true
        p != q? true
        p != p? false
        p.order(): 4
r: [ +5.0X^4 +4.0X^3 ]
r.order(): 4
r.fixorder(): [ +5.0X^4 +4.0X^3 ]


---------------- D O N E -------------
[       OK ] TEST_BASIC_TEST.BasicTest (23 ms)
[----------] 1 test from TEST_BASIC_TEST (24 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (24 ms total)
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
[ RUN      ] TEST_STUB.TestTermOperators
[       OK ] TEST_STUB.TestTermOperators (0 ms)
[ RUN      ] TEST_STUB.TestPolyCTORS
[       OK ] TEST_STUB.TestPolyCTORS (0 ms)
[ RUN      ] TEST_STUB.TestBigThree
[       OK ] TEST_STUB.TestBigThree (0 ms)
[ RUN      ] TEST_STUB.TestPolyEquality
[       OK ] TEST_STUB.TestPolyEquality (0 ms)
[ RUN      ] TEST_STUB.TestPolyGreater
[       OK ] TEST_STUB.TestPolyGreater (0 ms)
[ RUN      ] TEST_STUB.TestPolyLesser
[       OK ] TEST_STUB.TestPolyLesser (0 ms)
[ RUN      ] TEST_STUB.TestOperatorAdd
p: [ +4.0X^4 +6.0X^2 +5.0X +8.0 ]
q: [ +9.0X^5 +1.0X^4 +3.0X^2 +7.0X +2.0 ]
r: [ +9.0X^5 +5.0X^4 +9.0X^2 +12.0X +10.0 ]
r.order: 5
[       OK ] TEST_STUB.TestOperatorAdd (14 ms)
[ RUN      ] TEST_STUB.TestOperatorDivide
p: [ +4.0 ]
q: [ +2.0 ]
r = p / q : [ +2.0 ]
r.order: 0
r = q / p : [ +0.5 ]
r.order: 0
[       OK ] TEST_STUB.TestOperatorDivide (3 ms)
[ RUN      ] TEST_STUB.TestMajorOperators
[       OK ] TEST_STUB.TestMajorOperators (0 ms)
[ RUN      ] TEST_STUB.TestExtraction
[       OK ] TEST_STUB.TestExtraction (0 ms)
[----------] 10 tests from TEST_STUB (29 ms total)

[----------] Global test environment tear-down
[==========] 10 tests from 1 test suite ran. (35 ms total)
[  PASSED  ] 10 tests.
<br/><br/>
</pre>

# main.cpp output:

<pre>
<br/><br/>
----------------------------
p: [ +3.0X^3 +2.0X^2 +1.0X +5.0 ] 
q: [ +4.0X^4 +3.0X^3 +2.0X^2 +1.0X +5.0 ] 

------- p + q ----------------------
[ +3.0X^3 +2.0X^2 +1.0X +5.0 ]  + [ +4.0X^4 +3.0X^3 +2.0X^2 +1.0X +5.0 ] 
      = [ +4.0X^4 +6.0X^3 +4.0X^2 +2.0X +10.0 ] VERIFIED

------- q + p ----------------------
[ +4.0X^4 +3.0X^3 +2.0X^2 +1.0X +5.0 ]  + [ +3.0X^3 +2.0X^2 +1.0X +5.0 ] 
      = [ +4.0X^4 +6.0X^3 +4.0X^2 +2.0X +10.0 ] VERIFIED

------- p - q ----------------------
[ +3.0X^3 +2.0X^2 +1.0X +5.0 ]  - [ +4.0X^4 +3.0X^3 +2.0X^2 +1.0X +5.0 ] 
      = [ -4.0X^4 ] VERIFIED

------- q - p ----------------------
[ +4.0X^4 +3.0X^3 +2.0X^2 +1.0X +5.0 ]  - [ +3.0X^3 +2.0X^2 +1.0X +5.0 ] 
      = [ +4.0X^4 ] VERIFIED

------- p * q ----------------------
[ +3.0X^3 +2.0X^2 +1.0X +5.0 ]  * [ +4.0X^4 +3.0X^3 +2.0X^2 +1.0X +5.0 ] 
      = [ +12.0X^7 +17.0X^6 +16.0X^5 +30.0X^4 +34.0X^3 +21.0X^2 +10.0X +25.0 ] VERIFIED

------- q * p ----------------------
[ +4.0X^4 +3.0X^3 +2.0X^2 +1.0X +5.0 ]  * [ +3.0X^3 +2.0X^2 +1.0X +5.0 ] 
      = [ +12.0X^7 +17.0X^6 +16.0X^5 +30.0X^4 +34.0X^3 +21.0X^2 +10.0X +25.0 ] VERIFIED

------- p / q ----------------------
[ +3.0X^3 +2.0X^2 +1.0X +5.0 ]  / [ +4.0X^4 +3.0X^3 +2.0X^2 +1.0X +5.0 ] 
      = [ ]    rem = [ +3.0X^3 +2.0X^2 +1.0X +5.0 ] VERIFIED

------- q / p ----------------------
[ +4.0X^4 +3.0X^3 +2.0X^2 +1.0X +5.0 ]  / [ +3.0X^3 +2.0X^2 +1.0X +5.0 ] 
      = [ +1.3X +0.1 ]    rem = [ +0.4X^2 -5.8X +4.4 ] VERIFIED
[P]  [Q]     e[X]it p
[P]: 6 x5 +4 x3 -2 x1 +3 x0

p: [ +6.0X^5 +4.0X^3 -2.0X +3.0 ] 
q: [ +4.0X^4 +3.0X^3 +2.0X^2 +1.0X +5.0 ]

------- p + q ----------------------
[ +6.0X^5 +4.0X^3 -2.0X +3.0 ]  + [ +4.0X^4 +3.0X^3 +2.0X^2 +1.0X +5.0 ]
      = [ +6.0X^5 +4.0X^4 +7.0X^3 +2.0X^2 -1.0X +8.0 ] VERIFIED

------- q + p ----------------------
[ +4.0X^4 +3.0X^3 +2.0X^2 +1.0X +5.0 ]  + [ +6.0X^5 +4.0X^3 -2.0X +3.0 ]
      = [ +6.0X^5 +4.0X^4 +7.0X^3 +2.0X^2 -1.0X +8.0 ] VERIFIED

------- p - q ----------------------
[ +6.0X^5 +4.0X^3 -2.0X +3.0 ]  - [ +4.0X^4 +3.0X^3 +2.0X^2 +1.0X +5.0 ]
      = [ +6.0X^5 -4.0X^4 +1.0X^3 -2.0X^2 -3.0X -2.0 ] VERIFIED

------- q - p ----------------------
[ +4.0X^4 +3.0X^3 +2.0X^2 +1.0X +5.0 ]  - [ +6.0X^5 +4.0X^3 -2.0X +3.0 ] 
      = [ -6.0X^5 +4.0X^4 -1.0X^3 +2.0X^2 +3.0X +2.0 ] VERIFIED

------- p * q ----------------------
[ +6.0X^5 +4.0X^3 -2.0X +3.0 ]  * [ +4.0X^4 +3.0X^3 +2.0X^2 +1.0X +5.0 ]
      = [ +24.0X^9 +18.0X^8 +28.0X^7 +18.0X^6 +30.0X^5 +10.0X^4 +25.0X^3 +4.0X^2 -7.0X +15.0 ] VERIFIED

------- q * p ----------------------
[ +4.0X^4 +3.0X^3 +2.0X^2 +1.0X +5.0 ]  * [ +6.0X^5 +4.0X^3 -2.0X +3.0 ]
      = [ +24.0X^9 +18.0X^8 +28.0X^7 +18.0X^6 +30.0X^5 +10.0X^4 +25.0X^3 +4.0X^2 -7.0X +15.0 ] VERIFIED

------- p / q ----------------------
[ +6.0X^5 +4.0X^3 -2.0X +3.0 ]  / [ +4.0X^4 +3.0X^3 +2.0X^2 +1.0X +5.0 ]
      = [ +1.5X -1.1 ]    rem = [ +4.4X^3 +0.8X^2 -8.4X +8.6 ] VERIFIED

------- q / p ----------------------
[ +4.0X^4 +3.0X^3 +2.0X^2 +1.0X +5.0 ]  / [ +6.0X^5 +4.0X^3 -2.0X +3.0 ]
      = [ ]    rem = [ +4.0X^4 +3.0X^3 +2.0X^2 +1.0X +5.0 ] VERIFIED
[P]  [Q]     e[X]it q
[Q]: 3 x8

p: [ +6.0X^5 +4.0X^3 -2.0X +3.0 ] 
q: [ +3.0X^8 ]

------- p + q ----------------------
[ +6.0X^5 +4.0X^3 -2.0X +3.0 ]  + [ +3.0X^8 ]
      = [ +3.0X^8 +6.0X^5 +4.0X^3 -2.0X +3.0 ] VERIFIED

------- q + p ----------------------
[ +3.0X^8 ]  + [ +6.0X^5 +4.0X^3 -2.0X +3.0 ]
      = [ +3.0X^8 +6.0X^5 +4.0X^3 -2.0X +3.0 ] VERIFIED

------- p - q ----------------------
[ +6.0X^5 +4.0X^3 -2.0X +3.0 ]  - [ +3.0X^8 ]
      = [ -3.0X^8 +6.0X^5 +4.0X^3 -2.0X +3.0 ] VERIFIED

------- q - p ----------------------
[ +3.0X^8 ]  - [ +6.0X^5 +4.0X^3 -2.0X +3.0 ]
      = [ +3.0X^8 -6.0X^5 -4.0X^3 +2.0X -3.0 ] VERIFIED

------- p * q ----------------------
[ +6.0X^5 +4.0X^3 -2.0X +3.0 ]  * [ +3.0X^8 ]
      = [ +18.0X^13 +12.0X^11 -6.0X^9 +9.0X^8 ] VERIFIED

------- q * p ----------------------
[ +3.0X^8 ]  * [ +6.0X^5 +4.0X^3 -2.0X +3.0 ]
      = [ +18.0X^13 +12.0X^11 -6.0X^9 +9.0X^8 ] VERIFIED

------- p / q ----------------------
[ +6.0X^5 +4.0X^3 -2.0X +3.0 ]  / [ +3.0X^8 ]
      = [ ]    rem = [ +6.0X^5 +4.0X^3 -2.0X +3.0 ] VERIFIED

------- q / p ----------------------
[ +3.0X^8 ]  / [ +6.0X^5 +4.0X^3 -2.0X +3.0 ]
      = [ +0.5X^3 -0.3X ]    rem = [ +2.3X^4 -1.5X^3 -0.7X^2 +1.0X ] VERIFIED
[P]  [Q]     e[X]it p
[P]: 2 x12

p: [ +2.0X^12 ] 
q: [ +3.0X^8 ]

------- p + q ----------------------
[ +2.0X^12 ]  + [ +3.0X^8 ]
      = [ +2.0X^12 +3.0X^8 ] VERIFIED

------- q + p ----------------------
[ +3.0X^8 ]  + [ +2.0X^12 ]
      = [ +2.0X^12 +3.0X^8 ] VERIFIED

------- p - q ----------------------
[ +2.0X^12 ]  - [ +3.0X^8 ]
      = [ +2.0X^12 -3.0X^8 ] VERIFIED

------- q - p ----------------------
[ +3.0X^8 ]  - [ +2.0X^12 ]
      = [ -2.0X^12 +3.0X^8 ] VERIFIED

------- p * q ----------------------
[ +2.0X^12 ]  * [ +3.0X^8 ]
      = [ +6.0X^20 ] VERIFIED

------- q * p ----------------------
[ +3.0X^8 ]  * [ +2.0X^12 ]
      = [ +6.0X^20 ] VERIFIED

------- p / q ----------------------
[ +2.0X^12 ]  / [ +3.0X^8 ]
      = [ +0.7X^4 ]    rem = [ ] VERIFIED

------- q / p ----------------------
[ +3.0X^8 ]  / [ +2.0X^12 ]
      = [ ]    rem = [ +3.0X^8 ] VERIFIED
[P]  [Q]     e[X]it x



----------------------------
<br/><br/>
</pre>
