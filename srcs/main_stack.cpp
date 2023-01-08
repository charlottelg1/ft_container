# include <stack>
# include <iostream>
# include <vector>
# include "../includes/vector.hpp"
# include "../includes/ft_enable_if.hpp"
# include "../includes/ft_equal.hpp"
# include "../includes/ft_is_integral.hpp"
# include "../includes/iterator/ft_iterator_traits.hpp"
# include "../includes/ft_lexicographical_compare.hpp"
# include "../includes/ft_pair.hpp"
# include "../includes/iterator/ft_random_access_iterator.hpp"
# include "../includes/iterator/ft_reverse_iterator.hpp"

# include "../includes/stack.hpp"

void	test_stack_constructor()
{
	// DEFAULT CONSTRUCTOR
	NS::stack<int>	stack1;
	// COPY CONSTRUCTOR
	NS::stack<int>	stack2(stack1);
	// OPERATOR =
	NS::stack<int>	stack3;
	stack1 = stack3;

}

void	test_stack()
{
	std::cout << std::boolalpha;
	
	NS::stack<int>	stack1;

	std::cout << "EMPTY\n";
	std::cout << "stack1 empty : " << stack1.empty()<< std::endl;
	std::cout << "stack1 size : " << stack1.size() << std::endl;

	stack1.push(4);

	std::cout << "\nPUSH 4\n";
	std::cout << "stack1 empty : " << stack1.empty() << std::endl;
	std::cout << "stack1 size : " << stack1.size() << std::endl;
	std::cout << "stack1 top : " << stack1.top() << std::endl;

	stack1.push(5);

	std::cout << "\nPUSH 5\n";
	std::cout << "stack1 empty : " << stack1.empty() << std::endl;
	std::cout << "stack1 size : " << stack1.size() << std::endl;
	std::cout << "stack1 top : " << stack1.top() << std::endl;

	stack1.pop();

	std::cout << "\nPOP\n";
	std::cout << "stack1 empty : " << stack1.empty() << std::endl;
	std::cout << "stack1 size : " << stack1.size() << std::endl;
	std::cout << "stack1 top : " << stack1.top() << std::endl;
}

void	test_stack_comparison()
{
	std::cout << std::boolalpha;

	NS::stack<int> stack1;
	stack1.push(1);
	stack1.push(2);
	stack1.push(3);

	NS::stack<int> stack2(stack1);

	NS::stack<int> stack3;
	stack3.push(2);
	stack3.push(3);
	stack3.push(4);

	std::cout << (stack1 == stack2) << std::endl;
	std::cout << (stack2 != stack3) << std::endl;
	std::cout << (stack1 < stack3) << std::endl;
	std::cout << (stack1 <= stack2) << std::endl;
	std::cout << (stack3 > stack2) << std::endl;
	std::cout << (stack3 >= stack1) << std::endl;
}

void	test_stack_basic()
{
	std::cout << "# test_stack" << std::endl;
	std::cout << "/* ********************************************************************** */" << std::endl;
	std::cout << "/*                          "<< "BASIC TESTS" <<"                                   */" << std::endl;
	std::cout << "/* ********************************************************************** */" << std::endl;
	NS::stack<int> mystack;

	std::cout << "stack<" << "int" << "> mystack" << std::endl;
	std::cout << std::endl;


	std::cout << "# empty" << std::endl;
	std::cout << "mystack.empty(): " <<  mystack.empty() << std::endl;
	std::cout << "mystack.size(): " << mystack.size() << std::endl;
	std::cout << "# one element" << std::endl;
	mystack.push(42);
	std::cout << "mystack.push(42)" << std::endl;
	std::cout << "mystack.empty(): " <<  mystack.empty() << std::endl;
	std::cout << "mystack.size(): " << mystack.size() << std::endl;
	std::cout << "mystack.top(): " << mystack.top() << std::endl;
	std::cout << "# two element" << std::endl;
	mystack.push(2);
	std::cout << "mystack.push(2)" << std::endl;
	std::cout << "mystack.size(): " << mystack.size() << std::endl;
	std::cout << "mystack.top(): " << mystack.top() << std::endl;
	std::cout << "# pop element" << std::endl;
	mystack.pop();
	std::cout << "mystack.pop()" << std::endl;
	std::cout << "mystack.size(): " << mystack.size() << std::endl;
	std::cout << "mystack.top(): " << mystack.top() << std::endl;
	std::cout << std::endl;

	NS::stack<int, NS::vector<int> > mystack2;

	std::cout << "stack<" << "int" << ", " << "ft::vector" << "> mystack2" << std::endl;
	std::cout << std::endl;


	std::cout << "# empty" << std::endl;
	std::cout << "mystack2.empty(): " <<  mystack2.empty() << std::endl;
	std::cout << "mystack2.size(): " << mystack2.size() << std::endl;
	std::cout << "# one element" << std::endl;
	mystack2.push(42);
	std::cout << "mystack2.push(42)" << std::endl;
	std::cout << "mystack2.empty(): " <<  mystack2.empty() << std::endl;
	std::cout << "mystack2.size(): " << mystack2.size() << std::endl;
	std::cout << "mystack2.top(): " << mystack2.top() << std::endl;
	std::cout << "# two element" << std::endl;
	mystack2.push(2);
	std::cout << "mystack2.push(2)" << std::endl;
	std::cout << "mystack2.size(): " << mystack2.size() << std::endl;
	std::cout << "mystack2.top(): " << mystack2.top() << std::endl;
	std::cout << "# pop element" << std::endl;
	mystack2.pop();
	std::cout << "mystack2.pop()" << std::endl;
	std::cout << "mystack2.size(): " << mystack2.size() << std::endl;
	std::cout << "mystack2.top(): " << mystack2.top() << std::endl;
	std::cout << std::endl;

	std::cout << "# test cpy and equality" << std::endl;
	NS::stack<int>	cpystack = mystack;
	std::cout << "stack<" << "int" << "> cpystack = mystack" << std::endl;
	std::cout << std::endl;

	std::cout << "cpystack == mystack:" << (cpystack == mystack) << std::endl;
	cpystack.push(7);
	std::cout << "cpystack.push(7)" << std::endl;
	std::cout << "cpystack == mystack:" << (cpystack == mystack) << std::endl;
}

int	main ()
{
	test_stack_constructor();
	test_stack();
	test_stack_comparison();
	test_stack_basic();
	return (0);
}