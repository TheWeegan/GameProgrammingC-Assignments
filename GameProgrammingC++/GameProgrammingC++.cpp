#include <iostream>
#include <algorithm>
#include "GameProgrammingC++.h"

ConstructorClassA::ConstructorClassA() { std::cout << "A constructed" << std::endl; }
ConstructorClassA::~ConstructorClassA() { std::cout << "A destructed" << std::endl; }

ConstructorClassB::ConstructorClassB() { std::cout << "B constructed" << std::endl; }
ConstructorClassB::~ConstructorClassB() { std::cout << "B destructed" << std::endl; }

ConstructorClassC::ConstructorClassC() { std::cout << "C constructed" << std::endl; }
ConstructorClassC::~ConstructorClassC() { std::cout << "C destructed" << std::endl; }

Assignments::Assignments() {}

Assignments::~Assignments() {}

void Assignments::IncorrectInput() {
    std::cout << "Incorrect input." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("pause");
}

int Assignments::TypeANumber(bool useMultipleOptions, int amountOfOptions, int numberOffset)
{
    int number;
number:
    std::cout << "Your choice: ";
    std::cin >> number;
    
    if (useMultipleOptions) {
        for (int i = 0; i < amountOfOptions; i++) {            
            if (number != i + numberOffset) {
                continue;
            }
            else {
                return number;
            }
        }    
        IncorrectInput();
        goto number;
    }
    if (std::cin.fail()) {
        IncorrectInput();
        goto number;
    }
    return number;
}

std::string Assignments::TypeAWord() {
    std::string word;
    std::cout << "Type something: ";
    std::cin >> word;
    std::cout << std::endl;

    return word;
}

bool Assignments::ArithmeticProgression() {    
    std::cout << "You picked arithmetic progression." <<
        std::endl << "Feel free to type in a number:" << std::endl;
    std::vector<int> vectorOfNumbers;
    bool running = true;

    while (running) {
        int input = TypeANumber(false, 0, 0);
        vectorOfNumbers.push_back(input);
        std::cout << "Do you want to insert more numbers?" << std::endl <<
            "1: Yes\t2: No" << std::endl << "Your choice: ";
        int choice = TypeANumber(true, 2, 1);
        switch (choice) {
        case 1: {
            break;
        }
        case 2: {
            running = false;
            break;
        }
        default:
            break;
        }
    }
    unsigned int lengthOfVector = vectorOfNumbers.size();

    for (int index = 0; index < lengthOfVector; index++) {
        std::cout << "Vector number " << index << ": " << vectorOfNumbers[index] << std::endl;
    }
    if (lengthOfVector == 1) {
        return true;
    }
    std::sort(vectorOfNumbers.begin(), vectorOfNumbers.end());
    
    int arithmeticNumber = vectorOfNumbers[1] - vectorOfNumbers[0];
    for (int index = 2; index < lengthOfVector; index++) {
        if (vectorOfNumbers[index] - vectorOfNumbers[index - 1] != arithmeticNumber) {
            return false;
        }
    }
    return true;
}

void Assignments::ReverseCollection() {
    std::string word = TypeAWord();
    std::string reversedWord;

    for (int i = word.length() - 1; i >= 0; i--) {
        reversedWord += word[i];        
    }
    std::cout << "The word was: " << word << "\tReversed is: " << reversedWord << std::endl;
    system("pause");
    system("CLS");
}

bool Assignments::Palindrome() {

    std::string word = TypeAWord();
    std::string reversedWord;
    std::cout << std::endl;

    int wordSize = word.size() - 1;
    if (wordSize == 1) {
        return true;
    }
    int j = 0;
    for (int i = wordSize; i >= 0; i--) {
        if (std::toupper(word[i]) != std::toupper(word[j])) {
            return false;
        }
        else {
            j++;
        }
    }
    return true;
}

void Assignments::PrintNumberInBinary(int number) {
    std::cout << "Number as binary: ";
    for (int i = 256; i > 0; i = i / 2) {
        if (number & i) {
            std::cout << "1 ";
        }
        else {
            std::cout << "0 ";
        }
    }
    std::cout << std::endl;
}

void Assignments::GetSetBits() {
    std::cout << "Type a number." << std::endl;
    int number = TypeANumber(false, 0, 0);
    PrintNumberInBinary(number);

    std::cout << "Type the bit position between 0 and 7." << std::endl;
    int bitPosition = TypeANumber(true, 8, 0);
    std::cout << "Bit at the position is: " << GetBit(number, bitPosition) << std::endl;

    std::cout << "Set the bit to either 0 or 1" << std::endl;
    int input = TypeANumber(true, 2, 0);
    int newNumber = SetBit(number, bitPosition, input);
    std::cout << "Number is: " << newNumber << std::endl;
    PrintNumberInBinary(newNumber);
    system("pause");
}

bool Assignments::GetBit(int number, int position) {
    bool bit = number & (1 << position);
    return bit;
}

int Assignments::SetBit(int& number, int position, bool value) {
    int mask = 1 << position;
    if (value) {
        number = number | mask;
    } else if (!value) {
        number = number & ~mask;
    } else {
        std::cout << "Choose either 0 or 1" << std::endl;
    }
    return number;
}

