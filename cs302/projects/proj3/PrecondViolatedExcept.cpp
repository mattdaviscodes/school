#include <stdexcept>
#include <string>

#include "PrecondViolatedExcept.h"

PrecondViolatedExcept::PrecondViolatedExcept(const std::string& message)
: std::logic_error(message.c_str() ) {
}