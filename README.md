# Proyecto-Planilla-Hospital---Kendall-Porras-Fern-ndez-

# Sistema de Gestión de Planilla Hospitalaria

Aplicación de consola desarrollada en **C++** bajo el paradigma de **Programación Orientada a Objetos (POO)** para el curso **EIF201 Programación I**. Permite administrar el personal médico y administrativo de un hospital, organizar departamentos, calcular salarios brutos y netos con las cargas sociales e impuesto sobre la renta vigentes en Costa Rica, y mantener persistencia automática en archivos de texto plano (`.txt`).

---

## Estudiante

* **Nombre:** Kendall Porras Fernández
* **Cédula:** 402770666
* **Curso:** EIF201 — Programación I

---

## Arquitectura y Principios SOLID

El proyecto consta de **18 clases** organizadas en archivos `.h` y `.cpp` con guardas de inclusión (`#ifndef`, `#define`, `#endif`), separación estricta entre interfaz de usuario y lógica de negocio, y gestión manual de memoria dinámica (`new` / `delete`):

* **SRP (Principio de Responsabilidad Única):** `InterfazMenu` gestiona únicamente la entrada/salida por consola (`cin`/`cout`), `GestorPlanilla` centraliza las reglas de negocio y la persistencia, y las clases del dominio (`Empleado`, `Departamento`, `Planilla`, `ComprobantePlanilla`) modelan los datos sin lógica de consola.
* **OCP (Principio Abierto/Cerrado):** La jerarquía de `Empleado` permite incorporar nuevas categorías de personal hospitalario sobrescribiendo `calcularSalarioBruto()` sin alterar el cálculo de planillas ni los comprobantes.
* **LSP (Principio de Sustitución de Liskov):** Las clases derivadas (`Medico`, `Enfermero`, `Administrativo`) pueden sustituir a `Empleado*` de forma transparente dentro de `ListaEmpleados`, `Departamento` y `ComprobantePlanilla`.
* **DIP (Inversión de Dependencias):** Los módulos de cálculo salarial y listas dependen de la abstracción `Empleado` en lugar de depender de implementaciones concretas.

### Relaciones UML Implementadas

* **Herencia:** `Medico`, `Enfermero` y `Administrativo` heredan de la clase abstracta `Empleado`.
* **Composición:** `InterfazMenu` compone a `GestorPlanilla`; `GestorPlanilla` compone a las tres listas maestras (`ListaEmpleados`, `ListaDepartamentos`, `ListaPlanillas`); `Departamento` compone a su `ListaEmpleados` interna; `Planilla` compone a `ListaComprobantes`; y cada lista compone a sus respectivos nodos.
* **Agregación:** Los nodos (`NodoEmpleado`, `NodoDepartamento`, `NodoPlanilla`, `NodoComprobante`) mantienen referencias a las entidades sin destruir los objetos compartidos al liberarse el nodo.
* **Asociación Unidireccional:** `ComprobantePlanilla` mantiene una referencia hacia `Empleado` para calcular su salario bruto polimórficamente.

---

## Fórmulas y Cálculos Salariales (CCSS — Costa Rica)

1. **Salario Bruto (Polimórfico):**
   * **Médico:** Salario base + pago de horas extra (1.5x) + recargo por guardias nocturnas.
   * **Enfermero:** Salario base + pago de horas extra (1.5x) + recargo del **33%** por turnos nocturnos.
   * **Administrativo:** Salario base + pago de horas extra (1.5x) + bonificación fija por puesto.
2. **Deducciones de Ley:**
   * **Cargas Sociales (CCSS):** `10.83%` sobre el salario bruto.
   * **Impuesto sobre la Renta (Tramos Costa Rica):**
     * Hasta ¢918,000: `0%`
     * Exceso de ¢918,000 hasta ¢1,347,000: `10%`
     * Exceso de ¢1,347,000 hasta ¢2,364,000: `15%`
     * Exceso de ¢2,364,000 hasta ¢4,727,000: `20%`
     * Exceso mayor a ¢4,727,000: `25%`
3. **Salario Neto:**
   $$\text{Salario Neto} = \text{Salario Bruto} - \text{Deducción CCSS} - \text{Impuesto de Renta}$$

---

## Instrucciones de Compilación (ZinjaI)

1. Abrir el archivo del proyecto (`.zpr`) en **ZinjaI**.
2. Verificar en el árbol izquierdo del proyecto que todos los archivos de cabecera (`.h`) y de implementación (`.cpp`) estén cargados.
3. Presionar **F9** (o hacer clic en *Ejecutar $\rightarrow$ Compilar y Ejecutar*) para compilar y levantar la consola.

---

## Guía de Uso

Al ejecutar la aplicación, el sistema carga automáticamente los datos almacenados en `empleados.txt`, `departamentos.txt` y `planilla.txt`:

1. **Gestión de Empleados:** Permite registrar médicos, enfermeros y administrativos, consultar sus datos por ID, listar el personal activo y eliminar registros.
2. **Gestión de Departamentos:** Permite crear unidades hospitalarias, asignar empleados existentes a un departamento, consultar su personal asignado y eliminar departamentos.
3. **Gestión de Planillas y Comprobantes:** Permite abrir una planilla por periodo, generar comprobantes individuales o una planilla general para todos los empleados registrados, y procesar el pago para cerrar la planilla.
4. **Guardar y Salir:** Serializa todos los cambios en los archivos `.txt` y libera la memoria dinámica antes de finalizar.
