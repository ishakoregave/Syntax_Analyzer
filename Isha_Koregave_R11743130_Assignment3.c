/**
 * This the example lexical analyzer code in pages 173 - 177 of the
 * textbook,
 *
 * Sebesta, R. W. (2012). Concepts of Programming Languages.
 * Pearson, 10th edition.
 *
 */

/* front.c - a lexical analyzer system for simple arithmetic expressions */
#include <ctype.h>
#include <stdio.h>
#include <string.h>

//#include "front.h"

#ifndef FRONT_H
#define FRONT_H


/* Character classes */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

/* Token codes */
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26
#define LESSER_OP 27
#define GREATER_OP 28
#define MOD_OP 29

#define EQUAL_OP 30
#define NEQUAL_OP 31
#define LEQUAL_OP 32
#define GEQUAL_OP 33
#define SEMICOLON 34

#define LEFT_CBRACE 35

#define RIGHT_CBRACE 36
#define KEY_READ 37

#define KEY_PRINT 38
#define KEY_WHILE 39
#define KEY_DO 40


int lex();
;

#endif



/* Global Variable */
int nextToken;
char String;

/* Local Variables */
static int charClass;
static char lexeme[100];
static char nextChar;
static int lexLen;
static FILE *in_fp;

/* Local Function declarations */
static void addChar();
static void getChar();
static void getNonBlank();

/******************************************************/
/* main driver */
int main(int argc, char *argv[]) {
  /* Open the input data file anLSd process its contents */
  printf("DanC Analyzer :: R11743130\n");
  if ((in_fp = fopen(argv[1], "r")) == NULL) {
    printf("ERROR - cannot open front.in \n");
  } else {
    getChar();
    do {
      lex();
      // expr();
    } while (nextToken != EOF);
  }

  return 0;
}

/*****************************************************/
/* lookup - a function to lookup operators and parentheses (everything in unknown)and return the
 * token */
static int lookup(char ch) {
  switch (ch) {

  case '=':
    addChar();
    nextToken = ASSIGN_OP;
    getChar();
    if (nextChar == '=') {
      addChar();
      nextToken = EQUAL_OP;
      printf(" %s    EQUAL_OP\n", lexeme);


    } else if (nextChar == '<') {


      printf(" %s     ASSIGN_OP\n", lexeme);
      nextToken = LESSER_OP;
      printf(" %c     LESSER_OP \n", nextChar);

    }

    else if (nextChar == '>') {


      printf(" %s     ASSIGN_OP\n", lexeme);
      nextToken = GREATER_OP;
      printf(" %c     GREATER_OP \n", nextChar);

    }

    else if (isalpha(nextChar)) {
      //
      printf(" %s     ASSIGN_OP\n", lexeme);

      nextToken = IDENT;

      printf(" %c     IDENT\n", nextChar);
    } else if (isdigit(nextChar)) {
      //
      printf(" %s     ASSIGN_OP\n", lexeme);

      nextToken = INT_LIT;

      printf(" %c     INT_LIT\n", nextChar);
    }

    else {
      printf(" %s     ASSIGN_OP\n", lexeme);

    }
    break;

  case '<':
    addChar();
    nextToken = LESSER_OP;

    getChar();
    if (nextChar == '=') {

      addChar();
      nextToken = LEQUAL_OP;
      printf(" %s    LEQUAL_OP\n", lexeme);
      break;

    } else if (nextChar == '>') {
      addChar();
      nextToken = NEQUAL_OP;
      printf(" %s    NEQUAL_OP\n", lexeme);
      break;

    }
    else{


    printf(" %s     LESSER_OP\n", lexeme);
    }
    break;

  case '>':
    addChar();
    nextToken = GREATER_OP;
    getChar();
    if (nextChar == '=') {
      addChar();
      nextToken = GEQUAL_OP;
      printf(" %s    GEQUAL_OP\n", lexeme);


    } else {
      printf(" %s     GREATER\n", lexeme);
    }
    break;

  case ';':
    addChar();
    nextToken = SEMICOLON;
    printf(" %s     SEMICOLON\n", lexeme);
    break;

  case '(':
    addChar();
    nextToken = LEFT_PAREN;
    printf(" %s     LEFT_PAREN\n", lexeme);
    break;

  case '{':
    addChar();
    nextToken = LEFT_CBRACE;
    printf(" %s     LEFT_CBRACE\n", lexeme);
    break;

  case '}':
    addChar();
    nextToken = RIGHT_CBRACE;
    printf(" %s     RIGHT_CBRACE\n", lexeme);
    break;

  case '+':
    addChar();
    nextToken = ADD_OP;
    printf(" %s     ADD_OP\n", lexeme);
    break;
  case '-':
    addChar();
    nextToken = SUB_OP;
    printf(" %s     SUB_OP\n", lexeme);
    break;
  case '*':
    addChar();
    nextToken = MULT_OP;
    printf(" %s     MULT_OP\n", lexeme);
    break;
  case '/':
    addChar();
    nextToken = DIV_OP;
    printf(" %s     DIV_OP\n", lexeme);
    break;
  case '%':
    addChar();
    nextToken = MOD_OP;
    printf(" %s     MOD_OP\n", lexeme);
    break;
  case ')':
    addChar();
    nextToken = RIGHT_PAREN;
    printf(" %s     RIGHT_PAREN\n", lexeme);
    break;
  default:
    addChar();

    nextToken = UNKNOWN;
    printf(" %s     UNKNOWN\n", lexeme);

    break;
  }
  return nextToken;
}

