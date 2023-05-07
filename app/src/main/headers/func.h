// func.h - declares the function type as specified in grammar.y
//
// Functions represent relation between two sets.
//
#pragma once
#include "polyn.h"
#include "set.h"
#include <optional>
#include <string>
namespace emel_lang {
    namespace data {
        /// <summary>
        /// Represents a relation between two sets.
        /// </summary>
        class Function {
            private:
                Set m_domain;
                Set m_codomain;
                std::vector<std::pair<std::string, std::string>> m_relations;
                std::optional<std::string> m_name;
                std::optional<std::string> m_expression;
            public:
                Function(Set domain, Set codomain, std::vector<std::pair<std::string, std::string>> relations, std::optional<std::string> name, std::optional<std::string> expression): m_domain(domain), m_codomain(codomain), m_relations(relations), m_name(name), m_expression(expression) {};
                /// <summary>
                /// Gets the domain of the function.
                /// </summary>
                Set domain();
                /// <summary>
                /// Gets the codomain of the function.
                /// </summary>
                Set codomain();
                /// <summary>
                /// Gets the relations of the function.
                /// </summary>
                std::vector<std::pair<std::string, std::string>> relations();
                /// <summary>
                /// Gets the name of the function.
                /// </summary>
                std::optional<std::string> name();
                /// <summary>
                /// Gets the expression of the function.
                /// </summary>
                std::optional<std::string> expression();

                /// <summary>
                /// Evaluates the function at a point.
                /// <param name="args">The arguments to evaluate the function at.</param>
                /// </summary>
                Polynomial eval(std::vector<Polynomial> args);
        };
    }
}