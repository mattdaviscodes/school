/** @file PrecondViolatedExcept.cpp */
#include "PrecondViolatedExcept.h"

PrecondViolatedExcept::PrecondViolatedExcept(const string& message)
        : logic_error("Precondition Violated Exception: " + message)
{
}  // end constructor

// End of implementation file.