#include <iostream>
#include <thread>
#include <string>
#include <algorithm>
using namespace std;

void input_string(std::string& s)
{
    cout << "Enter a string: ";
    std::getline(std::cin, s);
}

void reverse_string(const std::string& s)
{
    std::string reversed_s(s.rbegin(), s.rend());
    cout << "Reversed string: " << reversed_s <<endl;
}

void capitalize_string(const std::string& s)
{
    std::string capitalized_s;
    for (char c : s)
        capitalized_s += toupper(c);
	    cout << "Capitalized string: " << capitalized_s <<endl;
}

void shift_string(const std::string& s)
{
    std::string shifted_s;
    for (char c : s)
        shifted_s += (c + 2);
	cout << "Shifted string: " << shifted_s <<endl;
}

int main()
{
    std::string s;

    // Create the first thread to input the string
    std::thread t1(input_string, std::ref(s));

    // Wait for the first thread to finish
    t1.join();

    // Create the other three threads
    std::thread t2(reverse_string, std::cref(s));
    std::thread t3(capitalize_string, std::cref(s));
    std::thread t4(shift_string, std::cref(s));

    // Wait for the threads to finish
    t2.join();
    t3.join();
    t4.join();

    return 0;
}