#include <iostream>
//#include <boost/algorithm/string/replace.hpp>
#include "symbol_table/table.h"
#include "pretty_printer.h"

using namespace std;

namespace visitors {

PrettyPrintVisitor::PrettyPrintVisitor(std::ostream &out, bool print_sym_table)
	:ppout(out), print_sym_table_(print_sym_table){}

void PrettyPrintVisitor::Indent(){
    indent_->append("  ");
}

void PrettyPrintVisitor::DeIndent(){
    if(indent_->size() > 0){
        indent_->pop_back();
        indent_->pop_back();
    }
}

void PrettyPrintVisitor::PrintIndent(){
    ppout<<*indent_;
}

string PrettyPrintVisitor::IndentStr(string str){
	//TODO: fix when have time
	// problem is that when you run IndentStr multiple times on
	// whatever's string, it will just keep adding \t's
	// find a way to remove \n\t+ than add the appropriate indentation...
//    string indentation = "\n";
//    indentation += *indent_;
//    string indented = boost::replace_all_copy(str, "\n", indentation);
//    return indented;
	return str;
}

void PrettyPrintVisitor::PrintSymTable(ast::Base *s, bool last_scope_only) const{
	if(print_sym_table_){
		s->get_sym_table()->PrettyPrint(ppout, last_scope_only);
	}
}

void PrettyPrintVisitor::visit(ast::Service *s){
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

void PrettyPrintVisitor::visit(ast::Whatever *s ) {
    ppout<<IndentStr(s->whatever_);
}

void PrettyPrintVisitor::visit(ast::Variable *s) {
    PrintIndent();
    if(s->is_const_){
        ppout<<"const ";
    }
    s->type_->accept(this);
    ppout<<" "<<s->name_;
    if(s->value_){
        ppout<<" = ";
        if(print_sym_table_ && s->type_->type_ == ast::kType::HTML){
        	ppout<<std::endl;
        	ppout<<" ---- Symbols inside the HTML"<<std::endl;
        	PrintSymTable(s, true);
        }
        s->value_->accept(this);
    }
    ppout<<";"<<endl;
}

void PrettyPrintVisitor::visit(ast::Function *s) {
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

void PrettyPrintVisitor::visit(ast::Field *s) {
    PrintIndent();
    s->type_->accept(this);
    ppout<<" "<<s->id_<<";"<<endl;
}

void PrettyPrintVisitor::visit(ast::Empty *) {}

void PrettyPrintVisitor::visit(ast::HtmlTag *s) {
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

void PrettyPrintVisitor::visit(ast::Argument *s) {
    s->type_->accept(this);
    ppout<<" "<<s->id_;
}

void PrettyPrintVisitor::visit(ast::MetaTag *s) {
    ppout<<"<!-- ";
    ppout<<IndentStr(s->content_);
    ppout<<" -->";
}

void PrettyPrintVisitor::visit(ast::Schema *s) {
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

void PrettyPrintVisitor::visit(ast::String *s) {
    ppout<<"\""<<IndentStr(s->content_)<<"\"";
}

void PrettyPrintVisitor::visit(ast::List *s) {
    for(auto const &exp : *(s->exps_)){
        exp->accept(this);
    }
}

void PrettyPrintVisitor::visit(ast::Type *s) {
	ppout<<ast::KTypeToStr(s->type_);
	if(s->type_ == ast::kType::TUPLE){
		ppout<<" "<<s->tuple_id_;
	}
}

void PrettyPrintVisitor::visit(ast::Session *s){
    PrintIndent();
    ppout<<"session "<<s->id_<<" ()";
    s->stm_->accept(this);
}

void PrettyPrintVisitor::visit(ast::EmptyStm *s) {
    PrintIndent();
    if(s->print_semicol_){
        ppout<<";"<<endl;
    }else{
    	ppout<<endl;
    }
}

void PrettyPrintVisitor::visit(ast::CompoundStm *s) {
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

void PrettyPrintVisitor::visit(ast::ShowStm *s) {
    PrintIndent();
    ppout<<"show ";
    s->doc_->accept(this);
    s->receive_->accept(this);
    ppout<<";"<<endl;
}

void PrettyPrintVisitor::visit(ast::DocumentStm *s){
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

void PrettyPrintVisitor::visit(ast::PlugStm *s){
    ppout<<s->id_<<" = ";
    s->exp_->accept(this);
}

void PrettyPrintVisitor::visit(ast::ReceiveStm *s){
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

void PrettyPrintVisitor::visit(ast::InputStm *s){
    ppout<<s->lvalue_<<" = "<<s->id_;
}

void PrettyPrintVisitor::visit(ast::ExitStm *s){
    PrintIndent();
    ppout<<"exit ";
    s->doc_->accept(this);
    ppout<<";"<<endl;
}

void PrettyPrintVisitor::visit(ast::ReturnStm *s){
    PrintIndent();
    ppout<<"return ";
    s->exp_->accept(this);
    ppout<<";"<<endl;
}

void PrettyPrintVisitor::visit(ast::IfStm *s){
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

void PrettyPrintVisitor::visit(ast::WhileStm *s){
    PrintIndent();
    ppout<<"while (";
    s->condition_->accept(this);
    ppout<<")";
    Indent();
    s->stm_->accept(this);
    DeIndent();
    ppout<<endl;
}

void PrettyPrintVisitor::visit(ast::ExpStm *s){
    PrintIndent();
    s->exp_->accept(this);
    ppout<<";"<<endl;
}

void PrettyPrintVisitor::visit(ast::Exp *){
    //TODO: remove this when have time
}

void PrettyPrintVisitor::visit(ast::LValExp *s){
    ppout<<s->lvalue_;
}

void PrettyPrintVisitor::visit(ast::BinopExp *s){
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

void PrettyPrintVisitor::visit(ast::UnopExp *s){
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

void PrettyPrintVisitor::visit(ast::TupleopExp *s){
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

void PrettyPrintVisitor::visit(ast::FunctionExp *s){
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

void PrettyPrintVisitor::visit(ast::IntegerExp *s){
    ppout<<s->i_;
}

void PrettyPrintVisitor::visit(ast::TrueExp *){
    ppout<<"true";
}

void PrettyPrintVisitor::visit(ast::FalseExp *){
    ppout<<"false";
}

void PrettyPrintVisitor::visit(ast::StringExp *s){
    ppout<<s->str_;
}

void PrettyPrintVisitor::visit(ast::FieldValExp *s){
    ppout<<s->id_<<" = ";
    s->exp_->accept(this);
}

void PrettyPrintVisitor::visit(ast::TupleExp *s){
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
