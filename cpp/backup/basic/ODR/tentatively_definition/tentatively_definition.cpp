#include "tentatively_definition.h"

// The sentence "using namespace" can not used for definition.
// using namespace NamespaceVariable;
// string globalStr = "Initialized";

// Definition must give the scope apparently.
string NamespaceVariable::globalStr = "Definition";
