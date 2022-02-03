#include "pch.h"
#include"..\\Polinoms\polinom.h"

double drand();

TEST(monom, can_create_monom) {
	ASSERT_NO_THROW(monom m());
}

TEST(monom, can_add_monom) {
	monom f(1, 1), s(3, 1), exp(4, 1);
	EXPECT_EQ(f + s, exp);
}

TEST(monom, cant_add_monom_with_different_powers) {
	monom f(1, 2), s(3, 1);
	EXPECT_ANY_THROW(f + s);
}

TEST(monom, can_multiply_monom) {
	monom f(1, 1), s(3, 1), exp(3, 2);
	EXPECT_EQ(f * s, exp);
}

TEST(monom, cant_multiply_monom_when_overflow) {
	monom f(1, 5), s(3, 6);
	EXPECT_ANY_THROW(f + s);
}

TEST(polinom, can_create_polinom)
{
	ASSERT_NO_THROW(polinom m());
}

TEST(polinom, can_add_polinoms1)
{
	list<monom> l1, l2, l3;
	
	for (int i = 0; i < 10; i++)
	{
		l1.add(monom(i * 2 + 1, i));
		l2.add(monom(i * 2 - 1, i));
		if (i != 0)
			l3.add(monom(i * 4, i));
	}

	polinom a(l1), b(l2), exp(l3);

	EXPECT_EQ(a + b, exp);
}

TEST(polinom, can_add_polinoms2)
{
	list<monom> l1, l2, l3;

	for (int i = 0; i < 10; i++)
	{
		double res;
		double x;
		x = drand();
		res = x;
		l1.add(monom(x, i));
		x = drand();
		res += x;
		l2.add(monom(x, i));
		l3.add(monom(res, i));
	}

	polinom a(l1), b(l2), exp(l3);

	EXPECT_EQ(a + b, exp);
}

TEST(polinom, can_subtract_polinoms)
{
	list<monom> l1, l2, l3;

	for (int i = 0; i < 10; i++)
	{
		double res;
		double x;
		x = 1;
		x = drand();
		res = x;
		l1.add(monom(x, i));
		x = drand();
		res -= x;
		l2.add(monom(x, i));
		if(res!=0)
			l3.add(monom(res, i));
	}

	polinom a(l1), b(l2), exp(l3);

	EXPECT_EQ(a - b, exp);
}

TEST(polinom, can_multiply_polinom_and_double)
{
	list<monom> l1, l2;

	for (int i = 0; i < 10; i++)
	{
		double x;
		x = drand();
		l1.add(x);
		l2.add(x * 4.5);
	}

	polinom a(l1), exp(l2);

	EXPECT_EQ(a * 4.5, exp);
}

TEST(polinom, can_multiply_polinoms1)
{
	list<monom> l1, l2, l3;

	for (int i = 0; i < 2; i++)
	{
		double res;
		double x;
		x = i - 2;
		res = x;
		l1.add(monom(x, i*111));
		x = i + 2;
		res *= x;
		l2.add(monom(x, i*111));
		if (res != 0)
			l3.add(monom(res, 2 * i * 111));
	}
	l3.add(monom(-8, 111));


	polinom a(l1), b(l2), exp(l3);

	EXPECT_EQ(a * b, exp);
}

TEST(polinom, can_multiply_polinoms2)
{
	list<monom> l1, l2, l3;

	l1.add(monom(1, 111));
	l1.add(monom(-4, 31));
	l1.add(monom(8, 0));

	l2.add(monom(1, 200));
	l2.add(monom(-0.5, 111));
	l2.add(monom(-0.8, 110));

	l3.add(monom(1, 311));
	l3.add(monom(-4, 231));
	l3.add(monom(8, 200));
	l3.add(monom(-0.5, 222));
	l3.add(monom(2, 142));
	l3.add(monom(-4, 111));
	l3.add(monom(-0.8, 221));
	l3.add(monom(3.2, 141));
	l3.add(monom(-6.4, 110));


	polinom a(l1), b(l2), exp(l3);

	EXPECT_EQ(a * b, exp);
}

TEST(polinom, can_multiply_polinoms3)
{
	list<monom> l1, l2, l3;

	l1.add(monom(1, 2));
	l1.add(monom(-3, 1));
	l1.add(monom(5, 0));

	l2.add(monom(1, 1));
	l2.add(monom(2, 000));
	

	l3.add(monom(1, 3));
	l3.add(monom(-1, 2));
	l3.add(monom(-1, 1));
	l3.add(monom(10, 0));


	polinom a(l1), b(l2), exp(l3);

	EXPECT_EQ(a * b, exp);
}

TEST(polinom, can_multiply_polinoms4)
{
	list<monom> l1, l2;

	for (int i = 0; i < 445; i++)
	{
		if (!check_power(i, i))
			continue;
		
		double x;
		x = drand();
	
		l1.add(monom(x, i));
		x = drand();

		l2.add(monom(x, i));
	}

	polinom a(l1), b(l2);

	EXPECT_NO_THROW(a * b);
}


TEST(polinom, can_multiply_polinoms5)
{
	list<monom> l1, l2,l3;

	l1.add(monom(1e-162, 100));
	l2.add(monom(1e-162, 1));

	polinom a(l1), b(l2), exp(l3);

	EXPECT_EQ(a * b, exp);
}

double drand()
{
	double result = 0;
	while (result == 0)
	{
		result = double(rand() - RAND_MAX / 2) / (rand() + 1) * 100;
	}
	return result;
}