#include <iostream>
#include <iomanip>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	main_print_banner(std::string title);

void    test1()
{
    main_print_banner("TEST 1 forms create-print-sign-print-destroy");
    {
        Form f1("150-150A", 150, 150);
        Form f2("001-150A", 1, 150);
        Form f3("", 2, 150);

        std::cout << f1;
        std::cout << f2;
        std::cout << f3;

        Bureaucrat b("Regio", 1);
        std::cout << b;
        b.signForm(&f1);
        b.signForm(&f2);
        b.signForm(&f3);

        std::cout << f1;
        std::cout << f2;
        std::cout << f3;
    }
}

void    test2()
{
    main_print_banner("TEST 2 form create with hight garde to_sign 0");
    {
        Form form("000-150E", 0, 150);
        std::cout << form;
    }
}

void    test3()
{
    main_print_banner("TEST 3 form create with low garde to_sign 151");
    {
        Form form("151-150E", 151, 150);
        std::cout << form;
    }
}

void    test4()
{
    main_print_banner("TEST 4 form create with hight garde to_exec 0");
    {
        Form form("001-000E", 1, 0);
        std::cout << form;
    }
}

void    test5()
{
    main_print_banner("TEST 5 form create with low garde to_exec 151");
    {
        Form form("001-151E", 1, 151);
        std::cout << form;
    }
}

void test6() {
    main_print_banner("TEST 6 bureaucrat grade 2 try to sign form grade to_sign 1");
    {
        Form f1("001-150A", 1, 150);
        std::cout << f1;    

        Bureaucrat b("Fleming", 2);
        std::cout << b;
        b.signForm(&f1);

        std::cout << f1;
    }
}

void test7() {
    main_print_banner("TEST 7 bureaucrat grade 2 try to sign NULL form");
    {
        Bureaucrat b("Fleming", 2);
        std::cout << b;
        b.signForm(NULL);
    }
}

void test8() {
    main_print_banner("TEST 8 bureaucrat and form empty name");
    {
        Bureaucrat b("", 2);
        Form f("", 1,1);
        std::cout << b;
        std::cout << f;
    }
}

void    test9()
{
    main_print_banner("TEST 9 form constructor copy and sign original");
    {
        Form f1("030-150F", 30, 150);
        Form f2(f1);
        std::cout << f1;
        std::cout << f2;

        Bureaucrat b("Serius", 1);
        std::cout << b;

        b.signForm(&f1);
        std::cout << f1;
        std::cout << f2;
    }
}

void    test10()
{
    main_print_banner("TEST 10 form constructor copy a signed form");
    {
        Form f1("030-150F", 30, 150);
        std::cout << f1;
        Bureaucrat b("Rigorous", 1);
        std::cout << b;
        b.signForm(&f1);
        std::cout << f1;
        Form f2(f1);
        std::cout << f2;
    }
}

void    test11()
{
    main_print_banner("TEST 11 form copy operator");
    {
        Form f1("030-150F", 30, 150);
        Form f2("040-150F", 40, 150);
        std::cout << f1;
        std::cout << f2;
        f1 = f2;
        std::cout << f1;
        std::cout << f2;

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
        test9,
        test10
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