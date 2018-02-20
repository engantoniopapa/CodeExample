#include "Data.hpp"
#include <algorithm>
#include <cstdlib>

//copy constructor
Data::Data(const Data& data)
{
    this->name = data.name;
    this->size = data.size;
    
    this->parameters = new int[this->size];
    std::copy(data.parameters ,  data.parameters+data.size , this->parameters);
}

//copy constructor v.2
Data::Data(const Data& data , const std::string& name)
: Data(data)
{
    this->name = name;
}

//Comparison operator
bool Data::operator==(const Data& data)
{
    if(size != data.size)
        return false;
        
    for(int i = 0 ; i < size; ++i)
    {
        if(parameters[i] != data[i])
            return false;
    }
    return true;
}
bool Data::operator==(const int val)
{
    for(int i = 0 ; i < size; ++i)
    {
        if(parameters[i] != val)
            return false;
    }
    return true;
}

bool Data::operator!=(const Data& data)
{
    return !( (*this) == data);
}

bool Data::operator!=(const int val)
{
    return !( (*this) == val);
} 
// end Comparison Operator


//asign operator
Data& Data::operator=(const Data& data)
{
    if(this == &data)
        return *this;
        
    this->name = data.name;
    this->size = data.size;
    
    if(!this->parameters)
        delete [] parameters;
    
    this->parameters = new int[this->size];
    std::copy(data.parameters ,  data.parameters+data.size , this->parameters);
    return *this;
}

//pre-increment operator
Data& Data::operator++()
{
    for(int i = 0; i < size ; i++)
    {
        ++parameters[i];
    }  
    
    return *this;
}

// post-increment operator
// The int parameter is a dummy parameter used to differentiate between 
// prefix and postfix versions of the operators. 
Data Data::operator++(int)
{
    Data old(*this);
    ++(*this);
    
    return old;
}

//pre-decrement operator
Data& Data::operator--()
{
    for(int i = 0; i < size ; i++)
    {
        --parameters[i];
    }  
    
    return *this;
}

// post-decrement operator
// The int parameter is a dummy parameter used to differentiate between 
// prefix and postfix versions of the operators. 
Data Data::operator--(int)
{
    Data old_data(*this);
    --(*this);
    
    return old_data;
}

//works with: data1 + data2, data1 and data2 has to have the same size
Data Data::operator+(const Data& data) 
{
    if(this->size != data.size)
        throw  DataError("Error Data obj1 + Data obj2: Different Size");
    
    Data result_data(*this);

    for(int i = 0; i < size ; i++)
    {
        result_data.parameters[i] = this->parameters[i] + data.parameters[i];
    }  
    
    return result_data;
}

//works with: data1 + int 
Data Data::operator+(int val)
{
    Data result_data(*this);

    for(int i = 0; i < size ; i++)
    {
        result_data.parameters[i] = this->parameters[i] + val;
    }  
    
    return result_data;
} 

//works with: int + data2
//doesn't have sense but I have just implemented to have a simmetric implementation with friend 
Data operator+(int val , const Data& data) 
{
    Data result_data(data);

    for(int i = 0; i < data.size ; i++)
    {
        result_data.parameters[i] = result_data.parameters[i] + val;
    }  
    
    return result_data;
}

//works with: data1 += data2
Data& Data::operator+=(const Data& data)
{
    (*this) = (*this)+data;
    return (*this);
}

//works with: data1 += val
Data& Data::operator+=(int val)
{
    (*this) = (*this) + val;
    return (*this);
}

//works with data1 - data2, data1 and data2 has to have the same size
Data Data::operator-(const Data& data) 
{
    if(this->size != data.size)
        throw  DataError("Error Data obj1 - Data obj2: Different Size");
    
    Data result_data(*this);

    for(int i = 0; i < size ; i++)
    {
        result_data.parameters[i] = this->parameters[i] - data.parameters[i];
    }  
    
    return result_data;
}

//works with: data1 - int 
Data Data::operator-(int val)
{
    Data result_data(*this);

    for(int i = 0; i < size ; i++)
    {
        result_data.parameters[i] = this->parameters[i] - val;
    }  
    
    return result_data;
} 

//works with data1 * data2, data1 and data2 has to have the same size
Data Data::operator*(const Data& data) 
{
    if(this->size != data.size)
        throw  DataError("Error Data obj1 * Data obj2: Different Size");
    
    Data result_data(*this);

    for(int i = 0; i < size ; i++)
    {
        result_data.parameters[i] = this->parameters[i] * data.parameters[i];
    }  
    
    return result_data;
}

//works with: data1 * int 
Data Data::operator*(int val)
{
    Data result_data(*this);

    for(int i = 0; i < size ; i++)
    {
        result_data.parameters[i] = this->parameters[i] * val;
    }  
    
    return result_data;
} 

//works with data1 / data2, data1 and data2 has to have the same size
Data Data::operator/(const Data& data) 
{
    if(this->size != data.size)
        throw  DataError("Error Data obj1 / Data obj2: Different Size");
    
    Data result_data(*this);

    for(int i = 0; i < size ; i++)
    {
        result_data.parameters[i] = this->parameters[i] / data.parameters[i];
    }  
    
    return result_data;
}

//works with: data1 / int 
Data Data::operator/(int val)
{
    Data result_data(*this);

    for(int i = 0; i < size ; i++)
    {
        result_data.parameters[i] = this->parameters[i] / val;
    }  
    
    return result_data;
} 

//works with: cout << data1 << data2
std::ostream& operator<<(std::ostream& os , const Data &data)
{
    os << "Data Name: " << data.name << "\n" << "[";
    
    for( int i = 0 ; i  < data.size ; ++i)
    {
        if ( i == data.size-1){
            os << " " << data.parameters[i] << " ]" << "\n";
        }
        else{
            os << " " << data.parameters[i] << " ,";
        }
    }  
    return os;
} 

//works with: cin >> data1 >> data2
std::istream& operator>>(std::istream& is , Data &data)
{
    std::string line;
    std::getline(is, line);
    
    // the first element don't need to have the comma token
    int size_element = 1; 
     
    //find size
    for(unsigned int i=0 ; i < line.length() ; ++i)
    {
        if(line[i] == ',')
          ++size_element; 
    }   
    
    if(data.size != size_element)
    {
        delete [] data.parameters;
        data.parameters = new int[size_element];
        data.size = size_element;
    }
    
    std::memset(data.parameters , 0 , size_element*sizeof(data.parameters[0]) );
    char *p_token = std::strtok(const_cast<char*>(line.c_str()), ", (){}[]");
    
    int index = 0;
    while (p_token != NULL)
    {
        data.parameters[index] = std::atoi(p_token);
        ++index;
        p_token = std::strtok(NULL, ", (){}[]");
    }
    
    return is;
}

//subscription operator
int& Data::operator[](const int i) const
{
    if(i >= size){
        throw DataError("Error Data: Out-Of-Range");
    }

    return parameters[i];
}

