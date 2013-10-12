#include <iostream>
#include "pretty_printer.h"

using namespace std;

namespace pp {

void PrettyPrintVisitor::visit(ast::Service *s){
    cout<<"service {"<<endl;
    s->htmls_->accept(this);
    cout<<endl;
    s->schemas_->accept(this);
    cout<<endl;
    s->global_variables_->accept(this);
    cout<<endl;
    s->functions_->accept(this);
    cout<<"}"<<endl;
}

void PrettyPrintVisitor::visit(ast::Whatever *s ) {
    cout<<s->whatever_;
}

void PrettyPrintVisitor::visit(ast::Variable *s) {
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
    cout<<s->content_;
    cout<<" -->";
}

void PrettyPrintVisitor::visit(ast::Schema *s) {
    cout<<"schema "<<s->id_<<" {"<<endl;
    s->fields_->accept(this);
    cout<<"}"<<endl;
}

void PrettyPrintVisitor::visit(ast::String *s) {
    cout<<"\""<<s->content_<<"\"";
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

void PrettyPrintVisitor::visit(ast::EmptyStm *s) {
    if(s->print_semicol_){
        cout<<";"<<endl;
    }
}

void PrettyPrintVisitor::visit(ast::CompoundStm *s) {
    cout<<" { "<<endl;
    for(auto const &var : *(s->vars_)){
        var->accept(this);
    }
    for(auto const &stm : *(s->stms_)){
        stm->accept(this);
    }
    cout<<"}";
}

void PrettyPrintVisitor::visit(ast::ShowStm *s) {
    cout<<"show ";
    s->doc_->accept(this);
    s->receive_->accept(this);
    cout<<";"<<endl;
}

void PrettyPrintVisitor::visit(ast::DocumentStm *s){
    if(s->pluggable_){
        cout<<"plug "<<s->id_<<"[";
        // TODO: fix this after. there's always a trailing ','
        for(auto const &plug : *(s->plugs_)){
            plug->accept(this);
            cout<<", ";
        }
        cout<<"]";
    }else{
        cout<<s->id_;
    }
}

void PrettyPrintVisitor::visit(ast::PlugStm *s){
    cout<<s->id_<<"=";
    s->exp_->accept(this);
}

void PrettyPrintVisitor::visit(ast::ReceiveStm *s){
    cout<<"receive [";
    for(auto const &input : *(s->inputs_)){
        input->accept(this);
        cout<<", ";
    }
    cout<<"]";
}

void PrettyPrintVisitor::visit(ast::InputStm *s){
    cout<<s->lvalue_<<" = "<<s->id_;
}

void PrettyPrintVisitor::visit(ast::ExitStm *s){
    cout<<"exit ";
    s->doc_->accept(this);
    cout<<";"<<endl;
}

void PrettyPrintVisitor::visit(ast::ReturnStm *s){
    cout<<"return ";
    s->exp_->accept(this);
    cout<<";"<<endl;
}

void PrettyPrintVisitor::visit(ast::IfStm *s){
    cout<<"if (";
    s->condition_->accept(this);
    cout<<")";
    s->true_stm_->accept(this);
    if(s->else_stm_ != nullptr){
        cout<<"else"<<endl;
        s->else_stm_->accept(this);
    }
}

void PrettyPrintVisitor::visit(ast::WhileStm *s){
    cout<<"while (";
    s->condition_->accept(this);
    cout<<")";
    s->stm_->accept(this);
    cout<<endl;
}

void PrettyPrintVisitor::visit(ast::ExpStm *s){
    s->exp_->accept(this);
    cout<<";"<<endl;
}

void PrettyPrintVisitor::visit(ast::Exp *s){
    cout<<"<empty>";
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

}
