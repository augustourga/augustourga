/*
 * cpu.h
 *
 *  Created on: 11/09/2014
 *      Author: utnso
 */

#ifndef CPU_H_
#define CPU_H_

#include <commons/bitarray.h>
#include <commons/config.h>

typedef struct{
	int A,B,C,D,E;
} t_reg_prog;

typedef struct{
	int pid,tid,m,tam;
	char km;
	unsigned int p,x,s;
	t_reg_prog* reg;
} t_TCB;

typedef struct{
	int PUERTO_MSP;
	int PUERTO_KERNEL;
	int RETARDO;
	char* IP_KERNEL;
	char* IP_MSP;

} t_config_cpu;

typedef struct{

	char* params;
	t_bitarray* instr;

} t_instr_params;



typedef struct{
	int sock_kernel,sock_msp;
}t_conexion_cpu;

t_conexion_cpu* levantarConexion(t_config_cpu*);
t_config_cpu*  levantarConfiguracion();

#endif /* CPU_H_ */
