# include <vector>
# include <list>
# include <iostream>
# include "../includes/ft_enable_if.hpp"
# include "../includes/ft_equal.hpp"
# include "../includes/ft_is_integral.hpp"
# include "../includes/iterator/ft_iterator_traits.hpp"
# include "../includes/ft_lexicographical_compare.hpp"
# include "../includes/ft_pair.hpp"
# include "../includes/iterator/ft_random_access_iterator.hpp"
# include "../includes/iterator/ft_reverse_iterator.hpp"

# include "../includes/vector.hpp"

template <class T>
void	print(NS::vector<NS::vector<T> >& lst)
{
	for (typename NS::vector<NS::vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename NS::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			std::cout << *it2 << ' ';
		std::cout << '\n';
	}
}

template <class T>
void	print(NS::vector<T>& lst)
{
	for (typename NS::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}

void 	test_vector_constructor()
{
	// DEFAUT CONSTRUCTOR
	NS::vector<int> vect1;
	// VALUE CONSTRUSCTOR
	NS::vector<int> vect2(5,5);
	// RANGE CONSTRUCTOR
	NS::vector<int> vect3(vect2.begin(), vect2.end());
	// COPY CONSTRUCTOR
	NS::vector<int> vect4(vect2);
	// ASSIGN = 
	NS::vector<int> vect5 = vect2;
}

void 	test_vector_assign()
{
	NS::vector<int> vect1(1,1);
	// ASSIGN VALUE
	vect1.assign(2,2);

	NS::vector<int> vect2;
	// ASSIGN RANGE
	vect2.assign(vect1.begin(), vect1.end());
}

void	test_vector_capacity()
{
	NS::vector<int> vect1;
	NS::vector<int> vect2(2,2);

	// EMPTY
	std::cout << "vect 1 empty : " << vect1.empty() << std::endl;
	std::cout << "vect 2 empty : " << vect2.empty() << std::endl;

	// SIZE
	std::cout << "vect 1 size : " << vect1.size() << std::endl;
	std::cout << "vect 2 size : " << vect2.size() << std::endl;

	// MAX_SIZE
	std::cout << "vect 1 max_size : " << vect1.max_size() << std::endl;
	std::cout << "vect 2 max_size : " << vect2.max_size() << std::endl;

	// CAPACITY
	std::cout << "vect 1 capacity : " << vect1.capacity() << std::endl;
	std::cout << "vect 2 capacity : " << vect2.capacity() << std::endl;

	// RESERVE
	std::cout << "vect 1 capacity : " << vect1.capacity() << std::endl;
	vect1.reserve(45);
	std::cout << "vect 1 capacity : " << vect1.capacity() << std::endl;
	vect1.reserve(25);
	std::cout << "vect 1 capacity : " << vect1.capacity() << std::endl;
	vect1.reserve(50);
	std::cout << "vect 1 capacity : " << vect1.capacity() << std::endl;

	std::cout << "vect 2 capacity : " << vect2.capacity() << std::endl;
	vect2.reserve(1);
	std::cout << "vect 2 capacity : " << vect2.capacity() << std::endl;

	// try
	// {
	// 	vect2.reserve(2305843009213693952);
	// }
	// catch(const std::length_error & e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	std::vector<int> vect3;
	std::vector<int> vect4(2,2);

	std::cout << "vect 3 capacity : " << vect3.capacity() << std::endl;
	vect3.reserve(45);
	std::cout << "vect 3 capacity : " << vect3.capacity() << std::endl;
	vect3.reserve(25);
	std::cout << "vect 3 capacity : " << vect3.capacity() << std::endl;
	vect3.reserve(50);
	std::cout << "vect 3 capacity : " << vect3.capacity() << std::endl;

	std::cout << "vect 4 capacity : " << vect4.capacity() << std::endl;
	vect4.reserve(1);
	std::cout << "vect 4 capacity : " << vect4.capacity() << std::endl;
}

void	test_vector_modifiers()
{
	NS::vector<int>	vect1(2,2);
	NS::vector<int> vect2;

	// CLEAR
	vect1.clear();
	vect2.clear();

	// INSERT
	print(vect1);
	vect1.insert(vect1.begin(), 1);
	print(vect1);
	vect1.insert(vect1.end(), 5, 6);
	print(vect1);

	vect2.insert(vect2.begin(), vect1.begin(), vect1.end());
	print(vect2);
	vect2.insert(vect2.end(), vect1.begin(), vect1.end());
	print(vect2);

	// ERASE
	vect1.erase(vect1.begin());
	print(vect1);
	vect1.insert(vect1.end(), 5, 6);
	print(vect1);
	vect1.erase(vect1.begin() + 2, vect1.end());
	print(vect1);

	// PUSH_BACK
	vect1.push_back(3);
	print(vect1);
	vect2.push_back(3);
	print(vect2);

	// POP_BACK
	vect1.pop_back();
	print(vect1);
	vect2.pop_back();

	// RESIZE
	std::cout << "size : " << vect1.size() << std::endl;
	vect1.resize(10,2);
	std::cout << "size : " << vect1.size() << std::endl;
	print(vect1);
	vect1.resize(6,4);
	print(vect1);
	std::cout << "size : " << vect1.size() << std::endl;

	vect2.push_back(2);
	print(vect2);

	// SWAP 
	vect1.swap(vect2);
	print(vect1);
	print(vect2);

}

void	test_vector_erase()
{
  NS::vector<int> myvector;

  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) myvector.push_back(i);

  // erase the 6th element
  std::cout  << "6 elem : " << (*(myvector.begin()+5)) <<std::endl;
  myvector.erase (myvector.begin()+5);

  // erase the first 3 elements:
  myvector.erase (myvector.begin(),myvector.begin()+3);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  std::vector<int> stdmyvector;

  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) stdmyvector.push_back(i);


  // erase the 6th element
   std::cout << "6 elem : " << (*(stdmyvector.begin()+5)) <<std::endl;
  stdmyvector.erase (stdmyvector.begin()+5);

  // erase the first 3 elements:
  stdmyvector.erase (stdmyvector.begin(),stdmyvector.begin()+3);

  std::cout << "stdvector contains:";
  for (unsigned i=0; i<stdmyvector.size(); ++i)
    std::cout << ' ' << stdmyvector[i];
  std::cout << '\n';

}

