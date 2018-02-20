#include <iostream>

class Base
{
public:
    Base() {};
    virtual ~Base(){};
    virtual void Test1(){std::cout <<"Base: Test1()"<< std::endl;};
    virtual void Test2(){std::cout <<"Base: Test2()"<< std::endl;};
};

class Deriv : public Base
{
public:
    Deriv() : Base() , test4(0) {};
    void Test1() override {std::cout <<"Deriv: Test1()"<< std::endl;};
    void Test3()  {std::cout <<"Deriv: Test3()"<< std::endl;};
    int test4;
};

class OtherA
{
public:
    OtherA() : test7(0) {};
    void Test5()  {std::cout <<"OtherA: Test5()"<< std::endl;};
    void Test6()  {std::cout <<"OtherA: Test6()"<< std::endl;};
    int test7;
};

class OtherB
{
public:
    OtherB() : test7(0) {};
    void Test5()  {std::cout <<"OtherB: Test5()"<< std::endl;};
    void Test6()  {std::cout <<"OtherB: Test6()"<< std::endl;};
    int test7;
};

void foo(Deriv* d)
{
    std::cout <<"foo(): -> [test4]+10 = " << d->test4 + 10 << std::endl;
}


int main()
{
//1.a) const_cast to cast away the constness of a pointer to const value

    Deriv d1a;
    Deriv const* p_d1a = &d1a;
    
    //without const_cast using the code below,  you will get: 
    //p_d1->test4 =2; 
    //error: assignment of member ‘Deriv::test4’ in read-only object
    //and
    //foo(p_d1);
    //error: invalid conversion from ‘const Deriv*’ to ‘Deriv*’
    
    (const_cast<Deriv*>(p_d1a))->test4 =2;
    std::cout << "[p_d1a->test4] = " << p_d1a->test4 << std::endl;
    foo(const_cast<Deriv*>(p_d1a));

//1.b) const_cast can cast away the constness also if the object/variable itself is constant
//     but the behaviour is undefined.

    Deriv const d1b;
    Deriv const* p_d1b = &d1b;
    
    (const_cast<Deriv*>(p_d1b))->test4 =5;
    std::cout << "[p_d1b->test4] = " << p_d1b->test4 << std::endl;
    foo(const_cast<Deriv*>(p_d1b));
    
//2.a) static cast *Deriv->*Base->*Deriv
//Note the static cast does not perform run-time type checking.

    Deriv* pd_d2a = new Deriv();
    Base* pb_d2a = pd_d2a; // you don't need a cast;
    pb_d2a->Test1();
    pd_d2a->Test1();
        
    pd_d2a = static_cast<Deriv*>(pd_d2a); // Need a cast to go down the hierarchy
    
    pd_d2a->test4 =7;
    std::cout << "[pd_d2a->test4] = " << pd_d2a->test4 << std::endl;
    pb_d2a->Test1();
    pd_d2a->Test1();
    
    delete pd_d2a;
    
//2.b) static cast *Base->*Deriv :  undefined behavior
//Note the static cast does not perform run-time type checking.

    Base* pb_b2b = new Base();
    Deriv* pd_b2b;     
    
    // undefined behavior
    pd_b2b = static_cast<Deriv*>(pb_b2b); 
    
    pd_b2b->test4 =7;
    std::cout << "[pd_b2b->test4] = " << pd_b2b->test4 << std::endl;
    
    pb_b2b->Test1();
    pd_b2b->Test1();
    
    delete pb_b2b;
    
// dynamic_cast performs run-time type checking
// If the cast doesn’t make sense, dynamic_cast returns a null pointer
//(for the pointer version) or throws an std::bad_cast exception (for the reference version).
// ----------------------------    
//3.a) dynamic cast *Deriv->*Base->*Deriv

    Deriv* pd_d3a = new Deriv();
    Base* pb_d3a = pd_d3a; // you don't need a cast;
    pb_d3a->Test1();
    pd_d3a->Test1();
        
    pd_d3a = dynamic_cast<Deriv*>(pd_d3a); // Need a cast to go down the hierarchy
    
    pd_d3a->test4 =7;
    std::cout << "[pd_d3a->test4] = " << pd_d3a->test4 << std::endl;
    pb_d3a->Test1();
    pd_d3a->Test1();
    
    delete pd_d3a;   
    
//3.b) static cast *Base->*Deriv :  null pointer   
    
    Base* pb_b3b = new Base();
    Deriv* pd_b3b;     
    
    pd_b3b = dynamic_cast<Deriv*>(pb_b3b); // pd_b3b = nullptr
    
    if(pd_b3b)
    {
        pd_b3b->test4 =7;
        std::cout << "[pd_b3b->test4] = " << pd_b3b->test4 << std::endl;
    
        pb_b3b->Test1();
        pd_b3b->Test1();
    }
    else {
         std::cout << "pd_b3b = nullptr" << std::endl;
    }
    delete pb_b3b;   
    
//3.c) static cast *Base->*Deriv :  null pointer   

    Base* pb_b3c = new Base();
    Base& rb_b3c = *pb_b3c;
    
    try{
        Deriv& rd_b3c = dynamic_cast<Deriv&>(rb_b3c); // pd_b3b = nullptr

        rd_b3c.test4 =7;
        std::cout << "[rd_b3c.test4] = " << rd_b3c.test4 << std::endl;
    
        rb_b3c.Test1();
        rd_b3c.Test1();
    }
    catch(const std::exception &e){
        std::cerr <<"Error: " <<e.what() << std::endl;
    }
    delete pb_b3c;   
    
//4.a) reinterpret cast *OtherA->*OtherB

    OtherA* poa_oa4a = new OtherA();
    OtherB* pob_oa4a;
    
    //without cast using the code below,  you will get: 
    // pob_oa4a = poa_oa4a; 
    //error: cannot convert ‘OtherA*’ to ‘OtherB*’ in assignment
    
    //with static_cast using the code below,  you will get:     
    //pob_oa4a = static_cast<OtherB*>(poa_oa4a);
    //error: invalid static_cast from type ‘OtherA*’ to type ‘OtherB*’
    
    pob_oa4a = reinterpret_cast<OtherB*>(poa_oa4a);
    pob_oa4a->test7 = 17;
    std::cout << "[pob_oa4a->test7] = " << poa_oa4a->test7 << std::endl;   
    pob_oa4a->Test5();
    pob_oa4a->Test6();
    
    poa_oa4a->test7 = 27;
    std::cout << "[poa_oa4a->test7] = " << poa_oa4a->test7 << std::endl;    
    poa_oa4a->Test5();
    poa_oa4a->Test6();


    
    delete poa_oa4a;  
    return 0;
}
