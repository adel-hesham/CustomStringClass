#ifndef STRING_HPP
#define STRING_HPP
/*
------------------------------------------------------
                  Custom String Class
------------------------------------------------------
    Author: [Adel hesham elnimr]  
    Date: [2025/2/21]  
    Description:  
    - This is a custom implementation of a string class  
    - Supports small string optimization (SSO)  
    - Implements copy/move constructors and assignment operators  
    - Overloads various operators for string manipulation  
------------------------------------------------------
*/


/*
------------------------------------------------------
                  Include Libraries
------------------------------------------------------
*/
#include <iomanip>
#include<iostream>
#include<cstring>
#include <stdexcept>
/*
------------------------------------------------------
                  String Class Definition
------------------------------------------------------
*/
class string
{
public:
    string():str_size(0),mystring{'\0'},ptr(nullptr){}          //default constructor initializes an empty string

    explicit string(const char arr[]);                              //paramatized constructor

    string (const string &obj);                                     //copy constructor
 
    string &operator=(const string &obj);                           //copy assignment
  
    string (string &&obj);                                          //move constructor
   
    string &operator=(string &&obj);                                // move assignment 
       
    string &operator=(const char str[]);                            //string assignmet operator
    
    friend std::ostream& operator<<(std::ostream &os,const string &obj);       //friend <<operator to access private members
    friend std::istream& operator>>(std::istream &is, string &obj);       //friend <<operator to access private members


    ~string();                 //destructor
   
  
    
    const int size()const ;         //get the string size
    const bool empty()const ;       //check if string is empty
    void clear();                   //clear the string
    string operator+(string &obj)const; // Overloaded + operator for string concatenation
    // Comparison operators for string comparison 
    bool operator==(string &obj)const ;
    bool operator>=(string &obj)const;
    bool operator<=(string &obj)const;
    bool operator>(string &obj)const;
    bool operator<(string &obj)const;
    bool operator!=(string &obj)const;
    // Overloaded subscript operator for accessing characters
    char& operator[](int index);


private:
    static constexpr int small_string=17;
    char mystring[small_string];        //array to store the small string
    char *ptr;                          //pointer to point to the new memory created in the heap section to store the long strings
    int str_size;                       //to store the string size
    const char *get_str() const ;       //get the string whatever it is in heap or not

};
#endif