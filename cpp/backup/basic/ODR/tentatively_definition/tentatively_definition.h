#ifndef TENTATIVELY_DEFINITION_H
#define TENTATIVELY_DEFINITION_H
#include <string>
using namespace std;

namespace NamespaceVariable {
	// This will lead to ODR violations.
	// This is a normal global variable but in a specific namespace.
	// Mus use extern to indicate that the extern is a declaration.
	extern string globalStr;
	// This is a normal static variable but in a specific namespace.
	static string staticStr = "Static String";
}
#endif

