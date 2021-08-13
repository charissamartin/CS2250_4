//
//  DelimiterStack.h
//  Project 4 2250
//
//  Created by Charissa M Martin on 4/3/18.
//  Copyright © 2018 Charissa M Martin. All rights reserved.
//

#ifndef DelimiterStack_h
#define DelimiterStack_h

class DelimiterStack {
private:
    struct DelimiterNode {
        char character;
        int lineNumber;
        int charCount;
    };
    int stackTop, stackSize;
    DelimiterNode * stackArray;
    // Define stack top
public:
    //Constructor
    DelimiterStack(int);

    //Destructor
    ~DelimiterStack();
   
    //Stack Operations
    void push(char, int, int);
    void popDelimiter(char&, int &, int &); // reference variables because three variables cannot be returned through return statement
    bool isEmpty() const;
    bool isFull() const;
};

#endif /* DelimiterStack_h */
