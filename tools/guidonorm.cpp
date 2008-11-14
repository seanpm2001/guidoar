
#ifdef WIN32
# pragma warning (disable : 4786)
#endif

#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "guidoelement.h"
#include "guidoparser.h"
#include "normalizeOperation.h"

using namespace std;
using namespace guido;

//#define guidodebug

//_______________________________________________________________________________
static void usage(const char * name)
{
	cerr << "usage: " << name << " score"  << endl;
	cerr << "       put the input gmn files in normal form"  << endl;
	cerr << "       score: the input file or '-' the read stdin"  << endl;
	exit (1);
}

//_______________________________________________________________________________
static SARMusic read (const char* file) 
{
	guidoparser r;
	SARMusic score;
	if (!strcmp(file, "-"))
		score = r.parseFile(stdin);
	else
		score = r.parseFile(file);
	if (!score) {
		cerr << file << ": read failed"  << endl;
		exit (1);
	}
	return score;
}

//_______________________________________________________________________________
int main(int argc, char *argv[]) {
#ifdef guidodebug
	argc = 2;
	char * args[] = {"test.gmn", 0};
	char ** argsPtr = args;
#else
	if (argc != 2) usage(argv[0]);
	char ** argsPtr = &argv[1];
#endif

	Sguidoelement score = read (argsPtr[0]);
	normalizeOperation norm;
	Sguidoelement result = norm(score);
	cout << result << endl;
	return 0;
}