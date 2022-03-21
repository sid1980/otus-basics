#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include <iostream>
#include <string>


#include "astnode.hpp"

class Variable : public ASTNode {
  public:
  Variable(std::string val)
    : ASTNode(val)
    , val_(val)
  {
  }

    std::string value() const { return val_; }

  private:
    std::string val_;
};

#endif // VARIABLE_HPP
