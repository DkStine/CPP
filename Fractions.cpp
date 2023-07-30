#include "Fractions.hpp"
#include <bits/stdc++.h>

template <typename T>
T gcd(T a, T b){
  return b ? gcd<T>(b,a%b) : a;
}

//===================== DO NOT TOUCH THE STUFF ABOVE ==========

// print() implementation:
// it should print the fraction in the following order in its lowest form
// 1/2
// terminated by a newline, no spaces or anything else


//=========== YOUR CODE HERE ==============
// Constructor
template <typename T>
Fraction<T>::Fraction(T num, T den) : numerator(num), denominator(den) {}

// Reduce the fraction to its simplest form
template <typename T>
Fraction<T> Fraction<T>::reduce() {
    T gcd_val = gcd(numerator, denominator);
    numerator = numerator / gcd_val;
    denominator = denominator / gcd_val;

    if (denominator < 0)
    {
        numerator = -numerator
        denominator = -denominator
    }
    return *this;
  
    // return Fraction<T>(numerator / gcd_val, denominator / gcd_val);
}

// Get the numerator of the fraction
template <typename T>
T Fraction<T>::get_numerator() {
    return numerator;
}

// Get the denominator of the fraction
template <typename T>
T Fraction<T>::get_denominator() {
    return denominator;
}

// Overloaded operator: Addition
template <typename T>
Fraction<T> Fraction<T>::operator+(Fraction<T>& other) {
    if (denominator < 0)
    {
        numerator = -numerator
        denominator = -denominator
    }

    T new_num = numerator * other.denominator + other.numerator * denominator;
    T new_den = denominator * other.denominator;
    return Fraction<T>(new_num, new_den).reduce();
}

// Overloaded operator: Subtraction
template <typename T>
Fraction<T> Fraction<T>::operator-(Fraction<T>& other) {
    if (denominator < 0)
    {
        numerator = -numerator
        denominator = -denominator
    }

    T new_num = numerator * other.denominator - other.numerator * denominator;
    T new_den = denominator * other.denominator;
    return Fraction<T>(new_num, new_den).reduce();
}

// Overloaded operator: Multiplication
template <typename T>
Fraction<T> Fraction<T>::operator*(Fraction<T>& other) {
    if (denominator < 0)
    {
        numerator = -numerator
        denominator = -denominator
    }

    T new_num = numerator * other.numerator;
    T new_den = denominator * other.denominator;
    return Fraction<T>(new_num, new_den).reduce();
}

// Overloaded operator: Division
template <typename T>
Fraction<T> Fraction<T>::operator/(Fraction<T>& other) {
    if (denominator < 0)
    {
        numerator = -numerator
        denominator = -denominator
    }

    T new_num = numerator * other.denominator;
    T new_den = denominator * other.numerator;
    return Fraction<T>(new_num, new_den).reduce();
}

// Overloaded operator: Equal to
template <typename T>
bool Fraction<T>::operator==(Fraction<T>& other) {
    if (denominator < 0)
    {
        numerator = -numerator
        denominator = -denominator
    }

    Fraction<T> curr = *this;
    curr.reduce();
    other.reduce();
    return (curr.numerator == other.numerator && curr.denominator == other.denominator);
}

// Overloaded operator: Not equal to
template <typename T>
bool Fraction<T>::operator!=(Fraction<T>& other) {
    if (denominator < 0)
    {
        numerator = -numerator
        denominator = -denominator
    }

    return !(*this == other);
}

// Overloaded operator: Less than or equal to
template <typename T>
bool Fraction<T>::operator<=(Fraction<T>& other) {
    // if (denominator < 0)
    // {
    //     numerator = -numerator
    //     denominator = -denominator
    // }

    Fraction<T> curr = *this;
    curr.reduce();
    other.reduce();
    return (curr.numerator * other.denominator <= other.numerator * curr.denominator);
}

// Overloaded operator: Less than
template <typename T>
bool Fraction<T>::operator<(Fraction<T>& other) {
    // if (denominator < 0)
    // {
    //     numerator = -numerator
    //     denominator = -denominator
    // }

    Fraction<T> curr = *this;
    curr.reduce();
    other.reduce();
    return (curr.numerator * other.denominator < other.numerator * curr.denominator);
}

// Overloaded operator: Greater than or equal to
template <typename T>
bool Fraction<T>::operator>=(Fraction<T>& other) {
    // if (denominator < 0)
    // {
    //     numerator = -numerator
    //     denominator = -denominator
    // }

    return !(*this < other);
}

// Overloaded operator: Greater than
template <typename T>
bool Fraction<T>::operator>(Fraction<T>& other) {
    // if (denominator < 0)
    // {
    //     numerator = -numerator
    //     denominator = -denominator
    // }

    return !(*this <= other);
}

// Print the fraction in its lowest form (e.g., "1/2")
template <typename T>
void Fraction<T>::print() {
    Fraction<T> reduced = reduce();
    std::cout << reduced.numerator << div_char << reduced.denominator << std::endl;
}