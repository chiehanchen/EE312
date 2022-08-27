// CRM <Project4.cpp>
// EE 312 Project 4 submission by
// Chieh-An Chen
// cc67994
// Slip days used: <0>
// Summer 2022
// Copy-Paste the above lines at the top of your submitted files.


#include <stdio.h>
#include <assert.h>
#include "MyString.h"
#include "Invent.h"

#define MAX_CUSTOMERS 1000
Customer customers[MAX_CUSTOMERS];
int num_customers = 0;
/* you'll probably need several more global variables */
/* and of course, you have a few functions to write */
int ratf = 0;
int botf = 0;
int diaf = 0;
int invent_bot = 0;
int invent_rat = 0;
int invent_dia = 0;



void checkBottle(String* itemkind){
    String bot = StringCreate("Bottles");
    if(StringIsEqualTo(itemkind, &bot)) {
        botf = 1;
    }
    StringDestroy(&bot);
}
void checkRattles(String* itemkind){
    String rat = StringCreate("Rattles");
    if(StringIsEqualTo(itemkind, &rat)) {
        ratf = 1;
    }
    StringDestroy(&rat);
}
void checkDiapers(String* itemkind) {
    String dia = StringCreate("Diapers");
    if(StringIsEqualTo(itemkind, &dia)) {
        diaf = 1;
    }
    StringDestroy(&dia);
}


/* clear the inventory and reset the customer database to empty */
void reset(void) {
    for (int i = 0; i < num_customers; i++){
        StringDestroy(&customers[i].name);
    }
    for (int j = 0; j < num_customers; j++) {
        customers[j].diapers = 0;
        customers[j].bottles = 0;
        customers[j].rattles = 0;
    }
    num_customers = 0;
    ratf = 0;
    botf = 0;
    diaf = 0;
    invent_bot = 0;
    invent_rat = 0;
    invent_dia = 0;
}

void processSummarize() {
    printf("There are %d Bottles, %d Diapers and %d Rattles in inventory\n", invent_bot, invent_dia, invent_rat);
    printf("we have had a total of %d different customers\n", num_customers);

    int maxBottle = 0;
    int maxIndexBOT = 0;
    int flagBot = 0;
    int b = 0;

    int maxDiaper = 0;
    int maxIndexDIA = 0;
    int flagDia = 0;
    int d = 0;

    int maxRattle = 0;
    int maxIndexRAT = 0;
    int flagRat = 0;
    int r = 0;

    while (b < num_customers) {
        if(customers[b].bottles > maxBottle) {
            maxIndexBOT = b;
            maxBottle = customers[b].bottles;
            flagBot = 1;
        }

        if(customers[b].diapers > maxDiaper) {
            maxIndexDIA = b;
            maxDiaper = customers[b].diapers;
            flagDia = 1;
        }

        if(customers[b].rattles > maxRattle) {
            maxIndexRAT = b;
            maxRattle = customers[b].rattles;
            flagRat = 1;
        }

        b++;
    }

    //PRINT: Bot, Dia, Rat - in this order
    /*
     * just make a lot of if statements to avoid any special cases????
     * i don't know if this will help lol but lets try
     * */

    if(flagBot != 1) {
        printf("no one has purchased any Bottles\n");
    }
    else {
        StringPrint(&customers[maxIndexBOT].name);
        printf(" has purchased the most Bottles (%d)\n", customers[maxIndexBOT].bottles);
    }

    if(flagDia != 1) {
        printf("no one has purchased any Diapers\n");
    }
    else {
        StringPrint(&customers[maxIndexDIA].name);
        printf(" has purchased the most Diapers (%d)\n", customers[maxIndexDIA].diapers);
    }

    if(flagRat != 1) {
        printf("no one has purchased any Rattles\n");
    }
    else {
        StringPrint(&customers[maxIndexRAT].name);
        printf(" has purchased the most Rattles (%d)\n", customers[maxIndexRAT].rattles);
    }
}


