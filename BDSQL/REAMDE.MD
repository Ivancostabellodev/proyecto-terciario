## ejemplo_trabajo

en esta Base de datos usamos 2 tablas las cuales son :

### usuarios

Id_usuario  | Dni | Departamento | Apellido | Segundo_apellido | Nombre | Segundo_nombre | Id_tarjeta | Password_keyb |

Esta vendria siendo la primera tabla. En esta encontramos varios campos de los cuales se pueden resaltar `Id_usuario` el cual es un campo que no hay que completar debido a que es nuestra clave primaria y es auto incremental, ademas encontramos campos como `Dni`, `Departamento`, `Apellido`, `Nombre` y los mas importantes `Id_tarjeta` y `Password_keyb` el cual no pueden quedar vacios ya que son los datos personales de las personas que ingresan con su tarjeta o contraseña previamente definida. Luego tambien estan los campos `Segundo_apellido` y `Segundo_nombre` los cuales si son posibles dejarlos nullos porque no toda persona cuenta con estos datos. Ademas es desde los campos de esta tabla donde el node-red ejecuta un SELECT donde busca los datos de la tarjeta o el teclado ingresados que coincidan con los ejecutados en el ESP

### Log

Id_usuario  | Sector | Id_tarjeta | Password_keyb | Hora | Fecha | 

Esta tabla es en la que se registran todos los movimentos que ocurren. Ya sea una tarjeta valida, una invalida, un password valido o un password invalido ademas de describir la hora y dia en que ocurrieron y en que sector.

### Usando el ejemplo

Id_usuario  | Dni | Departamento | Apellido | Segundo_apellido | Nombre | Segundo_nombre | Id_tarjeta | Password_keyb |
------------| ------------|------------|------------|------------|------------|------------|------------|------------|258648121 | A| Gutierrez | Null | Albreto | Maria | 897312548387 | 444 

Si ejecutamos el archivo `probar_BD.sql` nos deveria quedar la tabla usuarios asi, obviamente que los campos `Dni`, `Departamento`, `Apellido`, `Segundo_apellido`, `Nombre`, `
