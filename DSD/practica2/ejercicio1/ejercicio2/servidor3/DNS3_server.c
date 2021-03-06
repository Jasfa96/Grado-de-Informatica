/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "DNS3.h"

int util=0;
char valores[50][3][255];
char redusada[10]="Red3";

char **
introducir_1_svc(nombre arg1, red arg2, ip arg3,  struct svc_req *rqstp)
{
	static char * result;
 	if(strcmp(arg2,redusada)==0){
		strcpy(valores[util][0],arg1);
 		strcpy(valores[util][1],arg2);
 		strcpy(valores[util][2],arg3);
 		util++;
 		printf("%s\n", "HA SIDO INTRODUCIDO");
		result="HA SIDO INTRODUCIDO";
 	}
 	else{
 		printf("%s\n", "ESTA ES LA Red3, INTRODUCE LOS VALORES USANDO Red3");
		result="ESTA ES LA Red3, INTRODUCE LOS VALORES USANDO Red3";
 	}
	return &result;
}

char **
eliminar_1_svc(nombre arg1, red arg2,  struct svc_req *rqstp)
{
	static char * result;

	int i=0;
	int encontrado=999;
	if(strcmp(arg2,redusada)==0){
		for(i;i<util;i++){
			if(strcmp(arg1,valores[i][0])==0){
				encontrado=i;
			}
		}
		if(encontrado!=999){ //Tiene nombre y red correctos borramos la posición
			for(encontrado;encontrado<util;encontrado++){
				strcpy(valores[encontrado][0],valores[encontrado+1][0]);
				strcpy(valores[encontrado][1],valores[encontrado+1][1]);
				strcpy(valores[encontrado][2],valores[encontrado+1][2]);
			}
			strcpy(valores[util][0],"0");
			strcpy(valores[util][1],"0");
			strcpy(valores[util][2],"0");
			util--;
			encontrado=999;
      printf("%s\n", "BORRADO correctamente");
			result="BORRADO CORRECTAMENTE";
		}
		else{
			printf("%s\n", "NOMBRE NO encontrado");
			result="NOMBRE NO ENCONTRADO";
		}
	}
 	else{
		printf("%s\n", "ESTA ES LA Red3, INTRODUCE LOS VALORES USANDO Red3");
		result="ESTA ES LA RED 3, INTRODUCE VALORES USANDO Red3";
 	}

	return &result;
}

char **
consultar_1_svc(nombre arg1, red arg2,  struct svc_req *rqstp)
{
	static char * result;
	static char * prueba;
	result="NO ENCONTRADO POR ESE NOMBRE EN ESTA RED";
  int i=0;
	if(strcmp(arg2,redusada)==0){
	  for(i;i<util;i++){
	  	if(strcmp(arg1,valores[i][0])==0){
				result = "SE ENCUENTRA EL NOMBRE EN ESTA RED";
	        return &result;
	    }
	  }
	}
	else{
		CLIENT *clnt2;
		char * *result_1;

		#ifndef	DEBUG
		clnt2 = clnt_create ("localhost", DNS1, DNSVERS, "udp");
		if (clnt2 == NULL) {
			clnt_pcreateerror ("localhost");
			exit (1);
		}
		#endif	/* DEBUG */

		result_1 = consultar_1(arg1, arg2, clnt2);
		if (result_1 == (char **) NULL) {
			clnt_perror (clnt2, "call failed");
		}

		#ifndef	DEBUG
			clnt_destroy (clnt2);
		#endif	 /* DEBUG */
				result = *result_1;
	}
	return &result;
}
