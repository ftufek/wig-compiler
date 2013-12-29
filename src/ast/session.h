#ifndef SESSION_H
#define SESSION_H

#include <string>
#include "ast.h"
#include "stm.h"

namespace ast {

class Session : public Base
{
public:
    Session(std::string id, CompoundStm *stm);
    ~Session();
    void accept(Visitor *v) override;

    std::string id_;
    CompoundStm *stm_;
};

}

#endif // SESSION_H
