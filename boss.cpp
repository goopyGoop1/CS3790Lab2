#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std; 

int main(int argc, char *argv[]) {
    // Check for the correct number of command-line arguments
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <num_of_workers> <upper_bound>" << endl;
        return 1;
    }

    // Convert command-line arguments to integers
    int num_of_workers = atoi(argv[1]);  // Number of child processes to create
    int upper_bound = atoi(argv[2]);    // Upper bound for finding prime numbers

    // Validate input: Ensure both values are positive
    if (num_of_workers <= 0 || upper_bound <= 0) {
        cerr << "Usage: num_of_workers and upper_bound MUST be > 0" << endl;
        return 1;
    }

    // Calculate the range of numbers each worker process will handle
    int range_for_worker = upper_bound / num_of_workers;
    int remain = upper_bound % num_of_workers; // Remaining numbers after equal division

    // Create the worker processes in a loop
    for (int i = 0; i < num_of_workers; i++) {
        int lower_bound = i * range_for_worker + 1;
        int upper_bound_for_worker = (i + 1) * range_for_worker;

        if (i == (num_of_workers - 1)) {
            upper_bound_for_worker += remain;
        }

        pid_t pid = fork();
        if (pid == 0) {
            // Child process code:
            execl("./wrk", "./wkr",to_string(lower_bound).c_str(),to_string(upper_bound_for_worker).c_str(), (char*)NULL);
            perror("execl failed");
            return 1;
        } else if (pid < 0) {
            std::cerr << "Fork failed" << endl;
            return 1;
        }
    }

    // Parent process code: Wait for all child processes to finish
    for (int i = 0; i < num_of_workers; i++) {
        int status;
        wait(&status);
    }

    

    return 0;
}
