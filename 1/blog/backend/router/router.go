package router

import (
	"net/http"
	"strconv"
	"strings"
)

// Router is a func to server the routes of our backend
func Router(w http.ResponseWriter, r *http.Request) {
	var h http.Handler

	path := r.URL.Path
	switch {
	case match(path, "/"):
		h = get(home)
	default:
		http.NotFound(w, r)
		return
	}
	h.ServeHTTP(w, r)
}

func match(path, pattern string, vars ...interface{}) bool {
	for ; pattern != "" && path != ""; pattern = pattern[1:] {
		switch pattern[0] {
		case '+':
			// '+' matches till next slash in path
			slash := strings.IndexByte(path, '/')
			if slash < 0 {
				slash = len(path)
			}
			segment := path[:slash]
			path = path[slash:]
			switch p := vars[0].(type) {
			case *string:
				*p = segment
			case *int:
				n, err := strconv.Atoi(segment)
				if err != nil || n < 0 {
					return false
				}
				*p = n
			default:
				panic("vars must be *string or *int")
			}
			vars = vars[1:]
		case path[0]:
			// non-'+' pattern byte must match path byte
			path = path[1:]
		default:
			return false
		}
	}
	return path == "" && pattern == ""
}
