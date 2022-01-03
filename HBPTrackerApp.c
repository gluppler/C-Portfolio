
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 14
//Function Prototype
float calSDDYS(float readDYS[SIZE]);
float calSDSYS(float readSYS[SIZE]);
float calMaxDYS(float readDYS[SIZE]);
float calMaxSYS(float readSYS[SIZE]);
float calMinDYS(float readDYS[SIZE]);
float calMinSYS(float readSYS[SIZE]);
float calAvg(float readSYS[SIZE], float readDYS[SIZE]);
void displayOutput(float avgBP, float minSYSBP, float minDYSBP, float maxSYSBP, float maxDYSBP, float stddevSYSBP, float stddevDYSBP);
void inputFunc(float readSYS[SIZE], float readDYS[SIZE], float recTimeHour[SIZE], float recTimeMin[SIZE], float recDateDay[SIZE], float recDateMonth[SIZE], float recDateYear[SIZE]);
int main()
{
   //Declared Variables and Arrays
    float readSYS[SIZE], readDYS[SIZE], recDateDay[SIZE], recDateMonth[SIZE], recDateYear[SIZE],recTimeHour[SIZE], recTimeMin[SIZE];
    int userInput;
    float avgBP, minSYSBP, minDYSBP, maxSYSBP, maxDYSBP;
    float stddevSYSBP, stddevDYSBP;


    do
    {
        //Title of the program
        printf("\n========================================================================================================================\n");
        printf("\t\t\t\t\tmyHBPTracker Application\n");
        printf("\n========================================================================================================================\n");
        //Disclaimer of the program
        printf("\t\tDISCLAIMER: The HBPTracker Application is only capable of recording data for a week.\n");
        //This is the main menu of the program where you can decide to Input Readings, See your Weekly Results, or Quit the program
        printf("\n========================================================================================================================\n");
        printf("\t\t\t\t\t\tMAIN MENU\n");
        printf("\n[1]Input Readings\n[2]Weekly Results\n[3]Quit\n\n");
        printf("Please Input the numbers above to begin : ");
        scanf("%d", &userInput);
        //If the input is equal to 1 the input function will prompt out
        switch(userInput)
        {
            //Function Call
            case 1 : inputFunc(readSYS,readDYS,recTimeHour,recTimeMin,recDateDay,recDateMonth,recDateYear);
                    break;
            //If the input is equal to 2 the weekly results will be displayed
            //Function Call
            case 2 : avgBP = calAvg(readSYS,readDYS);
                     minSYSBP = calMinSYS(readSYS);
                     minDYSBP = calMinDYS(readDYS);
                     maxSYSBP = calMaxSYS(readSYS);
                     maxDYSBP = calMaxDYS(readDYS);
                     stddevSYSBP = calSDSYS(readSYS);
                     stddevDYSBP = calSDDYS(readDYS);
                     displayOutput(avgBP,minSYSBP,minDYSBP,maxSYSBP,maxDYSBP,stddevSYSBP,stddevDYSBP);
                     break;
            //If the input is equal to 3 the program will prompt a message indicating that you have exited the program and then break
            case  3 : break;
            //If the input is not equal to 1,2, or 3 the validation message will be displayed
            default :   printf("\n========================================================================================================================\n");
                        printf("\t\t\t\t\tYour Input is Invalid!\n");
                        printf("\t\t\t\t\t\tPlease try again.\n");
                        printf("\n========================================================================================================================\n");
                break;
        }
    }while(userInput != 3); //If the input is not equal to 3, the program will keep on looping to the main menu
    {
        //If the input is equal to 3, an exit message will be displayed
        printf("\n========================================================================================================================\n");
        printf("\t\t\t\t\tYou have successfully exited the program.\n");
        printf("\n========================================================================================================================\n");
    }
    return 0;
}

