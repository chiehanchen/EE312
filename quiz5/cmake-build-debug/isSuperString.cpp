//
// Created by Chieh-An Chen on 7/14/22.
//

bool isSuperString(char* str, char* supstr_candidate) {
    if (*str == *supstr_candidate){
        if(*str == '\0' && *supstr_candidate == '\0'){
            return true;
        } else {
            return (str + 1, supstr_candidate + 1);
        }
    }
    if (*str == '\0' && *supstr_candidate != '\0') {
        return false;
    } else{
        return isSuperString(str + 1, supstr_candidate); //not sure if i need this????
    }
}