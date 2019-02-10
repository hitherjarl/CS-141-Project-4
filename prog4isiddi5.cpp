/*
 * Project 4: Trinity Game
 */
#include<stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <cctype>


using namespace std;


// Display your identifying information (Name, lab day and time)
void displayIdentifyingInformation()
{
    printf("Author: Mohamed Imran Mohamed Siddique \n");
    
    printf("Class: CS 141, Spring 2016 \n");
    
    printf("Program #3: Decipher  \n");
    
    printf("System: XCode on Mac \n");
    
    printf(" \n");
}

void displayIdentifyingInstruction()
{
    printf("Choose your options: \n");
    
    printf("1. Encrypt a file \n");
    
    printf("2. Decrypt a file \n");
    
}
struct swap_struct{
    char encrypted;
    int freqcount;
    char replace;

} swap;

int main(){
    ifstream inStream, inStream2;         // declare an input file stream
    int choice;
    char returnChar;
    char encrypted[100000];
    char changed[100000];
    int i;
    int random = rand()%25;
    srand(1);
    
    
    // display identifying information
    displayIdentifyingInformation();
    
    // display instructions
    displayIdentifyingInstruction();
    
    printf("Enter number: ");
    scanf("%d%c", &choice, &returnChar);
    
    if (choice == 1){
        FILE *myFile;
        myFile = fopen("lifeonmiss.txt", "r");
        
        //read file into array
        
        
        for (i = 0; i < 100000; i++)
        {
            fscanf(myFile, "%c", &encrypted[i]);
        }
        //encrypts each letter by random transposition each time
        for ( i=0; i<100000; i++){
            if ((encrypted[i]+(random))>122){
                
                changed[i]=((encrypted[i]+(random))-25);}
            else if (encrypted[i]==' ')
                
            {changed[i]=((encrypted[i]+((random)*0)));}
            
            else if ((encrypted[i]+(random))<65)
                
            {changed[i]=((encrypted[i]+(random))+33);}
            
            else {changed[i]=((encrypted[i]+(random)));}
         
         }
        
        //print 1500 characters to the screen
     
            for (i = 0; i < 1500; i++)
        {
            if (changed[i] != '\0'){
            printf("%c", changed[i]);
            }
        }
        
        printf("\n\n");
        fclose(myFile);
  
        
        
        //saves the encrypted file into test.txt
        FILE *fp;
        
        fp = fopen("cipher1.txt", "w+");
        
        fputs(&changed[i], fp);
        fclose(fp);
        return 0;
        
    }
    if (choice == 2){
        ifstream inStream, inStream2;         // declare an input file stream
        int lettersArray[ 128];  // count occurrences of characters
        int lettersArray2[ 128];  // count occurrences of characters
        //char characterArray[ LIMIT];
        char c;                    // input character
        int i;
        
        // open input file
        inStream.open("test.txt");   // associate the actual file name with "inStream"
        if ( inStream.fail() ) {
            cout << "Input file opening failed.  Exiting...\n\n";
            exit(-1);
        }// open input file

        
        // initialize lettersArray count values
        for (i=0; i<128; i++) {
            lettersArray[ i] = 0;
        }
        
        // Process input file one character at at time, echoing input file.
        // Note that the input skips leading spaces, which is why we don't see
        // them as part of the output.
        cout << "lifeonmiss.txt contains: \n";
        while ( inStream >> c ) {
            lettersArray[ c]++;     // update letter count, using the character as the index
        }
        cout << endl;              // newline
        
        // display select portions of the table
        for (i=122; i>96; i--) {
            // See if it is a printable character and if there were any of that character
            if ( (isprint( i) && (lettersArray[ i] != 0) ))
            {
               
                // display the character and the number of occurences
                printf("\n");
                
                
                
                cout << (char)i << "--> " << lettersArray[ i] << "; ";
                
            }
        }
        for (i=90; i>64; i--) {
            // See if it is a printable character and if there were any of that character
            if ( (isprint( i) && (lettersArray[ i] != 0) ))
            {
                
                // display the character and the number of occurences
                printf("\n");
                
                cout << (char)i << "--> " << lettersArray[ i] << "; ";
                
            }
            
        }
        inStream.close();
        inStream2.open("lifeonmiss.txt");   // associate the actual file name with "inStream"
        if ( inStream2.fail() ) {
            cout << "Input file opening failed.  Exiting...\n\n";
            exit(-1);
        }// open input file
        
        
        // initialize lettersArray count values
        for (i=0; i<128; i++) {
            lettersArray2[ i] = 0;
        }
        
        // Process input file one character at at time, echoing input file.
        // Note that the input skips leading spaces, which is why we don't see
        // them as part of the output.
        cout << "\n cipher.txt contains: \n";
        while ( inStream2 >> c ) {
            lettersArray2[ c]++;     // update letter count, using the character as the index
        }
        cout << endl;              // newline
        
        // display select portions of the table
        for (i=122; i>96; i--) {
            // See if it is a printable character and if there were any of that character
            if ( (isprint( i) && (lettersArray2[ i] != 0) ))
            {
                
                // display the character and the number of occurences
                printf("\n");
                
                cout << (char)i << "--> " << lettersArray2[ i] << "; ";
                
            }
        }
        for (i=90; i>64; i--) {
            // See if it is a printable character and if there were any of that character
            if ( (isprint( i) && (lettersArray2[ i] != 0) ))
            {
                
                // display the character and the number of occurences
                printf("\n");
                
                cout << (char)i << "--> " << lettersArray2[ i] << "; ";
                
            }
            
        }
        printf("\n\n");
        
         
         
                      // newline
        printf("\n\n");
        inStream2.close();
        
        int charCounter;
        
        inStream.open("cipher.txt");
        while(inStream >> c && charCounter < 1501)
        {
            if (isalpha(c))
            {
                if(isupper(c))
                {
                    c = tolower(c);
                }
                for(int i = 0; i < 26; i++)
                {
                    //cout << alphabet[i] << " ";
                    //cout << c;
                    if(c == lettersArray[ i])
                    {
                        c = lettersArray[ i];
                    }
                }
            }
            cout << c;
            charCounter++;
        }
        
        
        

        
    }
}
