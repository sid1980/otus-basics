#pragma once

#include <string>

#include "astnode.hpp"

class Div : public ASTNode {
  public:
    Div( ASTNode *root, ASTNode *term)
        : ASTNode("/", root, term)
        , val_("/")
    {


    }

    std::string value() const { return val_; }

  private:
    std::string val_;
};
