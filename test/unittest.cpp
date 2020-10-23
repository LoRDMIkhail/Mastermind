#include "../src/Logic.hpp"
#include "gtest/gtest.h"
#include <limits.h>

namespace {

TEST(CheckKursSim, NoZeroFirst)
{
    char a[] = {'1', '2', '3', '4'};
    Logic test1(a, a);
    ASSERT_EQ(true, test1.CheckKursSim(1, 0));
    char b[] = {'1', '0', '0', '0'};
    Logic test2(b, a);
    ASSERT_EQ(true, test2.CheckKursSim(1, 0));
    char c[] = {'2', '3', '4', '5'};
    Logic test3(c, a);
    ASSERT_EQ(true, test3.CheckKursSim(1, 0));
    char d[] = {'2', '0', '0', '0'};
    Logic test4(d, a);
    ASSERT_EQ(true, test4.CheckKursSim(1, 0));
    char e[] = {'3', '4', '5', '6'};
    Logic test5(e, a);
    ASSERT_EQ(true, test5.CheckKursSim(1, 0));
    char f[] = {'3', '0', '0', '0'};
    Logic test6(f, a);
    ASSERT_EQ(true, test6.CheckKursSim(1, 0));
    char g[] = {'4', '5', '6', '7'};
    Logic test7(g, a);
    ASSERT_EQ(true, test7.CheckKursSim(1, 0));
    char h[] = {'4', '0', '0', '0'};
    Logic test8(h, a);
    ASSERT_EQ(true, test8.CheckKursSim(1, 0));
    char o[] = {'9', '0', '0', '0'};
    Logic test9(o, a);
    ASSERT_EQ(true, test9.CheckKursSim(1, 0));
    char p[] = {'9', '9', '9', '9'};
    Logic test10(p, a);
    ASSERT_EQ(true, test10.CheckKursSim(1, 0));
}
TEST(CheckKursSim, ZeroFirst)
{
    char a[] = {'0', '0', '0', '0'};
    Logic test1(a, a);
    ASSERT_EQ(false, test1.CheckKursSim(1, 0));
    char b[] = {'0', '1', '2', '3'};
    Logic test2(b, a);
    ASSERT_EQ(false, test2.CheckKursSim(1, 0));
    char c[] = {'0', '4', '5', '6'};
    Logic test3(c, a);
    ASSERT_EQ(false, test3.CheckKursSim(1, 0));
    char d[] = {'0', '7', '8', '9'};
    Logic test4(d, a);
    ASSERT_EQ(false, test4.CheckKursSim(1, 0));
    char e[] = {'0', '2', '3', '4'};
    Logic test5(e, a);
    ASSERT_EQ(false, test5.CheckKursSim(1, 0));
    char f[] = {'0', '3', '4', '5'};
    Logic test6(f, a);
    ASSERT_EQ(false, test6.CheckKursSim(1, 0));
    char g[] = {'0', '5', '6', '7'};
    Logic test7(g, a);
    ASSERT_EQ(false, test7.CheckKursSim(1, 0));
    char h[] = {'0', '6', '7', '8'};
    Logic test8(h, a);
    ASSERT_EQ(false, test8.CheckKursSim(1, 0));
    char o[] = {'0', '8', '9', '0'};
    Logic test9(o, a);
    ASSERT_EQ(false, test9.CheckKursSim(1, 0));
    char p[] = {'0', '9', '9', '9'};
    Logic test10(p, a);
    ASSERT_EQ(false, test10.CheckKursSim(1, 0));
}
TEST(CheckKursSim, 2check)
{
    char a[] = {'1', '2', '3', '4'};
    Logic test1(a, a);
    ASSERT_EQ(true, test1.CheckKursSim(2, 1));
    char b[] = {'2', '3', '4', '5'};
    Logic test2(b, a);
    ASSERT_EQ(true, test2.CheckKursSim(2, 2));
    char c[] = {'3', '4', '5', '6'};
    Logic test3(c, a);
    ASSERT_EQ(true, test3.CheckKursSim(2, 3));
    char d[] = {'4', '5', '6', '7'};
    Logic test4(d, a);
    ASSERT_EQ(true, test4.CheckKursSim(2, 4));
    char e[] = {'5', '6', '7', '8'};
    Logic test5(e, a);
    ASSERT_EQ(true, test5.CheckKursSim(2, 5));
    char f[] = {'6', '7', '8', '9'};
    Logic test6(f, a);
    ASSERT_EQ(true, test6.CheckKursSim(2, 6));
    char g[] = {'7', '8', '9', '0'};
    Logic test7(g, a);
    ASSERT_EQ(true, test7.CheckKursSim(2, 7));
    char h[] = {'8', '9', '0', '1'};
    Logic test8(h, a);
    ASSERT_EQ(true, test8.CheckKursSim(2, 8));
    char o[] = {'9', '0', '1', '2'};
    Logic test9(o, a);
    ASSERT_EQ(true, test9.CheckKursSim(2, 9));
}
TEST(CheckKursSim, 3check)
{
    char a[] = {'1', '2', '3', '4'};
    Logic test1(a, a);
    ASSERT_EQ(true, test1.CheckKursSim(3, 1));
    char b[] = {'2', '3', '4', '5'};
    Logic test2(b, a);
    ASSERT_EQ(true, test2.CheckKursSim(3, 2));
    char c[] = {'3', '4', '5', '6'};
    Logic test3(c, a);
    ASSERT_EQ(true, test3.CheckKursSim(3, 3));
    char d[] = {'4', '5', '6', '7'};
    Logic test4(d, a);
    ASSERT_EQ(true, test4.CheckKursSim(3, 4));
    char e[] = {'5', '6', '7', '8'};
    Logic test5(e, a);
    ASSERT_EQ(true, test5.CheckKursSim(3, 5));
    char f[] = {'6', '7', '8', '9'};
    Logic test6(f, a);
    ASSERT_EQ(true, test6.CheckKursSim(3, 6));
    char g[] = {'7', '8', '9', '0'};
    Logic test7(g, a);
    ASSERT_EQ(true, test7.CheckKursSim(3, 7));
    char h[] = {'8', '9', '0', '1'};
    Logic test8(h, a);
    ASSERT_EQ(true, test8.CheckKursSim(3, 8));
    char o[] = {'9', '0', '1', '2'};
    Logic test9(o, a);
    ASSERT_EQ(true, test9.CheckKursSim(3, 9));
}
TEST(CheckKursSim, 4check)
{
    char a[] = {'1', '2', '3', '4'};
    Logic test1(a, a);
    ASSERT_EQ(true, test1.CheckKursSim(4, 1));
    char b[] = {'2', '3', '4', '5'};
    Logic test2(b, a);
    ASSERT_EQ(true, test2.CheckKursSim(4, 2));
    char c[] = {'3', '4', '5', '6'};
    Logic test3(c, a);
    ASSERT_EQ(true, test3.CheckKursSim(4, 3));
    char d[] = {'4', '5', '6', '7'};
    Logic test4(d, a);
    ASSERT_EQ(true, test4.CheckKursSim(4, 4));
    char e[] = {'5', '6', '7', '8'};
    Logic test5(e, a);
    ASSERT_EQ(true, test5.CheckKursSim(4, 5));
    char f[] = {'6', '7', '8', '9'};
    Logic test6(f, a);
    ASSERT_EQ(true, test6.CheckKursSim(4, 6));
    char g[] = {'7', '8', '9', '0'};
    Logic test7(g, a);
    ASSERT_EQ(true, test7.CheckKursSim(4, 7));
    char h[] = {'8', '9', '0', '1'};
    Logic test8(h, a);
    ASSERT_EQ(true, test8.CheckKursSim(4, 8));
    char o[] = {'9', '0', '1', '2'};
    Logic test9(o, a);
    ASSERT_EQ(true, test9.CheckKursSim(4, 9));
}
TEST(CheckMyKurs, Allcorrect)
{
    char a[] = {'1', '2', '3', '4'};
    char b[] = {'1', '2', '3', '4'};
    Logic test1(a, b);
    ASSERT_EQ(true, test1.CheckMyKurs());
    char c[] = {'9', '8', '7', '6'};
    char d[] = {'9', '8', '7', '6'};
    Logic test2(c, d);
    ASSERT_EQ(true, test2.CheckMyKurs());
    char f[] = {'2', '6', '8', '3'};
    char e[] = {'2', '6', '8', '3'};
    Logic test3(f, e);
    ASSERT_EQ(true, test3.CheckMyKurs());
}
TEST(CheckMyKurs, uncorrect)
{
    char a[] = {'1', '2', '3', '5'};
    char b[] = {'1', '2', '3', '4'};
    Logic test1(a, b);
    ASSERT_EQ(false, test1.CheckMyKurs());
    char c[] = {'9', '8', '2', '6'};
    char d[] = {'9', '8', '7', '6'};
    Logic test2(c, d);
    ASSERT_EQ(false, test2.CheckMyKurs());
    char f[] = {'2', '4', '8', '3'};
    char e[] = {'2', '6', '5', '3'};
    Logic test6(f, e);
    ASSERT_EQ(false, test6.CheckMyKurs());
    char g[] = {'3', '5', '6', '1'};
    char h[] = {'2', '6', '8', '3'};
    Logic test3(g, h);
    ASSERT_EQ(false, test3.CheckMyKurs());
}
}
