# -*- coding: utf-8 -*-
class Cola:
    """ Representa una cola con operaciones de encolar, desencolar y
        verificar si está vacía. """
 
    def __init__(self):
        """ Crea una cola vacía. """
        # La cola vacía se representa con una lista vacía
        self.items=[]

    def encolar(self, x):
        """ Agrega el elemento x a la cola. """
        # Encolar es agregar al final de la cola.
        self.items.append(x)

    def desencolar(self):
        """ Devuelve el elemento inicial y lo elimina de la cola.
            Si la cola está vacía levanta una excepción. """
        try:
            return self.items.pop(0)
        except IndexError:
            raise ValueError("La cola está vacía")

    def es_vacia(self):
        """ Devuelve True si la lista está vacía, False si no. """
        return self.items == []

class Ips:
    
    cardiologia= Cola()
    pediatria=Cola()
    geriatria=Cola()
    oncologia=Cola()
    
class Persona:

    def __init__(self,nombre,edad):
        
        self.nombre=nombre
        self.edad=edad
        

if __name__ == "__main__":
    ips=Ips()
    while(True):
        nombrePersona=raw_input("Nombre del paciente : ")
        edadPersona=raw_input("Edad paciente : ")
        persona=Persona(nombrePersona,edadPersona)
        especialidad=int(raw_input("Ingrese especialidad : \n 1. cardiologia \n 2. pediatria \n 3. geriatria \n 4. oncologia \n 0.terminar \n"))
        if(especialidad==1):
            ips.cardiologia.encolar(persona)
        elif(especialidad==2):
            ips.pediatria.encolar(persona)
        elif(especialidad==3):
            ips.geriatria.encolar(persona)
        elif(especialidad==4):
            ips.geriatria.encolar(persona)
        elif(especialidad==0):
            break
        else:
            print("indice invalido")
    
        
    
   
