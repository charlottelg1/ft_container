# include "../includes/set.hpp"
# include <set>
# include <list>

void	test_set_constructor()
{
	std::cout << "\n\nCONSTRUCTORS\n";
	ft::set<int>	set1;

	set1.insert(4);
	set1.insert(5);

	ft::set<int>	set2(set1.begin(), set1.end());
	ft::set<int>	set3(set2);

	ft::set<int>	set4;
	set4 = set2;
}

void	test_set_capacity()
{
	std::cout << "\n\nCAPACITY\n";

	ft::set<int>	set1;

	std::cout << "empty : " << set1.empty() << std::endl;
	std::cout << "size : " << set1.size() << std::endl;
	std::cout << "max_size : " << set1.max_size() << std::endl;
	std::cout << std::endl;
	
	set1.insert(1);

	std::cout << "empty : " << set1.empty() << std::endl;
	std::cout << "size : " << set1.size() << std::endl;
	std::cout << "max_size : " << set1.max_size() << std::endl;
	std::cout << std::endl;

	set1.insert(2);

	std::cout << "empty : " << set1.empty() << std::endl;
	std::cout << "size : " << set1.size() << std::endl;
	std::cout << "max_size : " << set1.max_size() << std::endl;
	std::cout << std::endl;

	set1.insert(2);

	std::cout << "empty : " << set1.empty() << std::endl;
	std::cout << "size : " << set1.size() << std::endl;
	std::cout << "max_size : " << set1.max_size() << std::endl;

}

void	test_set_modifiers()
{
	std::cout << "\n\nMODIFIERS\n";
	
	ft::set<int>	set1;

	set1.insert(1);
	set1.insert(2);
	set1.insert(3);
	set1.insert(4);

	ft::set<int>	set3;

	set3.insert(1);
	set3.insert(7);
	set3.insert(10);
	set3.insert(2);
	set3.insert(3);
	set3.insert(11);

	set3.begin()++;

	// INSERT
	std::cout << "\nINSERT\n";
	ft::set<int>	set2;

	set2.insert(set1.begin(), set1.end());
	
	ft::set<int>::iterator it = set2.begin();
	set2.insert(it, 6);
	
	// SWAP
	std::cout << "\nSWAP\n";
	std::cout << "set1 size : " << set1.size() << std::endl;
	std::cout << "set3 size : " << set3.size() << std::endl;
	set3.swap(set1);
	std::cout << "set1 size : " << set1.size() << std::endl;
	std::cout << "set3 size : " << set3.size() << std::endl;

	// ERASE
	std::cout << "\nERASE\n";
	std::cout << "size : " << set3.size() << std::endl;
	std::cout << "empty : " << set3.empty() << std::endl;

	std::cout << "begin : " << (*(set3.begin())) << " end : " << (*(set3.end())) << std::endl;

	set3.erase(set3.begin());

	std::cout << "size : " << set3.size() << std::endl;
	std::cout << "empty : " << set3.empty() << std::endl;
	
	std::cout << "begin : " << (*(set3.begin())) << " end : " << (*(set3.end())) << std::endl;

	set3.erase(set3.begin(), set3.end());
	std::cout << "size : " << set3.size() << std::endl;
	std::cout << "empty : " << set3.empty() << std::endl;

	set1.insert(1);
	set1.insert(2);
	set1.insert(3);
	set1.insert(4);
	
	// CLEAR
	std::cout << "\nCLEAR\n";
	std::cout << "empty : " << set1.empty() << std::endl;
	set1.clear();
	std::cout << "empty : " << set1.empty() << std::endl;
}

void	test_set_lookup()
{
	std::cout << "\n\nLOOKUP\n";
	ft::set<int>	set1;

	set1.insert(1);
	set1.insert(2);
	// set1.insert(3);
	set1.insert(4);

	std::cout << "\nCOUNT\n";
	std::cout << set1.count(1) << std::endl;
	std::cout << set1.count(6) << std::endl;

	std::cout << "\nLOOKUP\n";
	std::cout << "\nLOWER\n";
	ft::set<int>::iterator	ite;
	ite = set1.lower_bound(1);
	std::cout << *ite << " " << *ite << std::endl;
	ite = set1.lower_bound(2);
	std::cout << *ite << " " << *ite << std::endl;
	ite = set1.lower_bound(3);
	std::cout << *ite << " " << *ite << std::endl;
	std::cout << "\nUPPER\n";
	ite = set1.upper_bound(1);
	std::cout << *ite << " " << *ite << std::endl;
	ite = set1.upper_bound(2);
	std::cout << *ite << " " << *ite << std::endl;
	ite = set1.upper_bound(4);
	std::cout << *ite << " " << *ite << std::endl;

}

void	test_set_comparison()
{
	std::cout << "\n\nCOMP\n";

	ft::set<int>	set1;

	set1.insert(1);
	set1.insert(2);
	set1.insert(7);
	set1.insert(4);

	ft::set<int>	set2(set1);

	ft::set<int>	set3;

	set3.insert(1);
	set3.insert(7);
	set3.insert(10);

	std::cout << "1) " << (set1 == set2) << std::endl;
	std::cout << "2) " << (set1 != set3) << std::endl;
	std::cout << "3) " << (set1 < set3) << std::endl;
	std::cout << "4) " << (set2 <= set3) << std::endl;
	std::cout << "5) " << (set1 <= set2) << std::endl;
	std::cout << "6) " << (set3 > set2) << std::endl;
	std::cout << "7) " << (set3 >= set2) << std::endl;
	std::cout << "8) " << (set2 >= set1) << std::endl;
}

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "value: " << *iterator;
	if (nl)
		o << std::endl;
	return ("");
}


void	test_set_bounds()
{
	int iter = 0;
	int param = 10;
	NS::set<int>	lst;
	for (int i = 0; i < 10; i++)
		lst.insert(i);
	
	{
		NS::set<int>::iterator ite = lst.end(), it[2];
		NS::pair<NS::set<int>::iterator, NS::set<int>::iterator> ft_range;

		std::cout << "\t-- [" << iter++ << "] --" << std::endl;
		std::cout << "with key [" << param << "]:" << std::endl;
		it[0] = lst.lower_bound(param); it[1] = lst.upper_bound(param);
		ft_range = lst.equal_range(param);
		std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
		std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
		std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
	}

	{
		NS::set<int>::const_iterator ite = lst.end(), it[2];
		NS::pair<NS::set<int>::const_iterator, NS::set<int>::const_iterator> ft_range;

		std::cout << "\t-- [" << iter++ << "] (const) --" << std::endl;
		std::cout << "with key [" << param << "]:" << std::endl;
		it[0] = lst.lower_bound(param); it[1] = lst.upper_bound(param);
		ft_range = lst.equal_range(param);
		std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
		std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
		std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
	}
}

int	main()
{
	std::cout << std::boolalpha;

	test_set_constructor();
	test_set_capacity();
	test_set_modifiers();
	test_set_lookup();
	test_set_comparison();
	test_set_bounds();
	return (0);
}