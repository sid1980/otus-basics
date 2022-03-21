#pragma once

#include <string>

#include "astnode.hpp"

class Add : public ASTNode {
  public:
    Add( ASTNode *root, ASTNode *term)
        : ASTNode("+", root, term)
        , val_("+")
    {


    }

    std::string value() const { return val_; }

  private:
    std::string val_;
};
