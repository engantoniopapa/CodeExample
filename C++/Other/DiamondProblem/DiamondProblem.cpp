#include <iostream>


class A
{
    public:
    void Test1() {std::cout << "Test 1A\n";};
};

class B : virtual public A
{
    public:
    void Test2() {std::cout << "Test 2B\n";};    
};

class C : virtual public A
{
    public:
    void Test2() {std::cout << "Test 2C\n";};    
};

class D : public B , public C
{
    public:
    void Test3() {std::cout << "Test 3D\n";};    
};

int main()
{
    D d;
    d.Test1(); // fix with : virtual public A in cass B and C definition
    
    //- 2 way to refer to Test2():
    //1) Using class scope
    //2a) Static cast with reference
    //2b) Static cast with pointer
    
    d.B::Test2();
    d.C::Test2();
    
    B &b = dynamic_cast<B&>(d);
    b.Test2();
    C &c = dynamic_cast<C&>(d);
    c.Test2();
    
    B* b_ptr = dynamic_cast<B*>(&d);
    b_ptr->Test2();
    C* c_ptr = dynamic_cast<C*>(&d);
    c_ptr->Test2();
    
    
    d.Test3();

    return 0;
}
