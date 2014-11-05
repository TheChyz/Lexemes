//Use only the following three libraries:
#include "parserClasses.h"
#include <iostream>
#include <fstream>

using namespace std;

//Removes all inline comments from the tokenList including the // marker
//Returns the number of comments removed
int removeInlineComments(TokenList &tokenList) { }

//Remove all block comments from the tokenList including /* and */ markers
//Returns the number of block comments removed (where each pair of /* and */ count as one comment)
int removeBlockComments(TokenList &tokenList) { }

//Input: a list of tokens
//Output: head pointer to the list of assignment statements
//NOTE: Assignment statement must end with a semi-colon
//@ description: extract all the assignment statements from input token list, prepare a new token list (assignment list)
//using extracted statements and return the head pointer to it
Token* getAssignmentStatements(TokenList &tokenList) { }

//Example Test code for interacting with your Token, TokenList, and Tokenizer classes
//Add your own code to further test the operation of your Token, TokenList, and Tokenizer classes
int main() {
	ifstream sourceFile;
	TokenList tokens;
	Tokenizer tokenizer;

	//Read in a file line-by-line and tokenize each line
	sourceFile.open("test.cpp");
	if (!sourceFile.is_open()) {
		cout << "Failed to open file" << endl;
		return 1;
	}

	while(!sourceFile.eof()) {
		string lineA, lineB;

		getline(sourceFile, lineA);

		//while the current line ends with a line-continuation \ append the next line to the current line
		while(lineA[lineA.length()-1] == '\\') {
			lineA.erase(lineA.length()-1, 1);
			getline(sourceFile, lineB);
			lineA += lineB;
		}

		tokenizer.setString(&lineA);
		while(!tokenizer.isComplete()) {
			tokens.append(tokenizer.getNextToken());
		}
		//Re-insert newline that was removed by the getline function
		tokens.append("\n");
	}

	removeInlineComments(tokens);
	removeBlockComments(tokens);

	/*Test your tokenization of the file by traversing the tokens list and printing out the tokens and the tokens type*/
	Token *t = tokens.getFirst();
	while(t) {
		cout << t->getStringRep() << " ";
		t = t->getNext();
	}
	t = tokens.getFirst();
	while(t) {
		cout << t->getStringType() << " ";
		t = t->getNext();
	}

	//Test your assignment statements
	Token *aListPtr = getAssignmentStatements(tokens);
	while(aListPtr) {
		cout << aListPtr->getStringRep() << " ";
		aListPtr = aListPtr->getNext();
	}

	return 0;
}