//Function Definition for Void Function Display
void displayOutput(float avgBP, float minSYSBP, float minDYSBP, float maxSYSBP, float maxDYSBP, float stddevSYSBP, float stddevDYSBP)
{
    //This void function displays all of the calculations in the program
    printf("\t\t\t\t\tDiastolic Average : %.1f mmHG\n", avgBP);
    printf("\t\t\t\t\tSystolic Minimum : %.0f mmHG\n", minSYSBP);
    printf("\t\t\t\t\tDiastolic Minimum : %.0f mmHG\n", minDYSBP);
    printf("\t\t\t\t\tSystolic Maximum : %.0f mmHG\n", maxSYSBP);
    printf("\t\t\t\t\tDiastolic Maximum : %.0f mmHG\n", maxDYSBP);
    printf("\t\t\t\t\tSystolic Standard Deviation : %.1f\n", stddevSYSBP);
    printf("\t\t\t\t\tDiastolic Standard Deviation : %.1f\n", stddevDYSBP);

}
//Function Definition for Void Function Input
void inputFunc(float readSYS[SIZE], float readDYS[SIZE], float recTimeHour[SIZE], float recTimeMin[SIZE], float recDateDay[SIZE], float recDateMonth[SIZE], float recDateYear[SIZE])
{
    int index;
    char sMornOrAfter;
    //For loop to prompt the inputs depending on the SIZE

    for(index=0; index < SIZE; index++)
    {
        //Prompt that allows the user to choose whether or not they want to take a Morning reading
        //or Afternoon reading.
        printf("\n========================================================================================================================\n");
        printf("\n[A]Morning\n[B]Afternoon\n\n");
        printf("Please enter your session : ");
        scanf(" %c",&sMornOrAfter);

        switch(sMornOrAfter)
        {
                        //Displays what the user has selected
                    //If Morning is selected the user will be allowed to input values into the other prompts
           case 'A': printf("\n========================================================================================================================\n");
                     printf("\t\t\t\t\t\tMorning Blood Reading\n");
                     printf("\n========================================================================================================================\n");
                                        //Prompts Systolic Input
                     printf("Enter Systolic Value[Upper] : ");
                     scanf("%f", &readSYS[index]);
                     break;
                     //If Afternoon is selected the user will be allowed to input values into the other prompts
           case 'B': printf("\n========================================================================================================================\n");
                     printf("\t\t\t\t\t\tAfternoon Blood Reading\n");
                     printf("\n========================================================================================================================\n");
                                       //Prompts Systolic Input
                     printf("Enter Systolic Value[Upper] : ");
                     scanf("%f", &readSYS[index]);
                     break;
            //Input Validation for sMornOrAfter
            case 'Q':
            case 'q':
            case 's':
            case 'a':
            case 'b':
            case 'C':
            case 'c':
            case 'D':
            case 'd':
            case 'E':
            case 'e':
            case 'F':
            case 'f':
            case 'G':
            case 'g':
            case 'H':
            case 'h':
            case 'I':
            case 'i':
            case 'J':
            case 'j':
            case 'K':
            case 'k':
            case 'L':
            case 'l':
            case 'N':
            case 'n':
            case 'M':
            case 'm':
            case 'O':
            case 'o':
            case 'P':
            case 'p':
            case 'R':
            case 'r':
            case 'T':
            case 't':
            case 'U':
            case 'u':
            case 'V':
            case 'v':
            case 'W':
            case 'w':
            case 'X':
            case 'x':
            case 'Y':
            case 'y':
            case 'Z':
            case 'z':
                    printf("\n========================================================================================================================\n");
                    printf("\t\t\t\t\tYour Input is Invalid!\n");
                    printf("\t\t\t\t\t\tPlease try again.\n");
                    printf("\n========================================================================================================================\n");
                    break;
            default : break;

        }
        //Input Validation for Systolic Array
        if(readSYS[index] != 0 && (sMornOrAfter == 'B' || sMornOrAfter == 'A'))
        {
                //Prompts Diastolic Input
                printf("Enter Diastolic Value[Lower] : ");
                scanf("%f", &readDYS[index]);
        }
        else
        {
            break;
        }
        //Input Validation for Diastolic Array
        if(readDYS[index] != 0 && (sMornOrAfter == 'B' || sMornOrAfter == 'A'))
        {
                //Prompts Hour of Time
                printf("Enter Hour [1-24]: ");
                scanf("%f", &recTimeHour[index]);
        }
        else
        {
            break;
        }
        //Input Validation for Hour of Time
        if(recTimeHour[index] != 0 && (sMornOrAfter == 'B' || sMornOrAfter == 'A'))
        {
                //Prompts Minutes of Time
                printf("Enter Minutes[1-60]: ");
                scanf("%f", &recTimeMin[index]);
        }
        else
        {
            break;
        }
        //Input Validation for Minutes of Time
        if(recTimeMin[index] != 0 && (sMornOrAfter == 'B' || sMornOrAfter == 'A'))
        {
                //Prompts Day of Date
                printf("Enter Day [1-31]: ");
                scanf("%f", &recDateDay[index]);
        }
        else
        {
            break;
        }
        //Input Validation for Day of Date
        if(recDateDay[index] != 0 && (sMornOrAfter == 'B' || sMornOrAfter == 'A'))
        {
                //Prompts Month of Date
                printf("Enter Month [1-12]: ");
                scanf("%f", &recDateMonth[index]);
        }
        else
        {
            break;
        }
        //Input Validation for Month of Date
        if(recDateMonth[index] != 0 && (sMornOrAfter == 'B' || sMornOrAfter == 'A'))
        {

                //Prompts Year of Date
                printf("Enter Year [2XXX+]: ");
                scanf("%f", &recDateYear[index]);
        }
        else
        {
            break;
        }
        //Input Validation for Year of Date
        if(recDateYear[index] == 0 && (sMornOrAfter == 'B' || sMornOrAfter == 'A'))
        {
            break;
        }



        //After everything has been inputted the if else statements will compare the values in each of the arrays
        //And will display the user's daily blood pressure and recorded time in the 24Hour scale and Date in standard scale.
        //Since this is done daily, it is necessary to keep the if else statement in a For loop
        //If Systolic is LESS than 120 AND Diastolic is LESS than 80
        if(readSYS[index] < 120 && readDYS[index] < 80)
        {
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\tYour Blood Pressure is NORMAL\n");
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\tBlood Pressure : %.1f / %.1f mmHG\n",readSYS[index],readDYS[index]);
            printf("\t\t\t\t\tRecorded Time : %.0f / %.0f AM/PM\n",recTimeHour[index], recTimeMin[index]);
            printf("\t\t\t\t\tRecorded Date : %.0f / %.0f / %.0f\n",recDateDay[index],recDateMonth[index],recDateYear[index]);

        }
        //If Systolic is GREATER or EQUAL to 120 AND Systolic is LESS than or EQUAL to 129
        //AND Diastolic is LESS than 80
        else if(readSYS[index] >= 120 && readSYS[index] <= 129 && readDYS[index] < 80)
        {
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\tYour Blood Pressure is ELEVATED\n");
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\tBlood Pressure : %.1f / %.1f mmHG\n",readSYS[index],readDYS[index]);
            printf("\t\t\t\t\tRecorded Time : %.0f / %.0f AM/PM\n",recTimeHour[index], recTimeMin[index]);
            printf("\t\t\t\t\tRecorded Date : %.0f / %.0f / %.0f\n",recDateDay[index],recDateMonth[index],recDateYear[index]);
        }
        //If Systolic is GREATER or EQUAL to 130 AND Systolic is LESS than or EQUAL to 139
        //OR Diastolic is LESS than 80 AND Diastolic is LESS than or EQUAL to 89
        else if((readSYS[index] >= 130 && readSYS[index] <= 139) || (readDYS[index] >= 80 && readDYS[index] <= 89))
        {
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\tYou have HIGH BLOOD PRESSURE\n");
            printf("\t\t\t\t\tHYPERTENSION STAGE 1\n");
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\tBlood Pressure : %.1f / %.1f mmHG\n",readSYS[index],readDYS[index]);
            printf("\t\t\t\t\tRecorded Time : %.0f / %.0f AM/PM\n",recTimeHour[index], recTimeMin[index]);
            printf("\t\t\t\t\tRecorded Date : %.0f / %.0f / %.0f\n",recDateDay[index],recDateMonth[index],recDateYear[index]);

        }
        //If Systolic is GREATER than or EQUAL to 140 OR Diastolic is GREATER than or EQUAL to 90
        else if(readSYS[index] >= 140 || readDYS[index] >= 90)
        {
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\tYou have HIGH BLOOD PRESSURE\n");
            printf("\t\t\t\t\tHYPERTENSION STAGE 2\n");
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\tBlood Pressure : %.1f / %.1f mmHG\n",readSYS[index],readDYS[index]);
            printf("\t\t\t\t\tRecorded Time : %.0f / %.0f AM/PM\n",recTimeHour[index], recTimeMin[index]);
            printf("\t\t\t\t\tRecorded Date : %.0f / %.0f / %.0f\n",recDateDay[index],recDateMonth[index],recDateYear[index]);

        }
        //If the calculated input is higher than all of the statements
        //This will be displayed instead
        else
        {
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\tYour Blood Pressure is TOO HIGH\n");
            printf("\t\t\t\t\tPlease consult a doctor immediately.\n");
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\tBlood Pressure : %.1f / %.1f mmHG\n",readSYS[index],readDYS[index]);
            printf("\t\t\t\t\tRecorded Time : %.0f / %.0f AM/PM\n",recTimeHour[index], recTimeMin[index]);
            printf("\t\t\t\t\tRecorded Date : %.0f / %.0f / %.0f\n",recDateDay[index],recDateMonth[index],recDateYear[index]);

        }



    }
}
//Function Definition for Return Function Average
float calAvg(float readSYS[SIZE], float readDYS[SIZE])
{
    //INITIALIZING the index, Systolic and Diastolic total, and Systolic and Diastolic Average variables
    int index;
    float totalSYS = 0.0, avgSYS = 0.0;
    float totalDYS = 0.0, avgDYS = 0.0;
    //A For loop is needed for the Summation of Systolic and Diastolic values
    for(index=0; index < SIZE; index++)
    {
        //Sums the the values in Systolic and Diastolic Array into their own total variables
        totalSYS += readSYS[index];
        totalDYS += readDYS[index];

    }
    //The total of both Systolic and Diastolic is then divided by the defined SIZE
    //And the output of both arrays are stored into their own average variables
    avgSYS = totalSYS/SIZE;
    avgDYS = totalDYS/SIZE;
        //After the user has reached the weekly results the if else statements will compare the values in each of the arrays
        //And will display the user's weekly blood pressure unlike the daily results.
        //Since this is done weekly, it is necessary to keep the if else statement outside of a For loop
        //If Systolic is LESS than 120 AND Diastolic is LESS than 80
        if(avgSYS < 120 && avgDYS < 80)
        {
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\t\tWEEKLY RESULTS\n");
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\tYour Blood Pressure is NORMAL\n");
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\tSystolic Average : %.1f mmHG\n",avgSYS);
            return avgDYS;


        }
        //If Systolic is GREATER or EQUAL to 120 AND Systolic is LESS than or EQUAL to 129
        //AND Diastolic is LESS than 80
        else if(avgSYS >= 120 && avgSYS <= 129 && avgDYS < 80)
        {
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\t\tWEEKLY RESULTS\n");
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\tYour Blood Pressure is ELEVATED\n");
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\tSystolic Average : %.1f mmHG\n",avgSYS);
            return avgDYS;

        }
        //If Systolic is GREATER or EQUAL to 130 AND Systolic is LESS than or EQUAL to 139
        //OR Diastolic is LESS than 80 AND Diastolic is LESS than or EQUAL to 89
        else if((avgSYS >= 130 && avgSYS <= 139) || (avgDYS >= 80 && avgDYS <= 89))
        {
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\t\tWEEKLY RESULTS\n");
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\tYou have HIGH BLOOD PRESSURE\n");
            printf("\t\t\t\t\tHYPERTENSION STAGE 1\n");
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\tSystolic Average : %.1f mmHG\n",avgSYS);
            return avgDYS;


        }
        //If Systolic is GREATER than or EQUAL to 140 OR Diastolic is GREATER than or EQUAL to 90
        else if(avgSYS >= 140 || avgDYS >= 90)
        {
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\t\tWEEKLY RESULTS\n");
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\tYou have HIGH BLOOD PRESSURE\n");
            printf("\t\t\t\t\tHYPERTENSION STAGE 2\n");
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\tSystolic Average : %.1f mmHG\n",avgSYS);
            return avgDYS;

        }
        //If the calculated input is higher than all of the statements
        //This will be displayed instead
        else
        {
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\t\tWEEKLY RESULTS\n");
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\tYour Blood Pressure is TOO HIGH\n");
            printf("\t\t\t\t\tPlease consult a doctor immediately.\n");
            printf("\n========================================================================================================================\n");
            printf("\t\t\t\t\tSystolic Average : %.1f mmHG\n",avgSYS);
            return avgDYS;

        }

}

