/*
 * error.h
 *
 *  Created on: Oct 27, 2013
 *      Author: user
 */

#ifndef ERROR_H_
#define ERROR_H_

#include <boost/preprocessor.hpp>
#include <string>
#include <list>
#include <initializer_list>

// The following code for error code generation comes from:
// http://stackoverflow.com/questions/5093460/how-to-convert-an-enum-type-variable-to-a-string
#define X_DEFINE_ENUM_WITH_STRING_CONVERSIONS_TOSTRING_CASE(r, data, elem)    \
	case elem : return BOOST_PP_STRINGIZE(elem);

#define DEFINE_ENUM_WITH_STRING_CONVERSIONS(name, enumerators)                \
    enum name {                                                               \
        BOOST_PP_SEQ_ENUM(enumerators)                                        \
    };                                                                        \
                                                                              \
    inline const char* ToString(name v)                                       \
    {                                                                         \
        switch (v)                                                            \
        {                                                                     \
            BOOST_PP_SEQ_FOR_EACH(                                            \
                X_DEFINE_ENUM_WITH_STRING_CONVERSIONS_TOSTRING_CASE,          \
                name,                                                         \
                enumerators                                                   \
            )                                                                 \
            default: return "[Unknown " BOOST_PP_STRINGIZE(name) "]";         \
        }                                                                     \
    }

namespace error {

DEFINE_ENUM_WITH_STRING_CONVERSIONS(ErrorCode,
		(NO_RETURN)
		(SYMBOL_ALREADY_PRESENT)
		(HTML_TAG_NOT_A_SYMBOL)
		/* typecheck error codes: */
		(SHOULD_BE_BOOL)
		(TYPES_DONT_MATCH)
		(CAN_COMPARE_INTEGERS_ONLY)
		(OP_INT_ONLY)
		(OP_INT_OR_STR_ONLY)
		(OP_BOOL_ONLY)
		(NOT_A_FUNCTION)
		(NOT_SAME_NUMBER_PARAMETERS)
		(ARGUMENT_TYPE_DONT_MATCH)
		(HTML_DOESNT_EXIST)
		(SHOULD_BE_HTML)
		(FUNCTION_RETURN_TYPE_DONT_MATCH)
		(PLUG_TYPE_UNDEFINED)
		(SCHEMA_NOT_DEFINED)
		(SCHEMA_DONT_HAVE_FIELD));

class Error
{
public:
	Error(ErrorCode code, std::string arg, int lineno);
	~Error();

	ErrorCode get_code();
	std::string get_arg();
	int get_line();
private:
	ErrorCode code_;
	std::string arg_;
	int lineno_;
};

bool ErrorsPresent();
void GenerateError(ErrorCode code, std::string str, int lineno);
void PrintErrors(std::ostream &out);
void PrintErrors();

}

#undef X_DEFINE_ENUM_WITH_STRING_CONVERSIONS_TOSTRING_CASE
#undef DEFINE_ENUM_WITH_STRING_CONVERSIONS

#endif /* ERROR_H_ */
