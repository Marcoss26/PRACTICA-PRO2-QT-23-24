/** @mainpage Simulación de un Sistema de Bicing bifurcado

    El programa principal se encuentra en el módulo program.cc.
    Atendiendo a los tipos de datos sugeridos en el enunciado, necesitaremos un
    módulo para representar el Sistema en el que se realizarán las acciones 
    (Cjt_estaciones), otro para representar una estacion (Estacion), además uno
    para almacenar todas las bicis del sistema ordenadas por identificador
    (Cjt_bicicletas), el cual nos facilitará la gestión de errores y por último
    un módulo que represente una Bici (Bicicleta). 
    

*/

/** @file program.cc

    @brief Programa principal

    Estamos suponiendo que los datos leídos siempre son correctos, ya que
    no incluímos comprobaciones al respecto. Además, como se utilizan órdenes
    para indicar lo que hay que hacer usaremos strings para representarlas. Por 
    último, en algunos casos, hacemos una serie de comprobación de errores 
    antes de llamar a las funciones de la clase correspondiente.
*/


#include "Cjt_estaciones.hh"
#include "Cjt_bicicletas.hh"




//Esquema de programa principal:
int main(){

    Cjt_estaciones cjt_estaciones;
    cjt_estaciones.leer_estructura();
    Cjt_bicicletas cjt_bicicletas;
    string orden;
    cin >> orden;
    while(orden != "fin"){

        if(orden == "alta_bici" or orden == "ab"){
            string idb,ide;
            cin >> idb >> ide;
            cout << "#ab " << idb << ' ' << ide << endl;
            if(cjt_bicicletas.existe_bici(idb)) cout << "error: la bici ya existe" << endl;
            else if(not cjt_estaciones.existe_estacion(ide)) cout << "error: la estacion no existe" << endl;
            else if(not cjt_estaciones.hay_espacio_est(ide)) cout << "error: la bici no cabe" << endl;
            else{
                cjt_estaciones.alta_bici(idb,ide);
                cjt_bicicletas.registrar_BICI(idb,ide);
            }

        } //entrada: id bici, id estacion ; dar de alta bici que no existe en estacion correcta
        else if(orden == "baja_bici" or orden == "bb"){
            string idb;
            cin >> idb;
            cout << "#bb " << idb << endl;
            if(not cjt_bicicletas.existe_bici(idb)) cout << "error: la bici no existe" << endl;
            else{
                
                string ide = cjt_bicicletas.consultar_IDEST_BICI(idb);
                cjt_bicicletas.quitar_BICI(idb);
                cjt_estaciones.baja_bici(idb,ide);
                
            }
        } //entrada: id bici; dar de baja bici que existe
        else if(orden == "estacion_bici" or orden == "eb"){
            string idb;
            cin >> idb;
            cout << "#eb " << idb << endl;
            if(not cjt_bicicletas.existe_bici(idb)) cout << "error: la bici no existe" << endl;
            else{
                cout << cjt_bicicletas.consultar_IDEST_BICI(idb) << endl;
            }
        } //entrada: id bici; escribir id de la estacion donde se encuentra
        else if(orden == "viajes_bici" or orden == "vb"){
            string idb;
            cin >> idb;
            cout << "#vb " << idb << endl;
            if(not cjt_bicicletas.existe_bici(idb)) cout << "error: la bici no existe" << endl;
            else{
                cjt_bicicletas.consultar_BICI(idb).escribir_VIAJES();
            }
        } //entrada: id bici ; escribir cuantos viajes ha hecho la bici
        else if(orden == "mover_bici" or orden == "mb"){
            string idb, ided;
            cin >> idb >> ided;
            cout << "#mb " << idb << ' ' << ided << endl;
            if(not cjt_bicicletas.existe_bici(idb)) cout << "error: la bici no existe" << endl;
            else if(not cjt_estaciones.existe_estacion(ided)) cout << "error: la estacion no existe" << endl;
            else if(cjt_bicicletas.bici_esta(idb,ided)) cout <<  "error: la bici ya esta en el sitio" << endl;
            else if(not cjt_estaciones.hay_espacio_est(ided)) cout << "error: la bici no cabe" << endl;
            else{
                cjt_estaciones.mover_bici(idb,ided, cjt_bicicletas);  
            }

        } //entrada: id bici, id estacion destino ; se añade un viaje a la bici y pasa a estar en la estacion
        else if(orden == "bicis_estacion" or orden == "be"){
            string ide;
            cin >> ide;
            cout << "#be " << ide << endl;
            if(not cjt_estaciones.existe_estacion(ide))cout << "error: la estacion no existe" << endl;
            else{
                cjt_estaciones.bicis_estacion(ide);
            }

        } //entrada: id estacion; escribir que bicis hay en orden de id
        else if(orden == "modificar_capacidad" or orden == "mc"){
            string ide;
            int n;
            cin >> ide >> n;
            cout << "#mc " << ide << ' ' << n <<  endl;
            if(not cjt_estaciones.existe_estacion(ide)) cout << "error: la estacion no existe" << endl;
            else if(n < cjt_estaciones.consultar_NUMBICIS(ide)) cout << "error: capacidad insuficiente" << endl;
            else{
               cjt_estaciones.mod_cap(ide,n); 
            }
        } //entrada: id estacion, int n >= 0; ahora la capacidad de la estacion es n
        else if(orden == "plazas_libres" or orden == "pl"){
            cout << "#pl" << endl;
            cjt_estaciones.escribir_PLIBRES();
        } // escribe cuantas plazas quedan libres entre todas las estaciones
        else if(orden == "subir_bicis" or orden == "sb"){
            cout << "#sb" << endl;
            cjt_estaciones.subir_bicis(cjt_bicicletas);
        } // acerca bicis a la primera estacion segun el 1.1
        else if(orden == "asignar_estacion" or orden == "ae"){
            string idb;
            cin >> idb;
            cout << "#ae " << idb << endl;
            if(cjt_bicicletas.existe_bici(idb)) cout << "error: la bici ya existe" << endl;
            else if(cjt_estaciones.consultar_PLIBRES() == 0) cout << "error: no hay plazas libres" << endl;
            else{
                cjt_estaciones.asignar_estacion(idb, cjt_bicicletas);
            }
        } // entrada: id bici, mete la bici en la estacion que toque segun el 1.2 y escribe el id de la estacion
        

        cin >> orden;
    }


}


