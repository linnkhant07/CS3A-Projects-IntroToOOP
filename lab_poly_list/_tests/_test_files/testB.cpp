#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/term/term.h"
#include "../../includes/poly_list/poly.h"

using namespace std;

bool test_term_operators(bool debug = false)
{
     // also test for CTORs
     Term t1(3.0, 2);
     Term t2(4.0, 2);

     Term t3(0, 2);
     t3 = t1 + t2;
     if (!double_equals(t3._coef, 7.0))
     {
          cout << "Term operator + not working\n";
          return false;
     }

     t3 = t1 - t2;
     if (!double_equals(t3._coef, -1.0))
     {
          cout << "Term operator - not working\n";
          return false;
     }

     t3 = t1 * t2;
     if (!double_equals(t3._coef, 12.0))
     {
          cout << "Term operator * not working\n";
          return false;
     }

     t3 = t1 / t2;
     if (!double_equals(t3._coef, 0.75))
     {
          cout << "Term operator / not working\n";
          return false;
     }

     t3 = -t1;
     if (!double_equals(t3._coef, -3.0))
     {
          cout << "Term unary operator - not working\n";
          return false;
     }

     if ((t3 != t2))
     {
          cout << "Term operator != not working\n";
          return false;
     }

     t3 = t2;
     if (!(t3 == t2))
     {
          cout << "Term operator == not working\n";
          return false;
     }

     if (debug)
     {
          cout << "t1: " << t1 << endl;
          cout << "t2: " << t2 << endl;
          cout << "t1 + t2: " << t1 + t2 << endl;
          cout << "t1 - t2: " << t1 - t2 << endl;
          cout << "t1 * t2: " << t1 * t2 << endl;
          cout << "t1 / t2: " << t1 / t2 << endl;
          cout << "t3: " << t3 << endl;

          Term t4(3.0, 2);
          Term t5(3.0, 2);
          cout << "t4 - t5 = " << t4 - t5 << endl;
     }

     return true;
}

bool test_CTOR(bool debug = false)
{
     if (debug)
     {

          Poly p;
          cout << "p: " << endl;
          cout << p.list();
          cout << "order is: " << p.order() << endl
               << endl;

          double coefs1[] = {7.0, 2.0, 0.0, 2.0, 4.0, 0.0, 6.0};
          Poly p1(coefs1, 6);
          cout << "p1: " << p1 << endl;
          cout << p1.list();
          cout << "order is: " << p1.order() << endl
               << endl;

          Poly p2(p1);
          cout << "p2: " << p2 << endl;
          cout << p2.list();
          cout << "order is: " << p2.order() << endl
               << endl;

          vector<double> vec = {5, 6, 7, 0, 5};
          Poly p3(vec);
          cout << "p3: " << p3 << endl;
          cout << p3.list();
          cout << "order is: " << p3.order() << endl
               << endl;
     }

     return true;
}

bool test_assignment(bool debug = false)
{
     if (debug)
     {
          Poly p;
          Poly p4;
          cout << "p: " << endl;
          cout << p.list();
          cout << "order is: " << p.order() << endl
               << endl;

          double coefs1[] = {2.0, 0.0, 0.0, 2.0, 4.0, 0.0, 5.0};
          Poly p1(coefs1, 6);
          cout << "p1: " << p1 << endl;
          cout << p1.list();
          cout << "order is: " << p1.order() << endl
               << endl;

          vector<double> vec = {5, 6, 7, 0, 9};
          Poly p3(vec);
          cout << "p3: " << p3 << endl;
          cout << p3.list();
          cout << "order is: " << p3.order() << endl
               << endl;

          p = p1;
          cout << "p after p = p1: " << p << endl;
          cout << "p new order is " << p.order() << endl
               << endl;

          p3 = p;
          cout << "p2 after p2 = p: " << p3 << endl;
          cout << "p3 new order is " << p3.order() << endl
               << endl;

          // self assignment
          p1 = p1;
          cout << "p1 after self assignment: " << p1 << endl;
          cout << "p1 new order is " << p1.order() << endl
               << endl;

          p1 = p4;
          cout << "p1 after p1 = p4: " << p1 << endl;
          cout << "p1 new order is " << p1.order() << endl
               << endl;
     }

     return true;
}

