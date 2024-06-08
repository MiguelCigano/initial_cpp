class nComplejo{
    private:
        // Atributos de clase.
        double real;
        double img;

        // Los metodos se implementan a parte.

    public:
        // Los siguiente métodos forman parte de la interfaz:
        void asignaReal(double r);
        void asignaImg(double i);
        double parteReal(); // método para leer la parte real.
        double parteImg();  // método para leer la parte imaginaria.
        void suma(const nComplejo &a, const nComplejo &b);
};   
  

// Los atributos "private" forman parte de la implementación y no es posible acceder a ellos. Desde afuera de la clase.
// Forman parte de la implementación

// Solo se puede acceder a ellos en la implementación de los métodos de la clase.


/************************************************************************************************************************/

// Los métodos que están en la parte pública (interfaz) describen el comportamiento de la clase.
// Lo anterior se refiere a las operaciones que podemos aplicar a algún objeto de la clase nComplejo.

/************************************************************************************************************************/

// La implementación de los métodos de una clase se realiza fuera de la construcción de la clase:




