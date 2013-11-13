#include <iostream>
#include <string>
#include "codegen.h"

using namespace std;

namespace visitors {

CodeGenerator::CodeGenerator(std::ostream &out):cgout(out){}

void CodeGenerator::visit(ast::Service *s){
}

void CodeGenerator::visit(ast::Whatever *s ) {
}

void CodeGenerator::visit(ast::Variable *s) {
}

void CodeGenerator::visit(ast::Function *s) {
}

void CodeGenerator::visit(ast::Field *s) {
}

void CodeGenerator::visit(ast::Empty *) {}

void CodeGenerator::visit(ast::HtmlTag *s) {
}

void CodeGenerator::visit(ast::Argument *s) {
}

void CodeGenerator::visit(ast::MetaTag *s) {
}

void CodeGenerator::visit(ast::Schema *s) {
}

void CodeGenerator::visit(ast::String *s) {
}

void CodeGenerator::visit(ast::List *s) {
}

void CodeGenerator::visit(ast::Type *s) {
}

void CodeGenerator::visit(ast::Session *s){
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
