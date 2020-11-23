#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool char_valid_check(char symbol) {
   return (symbol == 'a') || (symbol == 'b');
}

bool string_check(char *string, int len) {
   short state = 0;
   int i; char symbol;

   for(i = 0; i < len; i++) {
       symbol = *(string + i);
      
       if(char_valid_check(symbol) == false) {
           printf("Invalid character found.\n");
           return false;
       }

       if(state == 0 && symbol == 'a') {
           state = 1;
       }
       else if(state == 0 && symbol == 'b') {
           state = 0;
       }
       else if(state == 1 && symbol == 'a') {
           state = 2;
       }
       else if(state == 1 && symbol == 'b') {
           state = 0;
       }
       else if(state == 2) {
           break;
       }
   }
   return state == 2;
}


int main() {
   char *input_string; bool valid; int len;

   printf("Input string: ");
   scanf("%s", input_string);

   len = strlen(input_string);
   valid = string_check(input_string, len);

   puts(valid ? "String accepted": "Not accepted");
   return 0;
}