bool test_operator_plus(bool debug = false)
{
     if (debug)
     {
          double coefs1[] = {2.0, 0.0, 0.0, 2.0, 4.0, 0.0, 5.0};
          Poly p1(coefs1, 6);
          cout << "p1: " << p1 << endl;
          cout << p1.list();
          cout << "order is: " << p1.order() << endl
               << endl;

          vector<double> vec = {5, 6, 7, 0, 9};
          Poly p3(vec);
          cout << "p3: " << p3 << endl;
          cout << p3.list();
          cout << "order is: " << p3.order() << endl
               << endl;

          Term t(3, 1);
          Poly p4;
          p4 = p1 + p3;
          cout << "p4: " << p4 << endl;
          cout << p4.list();
          cout << "order is: " << p4.order() << endl
               << endl;

          p1 += p3;
          cout << "p1 after p1+=p3: " << p1 << endl;
          cout << p1.list();
          cout << "order is: " << p1.order() << endl
               << endl;

          double coefs5[] = {2.0, 0.0, 9.0, 7.0};
          Poly p5(coefs5, 3);
          cout << "p5: " << p5 << endl;
          cout << p5.list();
          cout << "order is: " << p5.order() << endl
               << endl;

          double coefs6[] = {-2.0, 1.0, -9.0, -7.0};
          Poly p6(coefs6, 3);
          cout << "p6: " << p6 << endl;
          cout << p6.list();
          cout << "order is: " << p6.order() << endl
               << endl;

          Poly p8;
          p8 = p5 + p6;
          cout << "p8 after p5 + p6: " << p8 << endl;
          cout << p8.list();
          cout << "order is: " << p8.order() << endl
               << endl;

          Poly p9, p10;
          p9 += p10;
          cout << "p9 is now: " << p9 << endl;
     }

     return true;
}

bool test_operator_minus(bool debug = false)
{
     if (debug)
     {
          double coefs1[] = {2.0, 0.0, 0.0, 2.0, 4.0, 0.0, 5.0};
          Poly p1(coefs1, 6);
          cout << "p1: " << p1 << endl;
          cout << p1.list();
          cout << "order is: " << p1.order() << endl
               << endl;

          double coefs2[] = {-2.0, 0.0, 0.0, -2.0, -4.0, 0.0, -5.0};
          Poly p2(coefs2, 6);
          cout << "p2: " << p2 << endl;
          cout << p2.list();
          cout << "order is: " << p2.order() << endl
               << endl;

          vector<double> vec = {5, 6, 7, 0, 9};
          Poly p3(vec);
          cout << "p3: " << p3 << endl;
          cout << p3.list();
          cout << "order is: " << p3.order() << endl
               << endl;

          Term t(3, 1);
          Poly p4;
          p4 = p1 - p3;
          cout << "p4 after p1 - p3: " << p4 << endl;
          cout << p4.list();
          cout << "order is: " << p4.order() << endl
               << endl;

          p4 = p1 + p2;
          cout << "p4 after p1 + p2: " << p4 << endl;
          cout << p4.list();
          cout << "order is: " << p4.order() << endl
               << endl;

          p1 -= p3;
          cout << "p1 after p1-=p3: " << p1 << endl;
          cout << p1.list();
          cout << "order is: " << p1.order() << endl
               << endl;
     }

     return true;
}

bool test_operator_multiply(bool debug = false)
{

     if (debug)
     {
          double coefs1[] = {2.0, 0.0, 0.0, 2.0, 4.0, 0.0, 5.0};
          Poly p1(coefs1, 6);
          cout << "p1: " << p1 << endl;
          cout << p1.list();
          cout << "order is: " << p1.order() << endl
               << endl;

          vector<double> vec = {5, 6, 7, 0, 9};
          Poly p3(vec);
          cout << "p3: " << p3 << endl;
          cout << p3.list();
          cout << "order is: " << p3.order() << endl
               << endl;

          Term t(3, 1);
          Poly p4;
          p4 = p1 * p3;
          cout << "p4: " << p4 << endl;
          cout << p4.list();
          cout << "order is: " << p4.order() << endl
               << endl;

          p1 *= p3;
          cout << "p1 after p1*=p3: " << p1 << endl;
          cout << p1.list();
          cout << "order is: " << p1.order() << endl
               << endl;

          Poly p5;
          cout << "p5: " << p5 << endl;
          cout << p5.list();
          cout << "order is: " << p5.order() << endl
               << endl;

          p1 *= p5;
          cout << "p1 after p1*=p5: " << p1 << endl;
          cout << p1.list();
          cout << "order is: " << p1.order() << endl
               << endl;
     }
     return true;
}

