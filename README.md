# emel-lang
The Emel programming language, a language for implementing mathematical solutions.

# Some examples
```
// Function signature.
fn f is R cart R -> R
  f(x + 1, y - 2) = x + 1 done (when ((there exists x, y in R but range[0, 1)) fulfills r >= 6))
  f(_, _) = 69 done. // unused variables can be discarded with _.
  
// Polynomials.

poly P(x) = x pw (12 / 2rt n + 1) - 3x pw 6 + 1 // `pw` for powers, `rt`for roots.
  done. // Polynomials get their signatures auto-detected.

const fn g(_) = 31 // signature is (fn g is E -> {31} intersect N)
              done.
              
// Set literal
set A = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12} union {-1}
    done.
    
// Set-builder

set B = {x + 1 | x in range[0, 9]}
    done.
    
// Boolean algebra is also available

/// Determines if x is a funny number.
bool p(x) === (x == 31) or (x == 69)
      done.
