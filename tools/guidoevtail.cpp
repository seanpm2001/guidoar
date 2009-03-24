/*

  Copyright (C) 2009  Grame
  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

  This file is provided as an example of the GuidoAR Library use.
  
*/

#include "common.cxx"

//#define debug

//_______________________________________________________________________________
static void usage(char * name)
{
	cerr << "usage: " << basename(name) << " <score> <evIndex | dscore>"  << endl;
	cerr << "       cut a score before a given event"  << endl;
	cerr << "       score: the input file or '-' the read stdin"  << endl;
	cerr << "       evIndex: index of the cut point event (1 based),"  << endl;
	cerr << "       dscore: a score file used as duration specifier"  << endl;
	exit (1);
}

//_______________________________________________________________________________
int main(int argc, char *argv[]) 
{
#ifdef debug
	argc = 3;
	char * args[] = {"bach.gmn", "4", 0};
	char ** argsPtr = args;
#else
	if (argc != 3) usage(argv[0]);
	char ** argsPtr = &argv[1];
#endif

	char *buff = readgmn(argsPtr[0]);
	garErr err = kNoErr;

	int index = intArg (argsPtr[1],-1);
	if (index > 0) {
		err = guidoVETail(buff, index, cout);
	}
	else {
		char *gmn = readgmn(argsPtr[1]);
		err = guidoGETail(buff, gmn, cout);
		delete[] gmn;
	}
	delete[] buff;
	checkErr (err, "head");
	return err;
}
