package emellang

import (
	"io"
	// "regexp"
)
type Literal interface {}

// Introduces keywords in Emel
const (
	KwPoly  = "poly"
	KwFn    = "fn"
	KwConst = "const"
	KwSet   = "set"
	KwBool  = "bool"
	KwDone  = "done"
	KwIn    = "in"
	KwIs    = "is"
	KwPw    = "pw"
	KwRt    = "rt"
	KwCart  = "cart"
)

// Introduces literal regexes of Emel
const (
	LitVec    = "\\[(\\d+\\s),+\\]"
	LitMatrix = "\\[(\\[(\\d+\\s),+\\]\\s)+\\]"
	LitSet    = "\\{(\\d+),+\\}"
)

// VectorLiteral represents a vector literal
type VectorLiteral struct {
	Values []int64
}

// MatrixLiteral represents a matrix literal
type MatrixLiteral struct {
	Rows []VectorLiteral
}

// SetLiteral represents a set literal
type SetLiteral struct {
	Values []int64
}

// Introduces operators in Emel
const (
	OpAdd = "+"
	OpSub = "-"
	OpMul = "*"
	OpDiv = "/"
	OpPow = "^"
	OpMod = "%"
	OpEq  = "=="
	OpNeq = "!="
	OpLt  = "<"
	OpGt  = ">"
	OpLte = "<="
	OpGte = ">="
	OpAnd = "&&"
	OpOr  = "||"
	OpNot = "!"
	OpXor = "^^"
	OpTo  = "->"
	OpIs = "is"
	OpIn = "in"
	OpThereExists = "there exists"
	OpForAll = "for all"
	OpCart = "cart"
	OpPw = "pw"
	OpRt = "rt"
	OpSetBuilder = "|"
)

// Introduces delimiters in Emel
const (
	DelSemiColon = ";"
	DelComma     = ","
	DelColon     = ":"
	DelDot       = "."
	DelOpenParen = "("
	DelCloseParen = ")"
	DelOpenBrace = "{"
	DelCloseBrace = "}"
	DelOpenBracket = "["
	DelCloseBracket = "]"
)

// Token represents a token
type Token struct {
	Kind  string
	Value string
}

// IdentToken represents an identifier token
type IdentToken struct {
	Token
}

// Parses tokens from a file and returns a list of tokens
func ParseTokens(r io.Reader) ([]Token, error) {
	tokens := make([]Token, 0)
	token := make([]byte, 256)
	for {
		_, err := r.Read(token)
		if err != nil {
			if err == io.EOF {
				break
			}
			return nil, err
		}
		tokenStr := string(token)
		tokens = append(tokens, Token{Kind: "ident", Value: tokenStr})
	}
	return tokens, nil
}