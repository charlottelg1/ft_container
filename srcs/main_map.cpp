# include "../includes/map.hpp"
# include <iostream>
# include <map>
#include <cstdio>
#include <iomanip>

template <class Key, class T>
void	print(NS::map<Key, T>& lst)
{
	std::cout << "printing a map : \n";
	for (typename NS::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}

void	test_map_constructor()
{
	std::cout << "\n\nCONSTRUCTORS\n";
	NS::map<int,int>	map1;

	map1.insert(NS::pair<int,int>(4,4));
	map1.insert(NS::pair<int,int>(5,5));

	NS::map<int,int>	map2(map1.begin(), map1.end());
	NS::map<int,int>	map3(map2);

	NS::map<int,int>	map4;
	map4 = map2;
}

void	test_map_access()
{
	std::cout << "\n\nACCESS\n";
	NS::map<int, int>	map1;

	map1.insert(NS::pair<int,int>(1,1));
	map1.insert(NS::pair<int,int>(2,2));
	map1.insert(NS::pair<int,int>(3,3));
	map1.insert(NS::pair<int,int>(4,5));

	std::cout << map1.at(1) << std::endl;
	std::cout << map1.at(2) << std::endl;
	std::cout << map1.at(3) << std::endl;
	std::cout << map1.at(4) << std::endl;
	// std::cout << map1.at(5) << std::endl;

	std::cout << "\n";
	std::cout << map1[1] <<std::endl;
	std::cout << map1[2] <<std::endl;
	std::cout << map1[3] <<std::endl;
	std::cout << map1[4] <<std::endl;
	// std::cout << map1[5] <<std::endl;
}

void	test_map_capacity()
{
	std::cout << "\n\nCAPACITY\n";

	NS::map<int,int>	map1;

	std::cout << "empty : " << map1.empty() << std::endl;
	std::cout << "size : " << map1.size() << std::endl;
	std::cout << "max_size : " << map1.max_size() << std::endl;
	std::cout << std::endl;
	
	map1.insert(NS::pair<int,int>(1,1));

	std::cout << "empty : " << map1.empty() << std::endl;
	std::cout << "size : " << map1.size() << std::endl;
	std::cout << "max_size : " << map1.max_size() << std::endl;
	std::cout << std::endl;

	map1.insert(NS::pair<int,int>(2,2));

	std::cout << "empty : " << map1.empty() << std::endl;
	std::cout << "size : " << map1.size() << std::endl;
	std::cout << "max_size : " << map1.max_size() << std::endl;
	std::cout << std::endl;

	map1.insert(NS::pair<int,int>(2,3));

	std::cout << "empty : " << map1.empty() << std::endl;
	std::cout << "size : " << map1.size() << std::endl;
	std::cout << "max_size : " << map1.max_size() << std::endl;

}

void	test_map_modifiers()
{
	std::cout << "\n\nMODIFIERS\n";
	
	NS::map<int, int>	map1;

	map1.insert(NS::pair<int,int>(1,1));
	map1.insert(NS::pair<int,int>(2,2));
	map1.insert(NS::pair<int,int>(3,3));
	map1.insert(NS::pair<int,int>(4,5));

	NS::map<int,int>	map3;

	map3.insert(NS::pair<int,int>(1,5));
	map3.insert(NS::pair<int,int>(7,8));
	map3.insert(NS::pair<int,int>(10,11));

	// INSERT
	NS::map<int, int>	map2;

	map2.insert(map1.begin(), map1.end());
	
	NS::map<int,int>::iterator it = map2.begin();
	map2.insert(it, NS::pair<int, int>(6,6));
	
	//SWAP
	std::cout << "map1 size : " << map1.size() << std::endl;
	std::cout << "map1[1] : " << map1.at(1) << std::endl;
	std::cout << "map3 size : " << map3.size() << std::endl;
	std::cout << "map3[1] : " << map3.at(1) << std::endl;
	map3.swap(map1);
	std::cout << "\nSWAP\n";
	std::cout << "map1 size : " << map1.size() << std::endl;
	std::cout << "map1[1] : " << map1.at(1) << std::endl;
	std::cout << "map3 size : " << map3.size() << std::endl;
	std::cout << "map3[1] : " << map3.at(1) << std::endl;

	// ERASE
	std::cout << "size : " << map3.size() << std::endl;
	std::cout << "empty : " << map3.empty() << std::endl;

	map3.erase(map3.begin());

	std::cout << "size : " << map3.size() << std::endl;
	std::cout << "empty : " << map3.empty() << std::endl;

	map3.erase(map3.begin(), map3.end());
	std::cout << "size : " << map3.size() << std::endl;
	std::cout << "empty : " << map3.empty() << std::endl;

	map1.insert(NS::pair<int,int>(1,1));
	map1.insert(NS::pair<int,int>(2,2));
	map1.insert(NS::pair<int,int>(3,3));
	map1.insert(NS::pair<int,int>(4,5));
	
	// CLEAR
	std::cout << "empty : " << map1.empty() << std::endl;
	map1.clear();
	std::cout << "empty : " << map1.empty() << std::endl;
}

void	test_map_lookup()
{
	std::cout << "\n\nLOOKUP\n";
	NS::map<int, int>	map1;

	map1.insert(NS::pair<int,int>(1,1));
	map1.insert(NS::pair<int,int>(2,2));
	map1.insert(NS::pair<int,int>(3,3));
	map1.insert(NS::pair<int,int>(4,5));

	std::cout << "\nCOUNT\n";
	std::cout << map1.count(1) << std::endl;
	std::cout << map1.count(6) << std::endl;

	std::cout << "\nLOOKUP\n";
	std::cout << "\nLOWER\n";
	NS::map<int,int>::iterator	ite;
	ite = map1.lower_bound(1);
	std::cout << ite->first << " " << ite->second << std::endl;
	ite = map1.lower_bound(2);
	std::cout << ite->first << " " << ite->second << std::endl;
	ite = map1.lower_bound(3);
	std::cout << ite->first << " " << ite->second << std::endl;
	std::cout << "\nUPPER\n";
	ite = map1.upper_bound(1);
	std::cout << ite->first << " " << ite->second << std::endl;
	ite = map1.upper_bound(2);
	std::cout << ite->first << " " << ite->second << std::endl;
	ite = map1.upper_bound(3);
	std::cout << ite->first << " " << ite->second << std::endl;

}

void	test_map_comparison()
{
	std::cout << "\n\nCOMP\n";

	NS::map<int, int>	map1;

	map1.insert(NS::pair<int,int>(1,1));
	map1.insert(NS::pair<int,int>(2,2));
	map1.insert(NS::pair<int,int>(7,6));
	map1.insert(NS::pair<int,int>(4,5));

	NS::map<int,int>	map2(map1);

	NS::map<int,int>	map3;

	map3.insert(NS::pair<int,int>(1,5));
	map3.insert(NS::pair<int,int>(7,8));
	map3.insert(NS::pair<int,int>(10,11));

	std::cout << "1) " << (map1 == map2) << std::endl;
	std::cout << "2) " << (map1 != map3) << std::endl;
	std::cout << "3) " << (map1 < map3) << std::endl;
	std::cout << "4) " << (map2 <= map3) << std::endl;
	std::cout << "5) " << (map1 <= map2) << std::endl;
	std::cout << "6) " << (map3 > map2) << std::endl;
	std::cout << "7) " << (map3 >= map2) << std::endl;
	std::cout << "8) " << (map2 >= map1) << std::endl;

}

#include <unistd.h>

void	test_map_rbegin()
{
	NS::map<char,int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	std::cout << mymap.rbegin()->first;

	// show content:
	NS::map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';
	

	for (NS::map<char,int>::const_reverse_iterator it=mymap.rbegin(); it!=mymap.rend(); it++)
		std::cout << it->first << " => " << it->second << '\n';

	NS::map<char, int>::const_reverse_iterator it = mymap.rbegin();
	NS::map<char, int>::const_reverse_iterator ti = mymap.rend();

	it++;
	++it;
	it--;
	--it;

	ti--;
	--ti;
	++ti;
	ti++;

	ti = it;

	NS::map<char, int>::reverse_iterator end = mymap.rend();
	while(it != end)
	{
		std::cout << it->first << " => " << it->second << '\n';
		it++;
	}
}

#define T1 int
#define T2 std::string

ft::map<T1, T2> mp;
ft::map<T1, T2>::iterator it = mp.end();

void	ft_find(T1 const &k)
{
	ft::map<T1, T2>::iterator ret = mp.find(k);

	if (ret != it)
		std::cout << ret->first << ret->second << std::endl;
	else
		std::cout << "map::find(" << k << ") returned end()" << std::endl;
}

void	ft_count(T1 const &k)
{
	std::cout << "map::count(" << k << ")\treturned [" << mp.count(k) << "]" << std::endl;
}

void		test_map_found(void)
{
	mp[42] = "fgzgxfn";
	mp[25] = "funny";
	mp[80] = "hey";
	mp[12] = "no";
	mp[27] = "bee";
	mp[90] = "8";
	std::cout << mp.size() <<std::endl ;

	std::cout << "\t-- FIND --" << std::endl;
	ft_find(12);
	ft_find(3);
	ft_find(35);
	ft_find(90);
	ft_find(100);

	std::cout << "\t-- COUNT --" << std::endl;
	ft_count(-3);
	ft_count(12);
	ft_count(3);
	ft_count(35);
	ft_count(90);
	ft_count(100);

	mp.find(27)->second = "newly inserted mapped_value";

	std::cout << mp.size() << std::endl; 

	ft::map<T1, T2> const c_map(mp.begin(), mp.end());
	std::cout << "const map.find(" << 42 << ")->second: [" << c_map.find(42)->second << "]" << std::endl;
	std::cout << "const map.count(" << 80 << "): [" << c_map.count(80) << "]" << std::endl;
}

void	test_map_full()
{
	std::cout << "# test_map" << std::endl;
	std::cout <<   "/* ********************************************************************** */" << std::endl;
	std::cout << "/*                          "<< "BASIC TESTS" <<  "                                   */" << std::endl;
	std::cout << "/* ********************************************************************** */" << std::endl;
	std::cout << std::endl;


	NS::map<std::string, int> mymap;
	print(mymap);


	std::cout << "mymap<" << "string" << ", " << "int" <<"> mymap;" << std::endl;

	std::cout << std::endl;
	std::cout << "mymap.max_size(): " << (mymap.max_size() > 10000) << std::endl;
	print(mymap);
	std::cout << std::endl;


	print(mymap);
	mymap.insert(NS::pair<std::string, int>("ft", 42));

	print(mymap);
	mymap.insert(NS::pair<std::string, int>("one", 1));


	std::cout << "# testing upper/lower_bound" << std::endl;
	NS::map<std::string, int>::iterator mit;
	NS::map<std::string, int>::iterator it;
	print(mymap);
	it = mymap.lower_bound("aaa");
	print(mymap);
	std::cout << std::setw(40) << "mymap.lower_bound(\"aaa\"): " << it->first << ":" << it->second << std::endl;
	std::cout << std::endl;
	print(mymap);
	it = mymap.lower_bound("one");
	print(mymap);
	std::cout << std::setw(40) << "mymap.lower_bound(\"one\"): " << it->first << ":" << it->second << std::endl;
	std::cout << std::endl;
	print(mymap);
	it = mymap.lower_bound("oae");
	print(mymap);
	std::cout << std::setw(40) << "mymap.lower_bound(\"oae\"): " << it->first << ":" << it->second << std::endl;
	std::cout << std::endl;
	print(mymap);
	it = mymap.lower_bound("ft");
	print(mymap);
	std::cout << std::setw(40) << "mymap.lower_bound(\"ft\"): " << it->first << ":" << it->second << std::endl;
	std::cout << std::endl;
	print(mymap);
	it = mymap.lower_bound("zzz");
	print(mymap);
	
	if (it == mymap.end())
		std::cout << std::setw(40) << "mymap.lower_bound(\"zzz\"): mymap.end()" << std::endl;
	std::cout << std::endl;
	print(mymap);
	it = mymap.upper_bound("aaa");
	
	print(mymap);
	std::cout << std::setw(40) << "mymap.upper_bound(\"aaa\"): " << it->first << ":" << it->second << std::endl;;
	std::cout << std::endl;
	print(mymap);
	it = mymap.upper_bound("oae");
	print(mymap);
	std::cout << std::setw(40) << "mymap.upper_bound(\"oae\"): " << it->first << ":" << it->second << std::endl;;
	std::cout << std::endl;
	print(mymap);
	it = mymap.upper_bound("one");
	
	if (it == mymap.end())
		std::cout << std::setw(40) << "mymap.upper_bound(\"one\"): mymap.end()" << std::endl;
	print(mymap);
	std::cout << std::endl;
	it = mymap.upper_bound("ft");
	print(mymap);
	std::cout << std::setw(40) << "mymap.upper_bound(\"ft\"): " << it->first << ":" << it->second << std::endl;;
	std::cout << std::endl;
	print(mymap);
	it = mymap.upper_bound("zzz");
	
	if (it == mymap.end())
		std::cout << std::setw(40) << "mymap.upper_bound(\"zzz\"): mymap.end()" << std::endl;
	print(mymap);
	std::cout << std::endl;

	print(mymap);
	mymap.erase("undefined");
	print(mymap);
	mymap.erase("ft");
	print(mymap);
	std::cout << "# double clear" << std::endl;
	mymap.clear();
	print(mymap);
	mymap.clear();
	print(mymap);
	mymap["lol"];
	print(mymap);
	mymap.insert(NS::pair<std::string, int>("xD", 123));
	print(mymap);
	mymap.insert(mymap.end(), NS::pair<std::string, int>("uch", 442));
	print(mymap);
	mymap.insert(mymap.begin(), NS::pair<std::string, int>("uch", 22));
	print(mymap);
	mymap.insert(mymap.end(), NS::pair<std::string, int>("uch", 23));
	print(mymap);
	mymap.insert(NS::pair<std::string, int>("uch", 23));
	print(mymap);
	mymap["lol"] = 8;


	print(mymap);
	NS::map<std::string, int> map2;

	print(mymap);
	print(map2);
	std::cout << "mymap<" << "string" << ", " << "int" <<"> mymap2;" << std::endl;
	print(mymap);
	std::cout << "empty line\n";
	print(map2);
	std::cout << "empty line2\n";

	swap(mymap, map2);
	std::cout << "empty line3\n";
	print(mymap);
	std::cout << "empty line4\n";
	print(map2);
	std::cout << "empty line5\n";

	mymap = map2;
	print(mymap);
	print(map2);

	std::cout << std::setw(40) << "map == map2: " << (mymap == map2) << std::endl;
	print(mymap);
	print(map2);
	std::cout << std::endl;

	mymap.clear();
	print(mymap);
	print(map2);

	mymap["satan"] = 666;
	print(mymap);
	print(map2);
	std::cout << std::setw(40) << "mymap == map2: " << (mymap == map2) << std::endl;
	print(mymap);
	print(map2);
	std::cout << std::endl;
	std::cout << std::setw(40) << "mymap <= map2: " << (mymap <= map2) << std::endl;
	print(mymap);
	print(map2);
	std::cout << std::endl;
	std::cout << std::setw(40) << "mymap >= map2: " << (mymap >= map2) << std::endl;
	print(mymap);
	print(map2);
	std::cout << std::endl;
	std::cout << std::setw(40) << "mymap > map2: " << (mymap > map2) << std::endl;
	print(mymap);
	print(map2);
	std::cout << std::endl;
	std::cout << std::setw(40) << "mymap < map2: " << (mymap > map2) << std::endl;
	print(mymap);
	print(map2);
	std::cout << std::endl;
}

int	main()
{
	std::cout << std::boolalpha;
	test_map_constructor();
	test_map_access();
	test_map_capacity();
	test_map_modifiers();
	test_map_lookup();
	test_map_comparison();
	test_map_rbegin();
	test_map_found();
	test_map_full();
	return (0);
}