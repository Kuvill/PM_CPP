#include <algorithm>

#include "string.hpp"

using namespace lp;

/*----------------------------RAII BLOCK-----------------------------------------*/

String::String(){
    //ctor
}

String::String(const String& other)
{
    if (_size != other._size){
        _point = new char[other._size];
        _size = other._size;
    }

    std::copy(other._point, other._point+other._size, _point);
}

String::String(char* addjoin){
    unsigned int i = 1;
    while (*addjoin != '\0')
        ++i;
    _point = new char[_size+i];
    std::copy(addjoin, addjoin+i, _point);
    _size = i;
}

String::String(char addjoin){
    _point = new char[++_size];
    _point[_size-1] = addjoin;
}

String::~String(){
    delete [] _point;
}

/*----------------------------math BLOCK-----------------------------------------*/

String String::operator=( String& other)
{
    if (_size != other._size){
        _point = new char[other._size];
        _size = other._size;
    }

    std::copy(other._point, other._point+other._size, _point);

    return *this; //not sure tbh
}

String String::operator+( String& other){
    String result(*this);
    result._point = new char[result._size+other._size+1]; // 2 allocation could be 1

    result._point[result._size] = ' ';

    std::copy(other._point, other._point+other._size, result._point+_size+1);

    return result;
}

String String::operator+=( String& other){
    _point = new char[_size+other._size+1]; // 2 allocation could be 1

    _point[_size] = ' ';
    std::copy(other._point, other._point+other._size, _point+_size+1);

    return *this;
}

String String::operator+=( String other){
    _point = new char[_size+other._size+1]; // 2 allocation could be 1

    _point[_size] = ' ';
    std::copy(other._point, other._point+other._size, _point+_size+1);

    return *this;
}
/*----------------------------compare BLOCK-----------------------------------------*/

bool String::operator<( String& other) const {
    if (_size < other._size)
        return true;
    if (_size > other._size)
        return false;
    for (unsigned int i = 0; i < _size; ++i)
        if (_point[i] != other._point[i]) //c++20 <=>
            return _point[i] < other._point[i];
    return false;
}

bool String::operator>( String& other) const {
    if (_size > other._size)
        return true;
    if (_size < other._size)
        return false;
    for (unsigned int i = 0; i < _size; ++i)
        if (_point[i] != other._point[i]) //c++20 <=>
            return _point[i] > other._point[i];
    return false;
}

bool String::operator==( String& other)const {
    if (_size != other._size)
        return false;
    for (unsigned int i = 0; i < _size; ++i)
        if (_point[i] != other._point[i])
            return false;
    return true;
}

/*----------------------------syntax BLOCK-----------------------------------------*/

char String::operator[](unsigned int index) const {
    return *(_point+index);
}



std::ostream& operator<<(std::ostream& os, const String& obj){
    bool isFirst = true;
    for (unsigned int i = 0; i < obj.GetSize(); ++i){

        if (isFirst)
            isFirst = false;
        else
            os << ' ';

        os << obj[i];
    }
    return os;
}

std::istream& operator>>(std::istream& is, const String& obj){
    char tmp;
    while (is.get(tmp) && tmp != '\n'){ //+= not working(
        obj+=tmp;
    }
    return is;
}
