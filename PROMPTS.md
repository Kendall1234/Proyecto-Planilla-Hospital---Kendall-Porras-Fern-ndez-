# Documentación de Prompts Utilizados

Registro cronológico y literal de los prompts empleados para la generación de las clases del **Sistema de Gestión de Planilla Hospitalaria** en C++.

---

### Prompt de la clase empleado:

"Quiero que hagas una clase llamada Empleado la cual tenga 5 atributos privados: id tipo string, nombre de tipo string, salarioBase de tipo double, turno de tipo string y horasExtra de tipo double.

Con esto quiero que el constructor no tenga parámetros, que tenga destructor, que tenga los sets y gets de cada uno de los atributos, y como último quiero que agregues los métodos: calcularSalarioBruto (que sea virtual puro, o sea = 0), calcularSalarioNeto, un método toString, el método llamado autoGuardar de tipo void que tenga un parámetro de tipo ofstream& llamado estFile. Y el último método que sea estático llamado autoLeer de tipo Empleado* con parámetro ifstream& llamado estFile también."

---

### Prompt de la clase Medico:

"Quiero que hagas una clase llamada Medico que herede de la clase Empleado. Esta clase debe tener 2 atributos privados extras: especialidad de tipo string y guardiasNocturnas de tipo int.

Con esto quiero que el constructor no tenga parámetros, que tenga un constructor con parámetros (que reciba los 5 del padre más la especialidad y las guardias), que tenga destructor, que tenga los sets y gets de cada uno de esos 2 atributos nuevos, y como último quiero que agregues los métodos que hereda del padre pero sobrescritos: calcularSalarioBruto (que este sí tiene lógica real con las guardias), un método toString (que llame al del padre y agregue los datos extra), el método autoGuardar (que llame al del padre y guarde los datos extra), y el último método que sea estático llamado autoLeer de tipo Medico con parámetro ifstream& llamado estFile (que lea los 5 datos del padre más los 2 extra y devuelva un new Medico)."

---

### prompt de la clase administrativo:

"Quiero que hagas una clase llamada Administrativo que herede de la clase Empleado. Esta clase debe tener 2 atributos privados extras: puesto de tipo string y bonificacionFija de tipo double.

Con esto quiero que el constructor no tenga parámetros, que tenga un constructor con parámetros (que reciba los 5 del padre más el puesto y la bonificación), que tenga destructor, que tenga los sets y gets de cada uno de esos 2 atributos nuevos, y como último quiero que agregues los métodos que hereda del padre pero sobrescritos: calcularSalarioBruto (que este sí tiene lógica real sumando la bonificación fija), un método toString (que llame al del padre y agregue los datos extra), el método autoGuardar (que llame al del padre y guarde los datos extra), y el último método que sea estático llamado autoLeer de tipo Administrativo con parámetro ifstream& llamado estFile (que lea los 5 datos del padre más los 2 extra y devuelva un new Administrativo)."

---

### prompt de la clase Enfermero:

"Quiero que hagas una clase llamada Enfermero que herede de la clase Empleado. Esta clase debe tener 2 atributos privados extras: areaAsignada de tipo string y turnosNocturnos de tipo int.

Con esto quiero que el constructor no tenga parámetros, que tenga un constructor con parámetros (que reciba los 5 del padre más el areaAsignada y los turnosNocturnos), que tenga destructor, que tenga los sets y gets de cada uno de esos 2 atributos nuevos, y como último quiero que agregues los métodos que hereda del padre pero sobrescritos: calcularSalarioBruto (que este sí tiene lógica real sumando el recargo por turnos nocturnos del 33% de la CCSS), un método toString (que llame al del padre y agregue los datos extra), el método autoGuardar (que llame al del padre y guarde los datos extra), y el último método que sea estático llamado autoLeer de tipo Enfermero con parámetro ifstream& llamado estFile (que lea los 5 datos del padre más los 2 extra y devuelva un new Enfermero)."

---

### prompt de la clase NodoEmpleado:

"Quiero que hagas una clase llamada NodoEmpleado. Esta clase debe tener 2 atributos privados: dato de tipo Empleado (puntero a Empleado) y sig de tipo NodoEmpleado* (puntero al siguiente nodo).*

Con esto quiero que el constructor reciba un parámetro de tipo Empleado llamado dato, que guarde ese dato en el atributo y que ponga sig en NULL. También quiero que tenga un destructor, que tenga los sets y gets de cada uno de los 2 atributos (dato y sig)."