/*****************************************************/
/* addChar - a function to add nextChar to lexeme */
static void addChar() {
  if (lexLen <= 98) {
    lexeme[lexLen++] = nextChar;
    lexeme[lexLen] = 0;
  } else {
    printf("Error - lexeme is too long \n");
  }
}

/*****************************************************/
/* getChar - a function to get the next character of input and determine its
 * character class */
static void getChar() {
  if ((nextChar = getc(in_fp)) != EOF) {
    if (isalpha(nextChar))

      charClass = LETTER;
    else if (isdigit(nextChar))
      charClass = DIGIT;
    else
      charClass = UNKNOWN;
  } else {
    charClass = EOF;
  }
}

/*****************************************************/
/* getNonBlank - a function to call getChar until it returns a non-whitespace
 * character */
static void getNonBlank() {
  while (isspace(nextChar))
    getChar();
}

/*****************************************************/
/* lex - a simple lexical analyzer for arithmetic expressions */
int lex() {
  lexLen = 0;
  getNonBlank();

  switch (charClass) {
  /* Parse identifiers */
  case LETTER:
    addChar();
    getChar();
    while (charClass == LETTER || charClass == DIGIT) {
      addChar();
      getChar();
    }
    nextToken = IDENT;
    //key words
    if (strcmp(lexeme, "read") == 0) {
      nextToken = KEY_READ;
      printf(" %s  KEY_READ\n", lexeme);

    } else if (strcmp(lexeme, "print") == 0) {
      nextToken = KEY_PRINT;
      printf(" %s KEY_PRINT\n", lexeme);

    } else if (strcmp(lexeme, "while") == 0) {
      nextToken = KEY_WHILE;
      printf(" %s KEY_WHILE\n", lexeme);
    }

    else if (strcmp(lexeme, "do") == 0) {
      nextToken = KEY_DO;
      printf(" %s    KEY_DO\n", lexeme);

    } else {
      printf(" %s     IDENT\n", lexeme);
    }
    break;

  /* Parse integer literals */
  case DIGIT:
    addChar();
    getChar();
    while (charClass == DIGIT) {
      addChar();
      getChar();
    }
    nextToken = INT_LIT;
    printf(" %s     INT_LIT\n", lexeme);

    break;

  /* Parentheses and operators */
  case UNKNOWN:
    lookup(nextChar);
    getChar();
    break;

  /* EOF */
  case EOF:
    nextToken = EOF;
    // printf(" %s     EOF\n",lexeme);
    lexeme[0] = 'E';
    lexeme[1] = 'O';
    lexeme[2] = 'F';
    lexeme[3] = 0;
    break;
  } /* End of switch */

  // printf("Next token is: %d, Next lexeme is %s\n", nextToken, lexeme);

  return nextToken;
} /* End of function lex */
