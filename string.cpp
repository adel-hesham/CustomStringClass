#include "string.hpp"
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
                  String Class Implementation
------------------------------------------------------
*/
/*
------------------------------------------------------
                    paramatized constructor
------------------------------------------------------
*/
string::string(const char arr[])                                        
{
    str_size=strlen(arr);
    if( str_size > small_string )
    {
        ptr = new char[str_size+1];
        strcpy(ptr,arr);
    }
    else
    {
        strcpy(mystring, arr);
        ptr=nullptr;
    }
}
/*
----------------------------------------------------------------
                        copy constructor
----------------------------------------------------------------
*/
string::string(const string &obj) : ptr(nullptr),str_size(0),mystring{'\0'}                          
{
    this->str_size=obj.str_size;                        //copy size
    if (obj.str_size > small_string)                    //check if it is a small string or not
    {
        this->ptr = new char [obj.str_size];                
        strcpy(this->ptr, obj.ptr);
    }
    else
    {
        strcpy(this->mystring, obj.mystring);
    }
}
/*
----------------------------------------------------------------
                    copy assignment    
----------------------------------------------------------------
*/
string& string::operator=(const string &obj)                                          
{
    if(this==&obj)
    {
        return *this;
    }
    this->str_size=obj.str_size;
    if(obj.str_size > small_string)
    {
        if(this->ptr!=nullptr)
        {
            delete [] this->ptr;
            this->ptr = new char[obj.str_size];
            strcpy(this->ptr, obj.ptr);
        }
        else if(this->ptr==nullptr)
        {
            this->ptr = new char[obj.str_size];
            strcpy(this->ptr, obj.ptr);
        }
    }
    else
    {
        strcpy(this->mystring, obj.mystring);
    }
    return *this;
}
/*
-------------------------------------------------------------------------
                        move constructor
-------------------------------------------------------------------------
*/
string::string(string &&obj) : ptr(nullptr),mystring{'\0'},str_size(0)                       
{
     {
        this->str_size=obj.str_size;
        obj.str_size=0;
        if(this->str_size > small_string)
        {
            this->ptr=obj.ptr;
            obj.ptr=nullptr;
        }
        else
        {
            strcpy(this->mystring, obj.mystring);
            obj.clear();
        }
    }
}
/*
-------------------------------------------------------------------------
                //move assignment
-------------------------------------------------------------------------
*/
string& string::operator=(string&& obj)                 
{
    if(this == &obj)
    {
        return *this;
    }
    this->str_size=obj.str_size;
    obj.str_size=0;
    if (this->str_size > small_string)
    {
        
        if(this->ptr){ delete [] this->ptr; } 
        this->ptr=obj.ptr;
        obj.ptr=nullptr;
    }
    else
    {
        strcpy(this->mystring, obj.mystring);
        obj.clear();
    }
    return *this;
}
/*
-------------------------------------------------------------------------
                <<operator overloading
-------------------------------------------------------------------------
*/
std::ostream& operator<<(std::ostream &os, const string &obj)           
{
    if(obj.str_size > obj.small_string)
    {
        os<<(obj.ptr);
    }
    else
    {
        os<<obj.mystring;
    }
    return os;
}
/*
-------------------------------------------------------------------------
                >>operator overloading
-------------------------------------------------------------------------
*/
std::istream& operator>>(std::istream &is, string &obj) 
{
    char temp[256];
    is >> std::setw(256) >> temp;
    obj = temp;
    return is;
}
/*
-------------------------------------------------------------------------
                    string assignmet operator
-------------------------------------------------------------------------
*/
string &string::operator=(const char str[])                           
{
    str_size=strlen(str);
    if( str_size > small_string )
    {
        if (ptr){ delete[] ptr; }
        ptr = new char[str_size+1];
        strcpy(ptr,str);
        ptr[str_size] = '\0';
    }
    else
    {
        strcpy(mystring, str);
        mystring[str_size] = '\0';
    }
    return *this;
}
/*
-------------------------------------------------------------------------
                        get string size
-------------------------------------------------------------------------
*/
const int string::size() const                 
{
    return str_size; 
}
/*
-------------------------------------------------------------------------
                check if string empty
-------------------------------------------------------------------------
*/
const bool string::empty() const                   
{
    return str_size==0;
}
/*
-------------------------------------------------------------------------
                    clear the string
-------------------------------------------------------------------------
*/
void string::clear()                    
{
    if(str_size>small_string)
    {
        delete [] ptr;
        ptr=nullptr;
    }
    else
    {
      mystring[0]='\0';
    }
    str_size=0;
}
/*
-------------------------------------------------------------------------
                Overloaded + operator: Concatenates two strings
-------------------------------------------------------------------------
*/
string string::operator+(string &obj) const         // Overloaded + operator
{
    string newstr;
    newstr.str_size=this->str_size+obj.str_size;
    if(newstr.str_size > small_string)
    {
        newstr.ptr = new char[newstr.str_size+1];
        strcpy(newstr.ptr, this->get_str());
        strcat(newstr.ptr, obj.get_str());
    }
    else
    {
        strcpy(newstr.mystring, this->mystring);
        strcat(newstr.mystring, obj.mystring);
    }
    return newstr;
}
/*
-------------------------------------------------------------------------
         Comparison operators for string comparison 
-------------------------------------------------------------------------
*/
bool string::operator==(string &obj) const
{
    return (strcmp(this->get_str(), obj.get_str()) == 0);
}
bool string::operator>=(string &obj) const
{
    return (strcmp(this->get_str(), obj.get_str()) >= 0);
}
bool string::operator<=(string &obj) const
{
    return (strcmp(this->get_str(), obj.get_str()) <= 0);
}
bool string::operator<(string &obj) const 
{
    return (strcmp(this->get_str(), obj.get_str()) < 0);
}
bool string::operator>(string &obj) const
{
    return (strcmp(this->get_str(), obj.get_str()) > 0);
}
bool string::operator!=(string &obj)const
{
    return (strcmp(this->get_str(), obj.get_str()) != 0);
}
/*
-------------------------------------------------------------------------
        subscribt 
-------------------------------------------------------------------------
*/
char& string::operator[](int index)
{
    if(index >= str_size || index < 0)
    {
        throw std::out_of_range("index out of range");
    }
    return (str_size > small_string) ? ptr[index] : mystring[index] ;
}
/*
-------------------------------------------------------------------------
            get string whatever it is in heap or not
-------------------------------------------------------------------------
*/
const char *string::get_str(void) const
{
    return(str_size > small_string) ? ptr : mystring;
}
/*
-------------------------------------------------------------------------
                destructor free the heap section
-------------------------------------------------------------------------
*/
string::~string()                             //destructor
{
    if (ptr!=nullptr)
    {
        delete[] ptr;
        ptr=nullptr;
    }    
}
