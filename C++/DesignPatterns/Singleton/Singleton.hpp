#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <mutex>

//Singleton1 - lazy initialization, no thread safe:
class Singleton1
{
private:
    static Singleton1* s_instance;
    Singleton1() {};

public:
    static Singleton1* get_instance();
    static void destroy_instance();
    void do_something();
    ~Singleton1(){};
    Singleton1(const Singleton1& )= delete;
    Singleton1& operator=(const Singleton1& )= delete;
};


//Singleton2 - lazy initialization, thread safe:
class Singleton2
{
private:
    static Singleton2* s_instance;
    Singleton2() {};
    static std::mutex singleton_mutex;

public:
    static Singleton2* get_instance();
    static void destroy_instance();
    void do_something();
    ~Singleton2(){};
    Singleton2(const Singleton2& )= delete;
    Singleton2& operator=(const Singleton2& )= delete;
};


//Singleton3 - lazy initialization, thread safe with Double-Checked Locking Pattern:
class Singleton3
{
private:
    static Singleton3* s_instance;
    Singleton3() {};
    static std::mutex singleton_mutex;

public:
    static Singleton3* get_instance();
    static void destroy_instance();
    void do_something();
    ~Singleton3(){};
    Singleton3(const Singleton3& )= delete;
    Singleton3& operator=(const Singleton3& )= delete;
};


#endif
