#include <commons/bitarray.h>
#include <commons/config.h>
#include "CPU.h"
#include "interpreter.h"


t_reg_prog* reg_prog=

//Carga en el registro, el numero dado
void load( char reg,int num){
 escribirReg(reg_instr,reg,num);
};

//Obtiene el valor de memoria apuntado por el segundo registro. El valor
//obtenido lo asigna en el primer registro

void getm(char reg,char reg2){
int aux;
aux= leerReg(reg_instr,reg2);
escribirReg(reg_instr,reg,aux);


}

// Pone tantos bytes desde el segundo registro, hacia la memoria apuntada
// por el primer registro.

void setm(num,reg,reg2){

}

//copia el valor del segundo registro hacia el primero
void movr(char reg,char reg2){
	reg=reg2;
}

//suma el primer registro con el segundo. El resultado se almacena en el registro A
void addr(char reg, char reg2){
 int aux,aux2;
 aux = leerReg(reg_instr,reg);
 aux2 = leerReg(reg_instr,reg2);
	reg_instr-> 'A' = aux + aux2;
}

//resta el primer registro con el segundo. El resultado se almacena en A

void subr(char reg, char reg2){
	 int aux,aux2;
	 aux = leerReg(reg_instr,reg);
	 aux2 = leerReg(reg_instr,reg2);
		reg_instr-> 'A' = aux - aux2;
	}

