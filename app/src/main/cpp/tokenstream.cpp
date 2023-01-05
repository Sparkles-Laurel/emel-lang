#include "app.h"

/// <summary>
/// Creates a new token stream.
/// </summary>
emel_lang::tokens::TokenStream::TokenStream(std::string source) {
    this->source = source;
}

/// <summary>
/// Returns the next token in the stream.
/// </summary>
emel_lang::tokens::Token emel_lang::tokens::TokenStream::next() {
    if (isAtEnd()) {
        return Token(TokenType::EOF, "", 0, 0);
    }
    current++;
    return tokens[current - 1];
}

/// <summary>
/// Returns the next token in the stream without consuming it.
/// </summary>
emel_lang::tokens::Token emel_lang::tokens::TokenStream::peek() {
    if (isAtEnd()) {
        return Token(TokenType::EOF, "", 0, 0);
    }
    return tokens[current];
}
/// <summary>
/// Returns true if the stream is at the end.
/// </summary>
bool emel_lang::tokens::TokenStream::isAtEnd() {
    return current >= tokens.size();
}

bool emel_lang::tokens::TokenStream::__process_string() {
    // Convert source to a token array.
    // Split source through whitespace.
    std::vector<std::string> source_tokens;
    std::string token;
    std::istringstream iss(source);
    while (iss >> token) {
        source_tokens.push_back(token);
    }

    // Convert source tokens to tokens.
    for(auto &tok: source_tokens) {
        // Check if token is a keyword.
        switch(tok) {
            case "and":
            case "&&":
                tokens.push_back(Token(TokenType::AND, tok, 0, 0));
                break;
            case "or":
            case "||":
                tokens.push_back(Token(TokenType::OR, tok, 0, 0));
                break;
            case "xor":
            case "^^":
                tokens.push_back(Token(TokenType::XOR, tok, 0, 0));
                break;
            case "not":
            case "!":
                tokens.push_back(Token(TokenType::NOT, tok, 0, 0));
                break;
            case "bool":
                tokens.push_back(Token(TokenType::BOOL, tok, 0, 0));
                break;
            case "fn":
                tokens.push_back(Token(TokenType::FN, tok, 0, 0));
                break;
            case "poly":
                tokens.push_back(Token(TokenType::POLY, tok, 0, 0));
                break;
            case "set":
                tokens.push_back(Token(TokenType::SET, tok, 0, 0));
                break;
            case "union":
            case "unite":
                tokens.push_back(Token(TokenType::UNION, tok, 0, 0));
                break;
            case "intersect":
            case "intsct":
                tokens.push_back(Token(TokenType::INTERSECT, tok, 0, 0));
                break;
            case "diff":
                tokens.push_back(Token(TokenType::DIFFERENCE, tok, 0, 0));
                break;
            case "delta":
                tokens.push_back(Token(TokenType::SYMMETRIC_DIFFERENCE, tok, 0, 0));
                break;
            case "if":
                tokens.push_back(Token(TokenType::IF, tok, 0, 0));
                break;
            case "else":
                tokens.push_back(Token(TokenType::ELSE, tok, 0, 0));
                break;
            case "elif":
                tokens.push_back(Token(TokenType::ELIF, tok, 0, 0));
                break;
            case "yes":
                tokens.push_back(Token(TokenType::YES, tok, 0, 0));
                break;
            case "no":
                tokens.push_back(Token(TokenType::NO, tok, 0, 0));
                break;
            case "nil":
                tokens.push_back(Token(TokenType::__NULL, tok, 0, 0));
                break;
            default:
                // Check if token is a number.
                if (std::regex_match(tok, std::regex("[0-9]+"))) {
                    tokens.push_back(Token(TokenType::NUMBER, tok, 0, 0));
                } 
                // check if token is an identifier
                else if (std::regex_match(tok, std::regex("[a-zA-Z_][a-zA-Z0-9_]*"))) {
                    tokens.push_back(Token(TokenType::IDENTIFIER, tok, 0, 0));
                }
                // if neither cases match, bait out the token.
                else {
                    tokens.push_back(Token(TokenType::__BAITED, tok, 0, 0));
                }
        }
    }
}

static void _load_str_from_file(const char *filename, char **str) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr, "Error opening file '%s': %s", filename, strerror(errno));
        exit(1);
    }
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);
    *str = (char *) malloc(fsize + 1);
    fread(*str, fsize, 1, f);
    fclose(f);
    (*str)[fsize] = 0;
}