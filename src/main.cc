#include <iostream>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include "ast.h"
#include "pretty_printer.h"
#include "error.h"
#include "sym_tabler.h"
#include "typechecker.h"
#include "codegen.h"
#include "weeder.h"
#include "parser/y.tab.h"

int yyparse();
ast::Service *EXP; //AST of the input program
bool success = true; //set to false if parsing fails
extern FILE *yyin;

using namespace std;

void printHelp(){
	cout<<"Usage: fwig [options] <input_wig_file> "<<endl;
	cout<<endl;
	cout<<"Options: "<<endl;
	cout<<" -o [file] : output the result to a file instead of stdout"<<endl;
	cout<<" -p : enable pretty-printing"<<endl;
	cout<<" -w : enable weeding"<<endl;
	cout<<" -s : enable symbol table generation"<<endl;
	cout<<" -t : enable typechecking (will enable symbol table generation)"
			<<endl;
	cout<<" -v : verbose (prints symbol table and types when pretty-printing)"
			<<endl;
	cout<<" -c : code generation (will disable pretty-printing and enable all "
			"other phases)"<<endl;
	cout<<endl;
	cout<<" Errors during compiling are output to stderr"<<endl;
	cout<<endl;
	cout<<"Example usage: "<<endl;
	cout<<"fwig -p -w -o test.out test.wig  # will output pretty print result to"
			<<endl;
	cout<<"			# test.out file and weed result to console"<<endl;
}

int main(int argc, char **argv){
	if(argc == 1){
		//invalid arguments to the program
		printHelp();
		return 0;
	}

	// Parse arguments using getopt
	bool prettyPrint = false;
	bool weed = false;
	bool symbol = false;
	bool typecheck = false;
	bool verbose = false;
	bool genCode = false;
	char *outfile = NULL;
	char *infile = NULL;
	int c;

	while((c = getopt(argc, argv, "o:pwstvc")) != -1){
		switch(c){
		case 'o':
			outfile = optarg;
			break;
		case 'p':
			prettyPrint = true;
			break;
		case 'w':
			weed = true;
			break;
		case 's':
			symbol = true;
			break;
		case 't':
			typecheck = true;
			symbol = true;
			break;
		case 'v':
			verbose = true;
			break;
		case 'c':
			genCode = true;
			weed = true;
			symbol = true;
			typecheck = true;
			break;

		case '?':
			 if (optopt == 'o')
			   fprintf (stderr, "Option -%c requires an argument.\n", optopt);
			 else if (isprint (optopt))
			   fprintf (stderr, "Unknown option `-%c'.\n", optopt);
			 else
			   fprintf (stderr,
						"Unknown option character `\\x%x'.\n",
						optopt);
			 return 1;
		default:
			break;
		}
	}

	//get input file
	if(optind < argc){
		infile = argv[argc-1];
	}else{
		cerr<<"ERROR: no input file specified!"<<endl;
		return 0;
	}

	yyin = fopen(infile, "r");
	if(!yyin){
		cerr<<"ERROR: can't open file "<<infile<<endl;
		return 0;
	}

    yyparse();
    fclose(yyin);

    //run compiler phases
    if(success){
    	if(symbol || typecheck){
    		auto tabler = visitors::SymTabler();
    		tabler.visit(EXP);
    	}
    	if(weed){
			auto weeder = visitors::Weeder();
			weeder.visit(EXP);
		}
    	if(typecheck){
			auto typechecker = visitors::TypeChecker();
			typechecker.visit(EXP);
    	}

    	//Setup output stream
    	std::streambuf * buf;
		std::ofstream of;
		if(outfile) {
			of.open(outfile, std::fstream::out);
			buf = of.rdbuf();
		} else {
			buf = std::cout.rdbuf();
		}
		std::ostream out(buf);

    	if(prettyPrint && !genCode){
    		auto pp = visitors::PrettyPrinter(out, verbose);
			pp.visit(EXP);
    	}
    	if(genCode && error::ErrorsPresent()){
    		std::cerr<<"Errors happened during compiling: "<<std::endl;
    		error::PrintErrors();
    	}else if(genCode){
			auto pp = visitors::CodeGenerator(out);
			pp.visit(EXP);
    	}

		of.close();
    }
}
