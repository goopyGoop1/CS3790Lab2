#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std; 


// Function to check if a number is prime
bool primeNums (int num){
    if (num <= 1) return false; // 1 is not prime
    if (num <= 3) return true; // 2 and 3 are prime
    if (num % 2 == 0 || num % 3 == 0) return false; // If divisible by 2 or 3, not prime
    for (int i = 5; i * i <= num; i+= 6){ // Optimized primality test, checks divisibility by numbers of the form 6k ± 1
        if (num % i == 0 || num % (i + 2) ==  0) return false; 
    }
    
    return true; 
}

int main(int argc, char *argv[]){
    
    // Check if the correct number of command-line arguments are provided
    if (argc != 3){
        cerr <<  (string)"Usage: " << argv[0] << "<lower_bound> <upper_bound>" << endl; 
        
        return 1; 
    }
    // Convert command-line arguments to integers
    int lower_bound = atoi(argv[1]);
    int upper_bound = atoi(argv[2]); 
    
   
   // Check if lower bound is greater than upper bound
    if (lower_bound > upper_bound){
        cerr << "Usage: lower_bound must be < || == upper_bound" << endl; 
        
        return 1; 
    }
    
     // Construct the filename using the bounds
    string filename = "worker_"; 
    filename = filename + to_string(lower_bound) + "_" + to_string(upper_bound) + ".txt"; 
    ofstream MyFile(filename); 
    
    // Check if the file opened successfully
    if (!MyFile.is_open()){
        
        cerr << "Usage  : File did not open " << filename << endl; 
        
        return 1; 
    }
    
    // Write a header to the file
    MyFile << "The following Primes have been for the numbers between " << lower_bound << " & " << upper_bound << ".\n\n";
    
    
    // Iterate through the numbers within the specified bounds
    for(int i = lower_bound; i <= upper_bound; i++){
        if (primeNums(i)){
            MyFile << i << "\n"; 
        }
    }
    
    MyFile << endl; 
    

    
    

    MyFile.close(); 
    
    return 0; 
}
