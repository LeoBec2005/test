#include "mystring.h"
#include <iostream>

int my_strlen(const char* str) {
}

char* my_strcpy(char* dest, const char* src) {
    
}

char* my_strcat(char* dest, const char* src) {

}

char* my_strchr(const char* str, int c) {

}

char* my_substr(const char* str, int start, int end) {
    
}

void my_reverse(char* str) {
    
}

char* my_strtok(char* str, const char* delim) {
    static char* saved_ptr = nullptr;

    if (!str && !saved_ptr) {
        return nullptr;
    }

    char* start = str ? str : saved_ptr;

    
}
