/*
 * Copy the contents of header.txt (filled out) and paste here
 */
#include <iostream>
#include <cassert>
#include "UTString.h"
#include "CustomerDB.h"

using namespace std;

const int default_capacity = 1;

Customer::Customer(UTString name) { // done, please do not edit
    this->bottles = 0;
    this->rattles = 0;
    this->diapers = 0;
    this->name = name;
}

CustomerDB::CustomerDB(void) { // done, please do not edit
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

int CustomerDB::size(void) { // done, please do not edit
    return this->length;
}

CustomerDB::~CustomerDB(void) { // done, please do not edit
    delete[] this->data;
}



void CustomerDB::clear(void) { // done, please do not edit
    delete[] this->data;
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

Customer& CustomerDB::operator[](int k) { // done, please do not edit
    assert(k >= 0 && k < this->length);
    return this->data[k];
}

/*
 * do not touch any code above this
 * finish two functions underneath
 * */

Customer& CustomerDB::operator[](UTString name) {
    /* well i could not for the sake of my life figure out what this does without reading the lab doc
     * but also like doing the lab without reading the lab docs but now i have to read it anyway according to the lab doc
     * here is what's supposed to happen
     *
     *
     * check if the customer already exists,
     *      if so, return the customer by its reference
     * if the customer doesn't already exist
     *      add the customer to the database
     *      everytime a customer needs to be added, the capacity of the database doubles*/

    /* most of the code is in july 18 lecture */

    if (isMember(name) == 0){                     // not an existing customer
        int i = 0;
        if (capacity <= length){                  // check if the database is full already
            capacity = capacity * 2;              // double the capacity like the lab doc says
            Customer *newCusData = new Customer[capacity];  //malloc - couldn't we have just use realloc???
            while(i < length){                    // copying over all of the existing customers
                newCusData[i] = data[i];
                i++;
            }
            delete [] this -> data;                     // valgrind purposes - delete old databse free memory woohoo
            this -> data = newCusData;                  // use the updated database
        }
        data[length] = Customer(name);
        this -> length++;
        return data[length -1];
    }
    if (isMember(name) == 1){                   // the customer already exists in the db
        for (int i=0; i < length; i++) {
            if (name == data[i].name) {
                return data[i];                 // return customer by reference
            }
        }
    }

    /*
     * for some reason this works without using the this pointer? maybe cause the variable names are different???
     * i'm confusion*/
}

bool CustomerDB::isMember(UTString name) {
    // not done, your effort goes here
    int i = 0;
    while(i < length){                  //go through every customer in the database already
        if(name == data[i].name){
            return 1;                   // if they exist return 1
        }
        i++;
    }
    return 0;                           //doesn't exist
}
