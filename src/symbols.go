package symbols

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

// Represents a token stream
type TokenStream struct {
	tokens []string
	len    int64
	pos    int64
}

type ParseError struct{}

func (self ParseError) Error() string {
	return "Cannot parse."
}

// Skip spaces in a token stream
func (self *TokenStream) SkipSpaceTokens() error {
	return ParseError{}
}
