using namespace std;

#define CATCH_CONFIG_RUNNER  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "catch_reporter_appveyor.hpp"

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

int main(int argc, char* argv[])
{
	// Enable run-time memory leak check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(21499);
#endif
	{
		Catch::Session session;

		int returnCode = session.applyCommandLine(argc, argv);
		if (returnCode != 0) // Indicates a command line error
			return returnCode;
		
		int numFailed = session.run();

		return numFailed;
	}
}