#include <iostream>
#include "Data.hpp"

using namespace std;

int main()
{
    
    try{
        Data data1 = Data("data1"  , 7);
        
        data1[0] = 0;
        data1[1] = 1;
        data1[2] = 2;
        data1[3] = 3;
        data1[4] = 4;
        data1[5] = 5;
        data1[6] = 6;
        cout << data1 << endl;

        
        Data data2 = Data(data1 , "data2"); 
        cout << data2 << endl;
        
        if(data1 == data2){
            cout << "data1 and data2 have the same size and values"<< endl<< endl;
        }
        else{
            cout << "data1 and data2 do not have the same size or values"<< endl<< endl;
        }
            
        
        cout << "same line data2++: \n" << data2++ << endl;
        cout << "line below data2++: \n" << data2 << endl;
        cout << "same line ++data2: \n" << ++data2 << endl;
        
        
        if(data1 != data2){
            cout << "data1 and data2 do not have the same size and values"<< endl<< endl;
        }
        else{
            cout << "data1 and data2 have the same size or values"<< endl<< endl;
        }

        cout << "same line data1--: \n" << data1-- << endl;
        cout << "line below data1--: \n" << data1 << endl;
        cout << "same line --data1: \n" << --data1 << endl;    
        
        cout << "data1 + 2: \n" << (data1 + 2)<< endl;
        
        //doesn't have sense but I have just implemented to have a simmetric implementation with friend 
        cout << "2 + data1: \n" << (2 + data1) << endl; 
        
        cout << "data1 = data1 - 2: \n" << (data1 = data1 - 2)<< endl;
        cout << "data1 * 2: \n" << (data1 * 2)<< endl;
        cout << "data1 / 2: \n" << (data1 / 2)<< endl;        
        
        cout << data1 << endl;
        cout << data2 << endl;
        cout << "data1 + data2: \n" << (data1 + data2)<< endl;  
        cout << "data1 - data2: \n" << (data1 - data2)<< endl;  
        cout << "data1 = data1 * data2: \n" << (data1 = data1 * data2)<< endl;  
        cout << "data1 / data2: \n" << (data1 / data2)<< endl; 
        cout << "data1 += data2: \n" << (data1 += data2)<< endl;  
        cout << "data1 += -1: \n" << (data1 += -1)<< endl; 
        
        
        Data data3 = Data("MyData3" , 1); 
        cout << "\n\n insert the parameter for MyData3 ([val1, val2 ,.. , valn]): ";
        cin >> data3;
        
        cout << data3 << endl;
    }
    catch(DataError &e)
    {
        cout << e.get_message() << endl;
    }
    
    return EXIT_SUCCESS; 
}