void	test_vector_comparison()
{
	std::cout << std::boolalpha;
	
	NS::vector<int>		vect1(5,6);
	NS::vector<int>		vect2(vect1);
	NS::vector<int>		vect3;

	vect3.push_back(3);

	std::cout << (vect1 == vect2)<< std::endl;
	std::cout << (vect1 != vect2)<< std::endl;
	std::cout << (vect1 == vect3)<< std::endl;
	std::cout << (vect1 != vect3)<< std::endl;

	std::cout << (vect1 < vect2)<< std::endl;
	std::cout << (vect1 <= vect2)<< std::endl;
	std::cout << (vect1 == vect2)<< std::endl;

	std::cout << (vect1 > vect2)<< std::endl;
	std::cout << (vect1 >= vect2)<< std::endl;
}

void test_vector_inception()
{
	NS::vector<int>			test(3, 3);

	std::cout << "self assignation test\n";
	NS::vector<NS::vector<int> >	self_assign;
	NS::vector<NS::vector<int> >	*ptr = &self_assign;
	NS::vector<NS::vector<int> >	*ptr2 = &self_assign;

	self_assign.assign(4, test);
	*ptr = *ptr2;

	std::cout << std::boolalpha << (*ptr == *ptr2) << '\n';

	NS::vector<NS::vector<int> > JOHN;
	NS::vector<NS::vector<int> > BOB(5, test);
	std::cout << "BOB(5, test(test, 5)) : \n";
	for (size_t i = 0; i < BOB.size(); i++)
	{
		for (size_t j = 0; j < BOB[i].size(); j++)
			std::cout << BOB[i][j] << ' ';
		std::cout << '\n';
	}
	NS::vector<NS::vector<int> > MIKE(BOB);

	// CTORs
	std::cout << "\nCTORS\n";
	std::cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
	std::cout << "BOB is empty? " << BOB.empty() << '\n';

	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;

	// RESIZE
	size_t	bob_resize = 2;
	std::cout << "\nRESIZE\n";
	BOB.resize(bob_resize);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 63\n";

	size_t	mike_resize = 9;
	bob_resize = 0;
	
	BOB.resize(bob_resize);
	std::cout << "BOB is empty now ? " << BOB.empty() << '\n';
	MIKE.resize(mike_resize, test);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_resize)
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
		{
			std::cout << MIKE[i][j] << ' ';
		}
	std::cout << std::endl;
	}
	// RESERVE
	std::cout << "\nRESERVE\n";

	size_t	john_reserve = 0;
	size_t	bob_reserve = 3;
	size_t	mike_reserve = 4;

	JOHN.reserve(john_reserve);
	BOB.reserve(bob_reserve);
	MIKE.reserve(mike_reserve);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= john_reserve)
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_reserve)
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_reserve)
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}

	//AT
	std::cout << "\nAT\n";
	// try
	// {
	// 	std::cout << MIKE.at(2).front() << '\n';
	// 	std::cout << MIKE.at(87).back() << '\n';
	// }
	// catch (std::out_of_range& oor)
	// {
	// 	(void)oor;
	// 	std::cout << "OOR error caught\n";
	// }

	// FRONT / BACK
	std::cout << "\nFRONT / BACK\n";
	std::cout << "front() of MIKE : " << MIKE.front().front() << '\n';
	std::cout << "back() of MIKE : " << MIKE.back().back() << '\n';

	//ASSIGN
	std::cout << "\nASSIGN\n";
	test.assign(3, 17);
	BOB.assign(3, test);

	//ASSIGN RANGE
	std::cout << "\nASSIGN RANGE\n";
	NS::vector<NS::vector<int> >	assign_range;
	std::cout << "ici1\n";
	assign_range.assign(8, test);
	std::cout << "ici2\n";
	assign_range.assign(BOB.begin() + 1, BOB.end() - 2);

	//EMPTY
	std::cout << "\nEMPTY\n";
	std::cout << "BOB is empty ? " << BOB.empty() << '\n';
	std::cout << "BOB at(1) : " << BOB.at(1).front() << '\n';

	//PUSH/POP_BACK
	std::cout << "\nPUSH/POP_BACK\n";
	test.assign(2, 42);
	BOB.push_back(test);
	std::cout << "last elem of BOB : " << BOB.back().back() << '\n';
	BOB.pop_back();
	std::cout << "last elem of BOB : " << BOB.back().back() << '\n';

	//INSERT
	std::cout << "\nINSERT\n";
	NS::vector<NS::vector<int> >	insert_in_me;
	for (int i = 0; i < 15; i++)
	{
		NS::vector<int>	j(2, i);
		insert_in_me.push_back(j);
	}
	for (size_t i = 0; i < insert_in_me.size(); i++)
	{
		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
			std::cout << insert_in_me.at(i).at(j) << ' ';
		std::cout << '\n';
	}
	NS::vector<NS::vector<int> >::iterator	tmp;
	test.assign(23, 19);
	tmp = insert_in_me.begin() + 4;
	insert_in_me.insert(tmp, 8, test);
	for (size_t i = 0; i < insert_in_me.size(); i++)
	{
		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
			std::cout << insert_in_me.at(i).at(j) << ' ';
		std::cout << '\n';
	}

	NS::vector<NS::vector<int> >::const_iterator const_it(insert_in_me.begin());
	std::cout << "Const it.front() : " << std::endl;
	std::cout << (*const_it).front() << '\n';


	//INSERT
	std::cout << "\nINSERT\n";
	std::cout << "ici\n";
	NS::vector<NS::vector<int> >	std_insert_in_me;
	std::cout << "ici 1\n";
	for (int i = 0; i < 15; i++)
		std_insert_in_me.push_back(test); //ICI
	std::cout << "ici 1.1\n";
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		std::cout << std_insert_in_me.at(i).front() << ' ';
	std::cout << '\n';
	std::cout << "ici 2\n";
	NS::vector<NS::vector<int> >::iterator	std_tmp;
	std_tmp = std_insert_in_me.begin() + 4;
	std_insert_in_me.insert(std_tmp, 8, test);
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		std::cout << std_insert_in_me.at(i).back() << ' ';
	std::cout << '\n';
	std::cout << "ici 3\n";


	//INSERT RANGE
	std::cout << "\nINSERT RANGE\n";
	NS::vector<NS::vector<int> >	insert_bis;
	for (int i = 0; i < 7; i++)
	{
		NS::vector<int>	j(2, i * 3);
		insert_bis.push_back(j);
	}
	for (size_t i = 0; i < insert_bis.size(); i++)
		std::cout << insert_bis[i].back() << ' ';
	std::cout << '\n';

	insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
	for (size_t i = 0; i < insert_bis.size(); i++)
		std::cout << insert_bis[i].back() << ' ';
	std::cout << '\n';


	//ERASE
	std::cout << "\nERASE\n";
	NS::vector<NS::vector<int> >	erase_in_me;
	for (int i = 0; i < 15; i++)
	{
		NS::vector<int>	j(1, i);
		erase_in_me.push_back(j);
	}
	for (size_t i = 0; i < erase_in_me.size(); i++)
		std::cout << erase_in_me.at(i).front() << ' ';
	std::cout << '\n';

	erase_in_me.erase(erase_in_me.begin() + 7);
	for (size_t i = 0; i < erase_in_me.size(); i++)
		std::cout << erase_in_me.at(i).front() << ' ';
	std::cout << '\n';
	erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
	for (size_t i = 0; i < erase_in_me.size(); i++)
		std::cout << erase_in_me.at(i).front() << ' ';
	std::cout << '\n';

	//SWAP
	std::cout << "\nSWAP\n";
	john_reserve = 4;
	JOHN.reserve(john_reserve);
	BOB.swap(MIKE);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}

	MIKE.swap(JOHN);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}

	//CLEAR
	std::cout << "\nCLEAR\n";
	JOHN.clear();
	MIKE.clear();
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}

	//NON MEMBER Functions
	std::cout << "\nNON MEMBER functions\n";
	swap(BOB, MIKE);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}
	
	//RELATIONAL OPERATORS
	std::cout << "\nRELATIONAL OPERATORS\n";
	NS::vector<NS::vector<int> > MIKE_2(MIKE);
	std::cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
	std::cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';

	std::cout << "\nReal Vector\n";
	NS::vector<NS::vector<int> > real;
	real.assign(5, test);
	for (NS::vector<NS::vector<int> >::iterator it = real.begin(); it != real.end(); it++)
		std::cout << (*it).front() << " ";
	std::cout << '\n';

	std::cout << std::endl;
}

