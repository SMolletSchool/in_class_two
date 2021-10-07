#include <stdio.h>
#include <stdlib.h>

int inputTest() {

}

int main() {
    int testForLoShu[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    }; //Create 3 by 3 array
    
    //User input LoShu
    int userInput;
    int previousInputs[9];
    for (int i = 0; i < 3; i++) { //row value
        for (int j = 0; j < 3; j++) { //column value
            printf("input value from 1 to 9 (that hasn't already been inputted) into Lo Shu Square, space %d, %d: ", j, i);
            do {
                scanf("%d", &userInput);
                if (inputTest(userInput) == 0) userInput = 0; //If test fails, set userInput to invalid number
                if (userInput > 0 && userInput < 10) testForLoShu[j][i] = userInput;
                else printf("Invalid input! Input must be from 1 to 9, and cannot be repeating.");
            }
            while (userInput < 1 || userInput > 9 && inputTest() == 1);
            
            
            //scanf("%d", &testForLoShu[j][i]);
            printf("\n");
        }
    }

    //Output user's Lo Shu
    printf("User's Lo Shu attempt:\n[%d,%d,%d]\n[%d,%d,%d]\n[%d,%d,%d]\n", testForLoShu[0][0], testForLoShu[1][0], testForLoShu[2][0], testForLoShu[0][1], testForLoShu[1][1], testForLoShu[2][1], testForLoShu[0][2], testForLoShu[1][2], testForLoShu[2][2]);
    if (testForLoShu[0][0] + testForLoShu[0][1] + testForLoShu[0][2] == 15 && testForLoShu[1][0] + testForLoShu[1][1] + testForLoShu[1][2] == 15 && testForLoShu[2][0] + testForLoShu[2][1] + testForLoShu[2][2] == 15) { //Columns success
        if (testForLoShu[0][0] + testForLoShu[1][0] + testForLoShu[2][0] == 15 && testForLoShu[1][0] + testForLoShu[1][1] + testForLoShu[1][2] == 15 && testForLoShu[2][0] + testForLoShu[2][1] + testForLoShu[2][2] == 15) { //Rows success
            if (testForLoShu[0][0] + testForLoShu[1][1] + testForLoShu[2][2] == 15 && testForLoShu[2][0] + testForLoShu[1][1] + testForLoShu[0][2] == 15) { //Diagonals success
                printf("This is a valid Lo Shu square. Good work!\n");
            }
            else printf("This is not a valid Lo Shu square. Try again!\n");
        }
        else printf("This is not a valid Lo Shu square. Try again!\n");
    }
    else printf("This is not a valid Lo Shu square. Try again!\n");


    //Random test Lo Shu
    return EXIT_SUCCESS;
}
