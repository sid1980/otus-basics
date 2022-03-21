#pragma once

#include <string>

#include "astnode.hpp"

class Mul : public ASTNode {
  public:
    Mul( ASTNode *root, ASTNode *term)
        : ASTNode("*", root, term)
        , val_("*")
    {


    }

    std::string value() const { return val_; }

  private:
    std::string val_;
};