void test_vector_insert ()
{
  NS::vector<int> myvector (3,100);
  NS::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  NS::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void	test_vector_swap()
{
	NS::vector<int> foo (3,100);   // three ints with a value of 100
	NS::vector<int> bar (5,200);   // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
	std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
	std::cout << ' ' << bar[i];
	std::cout << '\n';

	{
		NS::vector<int> foo,bar;

		foo.push_back(100);
		foo.push_back(200);

		bar.push_back(11);
		bar.push_back(22);
		bar.push_back(33);


		NS::vector<int>::const_iterator tmp = foo.begin(); //tmp iterates through foo
		NS::vector<int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar

		swap(bar, foo); //tmp iterates through bar //tmp2 iterates through foo


		NS::vector<int>	other;

		other.push_back(73);
		other.push_back(173);
		other.push_back(763);
		other.push_back(73854);
		other.push_back(74683);
		other.push_back(753);

		NS::vector<int>::const_iterator tmp3 = other.begin(); // tmp3 iterates through other

		std::cout << "foo contains:\n";
		for (NS::vector<int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << *it << '\n';

		std::cout << "bar contains:\n";
		for (NS::vector<int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << *it << '\n';

		int i = 0;
		while(tmp != bar.end() && i < 10)
		{
			std::cout << *tmp << '\n';
			tmp++;
			i++;
		}
		tmp--;

		while(tmp2 != foo.end())
		{
			std::cout << *tmp2 << '\n';
			tmp2++;
		}
		tmp2--;

		swap(other, foo); //tmp2 iterates through other
		//tmp3 iterates throught foo
		print(other);
		print(foo);
		print(bar);
		while(tmp != bar.begin())
		{
			std::cout << *tmp << '\n';
			tmp--;
		}
		std::cout << *tmp << '\n';

		while(tmp2 != other.begin())
		{
			std::cout << *tmp2 << '\n';
			tmp2--;
		}
		std::cout << *tmp2 << '\n';

		while(tmp3 != foo.end())
		{
			std::cout << *tmp3 << '\n';
			tmp3++;
		}
		tmp3--;

		swap(bar, foo);
		swap(foo, bar);
		swap(bar, foo); //tmp3 iterates through bar
		//tmp iterates through foo

		print(other);
		print(foo);
		print(bar);

		while(tmp != foo.end())
		{
			std::cout << *tmp << '\n';
			tmp++;
		}

		while(tmp2 != other.end())
		{
			std::cout << *tmp2 << '\n';
			tmp2++;
		}

		while(tmp3 != bar.begin())
		{
			std::cout << *tmp3 << '\n';
			tmp3--;
		}
			std::cout << *tmp3 << '\n';
		}
}


void test_vector_rend()
{
	
	NS::vector<int> myvector (5);  // 5 default-constructed ints
	
	int i=0;

	
	NS::vector<int>::reverse_iterator rit = myvector.rbegin();
	
	std::cout << std::endl;
	std::cout << *(myvector.rbegin());
	std::cout << *(myvector.begin());
	std::cout << *(myvector.rend());
	std::cout << *(myvector.end());
	std::cout << std::endl;
	
	for (; rit!= myvector.rend(); ++rit)
	{
		// std::cout << *rit;
		*rit = ++i;
	}
		
	
	
	std::cout << "myvector contains:";
	
	
	for (NS::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	
	std::cout << '\n';
}

void	test_vector_reverse_it(void)
{
	std::cout << std::endl << "REVERSE IT TESTS" << std::endl;
	NS::vector<int> test;
	for (size_t i = 0; i < 12; i++) { test.push_back(i); }
	NS::vector<int>::reverse_iterator		revbeg = test.rbegin();
	for (NS::vector<int>::reverse_iterator it = revbeg; it != test.rend(); it++)
	{
		std::cout << *it << " ";
		if (!((revbeg - it) % 10) && it != revbeg)
			std::cout << std::endl;
	}
	std::cout << *(test.rbegin() + 2) << std::endl;
	std::cout << *(test.rend() - 8) << std::endl;
	std::cout << (test.rbegin() == revbeg) << std::endl;
	revbeg++;
	std::cout << *revbeg << std::endl;
	std::cout << (test.rbegin() == test.rend()) << std::endl;
	std::cout << (test.rbegin() <= test.rbegin()) << std::endl;
	std::cout << (test.rbegin() < test.rend()) << std::endl;
	std::cout << (test.rbegin() >= test.rend()) << std::endl;
	revbeg += 3;
	std::cout << *revbeg << std::endl;
	std::cout << std::endl;
}

void	test_vector_reserve()
{
	std::cout << std::endl << "FT - RESERVE TESTS" << std::endl;
	ft::vector<int> test(65, 7);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.reserve(12);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.reserve(66);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.reserve(128);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.reserve(1023);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.reserve(10252);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	// try
	// {
	// 	test.reserve(test.max_size() + 1);
	// }
	// catch(std::length_error &le)
	// {
	// 	std::cout << "length error" << std::endl;
	// }
	// catch(std::exception &e)
	// {
	// 	std::cout << "error : " << e.what() << std::endl;
	// }
	
	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';

	std::cout << std::endl << "STD - RESERVE TESTS" << std::endl;
	std::vector<int> test2(65, 7);
	std::cout << "s: " << test2.size() << ", c: " << test2.capacity() << std::endl;
	test2.reserve(12);
	std::cout << "s: " << test2.size() << ", c: " << test2.capacity() << std::endl;
	test2.reserve(66);
	std::cout << "s: " << test2.size() << ", c: " << test2.capacity() << std::endl;
	test2.reserve(128);
	std::cout << "s: " << test2.size() << ", c: " << test2.capacity() << std::endl;
	test2.reserve(1023);
	std::cout << "s: " << test2.size() << ", c: " << test2.capacity() << std::endl;
	test2.reserve(10252);
	std::cout << "s: " << test2.size() << ", c: " << test2.capacity() << std::endl;
	// try
	// {
	// 	test2.reserve(test.max_size() + 1);
	// }
	// catch(std::length_error &le)
	// {
	// 	std::cout << "length error" << std::endl;
	// }
	// catch(std::exception &e)
	// {
	// 	std::cout << "error : " << e.what() << std::endl;
	// }
	
	for (std::vector<int>::iterator it = test2.begin(); it != test2.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}

void	test_vector_resize()
{
	{
		std::cout << "FT - RESIZE TESTS" << std::endl;
		ft::vector<int> test(12, 12);

		test.resize(72);
		std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
		test.resize(100);
		std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
		test.resize(4170);
		std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
		test.resize(171, 12);
		std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
		test.resize(62);
		std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	}

	{
		std::cout << std::endl << "STD - RESIZE TESTS" << std::endl;
		std::vector<int> test(12, 12);

		test.resize(72);
		std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
		test.resize(100);
		std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
		test.resize(4170);
		std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
		test.resize(171, 12);
		std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
		test.resize(62);
		std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	}
}

void	test_vector_bidirect()
{
	{
		std::cout << "FT\n";
		std::list<int> lst;
		std::list<int>::iterator lst_it;
		for (int i = 1; i < 5; ++i)
			lst.push_back(i * 3);

		ft::vector<int> vct(lst.begin(), lst.end());
		std::cout << vct.size();

		lst_it = lst.begin();
		for (int i = 1; lst_it != lst.end(); ++i)
			*lst_it++ = i * 5;
		vct.assign(lst.begin(), lst.end());
		std::cout << vct.size();

		vct.insert(vct.end(), lst.rbegin(), lst.rend());
		std::cout << vct.size();
	}

	{
		std::cout << "\nSTD\n";
		std::list<int> lst;
		std::list<int>::iterator lst_it;
		for (int i = 1; i < 5; ++i)
			lst.push_back(i * 3);

		std::vector<int> vct(lst.begin(), lst.end());
		std::cout << vct.size();

		lst_it = lst.begin();
		for (int i = 1; lst_it != lst.end(); ++i)
			*lst_it++ = i * 5;
		vct.assign(lst.begin(), lst.end());
		std::cout << vct.size();

		vct.insert(vct.end(), lst.rbegin(), lst.rend());
		std::cout << vct.size();
	}
}

int		main()
{
	test_vector_constructor();
	test_vector_assign();
	test_vector_capacity();
	test_vector_modifiers();
	test_vector_erase();
	test_vector_comparison();
	test_vector_inception();
	test_vector_insert();
	test_vector_swap();
	test_vector_rend();
	test_vector_reverse_it();
	test_vector_reserve();
	test_vector_resize();
}