---

### prompt de la clase ListaEmpleados

"Quiero que hagas una clase llamada ListaEmpleados. Esta clase debe tener 3 atributos privados, todos de tipo NodoEmpleado: cabeza, actual y cola. El constructor debe poner los tres en NULL. El destructor debe recorrer la lista con un while y hacer delete de cada nodo (para no dejar fugas de memoria).*

Con esto quiero que agregues los siguientes métodos públicos: un método vacio() que devuelva bool y diga si la lista está vacía (cabeza == NULL); un método contar() que devuelva int y cuente los nodos; un método insertarEmpleado(Empleado dato) de tipo void que cree un NodoEmpleado y lo inserte al final de la lista usando la cola; un método eliminarEmpleado(string id) que devuelva string y elimine el nodo que tenga ese id; un método modificarEmpleado(string id, Empleado* dato) que devuelva string y reemplace el dato del nodo con ese id; un método consultarEmpleado(string id) que devuelva string y muestre el toString del empleado con ese id; un método listarEmpleados() que devuelva string y concatene el toString de todos los empleados; un método ordenarEmpleados() de tipo void que ordene la lista por salario base usando el método burbuja; y un método insertarPosicion(int posicion, Empleado* dato) que devuelva string e inserte un empleado en una posición específica."*

(Nota: El prompt se adjuntó junto a un proyecto de ejemplo de cómo se estructuraba el código por dentro. Solo ordené con el prompt el orden que necesito y para tener más control de lo que la IA va a generar).

---

### prompt de la clase Departamento

"Quiero que hagas una clase llamada Departamento. Esta clase debe tener 4 atributos privados: idDepartamento de tipo string (puntero a string), nombre de tipo string (puntero a string), ubicacion de tipo string (puntero a string) y empleados de tipo ListaEmpleados* (puntero a ListaEmpleados para manejar la relación de agregación).

Con esto quiero que el constructor no tenga parámetros (inicializando los punteros e instanciando una nueva ListaEmpleados), que tenga un constructor con parámetros (que reciba idDepartamento, nombre y ubicacion e inicialice también la lista vacía), que tenga destructor (que libere la memoria de los atributos y de la lista, sin eliminar los objetos Empleado porque es agregación), que tenga los sets y gets de idDepartamento, nombre y ubicacion, y que agregue los métodos agregarEmpleado(Empleado* emp) que inserte el empleado en la lista interna y getEmpleados() que devuelva el puntero a ListaEmpleados. Como último quiero que agregues un método toString() que muestre la información del departamento y sus empleados, el método autoGuardar de tipo void con parámetro ofstream& llamado estFile, y el método estático autoLeer de tipo Departamento* con parámetro ifstream& llamado estFile."

---

### prompt de la clase NodoDepartamento:

"Quiero que hagas una clase llamada NodoDepartamento. Esta clase debe tener 2 atributos privados: dato de tipo Departamento* (puntero a Departamento) y sig de tipo NodoDepartamento* (puntero al siguiente nodo).

Con esto quiero que el constructor reciba un parámetro de tipo Departamento* llamado dato, que guarde ese dato en el atributo y que ponga sig en NULL. También quiero que tenga un destructor (que no borre el dato porque la relación es de agregación), y que tenga los sets y gets de cada uno de los 2 atributos (dato y sig)."

---

### prompt de la clase ListaDepartamento

"Quiero que hagas una clase llamada ListaDepartamentos. Esta clase debe tener 3 atributos privados, todos de tipo NodoDepartamento*: cabeza, actual y cola. El constructor debe poner los tres en NULL. El destructor debe recorrer la lista con un while y hacer delete de cada nodo para no dejar fugas de memoria.

Con esto quiero que agregues los siguientes métodos públicos: un método vacio() que devuelva bool y diga si la lista está vacía (cabeza == NULL); un método contar() que devuelva int y cuente los nodos; un método insertarDepartamento(Departamento* dato) de tipo void que cree un NodoDepartamento y lo inserte al final de la lista usando la cola; un método eliminarDepartamento(string id) que devuelva string y elimine el nodo que tenga ese id; un método modificarDepartamento(string id, Departamento* dato) que devuelva string y reemplace el dato del nodo con ese id; un método consultarDepartamento(string id) que devuelva string y muestre el toString del departamento con ese id; un método listarDepartamentos() que devuelva string y concatene el toString de todos los departamentos; un método ordenarDepartamentos() de tipo void que ordene la lista por nombre usando el método burbuja; un método insertarPosicion(int posicion, Departamento* dato) que devuelva string e inserte un departamento en una posición específica; un método buscarPorId(string id) que devuelva Departamento* y retorne el puntero al departamento con ese id o NULL si no existe; y un método getCabeza() que devuelva NodoDepartamento*."

