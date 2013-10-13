/*
 * empty_visitor.cc
 *
 *  Created on: Oct 13, 2013
 *      Author: user
 */

#include "empty_visitor.h"

namespace visitors {

EmptyVisitor::EmptyVisitor() {}
EmptyVisitor::~EmptyVisitor() {}

void EmptyVisitor::visit(ast::Service *s){
    s->htmls_->accept(this);
    s->schemas_->accept(this);
    s->global_variables_->accept(this);
    s->functions_->accept(this);
    s->sessions_->accept(this);
}

void EmptyVisitor::visit(ast::Whatever *s ) {
}

void EmptyVisitor::visit(ast::Variable *s) {
    s->type_->accept(this);
    if(s->value_){
        s->value_->accept(this);
    }
}

void EmptyVisitor::visit(ast::Function *s) {
    s->type_->accept(this);
    auto iter = s->args_->begin();
    if(iter != s->args_->end()){
        (*iter)->accept(this);
        ++iter;
    }
    for(;iter != s->args_->end(); ++iter){
        (*iter)->accept(this);
    }
    s->stm_->accept(this);
}

void EmptyVisitor::visit(ast::Field *s) {
    s->type_->accept(this);
}

void EmptyVisitor::visit(ast::Empty *) {}

void EmptyVisitor::visit(ast::HtmlTag *s) {
}

void EmptyVisitor::visit(ast::Argument *s) {
    s->type_->accept(this);
}

void EmptyVisitor::visit(ast::MetaTag *s) {
}

void EmptyVisitor::visit(ast::Schema *s) {
    s->fields_->accept(this);
}

void EmptyVisitor::visit(ast::String *s) {
}

void EmptyVisitor::visit(ast::List *s) {
    for(auto const &exp : *(s->exps_)){
        exp->accept(this);
    }
}

void EmptyVisitor::visit(ast::Type *s) {
}

void EmptyVisitor::visit(ast::Session *s){
    s->stm_->accept(this);
}

void EmptyVisitor::visit(ast::EmptyStm *s) {
}

void EmptyVisitor::visit(ast::CompoundStm *s) {
    for(auto const &var : *(s->vars_)){
        var->accept(this);
    }
    for(auto const &stm : *(s->stms_)){
        stm->accept(this);
    }
}

void EmptyVisitor::visit(ast::ShowStm *s) {
    s->doc_->accept(this);
    s->receive_->accept(this);
}

void EmptyVisitor::visit(ast::DocumentStm *s){
    if(s->pluggable_){
        auto it = s->plugs_->begin();
        if(it != s->plugs_->end()){
            (*it)->accept(this);
            ++it;
        }
        for(; it != s->plugs_->end(); ++it){
            (*it)->accept(this);
        }
    }else{
    }
}

void EmptyVisitor::visit(ast::PlugStm *s){
    s->exp_->accept(this);
}

void EmptyVisitor::visit(ast::ReceiveStm *s){
    auto it = s->inputs_->begin();
    if(it != s->inputs_->end()){
        (*it)->accept(this);
        ++it;
    }
    for(; it != s->inputs_->end(); ++it){
        (*it)->accept(this);
    }
}

void EmptyVisitor::visit(ast::InputStm *s){
}

void EmptyVisitor::visit(ast::ExitStm *s){
    s->doc_->accept(this);
}

void EmptyVisitor::visit(ast::ReturnStm *s){
    s->exp_->accept(this);
}

void EmptyVisitor::visit(ast::IfStm *s){
    s->condition_->accept(this);
    s->true_stm_->accept(this);
    if(s->else_stm_ != nullptr){
        s->else_stm_->accept(this);
    }
}

void EmptyVisitor::visit(ast::WhileStm *s){
    s->condition_->accept(this);
    s->stm_->accept(this);
}

void EmptyVisitor::visit(ast::ExpStm *s){
    s->exp_->accept(this);
}

void EmptyVisitor::visit(ast::Exp *){
}

void EmptyVisitor::visit(ast::LValExp *s){
}

void EmptyVisitor::visit(ast::BinopExp *s){
    s->left_->accept(this);
    s->right_->accept(this);
}

void EmptyVisitor::visit(ast::UnopExp *s){
    s->exp_->accept(this);
}

void EmptyVisitor::visit(ast::TupleopExp *s){
    s->exp_->accept(this);
}

void EmptyVisitor::visit(ast::FunctionExp *s){
    auto it = s->exps_->begin();
    if(it != s->exps_->end()){
        (*it)->accept(this);
        ++it;
    }

    for(; it != s->exps_->end(); ++it){
        (*it)->accept(this);
    }
}

void EmptyVisitor::visit(ast::IntegerExp *s){
}

void EmptyVisitor::visit(ast::TrueExp *){
}

void EmptyVisitor::visit(ast::FalseExp *){
}

void EmptyVisitor::visit(ast::StringExp *s){
}

void EmptyVisitor::visit(ast::FieldValExp *s){
    s->exp_->accept(this);
}

void EmptyVisitor::visit(ast::TupleExp *s){
    auto it = s->field_vals_->begin();
    if(it != s->field_vals_->end()){
        (*it)->accept(this);
        ++it;
    }
    for(; it != s->field_vals_->end(); ++it){
        (*it)->accept(this);
    }
}

}
