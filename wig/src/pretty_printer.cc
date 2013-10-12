#include <iostream>
#include <boost/algorithm/string/replace.hpp>
#include "pretty_printer.h"

using namespace std;

namespace pp {

void PrettyPrintVisitor::Indent(){
    indent_->append("\t");
}

void PrettyPrintVisitor::DeIndent(){
    if(indent_->size() > 0){
        indent_->pop_back();
    }
}

void PrettyPrintVisitor::PrintIndent(){
    cout<<*indent_;
}

string PrettyPrintVisitor::IndentStr(string str){
    string indentation = "\n";
    indentation += *indent_;
    string indented = boost::replace_all_copy(str, "\n", indentation);
    return indented;
}

void PrettyPrintVisitor::visit(ast::Service *s){
    cout<<"service {"<<endl;
    Indent();
    s->htmls_->accept(this);
    cout<<endl;
    s->schemas_->accept(this);
    cout<<endl;
    s->global_variables_->accept(this);
    cout<<endl;
    s->functions_->accept(this);
    cout<<endl;
    s->sessions_->accept(this);
    DeIndent();
    cout<<"}"<<endl;
}

void PrettyPrintVisitor::visit(ast::Whatever *s ) {
    cout<<IndentStr(s->whatever_);
}

void PrettyPrintVisitor::visit(ast::Variable *s) {
    PrintIndent();
    if(s->is_const_){
        cout<<"const ";
    }
    s->type_->accept(this);
    cout<<" "<<s->name_;
    if(s->value_){
        cout<<" = ";
        s->value_->accept(this);
    }
    cout<<";"<<endl;
}

void PrettyPrintVisitor::visit(ast::Function *s) {
    PrintIndent();
    s->type_->accept(this);
    cout<<" "<<s->id_<<"(";
    auto iter = s->args_->begin();
    if(iter != s->args_->end()){
        (*iter)->accept(this);
        ++iter;
    }
    for(;iter != s->args_->end(); ++iter){
        cout<<", ";
        (*iter)->accept(this);
    }
    cout<<")";
    s->stm_->accept(this);
    cout<<endl;
}

void PrettyPrintVisitor::visit(ast::Field *s) {
    PrintIndent();
    s->type_->accept(this);
    cout<<" "<<s->id_<<";"<<endl;
}

void PrettyPrintVisitor::visit(ast::Empty *) {}

void PrettyPrintVisitor::visit(ast::HtmlTag *s) {
    if(s->is_closing_)
        cout<<"</";
    else if(s->is_gap_)
        cout<<"<[";
    else
        cout<<"<";

    cout<<s->id_;

    if(s->attrs_->size() > 0){
        for(auto it = s->attrs_->begin(); it != s->attrs_->end(); ++it){
            cout<<" "<<it->first;
            if(it->second.length() > 0){
                cout<<"="<<it->second;
            }
        }
    }
    if(s->is_gap_)
        cout<<"]>";
    else
        cout<<">";
}

void PrettyPrintVisitor::visit(ast::Argument *s) {
    s->type_->accept(this);
    cout<<" "<<s->id_;
}

void PrettyPrintVisitor::visit(ast::MetaTag *s) {
    cout<<"<!-- ";
    cout<<IndentStr(s->content_);
    cout<<" -->";
}

void PrettyPrintVisitor::visit(ast::Schema *s) {
    PrintIndent();
    cout<<"schema "<<s->id_<<" {"<<endl;
    Indent();
    s->fields_->accept(this);
    DeIndent();
    PrintIndent();
    cout<<"}"<<endl;
}

void PrettyPrintVisitor::visit(ast::String *s) {
    cout<<"\""<<IndentStr(s->content_)<<"\"";
}

void PrettyPrintVisitor::visit(ast::List *s) {
    for(auto const &exp : *(s->exps_)){
        exp->accept(this);
    }
}

void PrettyPrintVisitor::visit(ast::Type *s) {
    switch(s->type_){
    case ast::kType::INT:
        cout<<"int";
        break;

    case ast::kType::BOOL:
        cout<<"bool";
        break;

    case ast::kType::STRING:
        cout<<"string";
        break;

    case ast::kType::VOID:
        cout<<"void";
        break;

    case ast::kType::TUPLE:
        cout<<"tuple "<<s->tuple_id_;
        break;

    case ast::kType::HTML:
        cout<<"html";
        break;
    }
}

void PrettyPrintVisitor::visit(ast::Session *s){
    PrintIndent();
    cout<<"session "<<s->id_<<" ()";
    s->stm_->accept(this);
}

void PrettyPrintVisitor::visit(ast::EmptyStm *s) {
    PrintIndent();
    if(s->print_semicol_){
        cout<<";"<<endl;
    }
}

void PrettyPrintVisitor::visit(ast::CompoundStm *s) {
    cout<<" { "<<endl;
    Indent();
    for(auto const &var : *(s->vars_)){
        var->accept(this);
    }
    for(auto const &stm : *(s->stms_)){
        stm->accept(this);
    }
    DeIndent();
    PrintIndent();
    cout<<"}"<<endl;
}

void PrettyPrintVisitor::visit(ast::ShowStm *s) {
    PrintIndent();
    cout<<"show ";
    s->doc_->accept(this);
    s->receive_->accept(this);
    cout<<";"<<endl;
}

void PrettyPrintVisitor::visit(ast::DocumentStm *s){
    if(s->pluggable_){
        cout<<"plug "<<s->id_<<"[";

        auto it = s->plugs_->begin();
        if(it != s->plugs_->end()){
            (*it)->accept(this);
            ++it;
        }
        for(; it != s->plugs_->end(); ++it){
            cout<<", ";
            (*it)->accept(this);
        }
        cout<<"]";
    }else{
        cout<<s->id_;
    }
}

void PrettyPrintVisitor::visit(ast::PlugStm *s){
    cout<<s->id_<<" = ";
    s->exp_->accept(this);
}

void PrettyPrintVisitor::visit(ast::ReceiveStm *s){
    cout<<" receive [";

    auto it = s->inputs_->begin();
    if(it != s->inputs_->end()){
        (*it)->accept(this);
        ++it;
    }
    for(; it != s->inputs_->end(); ++it){
        cout<<", ";
        (*it)->accept(this);
    }
    cout<<"]";
}

void PrettyPrintVisitor::visit(ast::InputStm *s){
    cout<<s->lvalue_<<" = "<<s->id_;
}

void PrettyPrintVisitor::visit(ast::ExitStm *s){
    PrintIndent();
    cout<<"exit ";
    s->doc_->accept(this);
    cout<<";"<<endl;
}

void PrettyPrintVisitor::visit(ast::ReturnStm *s){
    PrintIndent();
    cout<<"return ";
    s->exp_->accept(this);
    cout<<";"<<endl;
}

void PrettyPrintVisitor::visit(ast::IfStm *s){
    PrintIndent();
    cout<<"if (";
    s->condition_->accept(this);
    cout<<")";
    s->true_stm_->accept(this);
    if(s->else_stm_ != nullptr){
        PrintIndent();
        cout<<"else";
        s->else_stm_->accept(this);
    }
}

void PrettyPrintVisitor::visit(ast::WhileStm *s){
    PrintIndent();
    cout<<"while (";
    s->condition_->accept(this);
    cout<<")";
    Indent();
    s->stm_->accept(this);
    DeIndent();
    cout<<endl;
}

void PrettyPrintVisitor::visit(ast::ExpStm *s){
    PrintIndent();
    s->exp_->accept(this);
    cout<<";"<<endl;
}

void PrettyPrintVisitor::visit(ast::Exp *){
    //TODO: remove this when have time
}

void PrettyPrintVisitor::visit(ast::LValExp *s){
    cout<<s->lvalue_;
}

void PrettyPrintVisitor::visit(ast::BinopExp *s){
    s->left_->accept(this);

    switch (s->type_) {
    case ast::kBinopType::Assignment:
        cout<<" = ";
        break;

    case ast::kBinopType::Equals:
        cout<<" == ";
        break;

    case ast::kBinopType::NotEquals:
        cout<<" != ";
        break;

    case ast::kBinopType::LowerThan:
        cout<<" < ";
        break;

    case ast::kBinopType::HigherThan:
        cout<<" > ";
        break;

    case ast::kBinopType::LowerEquals:
        cout<<" <= ";
        break;

    case ast::kBinopType::HigherEquals:
        cout<<" >= ";
        break;

    case ast::kBinopType::Add:
        cout<<" + ";
        break;

    case ast::kBinopType::Sub:
        cout<<" - ";
        break;

    case ast::kBinopType::Mult:
        cout<<" * ";
        break;

    case ast::kBinopType::Div:
        cout<<" / ";
        break;

    case ast::kBinopType::Mod:
        cout<<" % ";
        break;

    case ast::kBinopType::And:
        cout<<" && ";
        break;

    case ast::kBinopType::Or:
        cout<<" || ";
        break;

    case ast::kBinopType::Combine:
        cout<<" << ";
        break;

    default:
        break;
    }

    s->right_->accept(this);
}

void PrettyPrintVisitor::visit(ast::UnopExp *s){
    switch (s->type_) {
    case ast::kUnopType::LogicNegate:
        cout<<"!";
        break;

    case ast::kUnopType::Minus:
        cout<<"-";
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
        cout<<" \\+ ";
        break;

    case ast::kTupleopType::Discard:
        cout<<" \\- ";
        break;

    default:
        break;
    }

    cout<<"(";
    for(const auto &id : *(s->ids_)){
        cout<<id<<",";
    }
    cout<<")";
}

void PrettyPrintVisitor::visit(ast::FunctionExp *s){
    cout<<s->id_;
    cout<<"(";

    auto it = s->exps_->begin();
    if(it != s->exps_->end()){
        (*it)->accept(this);
        ++it;
    }

    for(; it != s->exps_->end(); ++it){
        cout<<", ";
        (*it)->accept(this);
    }
    cout<<")";
}

void PrettyPrintVisitor::visit(ast::IntegerExp *s){
    cout<<s->i_;
}

void PrettyPrintVisitor::visit(ast::TrueExp *){
    cout<<"true";
}

void PrettyPrintVisitor::visit(ast::FalseExp *){
    cout<<"false";
}

void PrettyPrintVisitor::visit(ast::StringExp *s){
    cout<<s->str_;
}

void PrettyPrintVisitor::visit(ast::FieldValExp *s){
    cout<<s->id_<<" = ";
    s->exp_->accept(this);
}

void PrettyPrintVisitor::visit(ast::TupleExp *s){
    cout<<"tuple { ";
    Indent();
    auto it = s->field_vals_->begin();
    if(it != s->field_vals_->end()){
        (*it)->accept(this);
        ++it;
    }
    for(; it != s->field_vals_->end(); ++it){
        cout<<", "<<endl;
        PrintIndent();
        (*it)->accept(this);
    }
    DeIndent();
    cout<<"}";
}

}
