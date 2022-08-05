#pragma once
# include <string>

/**
 * @brief Queries a given file for a given keyword
 * Creates an ifstream from given filename, running through line by line
 * checking for all instances of given keyword, storing results in a map
 * with key as line number and vaue as line containing keyword.
 */
void query(std::string, std::string, bool);

/**
 * @brief Prints help for the program.
 * 
 */
void print_help();