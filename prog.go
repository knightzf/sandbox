package delete

import "fmt"
import "github.com/gorilla/mux"

type Vertex struct {
	X int
	Y int
}

type A struct {
	a string
}

func NewPetsApiController() Router {
	return &A{"aaa"}
}

func main() {
	x := NewPetsApiController()
}
