#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include "AVL.h"

// This will take a string temp and an AVL object and will execute an instruction from the string
// no return, but writes the results of the instruction into the ofs
void parse_instruction(std::string temp, std::ofstream &ofs, AVL<int>* aptr);

// This function is a platform independent way of reading files of various line ending types.
// It's definiton is at the bottom of the file, don't worry if you don't understand it.
namespace ta {
	std::istream& getline(std::istream& is, std::string& line);
}


int main(int argc, char* argv[]) {


	VS_MEM_CHECK;               // enable memory leak check
								// Check for correct number of command line arguments
	if (argc < 3) {
		std::cout << "You need to supply an input and output file" << std::endl;
		return 1;
	}
	// Open input file
	std::ifstream ifs(argv[1]);
	if (!ifs) {
		std::cerr << "Unable to open input file" << std::endl;
		return 2;
	}
	// Open output file  - doing this now so we don't have to worry about the error later after doing the work
	std::ofstream ofs(argv[2]);
	if (!ofs)
	{
		ifs.close();
		std::cerr << "Unable to open " << argv[2] << " for output";
		return 3;
	}

	AVL<int>* avlptr = new AVL<int>();

	std::string temp; // used to store the current instruction
	while (ta::getline(ifs,temp)) { // while there are more instructions to get,
		parse_instruction(temp, ofs, avlptr); // parse the instructions using the AVL
	}
	if (avlptr != NULL) {
		delete avlptr;
		avlptr = NULL;
	}
	ifs.close();
	ofs.close();
	return 0;
}


//a function that takes an AVL and returns a level-order string representation of the AVL
//returns a string representation of the nodes in level order
string BSTtoString(AVL<int>* bst);

void parse_instruction(std::string temp, std::ofstream &ofs, AVL<int>* aptr) {
	std::string command, expression;
	std::stringstream ss(temp);

	if (!(ss >> command)) { return; } // get command, but if string was empty, return
	if (command == "Add") { // add the given value to the AVL if possible
		int valToAdd;
		ss >> valToAdd;
		if (aptr->add(valToAdd)) {
			ofs << temp << " True" << std::endl;
		}
		else {
			ofs << temp << " False" << std::endl;
		}
	}
	else if (command == "Remove") { // remove the given value from the AVL
		int valToRemove;
		ss >> valToRemove;
		if (aptr->remove(valToRemove)) {
			ofs << temp << " True" << std::endl;
		}
		else {
			ofs << temp << " False" << std::endl;
		}
	}
	else if (command == "Clear") { // clear the AVL
		aptr->clear();
		ofs << temp << std::endl;
	}
	else if (command == "PrintBST") { //you don't need to implement any function for this command
		ofs << temp << "\n" << BSTtoString(aptr) << std::endl;
	}
	else { // invalid command, wrong input file format
		std::cout << "Command: \"" << command << "\"" << std::endl;
		std::cout << "Invalid command.  Do you have the correct input file?" << std::endl;
	}
}


//a function that takes a BST and returns a level-order string representation of the BST
//returns a string representation of the nodes in level order
string BSTtoString(AVL<int>* bst) {
	queue<NodeInterface<int>*> readQ; // used to read in the levels of the tree, contains Node*
	stringstream nodeReader_ss; // used to store the values of the nodes and the level-order sequence
	int depth = 0; // the depth of a node on the tree

	if (bst->getRootNode() == NULL) {
		return "BST is empty\n";
	}

	readQ.push(bst->getRootNode()); // push the root node of the tree into the queue

	while (!readQ.empty()) { // as long as the queue has a remaining node:
		int i = readQ.size(); // store the number of nodes on this level of the tree
		nodeReader_ss << depth << ":  ";
		for (; i > 0; i--) { // for each node on this level,
			NodeInterface<int>* nextNode = readQ.front(); // store the next node in the queue
			nodeReader_ss << nextNode->getData() << " "; // store the data from the node into the ss
			if (nextNode->getLeftChild() != NULL) { // if there is a left child, push the left child into the queue
				readQ.push(nextNode->getLeftChild());
			}
			if (nextNode->getRightChild() != NULL) { // if there is a right child, push the left child into the queue
				readQ.push(nextNode->getRightChild());
			}
			readQ.pop(); // pop the node off of the queue, leaving its children in the queue
		}
		nodeReader_ss << "\n"; // push an endl into the ss to distinguish levels
		depth++;
	}

	return nodeReader_ss.str();
}





// Version of getline which does not preserve end of line characters
namespace ta {
	std::istream& getline(std::istream& in, std::string& line) {
		line.clear();

		std::istream::sentry guard(in, true); // Use a sentry to maintain the state of the stream
		std::streambuf *buffer = in.rdbuf();  // Use the stream's internal buffer directly to read characters
		int c = 0;

		while (true) { // Continue to loop until a line break if found (or end of file)
			c = buffer->sbumpc(); // Read one character
			switch (c) {
			case '\n': // Unix style, return stream for further parsing
				return in;
			case '\r': // Dos style, check for the following '\n' and advance buffer if needed
				if (buffer->sgetc() == '\n') { buffer->sbumpc(); }
				return in;
			case EOF:  // End of File, make sure that the stream gets flagged as empty
				in.setstate(std::ios::eofbit);
				return in;
			default:   // Non-linebreak character, go ahead and append the character to the line
				line.append(1, (char)c);
			}
		}
	}
}
