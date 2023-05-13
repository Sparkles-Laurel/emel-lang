#pragma once
#include <vector>
#include <string>
#include <optional>
#include <ctype.h>
#include <stdarg.h>

namespace emel_lang {
    namespace data {

        /// <summary>
        /// Represents a coefficient in a term.
        /// </summary>
        typedef struct __Coefficient {
            /// <summary>
            /// The coefficient.
            /// </summary>
            double coefficient;
            /// <summary>
            /// The exponent.
            /// </summary>
            unsigned int exponent;
        } Coefficient;

        /// <summary>
        /// Represents a term in a polynomial.
        /// </summary>
        typedef struct __Term {
            /// <summary>
            /// The coefficients of the term.
            /// </summary>
            std::vector<Coefficient> coefficients;
            /// <summary>
            /// The variable of the term.
            /// </summary>
            std::optional<std::string> variable;
            /// <summary>
            /// Parses a term from a string.
            /// </summary>
            struct __Term Parse(std::string source);
        } Term;

        /// <summary>
        /// Represents a polynomial.
        /// </summary>
        class Polynomial {
            private:
                std::vector<Term> m_terms;
            public:
                /// <summary>
                /// Constructs a polynomial from a list of terms.
                /// <param name="terms">The terms of the polynomial.</param>
                /// </summary>
                Polynomial(std::vector<Term> terms): m_terms(terms) {};

                /// <summary>
                /// Parses a polynomial from a string.
                /// <param name="source">The string to parse.</param>
                /// </summary>
                static Polynomial parse(std::string source);

                /// <summary>
                /// Evaluates the polynomial at a point. Accepts variadic arguments.
                /// <param name="args">The arguments to evaluate the polynomial at.</param>
                /// </summary>
                Polynomial operator()(...);

        };
    }
}