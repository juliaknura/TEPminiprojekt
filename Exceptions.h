#pragma once
#include <exception>

const std::string msg = "File reading failed while reading ";
const std::string msg3 = " number or neighbouring";

class FileOpenFailException : public std::exception {
private:
    const std::string message;

public:
    FileOpenFailException(const std::string& msg) : message(msg) {}
    const std::string what() {return message;}
};

class FileReadFailException : public std::exception {
private:
    int number;

public:
    FileReadFailException(int number) :number(number) { }
    const std::string what() {
        std::string numberString = std::to_string(number);
        std::string msg2;
        if (number % 10 == 1 && number!=11)
        {
            msg2 = "st";
        }
        else if (number % 10 == 2 && number!=12)
        {
            msg2 = "nd";
        }
        else if (number % 10 == 3 && number!=13)
        {
            msg2 = "rd";
        }
        else
        {
            msg2 = "th";
        }
        return msg + numberString + msg2 + msg3;
    }
};

class InvalidDataException : public std::exception {
private:
    const std::string message;

public:
    InvalidDataException(const std::string& msg) : message(msg) {}
    const std::string what() {return message;}
};