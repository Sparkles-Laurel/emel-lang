package emellang

import (
	"fmt"
	"io"
)

// Represents a token stream
type TokenStream struct {
	tokens []string
	len    int64
	pos    int64
}

type ParseError struct{
	ln int64
	chr int64
	expr string
}

func (perr ParseError) Error() string {
	return fmt.Sprintf("ln %v, col %v - EML-E0000009: unexpected \"%v\"",perr.ln, perr.chr, perr.expr)
}

// Skip spaces in a token stream
func (tkstr *TokenStream) SkipSpaceTokens() error {
	for tkstr.pos < tkstr.len && tkstr.tokens[tkstr.pos] == " " {
		tkstr.pos++
	}
	return nil
}

// Load tokens from a reader
func (tkstr *TokenStream) LoadTokens(r io.Reader) error {
	token := make([]byte, 256)
	for {
		_, err := r.Read(token)
		if err != nil {
			if err == io.EOF {
				break
			}
			return err
		}
		tokenStr := string(token)
		tkstr.tokens = append(tkstr.tokens, tokenStr)
		
	}
	tkstr.pos = 0
	tkstr.len = 0
	// sum all the lengths of the tokens in tkstr.len
	for _, token := range tkstr.tokens {
		tkstr.len += int64(len(token))
	}
	return nil
}