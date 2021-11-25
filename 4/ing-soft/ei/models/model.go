package models

type Student struct {
	ID        int    `json:"id,omitempty"`
	Nombre    string `json:"nombre,omitempty"`
	Matricula string `json:"matricula,omitempty"`
	Carrera   string `json:"carrera,omitempty"`
	Edad      int    `json:"edad,omitempty"`
}
