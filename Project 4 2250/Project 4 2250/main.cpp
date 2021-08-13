//
//  main.cpp
//  Project 4 2250
//
//  Created by Charissa M Martin on 4/3/18.
//  Copyright © 2018 Charissa M Martin. All rights reserved.
//

#include <iostream>
#include <string>
#include "DelimiterStack.h"
using namespace std;

int main() {

    DelimiterStack * stack = new DelimiterStack(20);
    
    string currentLine = "";
    
    char charHolder; //holds character popped off the stack
    int lineHolder, charPosition; // holds line number and character postion of the character popped off the stack
    
    int count = 1;
    do {
        getline(cin, currentLine, '\n');
        for (int i =0; i < currentLine.length(); i++){
            if (currentLine.at(i) == '(' || currentLine.at(i) ==  '[' || currentLine.at(i) == '{'){
            stack->push(currentLine.at(i), count,i);
            }
            //Error messages for improper entries
            if (currentLine.at(i) == ')'){
                charHolder = '\0';
                if (stack->isEmpty()){
                    cout << "Right delimiter " << currentLine.at(i) << " had no left delimiter found at line " << count << ", char " << i+1 << ".\n";
                    charHolder = '\0';
                }
                stack->popDelimiter(charHolder, lineHolder, charPosition);
                if (charHolder == '{' || charHolder == '['){
                    cout << "Error! Mismatched delimiter " << charHolder << " found at line " << lineHolder << ", char " << charPosition + 1 << " does not match " << currentLine.at(i) << " found at line " << count << ", char " << i+1 << endl;
                }
            }
                if (currentLine.at(i) == ']'){
                    charHolder = '\0';
                    if (stack->isEmpty()){
                    cout << "Right delimiter " << currentLine.at(i) << " had no left delimiter found at line " << count << ", char " << i+1 << ".\n";
                        charHolder = '\0';
                    }
                    stack->popDelimiter(charHolder, lineHolder, charPosition);
                    if (charHolder == '{' || charHolder == '('){
                        cout << "Error! Mismatched delimiter " << charHolder << " found at line " << lineHolder << ", char " << charPosition + 1 << " does not match " << currentLine.at(i) << " found at line " << count << ", char " << i+1 << endl;
                }
            }
            if (currentLine.at(i) == '}'){
                charHolder = '\0';
                if (stack->isEmpty()){
                    cout << "Right delimiter " << currentLine.at(i) << " had no left delimiter found at line " << count << ", char " << i+1 << ".\n";
                    charHolder = '\0';
                }
                stack->popDelimiter(charHolder, lineHolder, charPosition);
                if (charHolder == '(' || charHolder == '['){
                    cout << "Error! Mismatched delimiter " << charHolder << " found at line " << lineHolder << ", char " << charPosition + 1 << " does not match " << currentLine.at(i) << " found at line " << count << ", char " << i+1 << endl;
                }
            }
        }
        count++;
    } while (currentLine != "DONE");
    //Empties the stack of unmatched left delimiters
    while (!(stack-> isEmpty())){
        stack->popDelimiter(charHolder, lineHolder, charPosition);
        cout << "Left delimiter " << charHolder << " at line " << lineHolder << ", char " << charPosition + 1 << " had no right delimiter.\n";
        
    }
    return 0;
}