//Function Definition for Return Function Systolic Minimum
float calMinSYS(float readSYS[SIZE]) //Finds the Minimum of Systolic Array
{
    //INITIALIZING smallest and index variable
    int index;
    float smallest;
     //Minimum Calculation for Systolic
    smallest = readSYS[0];

    for(index=1; index<SIZE; index++)
    {
        //If the Array is smaller than the smallest variable
        //Array equals to smallest variable
        if(smallest>readSYS[index])
        {
            smallest = readSYS[index];
        }
    }
    //Returns the smallest variable of Systolic
    return smallest;

}
//Function Definition for Return Function Diastolic Minimum
float calMinDYS(float readDYS[SIZE])
{
    //INITIALIZING smallest and index variable
    int index;
    float smallest;
    //Minimum Calculation for Systolic
    smallest = readDYS[0];

    for(index=1; index<SIZE; index++)
    {
        //If the Array is smaller than the smallest variable
        //Array equals to smallest variable
        if(smallest>readDYS[index])
        {
            smallest = readDYS[index];
        }
    }
    //Returns the smallest variable of Diastolic
    return smallest;
}
//Function Definition for Return Function Systolic Maximum
float calMaxSYS(float readSYS[SIZE])
{
    //INITIALIZING biggest and index variable
    int index;
    float biggest;
    //Maximum Calculation for Systolic
    biggest = readSYS[0];

    for(index=1; index<SIZE; index++)
    {
        //If the Array is bigger than the biggest variable
        //Array equals to biggest variable
        if(biggest<readSYS[index])
        {
            biggest = readSYS[index];
        }
    }
    //Returns the biggest variable of Systolic
    return biggest;

}
//Function Definition for Return Function Diastolic Maximum
float calMaxDYS(float readDYS[SIZE])
{
     //INITIALIZING biggest and index variable
       int index;
       float biggest;
   //Maximum Calculation for Diastolic
    biggest = readDYS[0];

    for(index=1; index<SIZE; index++)
    {
        //If the Array is bigger than the biggest variable
        //Array equals to biggest variable
        if(biggest<readDYS[index])
        {
            biggest = readDYS[index];
        }
    }
    //Returns the biggest variable of Diastolic
    return biggest;
}
//Function Definition for Return Function Systolic Standard Deviation
float calSDSYS(float readSYS[SIZE])
{
    //INITIALIZING total and SD to 0.0 and index and avg variable
    float total = 0.0, avg, SD = 0.0;
    int index;
    for (index = 0; index < SIZE; index++)
    {
        //Sums the value from the Systolic Array
        total += readSYS[index];
    }
    //Divide the total by SIZE to find the average
    avg = total/SIZE;
    for (index = 0; index < SIZE; index++)
    {
        //Sums the deviation between the Systolic values
        SD += pow(readSYS[index] - avg, 2);
    }
    //Returns the deviation between the Systolic values
    return sqrt(SD / SIZE);
}
//Function Definition for Return Function Diastolic Standard Deviation
float calSDDYS(float readDYS[SIZE])
{
    //INITIALIZING total and SD to 0.0 and index and avg variable
    float total = 0.0, avg, SD = 0.0;
    int index;
    for (index = 0; index < SIZE; index++)
    {
        //Sums the value from the Diastolic Array
        total += readDYS[index];
    }
    //Divide the total by SIZE to find the average
    avg = total/SIZE;

    for (index = 0; index < SIZE; index++)
    {
        //Sums the deviation between the Diastolic values
        SD += pow(readDYS[index] - avg, 2);
    }
     //Returns the deviation between the Diastolic values
    return sqrt(SD / SIZE);
}




