#pragma once

#include <sstream>

namespace lp{

    class String
    {
    private:
        char* _point = nullptr;
        unsigned int _size = 0;

        /*friend std::ostream& operator<<(std::ostream& os, const String& obj);

        friend std::istream& operator>>(std::istream& is, const String& obj);*/
    public:
        String();

        String(const String& other);

        String(char* addjoin);

        String(char addjoin);

        ~String();

        const unsigned int GetSize() const {return _size;}

        const char* GetPoint() const {return _point;}

        String operator=(String& other);

        String operator+(String& other);

        String operator+=(String& other);

        String operator+=(String other);

        char operator[](unsigned int index) const;

        bool operator<(String& other) const;

        bool operator>(String& other) const;

        bool operator==(String& other) const;



    };

    std::ostream& operator<<(std::ostream& os, const String& obj);

    std::istream& operator>>(std::istream& is, const String& obj);

}
