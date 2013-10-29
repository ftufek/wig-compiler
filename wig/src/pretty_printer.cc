#include <iostream>
#include <string>
#include "symbol_table/table.h"
#include "pretty_printer.h"
#include "error.h"

using namespace std;

namespace visitors {

PrettyPrinter::PrettyPrinter(std::ostream &out, bool print_sym_table)
	:ppout(out), print_sym_table_(print_sym_table){}

void PrettyPrinter::Indent(){
    indent_.append("  ");
}

void PrettyPrinter::DeIndent(){
    if(indent_.size() > 0){
    	indent_.resize(indent_.size() - 2);
    }
}

void PrettyPrinter::PrintIndent(){
    ppout<<indent_;
}

void PrettyPrinter::PrintSymTable(ast::Base *s, bool last_scope_only) const{
	if(print_sym_table_){
		s->get_sym_table()->PrettyPrint(ppout, last_scope_only);
	}
}

void PrettyPrinter::visit(ast::Service *s){
	if(error::ErrorsPresent()){
		error::PrintErrors(ppout);
	}
    ppout<<"service {"<<endl;
    Indent();
    PrintSymTable(s);
    s->htmls_->accept(this);
    s->schemas_->accept(this);
    s->global_variables_->accept(this);
    s->functions_->accept(this);
    s->sessions_->accept(this);
    DeIndent();
    ppout<<"}"<<endl;
}

void PrettyPrinter::visit(ast::Whatever *s ) {
    ppout<<s->whatever_;
}

void PrettyPrinter::visit(ast::Variable *s) {
    PrintIndent();
    if(s->is_const_){
        ppout<<"const ";
    }
    s->type_->accept(this);
    ppout<<" "<<s->name_;
    if(s->value_){
        ppout<<" = ";
        if(print_sym_table_ && s->type_->type_ == ast::kType::HTML){
        	//If the variable is an HTML const
        	ppout<<std::endl;
        	ppout<<" ---- Symbols inside the HTML"<<std::endl;
        	PrintSymTable(s, true);
        }
        s->value_->accept(this);
    }
    ppout<<";"<<endl;
}

void PrettyPrinter::visit(ast::Function *s) {
    PrintIndent();
    s->type_->accept(this);
    ppout<<" "<<s->id_<<"(";
    auto iter = s->args_->begin();
    if(iter != s->args_->end()){
        (*iter)->accept(this);
        ++iter;
    }
    for(;iter != s->args_->end(); ++iter){
        ppout<<", ";
        (*iter)->accept(this);
    }
    ppout<<")";
    s->stm_->accept(this);
    ppout<<endl;
}

void PrettyPrinter::visit(ast::Field *s) {
    PrintIndent();
    s->type_->accept(this);
    ppout<<" "<<s->id_<<";"<<endl;
}

void PrettyPrinter::visit(ast::Empty *) {}

void PrettyPrinter::visit(ast::HtmlTag *s) {
    if(s->is_closing_)
        ppout<<"</";
    else if(s->is_gap_)
        ppout<<"<[";
    else
        ppout<<"<";

    ppout<<s->id_;

    if(s->attrs_->size() > 0){
        for(auto it = s->attrs_->begin(); it != s->attrs_->end(); ++it){
            ppout<<" "<<it->first;
            if(it->second.length() > 0){
                ppout<<"="<<it->second;
            }
        }
    }
    if(s->is_gap_)
        ppout<<"]>";
    else
        ppout<<">";
}

void PrettyPrinter::visit(ast::Argument *s) {
    s->type_->accept(this);
    ppout<<" "<<s->id_;
}

void PrettyPrinter::visit(ast::MetaTag *s) {
    ppout<<"<!-- ";
    ppout<<s->content_;
    ppout<<" -->";
}

void PrettyPrinter::visit(ast::Schema *s) {
    PrintIndent();
    ppout<<"schema "<<s->id_<<" {"<<endl;
    Indent();
    if(print_sym_table_){
    	ppout<<"------- Symbols inside the schema: "<<endl;
        PrintSymTable(s, true);
    }
    s->fields_->accept(this);
    DeIndent();
    PrintIndent();
    ppout<<"}"<<endl;
}

void PrettyPrinter::visit(ast::String *s) {
    ppout<<"\""<<s->content_<<"\"";
}

void PrettyPrinter::visit(ast::List *s) {
    for(auto const &exp : *(s->exps_)){
        exp->accept(this);
    }
}

void PrettyPrinter::visit(ast::Type *s) {
	ppout<<ast::KTypeToStr(s->type_);
	if(s->type_ == ast::kType::TUPLE){
		ppout<<" "<<s->tuple_id_;
	}
}

void PrettyPrinter::visit(ast::Session *s){
    PrintIndent();
    ppout<<"session "<<s->id_<<" ()";
    s->stm_->accept(this);
}

void PrettyPrinter::visit(ast::EmptyStm *s) {
    PrintIndent();
    if(s->print_semicol_){
        ppout<<";"<<endl;
    }else{
    	ppout<<endl;
    }
}

void PrettyPrinter::visit(ast::CompoundStm *s) {
    ppout<<" { "<<endl;
    Indent();
    PrintSymTable(s);
    for(auto const &var : *(s->vars_)){
        var->accept(this);
    }
    for(auto const &stm : *(s->stms_)){
        stm->accept(this);
    }
    DeIndent();
    PrintIndent();
    ppout<<"}"<<endl;
}

void PrettyPrinter::visit(ast::ShowStm *s) {
    PrintIndent();
    ppout<<"show ";
    s->doc_->accept(this);
    s->receive_->accept(this);
    ppout<<";"<<endl;
}

void PrettyPrinter::visit(ast::DocumentStm *s){
    if(s->pluggable_){
        ppout<<"plug "<<s->id_<<"[";

        auto it = s->plugs_->begin();
        if(it != s->plugs_->end()){
            (*it)->accept(this);
            ++it;
        }
        for(; it != s->plugs_->end(); ++it){
            ppout<<", ";
            (*it)->accept(this);
        }
        ppout<<"]";
    }else{
        ppout<<s->id_;
    }
}

void PrettyPrinter::visit(ast::PlugStm *s){
    ppout<<s->id_<<" = ";
    s->exp_->accept(this);
}

void PrettyPrinter::visit(ast::ReceiveStm *s){
    ppout<<" receive [";

    auto it = s->inputs_->begin();
    if(it != s->inputs_->end()){
        (*it)->accept(this);
        ++it;
    }
    for(; it != s->inputs_->end(); ++it){
        ppout<<", ";
        (*it)->accept(this);
    }
    ppout<<"]";
}

void PrettyPrinter::visit(ast::InputStm *s){
    ppout<<s->lvalue_<<" = "<<s->id_;
}

void PrettyPrinter::visit(ast::ExitStm *s){
    PrintIndent();
    ppout<<"exit ";
    s->doc_->accept(this);
    ppout<<";"<<endl;
}

void PrettyPrinter::visit(ast::ReturnStm *s){
    PrintIndent();
    ppout<<"return ";
    s->exp_->accept(this);
    ppout<<";"<<endl;
}

void PrettyPrinter::visit(ast::IfStm *s){
    PrintIndent();
    ppout<<"if (";
    s->condition_->accept(this);
    ppout<<")";
    s->true_stm_->accept(this);
    if(s->else_stm_ != nullptr){
        PrintIndent();
        ppout<<"else";
        s->else_stm_->accept(this);
    }
}

void PrettyPrinter::visit(ast::WhileStm *s){
    PrintIndent();
    ppout<<"while (";
    s->condition_->accept(this);
    ppout<<")";
    Indent();
    s->stm_->accept(this);
    DeIndent();
    ppout<<endl;
}

void PrettyPrinter::visit(ast::ExpStm *s){
    PrintIndent();
    s->exp_->accept(this);
    ppout<<";"<<endl;
}

void PrettyPrinter::visit(ast::Exp *){
}

void PrettyPrinter::visit(ast::LValExp *s){
    ppout<<s->lvalue_;
}

void PrettyPrinter::visit(ast::BinopExp *s){
    s->left_->accept(this);

    switch (s->type_) {
    case ast::kBinopType::Assignment:
        ppout<<" = ";
        break;

    case ast::kBinopType::Equals:
        ppout<<" == ";
        break;

    case ast::kBinopType::NotEquals:
        ppout<<" != ";
        break;

    case ast::kBinopType::LowerThan:
        ppout<<" < ";
        break;

    case ast::kBinopType::HigherThan:
        ppout<<" > ";
        break;

    case ast::kBinopType::LowerEquals:
        ppout<<" <= ";
        break;

    case ast::kBinopType::HigherEquals:
        ppout<<" >= ";
        break;

    case ast::kBinopType::Add:
        ppout<<" + ";
        break;

    case ast::kBinopType::Sub:
        ppout<<" - ";
        break;

    case ast::kBinopType::Mult:
        ppout<<" * ";
        break;

    case ast::kBinopType::Div:
        ppout<<" / ";
        break;

    case ast::kBinopType::Mod:
        ppout<<" % ";
        break;

    case ast::kBinopType::And:
        ppout<<" && ";
        break;

    case ast::kBinopType::Or:
        ppout<<" || ";
        break;

    case ast::kBinopType::Combine:
        ppout<<" << ";
        break;

    default:
        break;
    }

    s->right_->accept(this);
}

void PrettyPrinter::visit(ast::UnopExp *s){
    switch (s->type_) {
    case ast::kUnopType::LogicNegate:
        ppout<<"!";
        break;

    case ast::kUnopType::Minus:
        ppout<<"-";
        break;

    default:
        break;
    }

    s->exp_->accept(this);
}

void PrettyPrinter::visit(ast::TupleopExp *s){
    s->exp_->accept(this);

    switch (s->type_) {
    case ast::kTupleopType::Keep:
        ppout<<" \\+ ";
        break;

    case ast::kTupleopType::Discard:
        ppout<<" \\- ";
        break;

    default:
        break;
    }

    ppout<<"(";
    auto it = s->ids_->begin();
    if(it != s->ids_->end()){
    	ppout<<(*it);
    	++it;
    }
    for(; it != s->ids_->end(); ++it){
        ppout<<", "<<(*it);
    }
    ppout<<")";
}

void PrettyPrinter::visit(ast::FunctionExp *s){
    ppout<<s->id_;
    ppout<<"(";

    auto it = s->exps_->begin();
    if(it != s->exps_->end()){
        (*it)->accept(this);
        ++it;
    }

    for(; it != s->exps_->end(); ++it){
        ppout<<", ";
        (*it)->accept(this);
    }
    ppout<<")";
}

void PrettyPrinter::visit(ast::IntegerExp *s){
    ppout<<s->i_;
}

void PrettyPrinter::visit(ast::TrueExp *){
    ppout<<"true";
}

void PrettyPrinter::visit(ast::FalseExp *){
    ppout<<"false";
}

void PrettyPrinter::visit(ast::StringExp *s){
    ppout<<s->str_;
}

void PrettyPrinter::visit(ast::FieldValExp *s){
    ppout<<s->id_<<" = ";
    s->exp_->accept(this);
}

void PrettyPrinter::visit(ast::TupleExp *s){
    ppout<<"tuple { ";
    Indent();
    auto it = s->field_vals_->begin();
    if(it != s->field_vals_->end()){
        (*it)->accept(this);
        ++it;
    }
    for(; it != s->field_vals_->end(); ++it){
        ppout<<", "<<endl;
        PrintIndent();
        (*it)->accept(this);
    }
    DeIndent();
    ppout<<"}";
}

}
