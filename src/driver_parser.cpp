#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <exception>

#include "../include/bares.h"
#include "../include/parser.h"


void print_error_msg( const Parser::ResultType & result, std::string str )
{
    // Have we got a parsing error?
    switch ( result.type )
    {
        case Parser::ResultType::UNEXPECTED_END_OF_EXPRESSION:
            std::cout << "Unexpected end of expression at column (" << result.at_col + 1 << ")!\n";
            break;
        case Parser::ResultType::ILL_FORMED_INTEGER:
            std::cout << "Ill formed integer at column (" << result.at_col + 1 << ")!\n";
            break;
        case Parser::ResultType::MISSING_TERM:
            std::cout << "Missing <term> at column (" << result.at_col + 1 << ")!\n";
            break;
        case Parser::ResultType::EXTRANEOUS_SYMBOL:
            std::cout << "Extraneous symbol after valid expression found at column (" << result.at_col + 1 << ")!\n";
            break;
        case Parser::ResultType::INTEGER_OUT_OF_RANGE:
            std::cout << "Integer constant out of range beginning at column (" << result.at_col + 1 << ")!\n";
            break;
        case Parser::ResultType::MISSING_CLOSING_SCOPE:
            std::cout << "Missing closing \")\" at column (" << result.at_col + 1 << ")!\n";
            break;
        default:
            std::cout << ">>> Unhandled error found!\n";
            break;
    }
}


int main()
{
    Parser my_parser; // Instancia um parser.
    // Tentar analisar cada expressão da lista.
    std::string expr;

    bool passa = true;
    value_type resultado;
    
        
    while(getline(std::cin, expr))
    {
        passa = true;
        // Fazer o parsing desta expressão.
        auto result = my_parser.parse( expr );
        // Preparar cabeçalho da saida.
        //std::cout << std::setfill('=') << std::setw(80) << "\n";
        // Se deu pau, imprimir a mensagem adequada.
        if ( result.type != Parser::ResultType::OK )
        {
            print_error_msg( result, expr );
        }
        else
        {
            auto lista = my_parser.get_tokens();

            auto postfix = infix_to_postfix( lista );
            //std::cout << ">>> Input (infix)    = " << e << "\n";
            //std::cout << ">>> Output (postfix) = " << postfix << "\n";

            try
            {
                resultado = evaluate_postfix( postfix );
                //std::cout << ">>> Result is: " << result << std::endl;
            }
            catch(std::runtime_error e )
            {
                std::cerr << e.what();
                passa = false;
            }
            
            if(passa == true)
            {
                if( resultado < std::numeric_limits< short >::min() or
                    resultado > std::numeric_limits< short >::max()  )
                {
                      std::cout << "Numeric overflow error!\n";
                }
                else
                {
                    std::cout << resultado << std::endl;
                }
            }
        }

        



        /*// Recuperar a lista de tokens.
        auto lista = my_parser.get_tokens();
        std::cout << ">>> Tokens: { ";
        std::copy( lista.begin(), lista.end(),
             std::ostream_iterator< Token >(std::cout, " ") );
        std::cout << "}\n";
        std::cout << std::endl;
        */
    }

    return EXIT_SUCCESS;
}