---

### prompt para la clase Comprobante planilla:

Quiero que hagas una clase llamada ComprobantePlanilla. Esta clase debe tener 8 atributos privados, todos como punteros: idComprobante de tipo string*, fechaPago de tipo string*, empleado de tipo Empleado* (relación de asociación, por lo que el destructor no debe borrarlo), salarioBruto de tipo double*, deduccionCCSS de tipo double*, impuestoRenta de tipo double*, salarioNeto de tipo double*, y pagado de tipo bool*.

Con esto quiero que hagas un constructor por defecto que inicialice los punteros con valores por defecto (pagado en false y los montos en 0.0, empleado en NULL), y un constructor con parámetros que reciba string* idComprobante, string* fechaPago y Empleado* empleado, inicialice pagado en false y llame a calcularMontos() para calcular automáticamente los montos salariales. También debe tener su destructor que libere con delete todos los punteros propios excepto empleado, y los respectivos sets y gets.

Además, agrega los métodos públicos: calcularDeduccionCCSS() que retorne el 10.83% del salario bruto; calcularImpuestoRenta() que aplique los tramos de impuesto sobre la renta de Costa Rica (0% hasta 918,000; 10% sobre el exceso hasta 1,347,000; 15% sobre el exceso hasta 2,364,000; 20% sobre el exceso hasta 4,727,000; y 25% sobre el exceso mayor a 4,727,000); calcularMontos() que obtenga el salario bruto polimórficamente desde el empleado y actualice salarioBruto, deduccionCCSS, impuestoRenta y salarioNeto; procesarPago() que cambie pagado a true; y toString() que devuelva un string con el desglose completo del comprobante.

---

### prompt para la clase NodoComprobante:

Quiero que hagas una clase llamada NodoComprobante. Esta clase debe tener 2 atributos privados: dato de tipo ComprobantePlanilla* y sig de tipo NodoComprobante*.

Con esto quiero que el constructor reciba un parámetro de tipo ComprobantePlanilla* llamado dato, que guarde ese dato en el atributo y que ponga sig en NULL. También quiero que tenga un destructor (que no borre dato porque la relación es de agregación con el nodo), y que tenga los sets y gets de cada uno de los 2 atributos (dato y sig).

---

### prompt para la clase ListaComprobantes:

Quiero que hagas una clase llamada ListaComprobantes. Esta clase debe tener 3 atributos privados: cabeza de tipo NodoComprobante*, actual de tipo NodoComprobante* y cola de tipo NodoComprobante*.

Con esto quiero que tenga un constructor por defecto que inicialice los tres punteros en NULL, y un destructor que recorra toda la lista liberando con delete tanto cada ComprobantePlanilla* contenido en los nodos como cada NodoComprobante* (relación de composición).

Además, agrega los métodos públicos siguiendo el mismo estándar de las listas del proyecto: vacio(), contar(), insertarComprobante(ComprobantePlanilla* dato), eliminarComprobante(string id), modificarComprobante(string id, ComprobantePlanilla* dato), consultarComprobante(string id), listarComprobantes(), ordenarComprobantes() (ordenando por salario neto), insertarPosicion(int posicion, ComprobantePlanilla* dato), y los métodos de cálculo calcularTotalBruto(), calcularTotalDeducciones() y calcularTotalNeto().

---

### prompt para la clase Planilla:

Quiero que hagas una clase llamada Planilla. Esta clase debe tener 8 atributos privados, todos como punteros: idPlanilla de tipo string*, periodo de tipo string*, fechaGeneracion de tipo string*, comprobantes de tipo ListaComprobantes* (relación de composición), totalBruto de tipo double*, totalDeducciones de tipo double*, totalNeto de tipo double*, y cerrada de tipo bool*.

Con esto quiero que tenga un constructor por defecto que inicialice todos los punteros con valores por defecto (instanciando una nueva ListaComprobantes, montos en 0.0 y cerrada en false), y un constructor con parámetros que reciba string* idPlanilla, string* periodo y string* fechaGeneracion. También debe tener su destructor que libere con delete todos los punteros incluyendo comprobantes, y los respectivos sets y gets.

