#include <iostream>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include "ast.h"
#include "pretty_printer.h"
#include "error.h"
#include "sym_tabler.h"
#include "weeder.h"
#include "parser/y.tab.h"

int yyparse();
ast::Service *EXP;
bool success = true;
extern FILE *yyin;

using namespace std;

namespace {
void printHelp(){
	cout<<"Usage: fwig [options] <input>.wig "<<endl;
	cout<<endl;
	cout<<"Options: "<<endl;
	cout<<" -o [file] : output to file instead of stdout"<<endl;
	cout<<" -p : pretty-print (to stdout if -o [file] option isn't specified)"<<endl;
	cout<<" -w : weed and output the report to stderr"<<endl;
	cout<<" -s : enable symbol table (will print symbol table in pretty-printing)"<<endl;
	cout<<endl;
	cout<<"Example usage: "<<endl;
	cout<<"fwig -p -w -o test.out test.wig  # will output pretty print result to"<<endl;
	cout<<"			# test.out file and weed result to console"<<endl;
}
}

int main(int argc, char **argv){
	if(argc == 1){
		printHelp();
		return 0;
	}
	// Parse arguments using getopt
	bool prettyPrint = false;
	bool weed = false;
	bool symbol = false;
	char *outfile = NULL;
	char *infile = NULL;
	int c;

	while((c = getopt(argc, argv, "o:pws")) != -1){
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
    if(success){
    	if(symbol){
    		visitors::SymTabler tabler = visitors::SymTabler();
    		tabler.visit(EXP);
    	}
    	if(weed){
			visitors::Weeder weeder = visitors::Weeder();
			weeder.visit(EXP);
		}
    	if(prettyPrint){
    		std::streambuf * buf;
    		std::ofstream of;
    		if(outfile) {
    		    of.open(outfile, std::fstream::out);
    		    buf = of.rdbuf();
    		} else {
    		    buf = std::cout.rdbuf();
    		}
    		std::ostream out(buf);
    		visitors::PrettyPrintVisitor pp = visitors::PrettyPrintVisitor(out,symbol);
			pp.visit(EXP);
			of.close();
    	}

    }

//    delete(EXP); TODO: hmm it's bizarre, when I try to call
    //the destructor delete it, it creates more leaks. fix
}
