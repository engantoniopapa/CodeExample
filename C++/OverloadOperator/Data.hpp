#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>
#include <cstring>

class DataError
{
private:
    std::string message;

public:
    DataError() : message(""){};
    DataError(std::string message) :  message(message) {};
 
    void set_message(std::string message) { this->message = message;};
    std::string& get_message() {return this->message;};
};

class Data
{
private:
    std::string name;
    int* parameters;
    int size;

public:
    Data(std::string name , int size) : name(name), parameters( new int[size]), size(size) 
    {
        memset(parameters , 0 , size * sizeof(parameters[0]));
    }
    ~Data(){delete [] parameters;};
    
    
    Data(const Data& data); //copy constructor
    Data(const Data& data , const std::string& name); //copy constructor v2
    
    bool operator==(const Data& data);
    bool operator==(const int val); 
    bool operator!=(const Data& data);
    bool operator!=(const int val); 
     
    Data& operator=(const Data& data); //assign operator
    Data operator++(); //pre-increment operator
    Data operator++(int); //post-dcrement operator
    Data operator--(); //pre-decrement operator
    Data operator--(int); //post-decrement operator
    
    Data operator+(const Data& data); //works with: data1 + data2
    Data operator+(int val); //works with: data1 + val 
    Data operator+=(const Data& data); //works with: data1 += data2
    Data operator+=(int val); //works with: data1 += val 
    
    //works with: val + data2
    //doesn't have sense but I have just implemented to have a simmetric implementation with friend 
    friend Data operator+(int val , const Data& data); 
    
    Data operator-(const Data& data); //works with: data1 - data2
    Data operator-(int val); //works with: data1 - val 
    
    Data operator*(const Data& data); //works with: data1 * data2
    Data operator*(int val); //works with: data1 * val 
    
    Data operator/(const Data& data); //works with: data1 / data2
    Data operator/(int val); //works with: data1 / val 
    
    friend std::ostream& operator<<(std::ostream& os , const Data &data); //works with: cout << data1 << data2
    friend std::istream& operator>>(std::istream& is , Data &data); //works with: cin >> data1 >> data2
    
    int& operator[](const int i) const; //subscription operator

      
};

#endif