void Assignments::SwapBits() {
    std::cout << "Type a number" << std::endl;
    int numberA = TypeANumber(false, 0, 0);
    PrintNumberInBinary(numberA);

    std::cout << "Type a second number" << std::endl;
    int numberB = TypeANumber(false, 0, 0);
    PrintNumberInBinary(numberB);

    int bitPosition = 0;
    for (int i = 256; i > 0; i = i / 2) {
        unsigned int bit1 = (numberA >> bitPosition) & 1;
        unsigned int bit2 = (numberB >> bitPosition) & 1;
        if (bit1 != bit2) {
            unsigned int bitNumber = (bit1 ^ bit2);
            bitNumber = (bitNumber << bitPosition) | (bitNumber << bitPosition);

            numberA = numberA ^ bitNumber;
            numberB = numberB ^ bitNumber;
        }
        bitPosition++;
    }
    std::cout << "New first number: " << numberA << std::endl;
    PrintNumberInBinary(numberA);

    std::cout << "New second number: " << numberB << std::endl;
    PrintNumberInBinary(numberB);
    system("pause");
}

void Assignments::MinMaxSumAverage() {
    std::cout << "Insert a number" << std::endl;
    std::vector<int> numbers;
    int number;
number:
    number = TypeANumber(false, 0, 0);
    numbers.push_back(number);

    std::cout << "Want to insert more numbers?" << std::endl << "1: Yes\t2: No" << std::endl;
    int input = TypeANumber(true, 2, 1);
    switch (input) {
    case 1: {
        goto number;
        break;
    }
    case 2: {
        break;
    }
    default:
        break;
    }

    int amountOfNumbers = numbers.size() - 1;
    int sum = 0;
    int minimumNumber = INT_MAX;
    int highestNumber = INT_MIN;
    float average = 0.f;

    std::cout << "Numbers: ";
    for (int i = 0; i <= amountOfNumbers; i++) {
        int currentNumber = numbers[i];
        sum += currentNumber;
        if (currentNumber < minimumNumber) {
            minimumNumber = currentNumber;
        }
        if (currentNumber > highestNumber) {
            highestNumber = currentNumber;
        }
        std::cout << currentNumber << "\t";
    }
    std::cout << std::endl;
    average = (float)sum / amountOfNumbers;

    std::cout << "Sum: " << sum << "\tLowest number: " << minimumNumber << 
        "\tHighest number: " << highestNumber << "\tAverage: " << average << std::endl;
}

void Assignments::ConstructorOrder() {
    std::cout << "What instance do you want to create?" << std::endl <<
        "1: Create an instance of class A" << std::endl <<
        "2: Create an instance of class B" << std::endl <<
        "3: Create an instance of class C" << std::endl;
    int input = TypeANumber(true, 3, 1);

    switch (input) {
    case 1: {
        ConstructorClassA constructorClassA;
        break;
    }    
    case 2: {
        ConstructorClassB constructorClassB;
        break;
    }    
    case 3: {
        ConstructorClassC constructorClassC;
        break;
    }

    default:
        break;
    }
}

void Assignments::DoAssignment(AssignmentEnums doAssignment) {
    switch (doAssignment) {
        case AssignmentEnums::ArithmeticProgression: {
            (ArithmeticProgression()) ? (std::cout << "It's arithmetic" << std::endl) : (std::cout << "Not arithmetic" << std::endl);
            break;
        }
        case AssignmentEnums::ReverseCollection: {
            ReverseCollection();
            break;
        }
        case AssignmentEnums::Palindrome: {
            (Palindrome() ? (std::cout << "It's a palindrome" << std::endl) : (std::cout << "It's not a palindrome" << std::endl));
            break;
        }
        case AssignmentEnums::BitOfNumber: {
            GetSetBits();
            break;
        }
        case AssignmentEnums::SwapBits: {
            SwapBits();
            break;
        }
        case AssignmentEnums::MinMaxSumAverage: {
            MinMaxSumAverage();
            break;
        }
        case AssignmentEnums::ConstructorOrder: {
            ConstructorOrder();
            break;
        }
        default: {
            break;
        }
    }
}
int main() {
    Assignments assignments;
    std::string assignmentNames = 
        "1: ArithmeticProgression\n2: ReverseCollection\n3: Palindrome\n4: BitOfNumber\n5: SwapBits\n6: MinMaxSumAverage\n7: ConstructorOrder\n8: Quit";
    std::cout << "Yo o/" << std::endl << "I decided to do all assignments in one program to make things simpler :3" << std::endl;
    bool running = true;
    while (running) {
        std::cout << "Which assignment do you want to try: " << std::endl;
        std::cout << assignmentNames << std::endl;
        int input = assignments.TypeANumber(true, 8, 1);
        switch (input)
        {
        case 1: {
            assignments.DoAssignment(AssignmentEnums::ArithmeticProgression);
            break;
        }
        case 2: {
            assignments.DoAssignment(AssignmentEnums::ReverseCollection);
            break;
        }
        case 3: {
            assignments.DoAssignment(AssignmentEnums::Palindrome);
            break;
        }
        case 4: {
            assignments.DoAssignment(AssignmentEnums::BitOfNumber);
            break;
        }
        case 5: {
            assignments.DoAssignment(AssignmentEnums::SwapBits);
            break;
        }
        case 6: {
            assignments.DoAssignment(AssignmentEnums::MinMaxSumAverage);
            break;
        }
        case 7: {
            assignments.DoAssignment(AssignmentEnums::ConstructorOrder);
            break;
        }
        case 8: {
            std::cout << "Shutting down" << std::endl;
            running = false;
            break;
        }
        default:
            break;
        }
        system("pause");
        system("CLS");
    }
    return 0;
}