Además, agrega los métodos públicos: agregarComprobante(ComprobantePlanilla* comprobante) que inserte el comprobante en comprobantes (si la planilla no está cerrada) y llame a actualizarTotales(); actualizarTotales() que recalcule totalBruto, totalDeducciones y totalNeto desde ListaComprobantes; cerrarPlanilla() que marque cerrada en true y procese el pago de los comprobantes; y toString() que devuelva el resumen completo de la planilla y sus comprobantes.

---

### prompt para la clase NodoPlanilla:

Quiero que hagas una clase llamada NodoPlanilla. Esta clase debe tener 2 atributos privados: dato de tipo Planilla* y sig de tipo NodoPlanilla*.

Con esto quiero que el constructor reciba un parámetro de tipo Planilla* llamado dato, que guarde ese dato en el atributo y que ponga sig en NULL. También quiero que tenga un destructor (que no borre dato porque la relación es de agregación con el nodo), y que tenga los sets y gets de cada uno de los 2 atributos (dato y sig).

---

### prompt para la clase ListaPlanillas:

Quiero que hagas una clase llamada ListaPlanillas. Esta clase debe tener 3 atributos privados: cabeza de tipo NodoPlanilla*, actual de tipo NodoPlanilla* y cola de tipo NodoPlanilla*.

Con esto quiero que tenga un constructor por defecto que inicialice los tres punteros en NULL, y un destructor que recorra toda la lista liberando con delete tanto cada Planilla* contenido en los nodos como cada NodoPlanilla* (relación de composición).

Además, agrega los métodos públicos siguiendo el mismo estándar de las listas del proyecto: vacio(), contar(), insertarPlanilla(Planilla* dato), buscarPorId(string id), eliminarPlanilla(string id), modificarPlanilla(string id, Planilla* dato), consultarPlanilla(string id), listarPlanillas(), ordenarPlanillas() (ordenando por total neto), insertarPosicion(int posicion, Planilla* dato) y getCabeza().

---

### prompt para la clase GestorPLanilla

"Quiero que hagas una clase llamada GestorPlanilla. Esta clase debe tener 3 atributos privados, todos como punteros: departamentos de tipo ListaDepartamentos*, empleados de tipo ListaEmpleados* y planillas de tipo ListaPlanillas* (relaciones de composición).

Con esto quiero que tenga un constructor por defecto que instancie las tres listas vacías con new, y un destructor que libere con delete los objetos Departamento y Empleado contenidos en sus listas y luego haga delete de las tres listas para no dejar fugas de memoria.

Además, agrega los métodos públicos de persistencia en archivos de texto: cargarDatos() y guardarDatos(), junto con cargarDepartamentos(), guardarDepartamentos(), cargarEmpleados(), guardarEmpleados(), cargarPlanillas() y guardarPlanillas() (que lean y escriban en departamentos.txt, empleados.txt y planilla.txt usando polimorfismo con dynamic_cast para identificar Medico, Enfermero y Administrativo). Y agrega los métodos públicos de lógica de negocio que devuelvan string con mensajes de confirmación o error (sin usar cin ni cout): registrarDepartamento, asignarEmpleadoADepartamento, consultarDepartamento, listarDepartamentos, eliminarDepartamento, registrarMedico, registrarEnfermero, registrarAdministrativo, consultarEmpleado, listarEmpleados, eliminarEmpleado, crearPlanilla, generarComprobanteIndividual, generarPlanillaGeneral, procesarPagoPlanilla, consultarPlanilla y listarPlanillas."

---

### prompt para la clase InterfazMenu:

"Quiero que hagas una clase llamada InterfazMenu. Esta clase debe tener 1 atributo privado: gestor de tipo GestorPlanilla* (relación de composición).

Con esto quiero que tenga un constructor por defecto que instancie gestor con new GestorPlanilla(), y un destructor que libere con delete el puntero gestor para no dejar fugas de memoria.

Además, agrega los métodos públicos de tipo void que manejen toda la interacción por consola con el usuario (cout y cin): iniciar() (que llame a cargarDatos() al arrancar, ejecute un ciclo do-while con el menú principal y llame a guardarDatos() al salir), mostrarMenuPrincipal(), menuEmpleados(), menuDepartamentos() y menuPlanillas() (todos delegando las operaciones y validaciones al puntero gestor)."
