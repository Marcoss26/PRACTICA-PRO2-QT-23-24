/** @file Estacion.hh
    @brief Especificación de la clase Estacion
*/

#ifndef _ESTACION_HH_
#define _ESTACION_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <set>
#endif
using namespace std;



/** @class Estacion
    @brief Representa una Estacion de bicicletas.

    Tiene un identificador formado por letras y dígitos, puede albergar un numero n de bicis y debe saber qué bicis tiene. Además se puede modificar su capacidad.

*/

class Estacion
{

private:

    /** @brief Capacidad total de la estacion */
    int capacidad;

      /** @brief Número de bicis que hay en la estacion */ 
    int nbicis;

    /** @brief Conjunto de identificadores de las bicis que forman parte de la estacion. 

      Ordenad crecientemente por el id de sus bicicletas */
    set<string> bicis; 

public:

    //constructoras

    /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar una Estacion.
      \pre <em>cierto</em>
      \post El resultado es una Estacion de id 0 , capacidad 0 y set de bicis vacío
    */
    Estacion();

    /** @brief Creadora con valores concretos.

      \pre cap >= 0
      \post El resultado es una Estacion con id "id", nbicis = 0 y capacidad "cap" 
    */
    Estacion(const int& cap);

    //modificadoras

    /** @brief Modificadora de la capacidad de la estación
      \pre cap >= 0
      \post El parámetro implícito pasa a tener capacidad "cap"
    */
    void cambiar_CAPACIDAD(int cap);

    /** @brief Modificadora del numero de bicis de la estación
      \pre  n >= 0
      \post El parámetro implícito pasa a tener nbicis "n"
    */
    void cambiar_NUMBICIS(int n);

    /** @brief Modificadora del conjunto de id's de bicis del parámetro implícito
      \pre  <em>cierto</em>
      \post El parámetro implícito pasa a tener actualizado el conjunto de id's
    */
    void anadir_BICI(const string& new_id);

    /** @brief Modificadora del conjunto de id's de bicis del parámetro implícito
      \pre  <em>cierto</em>
      \post Se elimina del parámetro implícito el id "deleted_id"
    */
    void eliminar_BICI(const string& deleted_id);

    //consultoras

    /** @brief Consultora del identificador de la estacion
      \pre <em>cierto</em>
      \post El resultado es el identificador del parámetro implícito
    */
    int consultar_PL() const;

    

    /** @brief Consultora del número de bicis de la estacion
      \pre <em>cierto</em>
      \post El resultado es el número de bicis del parámetro implícito
    */
    int consultar_NUMBICIS() const;

    /** @brief Consultora de la capacidad de la estación
      \pre <em>cierto</em>
      \post El resultado es la capacidad del parámetro implícito
    */
    int consultar_CAPACIDAD() const;

    /** @brief Consultora de la primera bici del conjunto de bicis
      \pre <em>cierto</em>
      \post El resultado es la primera bici del conjunto de bicis
      */
    string consultar_BICI1() const;

    //Escritura de una Estacion


    /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Escribe que bicis hay en parámetro implícito por el canal estándar de salida
   */
   void escribir_BICIS() const;

};

#endif
