#include "stdafx.h"
#include "Singleton.hpp"
#include <iostream>



//TODO using thread to show the Singleton2 and Singleton3 behavior 
int main()
{
    Singleton1 *S1_1 = Singleton1::get_instance();
    Singleton1 *S1_2 = Singleton1::get_instance();

    Singleton2 *S2_1 = Singleton2::get_instance();
    Singleton2 *S2_2 = Singleton2::get_instance();

    Singleton3 *S3_1 = Singleton3::get_instance();
    Singleton3 *S3_2 = Singleton3::get_instance();

	Singleton4 *S4_1 = Singleton4::get_instance();
	Singleton4 *S4_2 = Singleton4::get_instance();

    S1_1->do_something();
    S1_2->do_something();
    S2_1->do_something();
    S2_2->do_something();
    S3_1->do_something();
    S3_2->do_something();
	S4_1->do_something();
	S4_2->do_something();

    Singleton1::destroy_instance();
    Singleton2::destroy_instance();
    Singleton3::destroy_instance();
	Singleton4::destroy_instance();


	std::cin.get();
    
    return EXIT_SUCCESS;
}
