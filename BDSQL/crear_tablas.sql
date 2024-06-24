create database ejemplo_trabajo;
use ejemplo_trabajo;
create table usuarios (
Id_usuario INT UNSIGNED AUTO_INCREMENT,
Dni int unsigned not null,
Departamento varchar (40)  NOT NULL,
Apellido varchar (40)  NOT NULL,
Segundo_apellido varchar(40),
Nombre varchar (40) NOT NULL,
Segundo_nombre varchar(40),
Id_tarjeta bigint unsigned NOT NULL,
Password_keyb int unsigned NOT NULL,
primary key(Id_usuario)
);


CREATE TABLE log (
    Id_usuario INT UNSIGNED AUTO_INCREMENT,
    Sector VARCHAR(40),
    Id_tarjeta bigINT UNSIGNED, 
    Password_keyb INT UNSIGNED,
    Hora DATETIME NOT NULL  ,                     
    Fecha DATE NOT NULL  , 
    PRIMARY KEY (Id_usuario)
);|