void processPurchase() {
    botf = 0;
    ratf = 0;
    diaf = 0;
    // inputs
    String customerName;
    String itemType;
    int amount;
    int customerIndex = 0;
    int customerflagbot = 1;
    int customerflagrat = 1;
    int customerflagdia = 1;

    readString(&customerName);
    readString(&itemType);
    readNum(&amount);

    //debugging variables
    int x = botf;
    int y = ratf;
    int z = diaf;

    checkBottle(&itemType);
    checkRattles(&itemType);
    checkDiapers(&itemType);

    StringDestroy(&itemType);



    //again use a lot of if statements
    if(amount <= 0) {
        StringDestroy(&customerName);
        return;
    }

    if(botf == 1) {                                                                     //if customers are trying to buy bottles
        if (amount > invent_bot){
            printf("Sorry ");
            StringPrint(&customerName);
            printf(" we only have %d Bottles\n", invent_bot);
            StringDestroy(&customerName);
        }
        if (amount <= invent_bot) {                                               //check if we have enough bottles in the inventory
            int b = 0;
            while (b < num_customers) {
                if (StringIsEqualTo(&customerName, &customers[b].name)) {
                    customerIndex = b;
                    customerflagbot = 0;
                }
                b++;
            }
            if (customerflagbot) {
                customerIndex = num_customers; // create new customer
                num_customers = num_customers + 1;
                customers[customerIndex].name = customerName;
            } else {
                StringDestroy(&customerName);
            }
            invent_bot = invent_bot - amount;
            customers[customerIndex].bottles = customers[customerIndex].bottles + amount;
        }
    }
    else if(ratf == 1) {
        if (amount > invent_rat){
            printf("Sorry ");
            StringPrint(&customerName);
            printf(" we only have %d Rattles\n", invent_rat);
            StringDestroy(&customerName);
        }
        if (amount <= invent_rat) {
            int r = 0;
            while (r < num_customers) {
                if (StringIsEqualTo(&customerName, &customers[r].name)) {
                    customerIndex = r;
                    customerflagrat = 0;
                }
                r++;
            }
            if (customerflagrat) {
                customerIndex = num_customers;
                customers[customerIndex].name = customerName;
                num_customers = num_customers + 1;
            } else {
                StringDestroy(&customerName);
            }
            invent_rat = invent_rat - amount;
            customers[customerIndex].rattles = customers[customerIndex].rattles + amount;
        }
    }
    else if(diaf == 1) {
        if (amount > invent_dia){
            printf("Sorry ");
            StringPrint(&customerName);
            printf(" we only have %d Diapers\n", invent_dia);
            StringDestroy(&customerName);
        }
        if (amount <= invent_dia) {
            int d = 0;
            while (d < num_customers) {
                if (StringIsEqualTo(&customerName, &customers[d].name)) {
                    customerIndex = d;
                    customerflagdia = 0;
                }
                d++;
            }
            if (customerflagdia) {
                customerIndex = num_customers;
                customers[customerIndex].name = customerName;
                num_customers = num_customers + 1;
            } else {
                StringDestroy(&customerName);
            }
            invent_dia = invent_dia - amount;
            customers[customerIndex].diapers = customers[customerIndex].diapers + amount;
        }
    }
    else {
        printf("Something went wrong in processPurchase\n");
    }
}

void processInventory() {
    botf = 0;
    ratf = 0;
    diaf = 0;
    String item_type;
    int num_receieved;
    readString(&item_type);
    readNum(&num_receieved);

    checkBottle(&item_type);
    checkRattles(&item_type);
    checkDiapers(&item_type);
    int x = botf;
    int y = ratf;
    int z = diaf;

    if (botf == 1){
        if (num_receieved > 0){
            invent_bot = invent_bot + num_receieved;
        }
    }
    else if (ratf == 1){
        if (num_receieved > 0){
            invent_rat = invent_rat + num_receieved;
        }
    }
    else if (diaf == 1){
        if (num_receieved > 0){
            invent_dia = invent_dia + num_receieved;
        }
    }

    StringDestroy(&item_type);
}
