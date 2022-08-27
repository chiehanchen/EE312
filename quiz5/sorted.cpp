//
// Created by Chieh-An Chen on 7/14/22.
//
int sorted(int x[], int n){

    if (x[1] < x[0]){
        return 1;
    }
    if (x[1] == x[0]){
        return 0;
    }
    if (x[1] > x[0]){
        return -1;
    }

    if(n == 1){
        return 0; //i'm assuming since it's just one element in the array, it has to be equal to itself so return 0?
    }
    if (n > 1) {
        if (x[0] == x[1] && sorted(x + 1, n - 1) == 0) {    //if all the elements in the array x are equal to each other
            return 0;                                       //return 0
        } else if (x[0] < x[1] && sorted(x + 1, n - 1) ==
                                  -1) {   //if all the elements in the array x are sorted in non-increasing order
            return -1;                                     //return -1
        } else if (x[0] > x[1] && sorted(x + 1, n - 1) ==
                                  1) {     //if all the elements in the array x are sorted in non-decreasing order
            return 1;                                       //return 1
        } else {
            return -99;
        }
    }
}