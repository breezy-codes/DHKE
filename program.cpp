#include <iostream>
#include <cmath>

// program to implement the diffie hellman key exchange algorithm

using namespace std;

// function to calculate the modular exponentiation
int modular_exponentiation(int base, int exponent, int modulus)
{
    int result = 1;
    base %= modulus;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

int main()
{
    //Declare the variables
    int prime, primitive_root, private_key_A, private_key_B;

    //ask user to enter in the values to check
    cout << "Enter a value for the prime number: ";
    cin >> prime;
    cout << "Enter a value for the primitive root: ";
    cin >> primitive_root;
    cout << "Enter a value for the private key for a: ";
    cin >> private_key_A;
    cout << "Enter a value for the private key for b: ";
    cin >> private_key_B;
    //print out the values to check
    cout << "Declaring the variable inputs for the key exchange" << endl;
    cout << "The prime number is: " << prime << endl;
    cout << "The primitive root is: " << primitive_root << endl;
    cout << "The private key for a is: " << private_key_A << endl;
    cout << "The private key for b is: " << private_key_B << endl;

    // run the Diffie-Hellman key exchange algorithm
    cout << "Running the Diffie-Hellman key exchange algorithm..." << endl;
    int public_key_A = modular_exponentiation(primitive_root, private_key_A, prime);
    int public_key_B = modular_exponentiation(primitive_root, private_key_B, prime);
    cout << "The public key for A is: " << public_key_A << endl;
    cout << "The public key for B is: " << public_key_B << endl;

    // calculate the shared secret key
    cout << "Calculating the shared secret key..." << endl;
    int shared_secret_key_A = modular_exponentiation(public_key_B, private_key_A, prime);
    int shared_secret_key_B = modular_exponentiation(public_key_A, private_key_B, prime);
    cout << "The shared secret key for A is: " << shared_secret_key_A << endl;
    cout << "The shared secret key for B is: " << shared_secret_key_B << endl;

    return 0;
}
