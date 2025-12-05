#include <stdio.h>

int main(void) {
    FILE *instruct;

    // Open a file in read mode
    instruct = fopen("./source/input", "r");

    // Print some text if the file does not exist
    if(instruct == NULL) {
        printf("Not able to open the file.");
        return 1;
    }

    fseek(instruct, 0L, SEEK_END);
    int fileSize = ftell(instruct);
    rewind(instruct);

    // Store the content of the file
    char instructionText[fileSize];

    // Read the content and store it inside myString
    for (int i = 0; i < fileSize; i++) {

        fseek(instruct, i, SEEK_SET);
        char letter = fgetc(instruct);
        instructionText[i] = letter;

        // Print the file content
        printf("%c", letter);
    }






    // Close the file
    fclose(instruct);



    return 0;
}