/*! \file bares.h
	\author Noé Fernandes
	\date October, 30th
*/

#ifndef BARES_H
#define BARES_H

#include "parser.h"
#include "token.h"


//=== Aliases
using value_type = long int; //!< Type we operate on.

/*! Checks whether it is operator.
@param t Token.
@return True if is operator. False, otherwise. */
bool is_operator ( Token t);


/*! Checks whether it is operand.
@param t Token.
@return True if is operand. False, otherwise. */
bool is_operand( Token t );


/*! Checks whether it is opening scope.
@param t Token.
@return True if is opening scope. False, otherwise. */
bool is_opening_scope( Token t );


/*! Checks whether it is closing scope.
@param t Token.
@return True if is closing scope. False, otherwise. */
bool is_closing_scope( Token t );

/*! Checks whether it is right association.
@param t Token.
@return True if is right association. False, otherwise.*/
bool is_right_association( Token op );

/*! Transforms the vector of tokens from infix to postfix.
@param infix Vector of tokens in infix.
@return vector of token in postix form.*/
std::vector<Token> infix_to_postfix( std::vector<Token> infix );


/*! Transforms a string in number form to integer.
@param t Token.
@return value type (long integer).*/
value_type str2integer( Token t);

/*! Returns the result of the expression.
@param postfix Vector in postfix form.
@return value type (long integer).*/
value_type evaluate_postfix( std::vector<Token> postfix );

/*! Returns the precedence value of the operation.
@param t Token
@return short int.*/ 
short get_precedence( Token t );

/*! It compares two operators and defines which one has precedence.
@param op1 Token.
@param op2 Token.
@return True if op1 >= op2. False, otherwise.*/
bool has_higher_or_eq_precedence( Token op1 , Token op2 );

/*! Perform an operation.
@param op1 Token.
@param op2 Token.
return value type (long integer).*/
value_type execute_operator( value_type v1, value_type v2, Token op );

#endif