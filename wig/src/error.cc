/*
 * error.cc
 *
 *  Created on: Oct 27, 2013
 *      Author: user
 */


#include <iostream>
#include "error.h"

namespace error{

std::list<Error> errors_ = std::list<Error>();

Error::Error(ErrorCode code, std::string arg)
	:code_(code), arg_(arg){};

Error::~Error(){};

ErrorCode Error::get_code(){
	return code_;
}

std::string Error::get_arg(){
	return arg_;
}

bool ErrorsPresent(){
	return errors_.size() > 0;
}

void GenerateError(ErrorCode code, std::string arg){
	errors_.push_back(Error(code, arg));
}

void PrintErrors(std::ostream &out){
	out<<"/* Produced errors: "<<std::endl;
	for(auto error : errors_){
		out<<ToString(error.get_code())<<"("<<error.get_arg()<<")"<<std::endl;
	}
	out<<"*/"<<std::endl;
}

}
