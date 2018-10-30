#ifndef BARES_H
#define BARES_H

#include "parser.h"
#include "token.h"

//=== Aliases
using value_type = long int; //!< Type we operate on.
//using symbol = char; //!< A symbol in this implementation is just a char.


//bool is_operator( symbol s );

bool is_operator ( Token t);

//bool is_operand( symbol s );

bool is_operand( Token t );

//bool is_opening_scope( symbol s );

bool is_opening_scope( Token t );

//bool is_closing_scope( symbol s );

bool is_closing_scope( Token t );

//bool is_right_association( symbol op );

bool is_right_association( Token op );

//std::string infix_to_postfix( std::string );

std::vector<Token> infix_to_postfix( std::vector<Token> infix );

//value_type char2integer( char c );

value_type str2integer( Token t);

//value_type evaluate_postfix( std::string );

value_type evaluate_postfix( std::vector<Token> postfix );

//short get_precedence( symbol op );

short get_precedence( Token t );

//bool has_higher_or_eq_precedence( symbol op1 , symbol op2 );

bool has_higher_or_eq_precedence( Token op1 , Token op2 );

//value_type execute_operator( value_type v1, value_type v2, symbol op );

value_type execute_operator( value_type v1, value_type v2, Token op );

#endif