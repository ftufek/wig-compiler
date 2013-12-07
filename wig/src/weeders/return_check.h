/*
 * weeder.h
 *
 *  Created on: Oct 13, 2013
 *      Author: user
 */

#ifndef RETURN_CHECK_H_
#define RETURN_CHECK_H_

#include "../ast.h"

namespace visitors {

class ReturnCheck : public ast::VisitorOptional {
public:
	ReturnCheck();
	virtual ~ReturnCheck();

	bool is_valid();

	void visit(ast::Service *s) override;
	void visit(ast::Function *s) override;
	void visit(ast::List *s) override;
	void visit(ast::Session *s) override;

	void visit(ast::CompoundStm *s) override;
	void visit(ast::ExitStm *s) override;
	void visit(ast::ReturnStm *s) override;
	void visit(ast::IfStm *s) override;
	void visit(ast::WhileStm *s) override;
private:
	bool is_valid_ = true;
	bool temp_ends_with_return_ = false;
};

}

#endif /* WEEDER_H_ */
