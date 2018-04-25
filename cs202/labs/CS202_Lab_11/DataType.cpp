#include "DataType.h"

#include <cstdlib>

DataType::DataType()
 : m_intVal(0),
   m_doubleVal(0)
{
}

DataType::DataType(int intVal, double doubleVal)
 : m_intVal(intVal),
   m_doubleVal(doubleVal)
{
}

DataType::DataType(const DataType & other)
 : m_intVal(other.m_intVal),
   m_doubleVal(other.m_doubleVal)
{
}
	
bool DataType::operator==(const DataType& rhs) const{
  return m_intVal==rhs.m_intVal && m_doubleVal==rhs.m_doubleVal;
}

DataType& DataType::operator=(const DataType& rhs){
  if (this != &rhs){
    m_intVal = rhs.m_intVal;
    m_doubleVal = rhs.m_doubleVal;
  }
  return *this;
}

int DataType::getIntVal() const{
  return m_intVal;
}

void DataType::setIntVal(int i){
  m_intVal = i;
}

double DataType::getDoubleVal() const{
  return m_doubleVal;
}

void DataType::setDoubleVal(double d){
  m_doubleVal = d;
}

std::ostream & operator<<(std::ostream& os, const DataType & dt){
  os << "{" << dt.m_intVal << "," << dt.m_doubleVal << "}";
  return os;
}

std::istream & operator>>(std::istream & is, DataType & dt){
  char in_buf[255];
  is >> in_buf;
  dt.m_doubleVal = atof(in_buf);
  dt.m_intVal = (int)dt.m_doubleVal;
  dt.m_doubleVal -= dt.m_intVal;
  return is;
}
