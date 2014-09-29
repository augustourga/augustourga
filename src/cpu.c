/*
 * cpu.c
 *
 *  Created on: 11/09/2014
 *      Author: utnso
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cpu.h"
//#include "cpu_instrucciones.h"
#include<sockets.h>
#define PATH "/home/utnso/workspace/CPU_CONFIG.config"


//Consideraciones:
//1) Si ocurriese un segmentation fault se cancelara la ejecucion, se notificara al Kernel
// y se solicitara el proximo TCB
//2) Solo cuando el flag KM este activado se podra ejecutar instrucciones protegidas.
//3) Atencion de system calls?

int main(){

  t_config_cpu* config_cpu =  levantarConfiguracion();


 t_conexion_cpu* conexion_cpu = levantarConexion(config_cpu);


 //testeando
 printf("la variable %s %s %d %d %d"
		,config_cpu->IP_KERNEL
		,config_cpu->IP_MSP,
		config_cpu->PUERTO_KERNEL,
		config_cpu->PUERTO_MSP,
		config_cpu->RETARDO);

char* palabra =strdup( "hola");

//ej serializar char* bloque =  serializar(t_tcb);
 send(conexion_cpu->sock_kernel,palabra,strlen(palabra),0);

return 0;
}


//El proceso levantarConfiguracion recive el archivo de configuracion y carga
//los datos en un registro, llamese reg_CPU, el cual luego recivira levantarConfiguracion()

 t_config_cpu*  levantarConfiguracion(){

	t_config_cpu* reg_config = malloc(sizeof(t_config_cpu));


	t_config* archivo_config = config_create(PATH);


	reg_config->IP_KERNEL  = strdup(config_get_string_value(archivo_config, "IP_KERNEL"));
	reg_config->IP_MSP = strdup(config_get_string_value(archivo_config, "IP_MSP"));
	reg_config->PUERTO_KERNEL = config_get_int_value(archivo_config, "PUERTO_KERNEL");
	reg_config->PUERTO_MSP = config_get_int_value(archivo_config, "PUERTO_MSP");
	reg_config->RETARDO =  config_get_int_value(archivo_config, "RETARDO");

	config_destroy(archivo_config);

	return reg_config;
}







//El proceso levantarConexion intentara conectarse con la Msp y con el Kernel.
//en caso de no poder conectarse abortara la ejecucion y lo informa
//por pantalla y por log.

t_conexion_cpu* levantarConexion(t_config_cpu* config_cpu){

	t_conexion_cpu* reg_conexion = malloc(sizeof(t_conexion_cpu));

     reg_conexion->sock_kernel = obtener_socket();
    // reg_conexion->sock_msp =    obtener_socket();

	conectar_socket(config_cpu->PUERTO_KERNEL,config_cpu->IP_KERNEL,reg_conexion->sock_kernel);
	 puts("conectado al Kernel");

//	conectar_socket(config_cpu->PUERTO_MSP,config_cpu->IP_MSP,reg_conexion->sock_msp);
	// puts("conectado a la MSP");

	 return reg_conexion;
}
/*


//Una vez conectado le solicitara al kernel el TCB del proximo hilo a ejecutar
//,comenzara a ejecutar la operacion de ESO. Tambien recive el Quantum.

t_TCB* obtenerTcb(reg_conexion){

 int mensaje = 1;
send(conexion_cpu->sock_kernel,&mensaje,4,0 );

   recv(conexion_cpu->sock_kernel,tcb,tamanioTcb);
};

// Si el Quantum es distinto de cero o si KM esta activado.

// El proceso interpretarInstruccion() ademas de convertir la intruccion en BESO
// tambien debe ejecutar la operacion correspondiente. Tambien deberia actualizar
//el registro TCB e incrementar el puntero de instruccion.
//NOTA: puede dividirse en interpretarInstruccion() y ejecutarInstruccion.

void interpretarInstruccion();


//Una vez que el Quantum es cero.

//enviarTcb() le envia el registro actualizado al Kernel.
void enviarTcb();

// se ejecuta nuevamente  y vuelve al ciclo
void obtenerTcb();

//Este proceso, de existir, deberia cerrar las conexiones con el Kernel y con la Msp.
void cerrarConexiones();

void liberarMemoria();





*/
