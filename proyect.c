#include <stdio.h>
#include <stdlib.h>

int main() {
    // Inicializamos los contadores en 
    int idMayorpeso = 0, menu = 0, idcontenedor = 0, tipoMaterial=0, cOperaciones = 0, destino = 0, enviosMarte = 0, enviosJupiter = 0, totalMRadiacion = 0, cantidadOrganica = 0, capsulaPlomo = 0;
    int alertaCritica = 0, cMarte = 0, cJupiter = 0, cSaturno = 0, cNeptuno = 0;
	float ttonelada = 0, ptonelada = 0, radiacion = 0, aprobado = 0, rechazado = 0, pesoMarte = 0, pesoJupiter = 0, totalRadiacion = 0;
    
    

    printf("//------// Bienvenidos a Galactic Cargo Terminal //-----//\n");

    do {
    	
    	
        printf("\n--- MENU DE EXPORTACION ---\n");
         	printf ("desea realizar un envio:");
            scanf("%d",&menu);


        if (menu > 0) {
        	cOperaciones++;
        	printf ("ingrese el id del contenedor");
            scanf("%d",&idcontenedor);
            printf(" 1 = organico\n 2 = electronico\n 3 = combustible\n 4 = maquinaria\n");
            scanf("%d", &tipoMaterial);
            printf("Ingrese el peso en toneladas: ");
            scanf("%f", &ptonelada);
            printf("Ingrese el nivel de radiacion: ");
            scanf("%f", &radiacion);
        	printf("Ingrese planeta destino:\n");
        	printf(" 1. marte\n 2. jupiter\n 3. saturno\n 4. neptuno\n ");
        	scanf("%d", &destino);
        	
        	if(ptonelada > ttonelada){
        		ttonelada = ptonelada;
        		idMayorpeso = idcontenedor;
			}
        	
        	if(tipoMaterial == 3 || tipoMaterial == 4){
        		totalRadiacion+=radiacion;
        		totalMRadiacion++;
			}
			
			if(tipoMaterial == 3 || radiacion > 50){
				capsulaPlomo++;
			}
			
			if(tipoMaterial == 2 && radiacion > 80){
				alertaCritica++;
			}
			
            switch(destino) {
                case 1:
					  if (ptonelada < 50 && radiacion < 20) {
                        printf(">>> Solicitud APROBADA\n");
                        aprobado++;
                        pesoMarte+=ptonelada;
                        enviosMarte++;
                        cMarte++;
                    } else {
                        printf(">>> Solicitud RECHAZADA por exceso de peso o radiacion\n");
                        rechazado++;
                    }
                    break; 
                case 2:
                	if((tipoMaterial == 4 && ptonelada < 100) || (tipoMaterial == 3 && radiacion < 10)){
                		aprobado++;	
                		pesoJupiter+=ptonelada;
                        enviosJupiter++;
                        cJupiter++;
							
					}else{
						printf(">>> Solicitud RECHAZADA por exceso de peso o radiacion\n");
						rechazado++;
					}
					break;
				case 3:
					if(ptonelada > 10 && tipoMaterial !=1){
						aprobado++;
						cSaturno++;
					} else{
						rechazado++;
						cantidadOrganica++;
					}
					break;
				case 4:
					if(ptonelada > 10 && tipoMaterial !=1){
						aprobado++;
						cNeptuno++;
					} else{
						rechazado++;
						cantidadOrganica++;
					}
					break;
				default:
					break;
            }
        } else{
            break;
        }

    } while (menu != 0);

    printf("\n--- REPORTE FINAL ---\n");
    printf("Cargas aprobadas: %.2f%%\n", (aprobado*100)/cOperaciones);
    printf("Cargas rechazados: %.2f%%\n", (rechazado*100)/cOperaciones);
    
    if(enviosMarte > 0){
    	printf("Envios a Marte: %.2f\n", (pesoMarte/enviosMarte));
	}
    
    if(enviosJupiter > 0){
    	printf("Envios a Jupiter: %.2f\n", (pesoJupiter/enviosJupiter));
	}
	
	if(totalMRadiacion > 0){
    	printf("Promedio de Radiacion: %.2f\n", (totalRadiacion/totalMRadiacion));
	}
	if(cantidadOrganica > 0){
		printf("Material organico rechazado: %d\n", cantidadOrganica);
	}
	if(capsulaPlomo > 0){
		printf("Promedio de aprobados en capsulas de plomo: %.2f\n", (capsulaPlomo/aprobado));
	}
	if(alertaCritica > 0){
		printf("Cantidad de alerta critica = %d\n", alertaCritica);
	}
	
	printf("El ID del contenedor con el mayor peso es: #%d\n", idMayorpeso);
	
	if(cMarte > (cJupiter || cSaturno || cNeptuno)){
		printf("El lugar con mayor cantidad de envios fue: Marte");
	}else if ( cJupiter > ( cMarte || cSaturno || cNeptuno)){
		printf (" El lugar con mayor cantidad de envios fue: Jupiter");
	}else if (cSaturno > (cMarte || cJupiter || cNeptuno)){
		printf (" El lugar con mayor cantidad de envios fue: Saturno");
	}else if ( cNeptuno > (cSaturno || cMarte || cJupiter)){
		printf (" El lugar con mayor cantidad de envios fue: Neptuno");
	}
    return 0;
}
