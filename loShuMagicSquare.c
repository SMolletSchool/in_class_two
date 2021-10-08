#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Create 3 by 3 array for everything
int testForLoShu[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
};

int inputTest(int givenInt, int givenArray[]) {
    for (int l = 0; l < 9; l++) { //Size of array will be 9
        if (givenArray[l] == 0) { //If it's 0, then no need to check the rest of the array
            givenArray[l] = givenInt; //Set to the value for next time in the function
            return 1; //boolean True
        }
        else { //Value was found in the array
            if (givenArray[l] == givenInt) return 0; //boolean False
        }
    }
}

int LoShuValidate() {
    if (testForLoShu[0][0] + testForLoShu[0][1] + testForLoShu[0][2] == 15 && testForLoShu[1][0] + testForLoShu[1][1] + testForLoShu[1][2] == 15 && testForLoShu[2][0] + testForLoShu[2][1] + testForLoShu[2][2] == 15) { //Columns success
        if (testForLoShu[0][0] + testForLoShu[1][0] + testForLoShu[2][0] == 15 && testForLoShu[1][0] + testForLoShu[1][1] + testForLoShu[1][2] == 15 && testForLoShu[2][0] + testForLoShu[2][1] + testForLoShu[2][2] == 15) { //Rows success
            if (testForLoShu[0][0] + testForLoShu[1][1] + testForLoShu[2][2] == 15 && testForLoShu[2][0] + testForLoShu[1][1] + testForLoShu[0][2] == 15) { //Diagonals success
                return 1;
            }
            else return 0;
        }
        else return 0;
    }
    else return 0;
}

long long doRandomLoShu() {
    long long attempts = 0;

    do {
        attempts++;

        //reset LoShu
        for (int r = 0; r < 3; r++) { //row value
            for (int c = 0; c < 3; c++) { //column value
                testForLoShu[r][c] = 0;
            }
        }

        //simulate user inputs
        int almostUserInput;
        int previousInputs[9] = {0,0,0,0,0,0,0,0,0};
        for (int r = 0; r < 3; r++) { //row value
            for (int c = 0; c < 3; c++) { //column value
                do {
                almostUserInput = rand()%10;
                if (inputTest(almostUserInput, previousInputs) == 0) almostUserInput = 0; //If test fails, set userInput to invalid number
                if (almostUserInput > 0 && almostUserInput < 10) testForLoShu[r][c] = almostUserInput; //If test succeeds, set value in array to row r, column c
            }
            while (almostUserInput < 1 || almostUserInput > 9);
            }
        }

        //test randomly generated lo shu square (done in while)

    } while (LoShuValidate() == 0);
    
    return attempts;
}


int main() {

    //User input LoShu, commented out in final
    /*
    int userInput;
    int previousInputs[9] = {0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < 3; i++) { //row value
        for (int j = 0; j < 3; j++) { //column value
            printf("input value from 1 to 9 (that hasn't already been inputted) into Lo Shu Square, space %d, %d: ", j, i);
            do {
                scanf("%d", &userInput); //Get user input, save in according variable
                if (inputTest(userInput, previousInputs) == 0) userInput = 0; //If test fails, set userInput to invalid number
                if (userInput > 0 && userInput < 10) testForLoShu[j][i] = userInput; //If test succeeds, set value in array to row j, column i
                else printf("Invalid input! Input must be from 1 to 9, and cannot be repeating.");
            }
            while (userInput < 1 || userInput > 9);
            
            
            //scanf("%d", &testForLoShu[j][i]);
            printf("\n");
        }
    }

    //Output user's Lo Shu
    printf("User's Lo Shu attempt:\n[%d,%d,%d]\n[%d,%d,%d]\n[%d,%d,%d]\n", testForLoShu[0][0], testForLoShu[1][0], testForLoShu[2][0], testForLoShu[0][1], testForLoShu[1][1], testForLoShu[2][1], testForLoShu[0][2], testForLoShu[1][2], testForLoShu[2][2]);
    
    if (LoShuValidate() == 1) printf("This is a valid Lo Shu square. Good work!\n");
    else printf("This is not a valid Lo Shu square. Try again!\n");
    */

    //Random test Lo Shu
    srand(time(NULL)); //getting seed from time information
    printf("Random Lo Shu attempts: %d\n", doRandomLoShu());
    printf("Successful square:\n[%d,%d,%d]\n[%d,%d,%d]\n[%d,%d,%d]\n", testForLoShu[0][0], testForLoShu[1][0], testForLoShu[2][0], testForLoShu[0][1], testForLoShu[1][1], testForLoShu[2][1], testForLoShu[0][2], testForLoShu[1][2], testForLoShu[2][2]);

    return EXIT_SUCCESS;
}
