/*
    * polyn.cpp - Implementation of polyn.h (Polynomials)
    *
    *  Created on: 2023-05-01

    Copyright (c) 2023 Borusan Asım Kocabıyık Vocational and Technical Anatolian High School, All rights reserved.
*/
// See LICENSE for licensing information.

#include "../headers/polyn.h"

namespace emel_lang {
    namespace data {
               
        Term Term::Parse(std::string source) {
            // Root is denoted by rt. Powers are denoted by ^ or pw.
            // Coefficients are denoted like 2x where 2 is the coefficient and x is the variable...
            // Parse the term.
            std::vector<Coefficient> coefficients;
            std::optional<std::string> variable;
            std::string coefficient_string = "";
            for (int i = 0; i < source.length(); i++) {
                if (/*source[i] is alphanumeric and not 'p' or 'r'*/ isalnum(source[i]) && source[i] != 'p' && source[i] != 'r') {
                    // We have a variable.
                    variable = coefficient_string;
                    coefficient_string = "";
                } else if (source[i] == '^' || source[i] == 'p') {
                    // We have a power.
                    // If the next character is w, skip it.
                    if (source[i + 1] == 'w') {
                        i++;
                    }
                    // Parse the power.
                    std::string power_string = "";
                    for (int j = i + 1; j < source.length(); j++) {
                        power_string += source[j];
                    }
                    // Add the coefficient to the list.
                    coefficients.push_back(Coefficient{std::stod(coefficient_string), static_cast<unsigned int>(std::stoi(power_string))});
                    coefficient_string = "";
                } else if(source[i] == 'r') {
                    // We have a root.
                    // If the next character is t, skip it.
                    if (source[i + 1] == 't') {
                        i++;
                    }
                    // Parse the root.
                    std::string root_string = "";
                    for (int j = i + 1; j < source.length(); j++) {
                        root_string += source[j];
                    }
                    // Add the coefficient to the list.
                    coefficients.push_back(Coefficient{std::stod(coefficient_string), (unsigned)std::stoi(root_string)});
                    coefficient_string = "";

                } else if (isalpha(source[i])) {
                    // We have a variable.
                    variable = coefficient_string;
                    coefficient_string = "";
                } else if (source[i] == ' ') {
                    // Skip the space.
                } else if(source[i] == '+') {
                    // Add the coefficient to the list.
                    coefficients.push_back(Coefficient{std::stod(coefficient_string), 1});
                    coefficient_string = "";
                } else {
                    coefficient_string += source[i];
                }
            }
            // return the term.
            return Term{coefficients, variable};
        }

    }
}