#include <iso646.h>
#include <stdio.h>
#include <math.h>

int main(void) {
    FILE *instruct;

    // Open a file in read mode
    instruct = fopen("./source/input", "r");

    // Print some text if the file does not exist
    if (instruct == NULL) {
        printf("Not able to open the file.");
        return 1;
    }

    fseek(instruct, 0L, SEEK_END);
    int fileSize = ftell(instruct);
    rewind(instruct);

    // Store the content of the file
    char instructionText[fileSize];

    // Read the content and store it inside instructionText
    for (int i = 0; i < fileSize; i++) {
        fseek(instruct, i, SEEK_SET);
        char letter = fgetc(instruct);
        instructionText[i] = letter;

        // Print the file content
        //printf("%c", letter);
    }
    // Close the file
    fclose(instruct);

    bool isRight = false;
    int size;
    int numOfZeros = 0;
    int position = 50;
    for (int i = 0; i < fileSize; i++) {
        char obsv = instructionText[i];
        size++;
        int prevPosition = position;

        if (obsv == 'R') {
            isRight = true;
            size = 0;
        } else if (obsv == 'L') {
            isRight = false;
            size = 0;
        } else if (obsv == '\n') {
            for (int j = 0; j < size - 1; j++) {
                obsv = instructionText[i - j - 1];
                int clicks=(obsv - '0') * pow(10, j);
                if (isRight) {
                    for (int k = 0; k < clicks; k++) {
                        position ++;
                        if (position == 100) {
                            numOfZeros++;
                            position -= 100;
                        }
                    }
                }
                if (!isRight) {
                    for (int k = 0; k < clicks; k++) {
                        position --;
                        if (position == 0)
                            numOfZeros++;
                        if (position == -1) {
                            position += 100;
                        }
                    }
                }
            }

        }

    }

    printf("%d\n", numOfZeros);
    return 0;
}
