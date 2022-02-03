#include"pch.h"
#include<string>
#include"..\\application\input.h"

TEST(get_number, 1)
{
	std::string s="123(";
	int i = 0;
	double exp = 123.0;
	EXPECT_DOUBLE_EQ(getnumber(s, i), exp);
}

TEST(get_number, 2)
{
	std::string s = "123.05(";
	int i = 0;
	double exp = 123.05;
	EXPECT_DOUBLE_EQ(getnumber(s, i), exp);
}

TEST(get_number, 3)
{
	std::string s = "+123.05(";
	int i = 0;
	double exp = 123.05;
	EXPECT_DOUBLE_EQ(getnumber(s, i), exp);
}

TEST(get_number, 4)
{
	std::string s = "-123.05(";
	int i = 0;
	double exp = -123.05;
	EXPECT_DOUBLE_EQ(getnumber(s, i), exp);
}

TEST(get_number, 5)
{
	std::string s = "(";
	int i = 0;
	double exp = 0.0;
	EXPECT_DOUBLE_EQ(getnumber(s, i), exp);
}

TEST(get_number, 6)
{
	std::string s = "0.5(";
	int i = 0;
	double exp = 0.5;
	EXPECT_DOUBLE_EQ(getnumber(s, i), exp);
}

TEST(get_number, 7)
{
	std::string s = "0.0(";
	int i = 0;
	double exp = 0.0;
	EXPECT_DOUBLE_EQ(getnumber(s, i), exp);
}

TEST(_check_monom, 1)
{
	std::string s = "0.0(";
	int i = 0;
	
	EXPECT_ANY_THROW(check_monom(s, i));
}

TEST(_check_monom, 2)
{
	std::string s = "0.0)";
	int i = 0;

	EXPECT_ANY_THROW(check_monom(s, i));
}

TEST(_check_monom, 3)
{
	std::string s = "3(1234)";
	int i = 0;

	EXPECT_ANY_THROW(check_monom(s, i));
}

TEST(_check_monom, 4)
{
	std::string s = "0.0(123";
	int i = 0;

	EXPECT_ANY_THROW(check_monom(s, i));
}

TEST(_check_monom, 5)
{
	std::string s = "0.0.(123)";
	int i = 0;

	EXPECT_ANY_THROW(check_monom(s, i));
}

TEST(_check_monom, 6)
{
	std::string s = "0.0()";
	int i = 0;

	EXPECT_NO_THROW(check_monom(s, i));
}

TEST(_check_monom, 7)
{
	std::string s = "123(123)";
	int i = 0;

	EXPECT_NO_THROW(check_monom(s, i));
}

TEST(_check_monom, 8)
{
	std::string s = "+123(123)";
	int i = 0;

	EXPECT_NO_THROW(check_monom(s, i));
}

TEST(_check_monom, 9)
{
	std::string s = "-123(123)";
	int i = 0;

	EXPECT_NO_THROW(check_monom(s, i));
}

TEST(_parcer, 1)
{
	std::string s = "-1(123)+3(0)-2(23)";
	
	list<monom> exp;
	exp.add(monom(-1, 123));
	exp.add(monom(3, 0));
	exp.add(monom(-2, 23));

	EXPECT_EQ(exp, parcer(s));
}

TEST(_parcer, 2)
{
	std::string s = "-1(1)+3(10)-2(100)";

	list<monom> exp;
	exp.add(monom(-1, 1));
	exp.add(monom(3, 10));
	exp.add(monom(-2, 100));

	EXPECT_EQ(exp, parcer(s));
}