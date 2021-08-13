//
//  DelimiterStack.cpp
//  Project 4 2250
//
//  Created by Charissa M Martin on 4/3/18.
//  Copyright © 2018 Charissa M Martin. All rights reserved.
//

#include "DelimiterStack.h"
#include <iostream>

using namespace std;
//Constructor
DelimiterStack :: DelimiterStack(int sizeOfArray){
    stackArray = new DelimiterNode[sizeOfArray];
    stackTop = -1;
    this->stackSize = sizeOfArray;
};

void DelimiterStack :: push(char character, int lineNumber, int charCount){
    if (isFull()){
        cout << "The stack is full.\n";
    }
    else {
        stackTop++;
        stackArray[stackTop].character = character;
        stackArray[stackTop].lineNumber = lineNumber;
        stackArray[stackTop].charCount = charCount;
    }
}
void DelimiterStack :: popDelimiter(char &character, int &lineNumber, int &charCount){
    if (!isEmpty()) {
        character = stackArray[stackTop].character;
        lineNumber = stackArray[stackTop].lineNumber;
        charCount = stackArray[stackTop].charCount;
        stackTop--;
    }
} // reference variables because three variables cannot be returned through return statement


bool DelimiterStack :: isEmpty() const {
    bool status;
    if (stackTop == -1)
        status = true;
    else status = false;
    return status;
}
bool DelimiterStack :: isFull() const {
    bool status;
    if (stackTop == stackSize -1)
        status = true;
    else
        status = false;
    return status;
}
