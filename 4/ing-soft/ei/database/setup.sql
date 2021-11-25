CREATE TABLE ALUMNO
(
    ID        SERIAL PRIMARY KEY,
    Nombre    VARCHAR(50) NOT NULL,
    Matricula VARCHAR(50) NOT NULL,
    Carrera   VARCHAR(50) NOT NULL,
    Edad      INTEGER     NOT NULL
);

