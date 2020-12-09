#include <vector>
#include <stack>
#include "stack.hpp"

namespace stack_test
{
	template<typename T>
	void test1(T &stack)
	{
		int sum = 0;

		for (int i = 1; i <= 3; i++)
			stack.push(i);

		while (!stack.empty())
		{
			sum += stack.top();
			stack.pop();
		}

		std::cout << "total: " << sum << '\n';
		std::cout << "size: " << stack.size() << '\n';
	}

	template<typename T>
	void test2(T &stack)
	{
		std::cout << "0. size: " << stack.size() << '\n';

		for (int i = 0; i < 5; i++)
			stack.push(i);
		std::cout << "1. size: " << stack.size() << '\n';

		stack.pop();
		std::cout << "2. size: " << stack.size() << '\n';
	}

	template<typename T>
	void test3(T &mystack)
	{
		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;

		std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}


	template<typename T>
	void test4(T &a, T &b, T &c)
	{
		std::cout << "Operators test" << std::endl;

		a.push(10);
		a.push(20);
		a.push(30);
		b.push(10);
		b.push(20);
		b.push(30);
		c.push(30);
		c.push(20);
		c.push(10);
		if (a == b)
			std::cout << "a and b are equal\n";
		if (b != c)
			std::cout << "b and c are not equal\n";
		if (b < c)
			std::cout << "b is less than c\n";
		if (c > b)
			std::cout << "c is greater than b\n";
		if (a <= b)
			std::cout << "a is less than or equal to b\n";
		if (a >= b)
			std::cout << "a is greater than or equal to b\n";
	}
}
	int stack_main()
	{
		std::stack<int> lib;
		std::stack<int> my;
		std::cout << "          Lib test 1 " << std::endl;
		stack_test::test1(lib);
		std::cout << "          my test 1" << std::endl;
		stack_test::test1(my);
		std::cout << "          Lib test 2" << std::endl;
		stack_test::test2(lib);
		std::cout << "          my test 2" << std::endl;
		stack_test::test2(my);
		std::cout << "          Lib test 3" << std::endl;
		stack_test::test3(lib);
		std::cout << "          my test 3" << std::endl;
		stack_test::test3(my);
		std::cout << "          Relationship operators lib: " << std::endl;
		std::stack<int> lib1, lib2, lib3;
		stack_test::test4(lib1, lib2, lib3);
		ft::stack<int> my1, my2, my3;
		std::cout << "          Relashionship operators my: " << std::endl;
		stack_test::test4(my1, my2, my3);
		return (1);
	}


