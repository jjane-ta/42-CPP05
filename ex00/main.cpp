#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include <typeinfo>
#include "Bureaucrat.hpp"

void	main_print_banner(std::string title);

void    test1()
{
    main_print_banner("TEST 1 bureaucrats create/validateGrade/print/destroy");
    {
        Bureaucrat b1("Calimero", 150);
        std::cout << b1;
        Bureaucrat b2("Hermenegildo", 75);
        std::cout << b2;
        Bureaucrat b3("Maximus", 1);
        std::cout << b3;
    }
}

void    test2()
{
    main_print_banner("TEST 2 bureaucrat create with hight garde 0");
    {
        Bureaucrat bureaucrat("Calimero", 0);
        std::cout << bureaucrat;
    }
}

void    test3()
{
    main_print_banner("TEST 3 bureaucrat create with low garde 151");
    {
        Bureaucrat bureaucrat("Calimero", 151);
        std::cout << bureaucrat;
    }
}
void    test4()
{
    main_print_banner("TEST 4 bureaucrat increase grade 1 to 0");
    {
        Bureaucrat bureaucrat("Calimero", 1);
        std::cout << bureaucrat;
        bureaucrat.increaseGrade();
        std::cout << bureaucrat;
    }
}

void    test5()
{
    main_print_banner("TEST 5 bureaucrat decrease grade 150 to 151");
    {
        Bureaucrat bureaucrat("Calimero", 150);
        std::cout << bureaucrat;
        bureaucrat.decreaseGrade();
        std::cout << bureaucrat;
    }
}

void    test6()
{
    main_print_banner("TEST 6 constructor copy");
    {
        Bureaucrat b1("Idem", 30);
        Bureaucrat b2(b1);
        std::cout << b1;
        std::cout << b2;
        b1.decreaseGrade();
        std::cout << b1;
        std::cout << b2;
    }
}

void    test7()
{
    main_print_banner("TEST 7 operator copy");
    {
        Bureaucrat b1("Solo", 30);
        Bureaucrat b2("Mimic",40);
        std::cout << b1;
        std::cout << b2;
        b1 = b2;
        std::cout << b1;
        std::cout << b2;
        b1.decreaseGrade();
        std::cout << b1;
        std::cout << b2;
    }
}

void    test8()
{
    main_print_banner("TEST bureaucrat with empty string name");
    {
        Bureaucrat bureaucrat("", 22);
        std::cout << bureaucrat;
    }
}

int	main ( void )
{
    void    (*functions[])() = {
        test1,
        test2,
        test3,
        test4,
        test5,
        test6,
        test7,
        test8
    };

    for (int test_num = 0; test_num < (int)(sizeof(functions) / sizeof(void *)); test_num++)
    {
        try
        {
            functions[test_num]();
        }
        catch (std::exception & e)
        {
            std::cout << e.what();
        }
        main_print_banner("END TEST");
     }
}

void	main_print_banner(std::string title)
{	
	std::cout	<<	std::endl;
	std::cout	<<	std::setfill('*') << std::setw(title.size()) << "" << std::endl;
	std::cout	<<	title	<<	std::endl;
	std::cout	<<	std::setfill('*') << std::setw(title.size()) << "" << std::endl;
	std::cout	<<	std::endl;
}