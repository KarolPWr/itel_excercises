/*
** checked_memory_test.c -- memory testing program with array of strings and check
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_SIZE 1024  // in bytes
#define NUM_STRINGS 15

void test_memory() {
    // Allocate memory
    char *memory_block = (char *)malloc(MEMORY_SIZE);
    if (memory_block == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    // Test data: an array of strings
    const char *test_data[NUM_STRINGS] = {
        "This is a test.",
        "Another string.",
        "Short one.",
        "A bit longer string.",
        "Testing memory.",
        "1234567890",
        "A",
        "This is the eighth string.",
        "Number 9.",
        "Ten!",
        "Yet another string.",
        "Testing.",
        "Short.",
        "A longer one.",
        "Last string."
    };

    // Write data to the memory block using strncpy in a loop
    size_t offset = 0;
    for (size_t i = 0; i < NUM_STRINGS; ++i) {
        size_t len = strlen(test_data[i]);
        if (offset + len < MEMORY_SIZE) {
            strncpy(memory_block + offset, test_data[i], len);
            offset += len;
        } else {
            fprintf(stderr, "Insufficient memory for string %zu\n", i);
            break;
        }
    }

    // Read and print the data
    printf("Data read from memory: %s\n", memory_block);

    // Check if written and read strings are the same
    for (size_t i = 0, offset = 0; i < NUM_STRINGS; ++i) {
        size_t len = strlen(test_data[i]);
        if (strncmp(memory_block + offset, test_data[i], len) != 0) {
            fprintf(stderr, "Error: Written and read strings are different at index %zu\n", i);
        }
        offset += len;
    }

    // Free the allocated memory
    free(memory_block);
}

int main(void) {
    test_memory();

    return 0;
}
