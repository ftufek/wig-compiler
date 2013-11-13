#include <iostream>
#include <string>
#include <sstream>
#include "codegen.h"
#include "pretty_printer.h"

using namespace std;

namespace visitors {

CodeGenerator::CodeGenerator(std::ostream &out)
	:cgout(out),_fields({}){}

std::string CodeGenerator::PrettyPrint(ast::Base *s){
	stringstream ss;
	auto printer = visitors::PrettyPrinter(ss, false);
	s->accept(&printer);
	return ss.str();
}

void CodeGenerator::visit(ast::Service *s){
	cgout<<_t_env()
		 <<_t_imports(std::list<std::string> {"cgi","cgitb","os","uuid","pickle"})
		 <<_t_enable_cgi()<<_t_state_vars()<<endl;

	s->schemas_->accept(this);
	cgout<<_t_html_layout()<<endl;
	s->htmls_->accept(this);
	s->sessions_->accept(this);
}

void CodeGenerator::visit(ast::Whatever *s ) {
}

void CodeGenerator::visit(ast::Variable *s) {
	if(s->type_->type_ == ast::kType::HTML){
		//Generate html function
		cgout<<_t_html_function(s->name_, PrettyPrint(s->value_))<<endl;
	}
}

void CodeGenerator::visit(ast::Function *s) {
}

void CodeGenerator::visit(ast::Field *s) {
	string field_name = s->id_;
	string field_default_value{"\"\""};
	switch(s->type_->type_){
	//INT, BOOL, STRING, VOID, TUPLE, HTML, SCHEMA, UNDEFINED
	case ast::kType::INT:
		field_default_value = "0";
		break;

	case ast::kType::BOOL:
		field_default_value = "False";
		break;

	default:
		break;
	}
	_fields.push_back(make_pair(field_name, field_default_value));
}

void CodeGenerator::visit(ast::Empty *) {}

void CodeGenerator::visit(ast::HtmlTag *s) {
}

void CodeGenerator::visit(ast::Argument *s) {
}

void CodeGenerator::visit(ast::MetaTag *s) {
}

void CodeGenerator::visit(ast::Schema *s) {
	_fields.clear();
	s->fields_->accept(this);
	cgout<<_t_schema_class(s->id_, _fields);
	cgout<<endl;
	_fields.clear();
}

void CodeGenerator::visit(ast::String *s) {
}

void CodeGenerator::visit(ast::List *s) {
	for(auto e : *(s->getList())){
		e->accept(this);
	}
}

void CodeGenerator::visit(ast::Type *s) {
}

void CodeGenerator::visit(ast::Session *s){
	cgout<<_t_save_session(s->id_)<<endl
			<<_t_init_session(s->id_)<<endl
			<<_t_load_session(s->id_)<<endl
			<<_t_session(s->id_)<<endl;
}

void CodeGenerator::visit(ast::EmptyStm *s) {
}

void CodeGenerator::visit(ast::CompoundStm *s) {
}

void CodeGenerator::visit(ast::ShowStm *s) {
}

void CodeGenerator::visit(ast::DocumentStm *s){
}

void CodeGenerator::visit(ast::PlugStm *s){
}

void CodeGenerator::visit(ast::ReceiveStm *s){
}

void CodeGenerator::visit(ast::InputStm *s){
}

void CodeGenerator::visit(ast::ExitStm *s){
}

void CodeGenerator::visit(ast::ReturnStm *s){
}

void CodeGenerator::visit(ast::IfStm *s){
}

void CodeGenerator::visit(ast::WhileStm *s){
}

void CodeGenerator::visit(ast::ExpStm *s){
}

void CodeGenerator::visit(ast::Exp *){
}

void CodeGenerator::visit(ast::LValExp *s){
}

void CodeGenerator::visit(ast::BinopExp *s){
}

void CodeGenerator::visit(ast::UnopExp *s){
}

void CodeGenerator::visit(ast::TupleopExp *s){
}

void CodeGenerator::visit(ast::FunctionExp *s){
}

void CodeGenerator::visit(ast::IntegerExp *s){
}

void CodeGenerator::visit(ast::TrueExp *s){
}

void CodeGenerator::visit(ast::FalseExp *s){
}

void CodeGenerator::visit(ast::StringExp *s){
}

void CodeGenerator::visit(ast::FieldValExp *s){
}

void CodeGenerator::visit(ast::TupleExp *s){
}

}
