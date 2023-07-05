#include <iostream>
#include <iomanip>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	main_print_banner(std::string title);

void    test1()
{
    main_print_banner("TEST 1 forms create/validateGrade/print/destroy");
    {
        Form f1("150A", 150);
        std::cout << f1;
        Form f2("75A", 75);
        std::cout << f2;
        Form f3("1A", 1);
        std::cout << f3;
    }
}

void    test2()
{
    main_print_banner("TEST 2 form create with hight garde 0");
    {
        Form form("00E", 0);
        std::cout << form;
    }
}

void    test3()
{
    main_print_banner("TEST 3 form create with low garde 151");
    {
        Form form("151E", 151);
        std::cout << form;
    }
}

void    test4()
{
    main_print_banner("TEST 4 constructor copy && bureaucrat sign one of them NO EXCEPTz");
    {
        Bureaucrat b("Calimero", 1);
        Form f1("30F", 30);
        Form f2(f1);
        std::cout << f1;
        std::cout << f2;
        b.signForm(&f1);
        std::cout << f1;
        std::cout << f2;
    }
}

void    test5()
{
    main_print_banner("TEST 4 operator copy && bureaucrat sign one of them NO EXCEPT");
    {
        Bureaucrat b("Calimero", 1);
        Form f1("30F", 30);
        Form f2("40F", 40);
        std::cout << f1;
        std::cout << f2;
        f1 = f2; 
        b.signForm(&f1);
        std::cout << f1;
        std::cout << f2;
    }
}


void    test6()
{
    main_print_banner("TEST  constructor copy && bureaucrat sign one of them caching EXCEPT");
    {
        Bureaucrat b("Calimero", 150);
        Form f1("30F", 30);
        Form f2(f1);
        std::cout << f1;
        std::cout << f2;
        b.signForm(&f1);
        std::cout << f1;
        std::cout << f2;
    }
}

void    test7()
{
    main_print_banner("TEST 7 operator copy && bureaucrat sign one of them  caching EXCEPT");
    {
        Bureaucrat b("Calimero", 150);
        Form f1("30F", 30);
        Form f2("40F", 40);
        std::cout << f1;
        std::cout << f2;
        f1 = f2; 
        b.signForm(&f1);
        std::cout << f1;
        std::cout << f2;
    }
}

void    test8()
{
    main_print_banner("TEST 8 form with empty string name");
    {
        Form form("", 22);
        std::cout << form;
    }
}

void    test9()
{
    main_print_banner("TEST 9 bureaucrat try sign null pointer");
    {
        Bureaucrat b("Calimero", 150);
        b.signForm(NULL);
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
        test8,
        test9
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