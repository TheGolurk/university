package models

type Student struct {
	ID        int    `json:"id,omitempty"`
	Nombre    string `json:"nombre,omitempty"`
	Matricula string `json:"matricula,omitempty"`
	Carrera   string `json:"carrera,omitempty"`
	Edad      int    `json:"edad,omitempty"`
}

type StudentsAssistance struct {
	Nombre    string `json:"nombre,omitempty"`
	Carrera   string `json:"carrera,omitempty"`
	Matricula string `json:"matricula,omitempty"`
	Fecha     string `json:"fecha,omitempty"`
}
