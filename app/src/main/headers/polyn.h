#pragma once
#include <vector>
#include <string>
#include <optional>
#include <ctype.h>

namespace emel_lang {
    namespace data {
        typedef struct __Coefficient {
            double coefficient;
            unsigned int exponent;
        } Coefficient;

        typedef struct __Term {
            std::vector<Coefficient> coefficients;
            std::optional<std::string> variable;
            struct __Term Parse(std::string source);
        } Term;

        class Polynomial {
            private:
                std::vector<Term> m_terms;
            public:
                Polynomial(std::vector<Term> terms): m_terms(terms) {};
                static Polynomial Parse(std::string source);
        };
    }
}