/** @file Cjt_bicicletas.hh
    @brief Especificación de la clase Cjt_bicicletas
*/

#ifndef _CJT_BICICLETAS_HH_
#define _CJT_BICICLETAS_HH_

#include "Bicicleta.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif



/** @class Cjt_bicicletas
    @brief Representa un Conjunto de bicicletas.

    Consta de un mapa de strings y bicicletas y tiene operaciones para consultar ciertos elementos, añadirlos o eliminarlos.

*/

class Cjt_bicicletas
{

private:

    map<string,Bicicleta> cjt_bicis;

public:


    /** @brief Creadora con valores concretos.

      \pre <em>cierto</em>
      \post El resultado es un Conjunto de Bicis 
    */
    Cjt_bicicletas();


    //modificadoras

    /** @brief Modificadora del conjunto de bicis de la estación
      \pre  La bici con id "idb" no existe, la estacion con id "ide" existe, la bici cabe en la estacion
      \post El parámetro implícito pasa a tener la nueva Bici en el mapa y su id en la parte string de este.
    */
    void registrar_BICI(const string& idb, const string& ide);

    /** @brief Modificadora del conjunto de bicis de la estación
      \pre La bici con id "a" existe
      \post El parámetro implícito pasa a tener las mismas bicis que antes menos la de parámetro "a".
    */
    void quitar_BICI(const string& a);

    /** @brief Modificadora de el id de la estacion donde esta la bici con id "idb"
      \pre  <em>cierto</em>
      \post La bici con id "idb" pasa a tener como id de estacion asignada "idest".
    */
    void cambiar_IDEST_bici(const string& idb, const string& idest);

    /** @brief Modificadora de los viajes de la bici con id "idb"
      \pre  <em>cierto</em>
      \post La bici con id "idb" pasa a tener un viaje mas.
    */
    void aumentar_VIAJES_BICI(const string& idb, const string& ided);


    //consultoras

    /** @brief Consultora de una Bici del Conjunto
      \pre <em>cierto</em>
      \post El resultado es una bici del parámetro implícito
    */
    Bicicleta consultar_BICI(const string& id) ;

    /** @brief Consultora del id de la estacion donde las bici con id "id" está asignada
      \pre <em>cierto</em>
      \post El resultado es el id de la estacion donde la bici con id "idb" del parámetro implícito está asignada
    */
    string consultar_IDEST_BICI(const string& idb) ;

    /** @brief Consulta si existe una bici en el conjunto de bicis
      \pre <em>cierto</em>
      \post true si la bici existe, si no false
    */
    bool existe_bici(const string& id) const;

    /** @brief Consulta si la bici con id "idb" está en la estación con id "ided"
      \pre <em>cierto</em>
      \post true si la bici está, si no false
    */
    bool bici_esta(const string& idb, const string& ided) ;




};

#endif








