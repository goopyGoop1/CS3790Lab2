# CS3790Lab2
Boss Worker 



# Boss-Worker Prime Number Finder

This project implements a simple boss-worker computing model in C++ to find all prime numbers within a given range. The boss process creates multiple worker processes, each responsible for finding primes in a specific sub-range.

## Files

1. **boss.cpp**: This program takes two command-line arguments: the number of worker processes to create and the upper bound for finding prime numbers. It divides the range into equal parts and creates the specified number of worker processes to search for primes in their respective sub-ranges.

2. **worker.cpp**: This program takes two command-line arguments: the lower and upper bounds of the range within which it will search for prime numbers. It checks if each number in the range is prime and writes the prime numbers to a file named `worker_<lower_bound>_<upper_bound>.txt`.

## How to Compile and Run

### Compile

First, compile both `boss.cpp` and `worker.cpp` into executable files.


###
g++ -o bos boss.cpp

###
g++ -o wrk worker.cpp  (you MUST compile the  worker this way to ensure it works.)

### Running 

When ./bos 4 300 to run program unless you've named the worker .exe file wrk it will fail. Or you can change this line in the code to [execl("./wrk", "./wkr",to_string(lower_bound).c_str(),to_string(upper_bound_for_worker).c_str(), (char*)NULL);
 perror("execl failed");] to whatever you name the worker files .exe this change will ensure your code runs. 



