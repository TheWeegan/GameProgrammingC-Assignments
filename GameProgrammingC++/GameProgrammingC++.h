#pragma once
#include <vector>
#include <string>

enum class AssignmentEnums {
    ArithmeticProgression,
    ReverseCollection,
    Palindrome,
    BitOfNumber,
    SwapBits,
    MinMaxSumAverage,
    ConstructorOrder,
    Count
};

class ConstructorClassA {
public:
    ConstructorClassA();
    ~ConstructorClassA();
};

class ConstructorClassB : ConstructorClassA {
public:
    ConstructorClassB();
    ~ConstructorClassB();
};

class ConstructorClassC : ConstructorClassB {
public:
    ConstructorClassC();
    ~ConstructorClassC();
};

class Assignments {

public:    
    Assignments();
    ~Assignments();    
    void DoAssignment(AssignmentEnums doAssignment);
    int TypeANumber(bool useMultipleOptions, int amountOfOptions, int numberOffset);

private:
    void IncorrectInput();

    std::string TypeAWord();

    bool ArithmeticProgression();
    
    void ReverseCollection();

    bool Palindrome();

    void PrintNumberInBinary(int number);    
    void GetSetBits();
    bool GetBit(int number, int position);
    int SetBit(int& number, int position, bool value);
    void SwapBits();
    
    void MinMaxSumAverage();

    void ConstructorOrder();
};