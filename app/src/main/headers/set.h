// set.h - declares the set type as specified in grammar.y
// //
// // Sets represent a collection of elements.
// //
// This header also declares the special rings of natural numbers, integers, rational numbers, real numbers and complex numbers.
#pragma once
#include <vector>
#include <string>
#include <optional>
namespace emel_lang {
    namespace data {
        enum class RingType {
            NATURAL, INTEGER, RATIONAL, REAL, COMPLEX
        };
 

        class Set {
            private:
                std::vector<std::string> m_elements;
                std::string m_name;
            public:
                /// <summary>
                /// Constructs a set from a list of elements.
                /// <param name="name">The name of the set.</param>
                /// <param name="elements">The elements of the set.</param>
                /// </summary>
                Set(std::string name, std::vector<std::string> elements): m_elements(elements), m_name(name) {};
                /// <summary>
                /// Name of the set.
                /// </summary>
                std::string name();
                /// <summary>
                /// Gets if the set is a ring.
                /// </summary>
                bool is_ring();
                /// <summary>
                /// Gets if the set is a field.
                /// </summary>
                bool is_field();
                /// <summary>
                /// Union of two sets.
                /// <param name="other">The other set.</param>
                /// </summary>
                Set unite(Set other);
                /// <summary>
                /// Intersection of two sets.
                /// <param name="other">The other set.</param>
                /// </summary>
                Set intersect(Set other);
                /// <summary>
                /// Difference of two sets.
                /// <param name="other">The other set.</param>
                /// </summary>
                Set difference(Set other);
                /// <summary>
                /// Symmetric difference of two sets.
                /// <param name="other">The other set.</param>
                /// </summary>
                Set symmetric_difference(Set other);
                /// <summary>
                /// Cartesian product of two sets.
                /// <param name="other">The other set.</param>
                /// </summary>
                Set cartesian_product(Set other);
                /// <summary>
                /// The set of all subsets of a set.
                /// </summary>
                Set power_set();
                /// <summary>
                /// The set of everything that is not in the set.
                /// Equivalent to bulk union of power set minus this set.
                /// </summary>
                Set complement();
                /// <summary>
                /// The set of all elements that are in either set but not both.
                /// </summary>
                Set inverse();
                /// <summary>
                /// The set of all elements that are in either set.
                /// </summary>
                Set quotient(Set other);
                /// <summary>
                /// Wheter this set is a ring. If it is, returns the ring type.
                /// </summary>
                std::optional<RingType> ring_type();
                /// <summary>
                /// Parses a set from a string.
                /// <param name="source">The string to parse.</param>
                /// </summary>
                static Set Parse(std::string source);

                /// <summary>
                /// Gets the elements of the set.
                /// </summary>
                std::string operator[](int index);
        };
   }
}