bool test_operator_divide(bool debug = false)
{
     if (debug)
     {
          double coefs1[] = {2.0, 2.0};
          Poly p1(coefs1, 1);
          cout << "p1: " << p1 << endl;
          cout << p1.list();
          cout << "order is: " << p1.order() << endl
               << endl;

          vector<double> vec = {2.0};
          Poly p3(vec);
          cout << "p3: " << p3 << endl;
          cout << p3.list();
          cout << "order is: " << p3.order() << endl
               << endl;

          p1 = p1 / p3;
          cout << "p1: " << p1 << endl;
          cout << p1.list();
          cout << "order is: " << p1.order() << endl
               << endl;

          vector<double> v2;
          Poly p4(v2);
          cout << "p4: " << p4 << endl;
          cout << p4.list();
          cout << "order is: " << p4.order() << endl
               << endl;

          vector<double> v5 = {25, 10, 21, 34, 30, 16, 17, 12};
          Poly p5(v5);
          vector<double> v6 = {5, 1, 2, 3, 4};
          Poly p6(v6);

          p4 = p5 / p6;
          cout << "p4 after p4 = p5/p6: " << p4 << endl;
          cout << p4.list();
          cout << "order is: " << p4.order() << endl
               << endl;
          //[ +12.0X^7 +17.0X^6 +16.0X^5 +30.0X^4 +34.0X^3 +21.0X^2 +10.0X +25.0 ]
          //[ +4.0X^4 +3.0X^3 +2.0X^2 +1.0X +5.0 ]

          return true;
     }
}

// major arithmetic operators
void test_plus(const Poly &p, const Poly &q)
{
     Poly r = p + q;
     cout << p << " + " << q << endl;
     cout << "      = " << r;

     // if r = p + q then r - q should be equal to p:
     if (r - q == p)
     {
          cout << "VERIFIED" << endl;
     }
     else
     {
          cout << endl
               << "   ***VERIFICATION FAILED" << endl;
          cout << "   r - q: " << r - q << endl;
          cout << "   r - q: " << r - q << "=/=" << p << endl;
     }
}

void test_minus(const Poly &p, const Poly &q)
{
     Poly r = p - q;
     cout << p << " - " << q << endl;
     cout << "      = " << r;

     // if r = p - q then p should be equal to r + q:
     if (r + q == p)
     {
          cout << "VERIFIED" << endl;
     }
     else
     {
          cout << endl
               << "   ***VERIFICATION FAILED" << endl;
          cout << "   r + q: " << r + q << endl;
          cout << "   r + q: " << r + q << "=/=" << p << endl;
     }
}

void test_multiply(const Poly &p, const Poly &q)
{
     Poly r = p * q;
     cout << p << " * " << q << endl;
     cout << "      = " << r;

     // if r = p * q then p should be equal to r / q:
     if (r / q == p)
     {
          cout << "VERIFIED" << endl;
     }
     else
     {
          cout << endl
               << "   ***VERIFICATION FAILED" << endl;
          cout << "   r / q: " << r / q << endl;
          cout << "   r / q: " << r / q << "=/=" << p << endl;
     }
}

void test_division(const Poly &p, const Poly &q)
{
     Poly r = p / q;
     Poly rem = p % q;
     cout << p << " / " << q << endl;
     cout << "      = " << r << "   rem = " << rem;

     // if r = p / q then r * q + p % q should be equal to p:
     if (r * q + p % q == p)
     {
          cout << "VERIFIED" << endl;
     }
     else
     {
          cout << endl
               << "   ***VERIFICATION FAILED" << endl;
          cout << "   r * q: " << r * q << endl;
          cout << "   p % q: " << p % q << endl;
          cout << "   r * q + p % q: " << r * q + p % q << "=/=" << p << endl;
     }
}

