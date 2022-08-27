// SuperStrings <Project1.cpp>
// EE 312 Project 1 submission by
// Chieh-An Chen
// cc67994
// Slip days used: <0>
// Summer 2022
// Copy-paste contents of this file at the top of every .c or .h file that you write or modify.
/*
 * Project1.cpp
 *
 * Name: Chieh-An Chen
 * EE312 Summer 2022
 * SuperStrings
 */

#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types

/*
All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)

You must write this function (printSuperStrings). Do not change the way the function is declared (i.e., it has
exactly two parameters, each parameter is a standard (mundane) C string (see Instruction).
*/

void printSuperStrings(char targets [], char candidates []) {

    /*
     * string target (list of strings) string candidates (list of candidate superstrings)
     * go through all words of candidates to check if each one of candidates is a superstring
     * while candidates has a next word:
     *      word = get the next word of candidates
     *      for target T in targets:
     *          if word is superstring of T:
     *              print word
     */

    /*
     * string target (list of strings) string candidates (list of candidate superstrings)
     * T_idx = start of target
     * C_idx = start of candidate
     * while target[c_idx] != null term { //I have not run out of candidates
     *      while candidate is not null term: {//I have not run out of targets for this candidate
         *       while target[c_idx] != whitespace:{ //while we are still in this target
         *          char = candidates[c_idx]
         *          if target[t_idx] = candidates[T_idx]: { //check if the target letter is up next
         *              T_idx++ //move to the next target letter
         *          }
         *          c_idx++ //move to next candidate letter
         *          if T_idx == whitespace { //If I have matched every letter in this target, print it all out
         *              reset C_idx to start of the word
         *              roll C_idx through the word, printing one letter at a time
         *          }
         *      }
         *      reset t_idx to start of the word
         *      move c_idx to start of next word
         * }
         * move T_idx to next word start
         * reset C_idx to first
     *  }
   */
    int t_idx = 0;
    int c_idx = 0;
    int target_len = 0;
    int target_lencopy = 0;
    int candidate_len = 0;
    int candidate_lencopy = 0;
    int notsuper = 0;
    char target;
    char candid;
    while (targets[t_idx] != '\0') { //while not at the end of the entire string
        while (candidates[c_idx] != '\0') {
            //while (targets[t_idx] != '\n' && targets[t_idx] != 0x09 && targets[t_idx] != 0x20 && targets[t_idx] != '\0') {
                while (targets[t_idx] == '\n' || targets[t_idx] == 0x09 || targets[t_idx] == 0x20 ){
                    t_idx++;
                }
                while (candidates[c_idx] == '\n' || candidates[c_idx] == 0x09 || candidates[c_idx] == 0x20 ){
                    c_idx++;
                }
                if (candidates[c_idx] == targets[t_idx]) {
                    t_idx++;
                    target_len++;
                    target = targets[t_idx];
                }
                if (candidates[c_idx] != '\0') {
                    c_idx++;
                    candidate_len++;
                    candid = candidates[c_idx];
                }

                if (targets[t_idx] == '\n' || targets[t_idx] == 0x09 || targets[t_idx] == 0x20 || targets[t_idx] == '\0') {
                    c_idx = c_idx - candidate_len; // reset C_idx to start of the word

                    while (candidates[c_idx] != '\n' && candidates[c_idx] != 0x09 && candidates[c_idx] != 0x20 && candidates[c_idx] != '\0') { //roll C_idx through the word, printing one letter at a time
                        printf("%c", candidates[c_idx]);
                        fflush(stdout);
                        candidate_lencopy = candidate_lencopy + 1;
                        c_idx++;
                    }

                    printf("\n");
                    target_lencopy = target_len;
                    t_idx = t_idx - target_len; // reset t_idx to start of the word
                    if (candidates[c_idx] != '\0') {
                        c_idx++;
                    }
                    candidate_len = 0;
                    target_len = 0;
                }
                if (candidates[c_idx] == '\n' || candidates[c_idx] == 0x09 || candidates[c_idx] == 0x20){
                    c_idx++;
                    t_idx = t_idx - target_len;
                    candidate_len = 0;
                    target_len = 0;
                }

            //} //still in the same target end

        }
        //move to next target
        while (targets[t_idx] != '\n' && targets[t_idx] != 0x09 && targets[t_idx] != 0x20 && targets[t_idx] != '\0'){
            t_idx++;
        }
        while (targets[t_idx - 1] != '\n' && targets[t_idx - 1] != 0x09 && targets[t_idx - 1] != 0x20 && targets[t_idx] != '\0'){
            t_idx++;
        }
        //t_idx = t_idx + target_lencopy;
        //t_idx++;
        //bring candidate back to beginning
        c_idx = 0;
        candidate_len = 0;
        target_len = 0;
        //}
    }


}
