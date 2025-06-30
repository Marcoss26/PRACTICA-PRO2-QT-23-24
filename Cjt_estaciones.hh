/** @file Cjt_estaciones.hh
    @brief Especificación de la clase Cjt_estaciones
*/

#ifndef _CJT_ESTACIONES_HH_
#define _CJT_ESTACIONES_HH_

#include "Estacion.hh"
#include "Cjt_bicicletas.hh"


#ifndef NO_DIAGRAM
#include <iostream>
#include "BinTree.hh"
#endif
using namespace std;


/** @class Cjt_estaciones
    @brief Representa un Conjunto de Estaciones de bicis.

    Consta del control de su capacidad total de almacenar bicis, de las plazas libres que le quedan, de la cantidad de bicis que hay en todo el sistema, de un conjunto de estaciones ordenadas por su id en orden lexicográfico y de un arbol de los ids de las estaciones.

*/

class Cjt_estaciones
{

private:

    /** @brief Capacidad total del Sistema de Bicing.*/
    int cap_total;
    /** @brief Plazas libres que hay en todo el Sistema.*/
    int plibres;
    /** @brief Numero de bicis que hay en el Sistema.*/
    int nbicis;
    /** @brief Mapa de identificadores de estaciones y estaciones. 

      Ordenado crecientemente según los identificadores de las Estaciones */
    map<string,Estacion> cjt_est;
    /** @brief Árbol binario de los identificadores de las estaciones. 

      Ordenado de la misma manera en que se recibe la entrada por el canal estándar */
    BinTree<string> ids_ests;
    /** @brief Operación de lectura auxiliar.
      \pre plibres >= 0
      \post Se añade al árbol y al conjunto de estaciones los datos leídos y se actualizan las plazas libres.
   */
    static void leer_estructura_arb(BinTree<string>& arb_est, map<string,Estacion>& cjt_ests, int& plibres);
    /** @brief Modificadora auxiliar para acercar bicis hacia la primera estación.
      \pre  cierto
      \post Se han acercado todas las bicis posibles según los criterios a la primera estación
    */
    static void subir_bicis_aux(const BinTree<string>& ests,Cjt_bicicletas& bicis,map<string,Estacion>& cjt_estacs);
    /** @brief Modificadora para asignar una estacion a la bici con id "idb" segun los criterios del apartado 1.2
      \pre coefmax >= 0, nests >= 0, plibs >= 0
      \post Se ha guardado el id de la estacion asignada según los criterios en "idest"
    */
    static void ae_rec(const BinTree<string>& ests, double& coefmax, double& nests, double& plibs, string& idest, map<string,Estacion>& cjt_ests );

public:

    /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar una Estacion.
      \pre <em>cierto</em>
      \post El resultado es un conjunto de Estaciones
    */
    Cjt_estaciones();

    //operaciones de lectura

    /** @brief Operación de lectura
      \pre 
      \post Se añade al árbol y al conjunto de estaciones los datos leídos.
   */
    void leer_estructura();

    //modificadoras no tengo ni idea

    /** @brief Modificadora de las bicis que hay en las estaciones del sistema
      \pre  La bici con id "idb" no existe, la estacion con id "ide" existe, la bici cabe en la estacion
      \post El parámetro implícito pasa a tener la bici con id "idb" en la estación con id "ide"
    */
    void alta_bici(const string& idb, const string& ide);

    /** @brief Modificadora del conjunto de id's de bicis del parámetro implícito
      \pre La bici con id "idb" existe
      \post Se elimina del parámetro implícito la bici con id "idb" que se encuentra en la estacion con id "ide"
    */
    void baja_bici(const string& idb, const string& ide);

    /** @brief Modificadora del conjunto de id's de bicis del parámetro implícito
      \pre La bici existe, la estacion destino existe, la bici no esta en la estacion, la bici cabe en la estacion destino
      \post La bici con id "idb" pasa a estar en la estacion con id "ided"
    */
    void mover_bici(const string& idb, const string& ided, Cjt_bicicletas& bicis);

    /** @brief Modificadora de la capacidad de la estacion con id "ide" del Parámetro implícito
      \pre  La estacion existe, el numero n es mayot que la cantidad de bicis que hay en la estacion a modificar
      \post La estacion con id "ide" pasa a tener capacidad "n"
    */
    void mod_cap(const string& ide, const int& n);

    /** @brief Modificadora para acercar bicis hacia la primera estación
      \pre <em>Cierto</em>
      \post Se han acercado todas las bicis posibles a la primera estación
    */
    void subir_bicis(Cjt_bicicletas& bicis);
    
    /** @brief Modificadora para asignar una estacion a la bici con id "idb" segun los criterios del apartado 1.2
      \pre La bici no existe y cabe en alguna estacion del sistema
      \post Se le ha asignado la bici con id "idb" a una estacion del parámetro implícito
    */
    void asignar_estacion(const string& idb, Cjt_bicicletas& bicis);
    

    //consultoras

    /** @brief Consultora de la capacidad total del sistema
      \pre <em>cierto</em>
      \post El resultado es la capacidad total  del parámetro implícito
    */
    int consultar_CAP_TOTAL() const;

    /** @brief Consultora del número de bicis de la estacion con identificador "ide"
      \pre <em>cierto</em>
      \post El resultado es el número de bicis de la estación con id "ide"
    */
    int consultar_NUMBICIS(const string& ide);


    /** @brief Consultora de las plazas libres que hay en el sistema
      \pre <em>cierto</em>
      \post El resultado son las plazas libres del parámetro implícito
    */
    int consultar_PLIBRES() const;

    /** @brief Consultora de las bicis que hay en el sistema
      \pre <em>cierto</em>
      \post El resultado es la cantidad de bicis que hay en el parámetro implícito
    */
    int consultar_NBICIS() const;

    /** @brief Consultora de la bici con id mas pequeño de la estacion con id "ide"
      \pre <em>cierto</em>
      \post El resultado es la bici con identificador mas pequeño de la estacion con id "ide"
    */
    string consultar_PRIM_BICI(const string& ide);
    
    /** @brief Consultora de las plazas libres de la estacion con id "ide"
      \pre <em>cierto</em>
      \post El resultado son las plazas libres de la estacion con id "ide"
    */
    int consultar_PL_EST(const string& ide);

     /** @brief Consulta si existe una estacion concreta
      \pre <em>cierto</em>
      \post true si existe la estacion, si no false
    */
    bool existe_estacion(const string& id) const;

    /** @brief Consulta si hay espacio para una bici en la estacion con id "ide"
      \pre <em>cierto</em>
      \post true si hay espacio, si no false
    */
    bool hay_espacio_est(const string& ide) ;

    //operaciones de escritura

    /** @brief Operacion de escritura del conjunto de bicis que hay en la estacion con id "ide" del parámetro implícito
      \pre  La estacion existe 
      \post Se escriben las bicis por orden de id que se encuentran en la estación con id "ide"  del parámetro implícito
    */
    void bicis_estacion(const string& ide) ;

    /** @brief Operacion de escritura de las plazas libres del parámetro implícito
      \pre  <em>cierto</em>
      \post Se escriben las plazal libres que quedan en el parámetro implícito
    */
    void escribir_PLIBRES()const;





};

#endif