bool test_major_operators(bool debug = false)
{
     if (debug)
     {
          cout << "\n\n\n";

          // P: [+3.0X^3 +2.0X^2 +X +5.0 ]
          // Q: [+4.0X^4 +3.0X^3 +2.0X^2 +X +5.0 ]
          double coefs_p1[] = {5.0, 1.0, 2.0, 3.0};
          double coefs_q1[] = {5.0, 1.0, 2.0, 3.0, 4.0};
          Poly p1(coefs_p1, 3);
          Poly q1(coefs_q1, 4);

          cout << "P1: " << p1 << endl;
          cout << "Q1: " << q1 << endl;
          //+
          test_plus(p1, q1);
          test_plus(q1, p1);
          //-
          test_minus(p1, q1);
          test_minus(q1, p1);
          //*
          test_multiply(p1, q1);
          test_multiply(q1, p1);
          // div
          test_division(p1, q1);
          test_division(q1, p1);

          // for additional testing
          double coefs3[] = {-2.0, 1.0, 1.0};
          double coefs4[] = {-1.0, 1.0};
          Poly p3(coefs3, 2);
          Poly p4(coefs4, 1);
          // cout << "p3: " << p3 << endl;
          // cout << "p4: " << p4 << endl;
          test_division(p3, p4);

          cout << "--------------------------------------------------\n";
          double coefs5[] = {3.0, -2.0, 0.0, 4.0, 0.0, 6.0};
          double coefs6[] = {5.0, 1, 2.0, 3.0, 4.0};
          Poly p5(coefs5, 5);
          Poly p6(coefs6, 4);
          test_plus(p5, p6);
          test_minus(p5, p6);
          test_multiply(p5, p6);
          test_division(p5, p6);

          // test with zero
          Poly p7;

          test_plus(p5, p7);
          test_minus(p5, p7);
          test_multiply(p7, p5);

          Poly p8;
          test_minus(p7, p8);
          test_minus(p8, p7);
          double coefs9[] = {0.0, 0, 0.0, 0.0, 0.0};
          Poly p9(coefs9, 4);
          cout << "p9: " << p9 << endl;
          cout << "p9.order: " << p9.order() << endl;

          p5 = p5;
          cout << "p5: " << p5 << endl;

          return true;
     }
}

void toUseLater()
{
     // p: [ +48.0X^12 +32.0X^11 +35.0X^10 +3.0X^9 +6.0X^8 +10.0X^7 +5.0X^6 +24.0X^5 +1.0X^4 +31.0X^3 +27.0X^2 +49.0X ] [12]
     vector<double> v = {0, 49};
     Poly p(v);
     cout << "p: " << p << endl;
     cout << p.list();
     cout << "order is: " << p.order() << endl
          << endl;

     Poly q;
     cout << "q: " << q << endl;
     cout << q.list();
     cout << "order is: " << q.order() << endl
          << endl;

     Poly sum = p + q;
     cout << "sum: " << sum << endl;
     cout << sum.list();
     q = sum - p;
     cout << "sum - p = q: " << q << endl;
     cout << q.list();
     cout << "order is: " << q.order() << endl
          << endl;

     vector<double> vMain = {0, 2};
     Poly p2(vMain);
     Poly p3(vMain);

     cout << "p2 - p3: " << p3 - p2 << endl;
}

TEST(TEST_STUB, TestTermOperators)
{

     EXPECT_EQ(1, test_term_operators(false));
}

TEST(TEST_STUB, TestCTOR)
{

     EXPECT_EQ(1, test_CTOR(false));
}

TEST(TEST_STUB, TestAssignment)
{

     EXPECT_EQ(1, test_assignment(false));
}

TEST(TEST_STUB, TestPlus)
{

     EXPECT_EQ(1, test_operator_plus(false));
}

TEST(TEST_STUB, TestMinus)
{

     EXPECT_EQ(1, test_operator_minus(false));
}

TEST(TEST_STUB, TestMultiply)
{

     EXPECT_EQ(1, test_operator_multiply(false));
}

TEST(TEST_STUB, TestDivide)
{

     EXPECT_EQ(1, test_operator_divide(true));
}

TEST(TEST_STUB, TestMajorOperators)
{

     EXPECT_EQ(1, test_major_operators(false));
}

int main(int argc, char **argv)
{
     ::testing::InitGoogleTest(&argc, argv);
     std::cout << "\n\n----------running testB.cpp---------\n\n"
               << std::endl;
     return RUN_ALL_TESTS();
}
