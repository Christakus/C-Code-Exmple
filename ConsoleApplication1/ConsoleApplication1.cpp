// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#pragma region NotCopyable base code


struct NotCopyable
{
    // implementing default constructor
    NotCopyable();
    // deleting the function for passing an instance
    // of the base struct into itself as parameter
    NotCopyable(const NotCopyable&) = delete; 
   
    // operator for deleting the "=" operator to prevent
    // copy-assignment
    NotCopyable& operator=(const NotCopyable&) = delete;
};

int main() {
    // cannot instantiate, even when default constructor is present.
    NotCopyable noCopy = NotCopyable();
    NotCopyable noCopy1 = NotCopyable();

    // cannot be copy-assigned to a datatype of itself
    noCopy = noCopy1;

    return 0;
}

#pragma endregion

#pragma region Basic Struct with "(int)" operator

/*
struct Example
{
public:
    Example() : value(43) { } // initalizer list

    //operator function to add input number to value
    int operator()(int num) { 
        value += num; // adding the input to value
        return value; 
    }

    int getValue() const { return value; }
private:
    int value; // cant be const as we are adding to it
};

int main() {
    Example example = Example();

    std::cout << example(5);
}
*/
#pragma endregion

#pragma region Deleting Copy Assignment Operator
/*struct Example {
public:
    Example() { } // default constructor
    // setting the operator "=" to deletion.
    // this prevents copy assignment
    Example& operator=(const Example&) = delete;
};
int main() {
    // instantiating 2 Examples
    Example example = Example();
    Example example2 = Example();

    // since we deleted the "=" operator for this Example
    // we are unable to assign the value of Example2 to Example.
    example = example2;
    return 0;
}*/
#pragma endregion


#pragma region Deleting Constructor with string parameter
/*
struct Example {
public:
    Example(float& num) { value = num; }
    // if the referenced variable is a string
    // Example will not initalise
    // as it has been deleted
    Example(std::string &text) = delete;
    int getValue() const { return value; }
private:
    float value;
};

int main()
{
    // variable for holding values
    float param = 5.5f;
    std::string invalid = "LET ME IN";

    // instantiating example with float value (Passed by reference)
    Example example = Example(param);
    // outputs 5.5
    std::cout << example.getValue();
    // there is an error here because we cannot instantiate 
    // Example with a string value as it is deleted
    example = Example(invalid);

    return 0;
}
*/
#pragma endregion


#pragma region Template Data Type and Functions with delete function for Type T

/*
template < typename T > // templating generic "Type T" property
// deleting function with any data type
float AddFloatValues(T, T) = delete;
// generating function and allocating memory to float values
float AddFloatValues(float num1, float num2) { return num1 + num2; }

int main() {

    // outputs 12
    std::cout << AddFloatValues(5.5f, 6.5f);
    // Cannot call function with non-float values
    // as it is a deleted function 
    std::cout << AddFloatValues(5.0, 6.0);
    return 0;
}
*/
#pragma endregion


#pragma region Pass-By-Reference Example
/*
struct Example {
public:
    Example() { } // default constructor

    // this function recieves a "reference" to a local variable in main()
    void ManipulateMessage(std::string &message) {
        // here we are modifying the orginal value of the
        // "message" variable in main()
        message = localMessage;
    }
private:
    // local constant string
    const std::string localMessage = "This is the struct message!";
};

int main() {

    // local variable
    std::string message = "This the base message!";
    // output base message
    std::cout << message << std::endl;
    Example example = Example();
    // passing the message to Example function
    example.ManipulateMessage(message);
    // output updated message
    std::cout << message << std::endl;

    return 0;
}
*/
#pragma endregion
