/** @file PrecondViolatedExcept.h */

#ifndef _PRECOND_VIOLATED_EXCEPT
#define _PRECOND_VIOLATED_EXCEPT

#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcept : public logic_error
{
public:
    PrecondViolatedExcept(const string& message = "");
}; // end PrecondViolatedExcept
#endif