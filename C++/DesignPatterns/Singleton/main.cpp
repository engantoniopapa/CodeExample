#include "Singleton.hpp"



//TODO using thread to show the Singleton2 and Singleton3 behavior 
int main()
{
    Singleton1 *S1_1 = Singleton1::get_instance();
    Singleton1 *S1_2 = Singleton1::get_instance();

    Singleton2 *S2_1 = Singleton2::get_instance();
    Singleton2 *S2_2 = Singleton2::get_instance();

    Singleton3 *S3_1 = Singleton3::get_instance();
    Singleton3 *S3_2 = Singleton3::get_instance();

    S1_1->do_something();
    S1_2->do_something();
    S2_1->do_something();
    S2_2->do_something();
    S3_1->do_something();
    S3_2->do_something();

    Singleton1::destroy_instance();
    Singleton2::destroy_instance();
    Singleton3::destroy_instance();
    
    return EXIT_SUCCESS;
}
