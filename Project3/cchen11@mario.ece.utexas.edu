// String ADT <Project3.cpp>
// EE 312 Project 3 submission by
// Chieh-An Chen
// cc67994
// Slip days used: <0>
// Summer 2022
// Copy and paste this file at the top of all your submitted source code files.
// Do not turn this in by itself.


#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "UTString.h"

/*
* Helper macro to find the signature of a UTString
* Treat this like a function that takes a UTString*
* Accesses a uint32_t from where the signature should be located
*/
#define CHECK(s) (*(uint32_t*) ((s)->string + (s)->length + 1))

/*
* Checks if a UTString is valid or not.
*/

bool isOurs(const UTString *s) {
    if (CHECK(s) == SIGNATURE) { return true; }
    else { return false; }
}

/*
 * Allocate a utstring on the heap.
 * Initialize the string correctly by copying src.
 * Return a pointer to the UTString.
 */

UTString *utstrdup(const char *src) {

    int srclen = strlen(src);
    int i = 0;
    int x = strlen(src) + 1 + 4;
    int z = strlen(src);
    UTString* utStringcopy = (UTString*)malloc(sizeof(UTString));
    utStringcopy -> length = strlen(src);
    utStringcopy -> capacity = strlen(src);
    utStringcopy -> string = (char*)malloc(sizeof(char)*(x));
    while (i <= srclen){
        utStringcopy->string[i] = src[i];
        i++;
    }

    CHECK(utStringcopy) = SIGNATURE;
    return utStringcopy;


}


/*
 * Returns the length of s.
 *  s must be a valid UTString.
 */

uint32_t utstrlen(const UTString *s) {
    assert(isOurs(s));
    return s -> length;
}


/*
 * Append the string suffix to the UTString s.
 *  s must be a valid UTString.
 * Do not allocate any additional storage: only append as many characters
 *  as will actually fit in s.
 * Update the length of s.
 * Return s with the above changes. */

UTString *utstrcat(UTString *s, const char *suffix) {
    assert(isOurs(s));
    int len1 = s->length;
    int s_cap = s->capacity;
    for (int i = 0; suffix[i] != 0 && ((s_cap - len1) > 0); i++){
        s->string[len1] = suffix[i];
        len1++;
    }

    s->length = len1;
    s->string[len1] = 0;
    CHECK(s) = SIGNATURE;
    return s;
}


/*
 * Copy src into dst.
 *  dst must be a valid UTString.
 *  src is an ordinary string.
 * Do not allocate any additional storage: only copy as many characters
 *  as will actually fit in dst.
 * Update the length of dst.
 * Return dst with the above changes.
 */

UTString *utstrcpy(UTString *dst, const char *src) {
    assert(isOurs(dst));
    int capacity= dst->capacity;
    int sourceLength=strlen(src);
    int j=0;
    for(int i=0; (i < capacity); i++){
        if (i < sourceLength) {
            dst->string[i] = *(src + i);
        }
        j = i;
    }
    j++;
    dst->string[j]=0;
    dst->length=j;
    CHECK(dst)=SIGNATURE;
    return dst;
}


/*
 * Free all memory associated with the given UTString.
 */

void utstrfree(UTString *self) {
    assert(isOurs(self));
    free(self->string);
    free(self);

}


/*
 * Make s have at least as much capacity as new_capacity.
 *  s must be a valid UTString.
 * If s has enough capacity already, do nothing.
 * If s does not have enough capacity, then allocate enough capacity,
 *  copy the old string and the null terminator, free the old string,
 *  and update all relevant metadata.
 * Return s with the above changes.
 */

UTString *utstrrealloc(UTString *s, uint32_t new_capacity) {

    assert(isOurs(s));
    uint32_t x = s->capacity;
    int y = new_capacity + 1 + 4;
    char *originalstring = s->string;
    char *copyofstring = (char *) malloc(new_capacity + 1 + 4);
    int i = 0;
    if (x < new_capacity) {
        s->capacity = new_capacity;
        while (originalstring[i] != '\0') {
            copyofstring[i] = originalstring[i];
            i++;
        }
        copyofstring[i] = 0; //null terminate
        s->string = copyofstring;
    }
    free((void *) originalstring);
    CHECK(s) = SIGNATURE;

    return s; // Return s
}