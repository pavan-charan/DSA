#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <set>
#include <algorithm>

// Define the keywords for C++
std::set<std::string> keywords = {"int", "return", "if", "else", "while", "for", "void", "char", "float", "double", "main"};

// Define operators and special symbols
std::set<std::string> operators = {"=", "+", "-", "*", "/", "%", "++", "--", "==", "!=", "<", ">", "<=", ">=", "&&", "||", "!"};
std::set<std::string> special_symbols = {"(", ")", "{", "}", "[", "]", ";", ",", ".", ":", "@"};

// Regular expression patterns
std::regex identifier_pattern("^[a-zA-Z_][a-zA-Z0-9_]*$");
std::regex constant_pattern("^[0-9]+$|^\"[^\"]*\"$");

void classifyTokens(const std::string& source_code) {
    // Split the source code into tokens using a regular expression
    std::regex token_pattern("[a-zA-Z_][a-zA-Z0-9_]*|\\d+|[(){}\\[\\];,\\.\\+\\-*/=<>!&|%^]+|\"[^\"]*\"");
    auto tokens_begin = std::sregex_iterator(source_code.begin(), source_code.end(), token_pattern);
    auto tokens_end = std::sregex_iterator();

    // Containers to store classified tokens
    std::vector<std::string> keyword_tokens;
    std::vector<std::string> operator_tokens;
    std::vector<std::string> special_symbol_tokens;
    std::vector<std::string> identifier_tokens;
    std::vector<std::string> function_tokens;
    std::vector<std::string> constant_tokens;

    for (std::sregex_iterator i = tokens_begin; i != tokens_end; ++i) {
        std::string token = (*i).str();

        // Classify the token
        if (keywords.find(token) != keywords.end()) {
            keyword_tokens.push_back(token);
        } else if (operators.find(token) != operators.end()) {
            operator_tokens.push_back(token);
        } else if (special_symbols.find(token) != special_symbols.end()) {
            special_symbol_tokens.push_back(token);
        } else if (std::regex_match(token, identifier_pattern)) {
            identifier_tokens.push_back(token);
        } else if (std::regex_match(token, constant_pattern)) {
            constant_tokens.push_back(token);
        }
    }

    // Print the results
    std::cout << "Keywords are: ";
    for (const auto& keyword : keyword_tokens) {
        std::cout << keyword << ", ";
    }
    std::cout << std::endl;

    std::cout << "Operators are: ";
    for (const auto& op : operator_tokens) {
        std::cout << op << ", ";
    }
    std::cout << std::endl;

    std::cout << "Identifiers are: ";
    for (const auto& identifier : identifier_tokens) {
        std::cout << identifier << ", ";
    }
    std::cout << std::endl;

    std::cout << "Functions are: ";
    // Function tokens can be identified by checking if they have parentheses following them
    for (const auto& func : identifier_tokens) {
        if (func != "main") {  // Exclude main for simplicity
            std::cout << func << ", ";
        }
    }
    std::cout << std::endl;

    std::cout << "Special symbols are: ";
    for (const auto& symbol : special_symbol_tokens) {
        std::cout << symbol << ", ";
    }
    std::cout << std::endl;

    std::cout << "Constants are: ";
    for (const auto& constant : constant_tokens) {
        std::cout << constant << ", ";
    }
    std::cout << std::endl;
}

int main() {
    // Input source code
    std::string source_code;
    std::cout << "Enter the source code (end input with a blank line):" << std::endl;

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty()) break;
        source_code += line + "\n";
    }

    // Call the function to classify tokens
    classifyTokens(source_code);

    return 0;
}
