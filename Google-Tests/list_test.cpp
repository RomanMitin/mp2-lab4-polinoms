#include "pch.h"
#include<algorithm>
#include<vector>
#include"..\\List\list.h"

//TEST(TestCaseName, TestName) {
//  EXPECT_EQ(1, 1);
//  EXPECT_TRUE(true);
//}

TEST(list, can_create_list) {
	ASSERT_NO_THROW(list<int> l());
}

TEST(list, can_add_elemens_in_list) {

	list<int> exp;
	exp.add(0);
	EXPECT_FALSE(exp.empty());
}

TEST(list, can_copy_list) {
	
	list<int> exp;

	for (int i = 0; i < 10; i++)
		exp.add(rand());

	list<int> act(exp);

	EXPECT_EQ(exp, act);
}

TEST(list, can_assign_list) {

	list<int> exp,act;

	for (int i = 0; i < 10; i++)
		exp.add(rand());

	act = exp;

	EXPECT_EQ(exp, act);
}

TEST(list, add_and_sort1) {
	
	list<int> exp, act;

	act.add(1);
	act.add(2);
	act.add(3);
	act.add(4);

	exp.add(4);
	exp.add(3);
	exp.add(2);
	exp.add(1);

	EXPECT_EQ(act, exp);
}

TEST(list, add_and_sort2) {

	list<int> exp, act;

	act.add(1);
	act.add(2);
	act.add(4);
	act.add(3);
	act.add(4);

	exp.add(4);
	exp.add(4);
	exp.add(3);
	exp.add(2);
	exp.add(1);

	EXPECT_EQ(act, exp);
}

TEST(list, add_and_sort3) {

	srand(0);
	const int n = 1000;
	list<int> exp, act;
	std::vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int x = rand();
		act.add(x);
		v.push_back(x);
	}
	std::sort(v.begin(), v.end());
	std::reverse(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		exp.add(v[i]);

	EXPECT_EQ(act, exp);
}