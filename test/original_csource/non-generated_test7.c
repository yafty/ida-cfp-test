/*source: https://github.com/techtabby/random_password_generator/blob/master/secure_passgen.c*/

#include <stdio.h> //Standard Input/Output
#include <time.h> //Time header needed to seed PRNG
#include <stdlib.h> //Needed for PRNG functions
char generateRandomChar(); //Returns a proper character 

int main(void) {
    int pwdLen = 1; //Default password length if there isn't any change in the variable.
    srand(time(NULL)); //Seeds using the time function.
    printf("Random Password Generator\n"); //Banner
    printf("Enter maximum password length: \n"); //Question for length of the generated passsword
    scanf("%d", &pwdLen); //Saves the length of the password into pwdLen variable (Integer)
    char password[pwdLen]; //Dynamically creates a password array to hold all the characters of the generated password made by using the generateRandomChar function 
    for (int lc = 0; lc < pwdLen; lc++){ //This loop assign a random character by increasing the index by one.
        password[lc] = generateRandomChar(); //Takes the character returned to set it to the correct position in the password array.
    }
    password[pwdLen] = '\0'; //Sets null byte at the end for printing as a string later on.
    printf("Your fresh password is:\n"); //Informs the user about the password.
    printf("%s", password); //Prints the character array like a string %s, reason why I set the last byte as a null byte.
	return 0; //Returns to the OS, a successful execution.
}

char generateRandomChar(){
    while(1){ //Keeps generating characters 
        char code; //variable 
        int dec_code = (rand() % 126); //Holds randomly generated integer
        if (dec_code >= 33 && dec_code <= 122){ //Checks if the integer is in the range of 33 - 122
            code = dec_code; //Sets integer to character, which is associated with ASCII Character Codes.
            return code; //Returns character to password array assignment.
        }
    }
}