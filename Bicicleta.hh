/** @file Bicicleta.hh
    @brief Especificación de la clase Bicicleta
*/

#ifndef _BICICLETA_HH_
#define _BICICLETA_HH_


#ifndef NO_DIAGRAM
#include <list>
#include <iostream>
#endif
using namespace std;



/** @class Bicicleta
    @brief Representa una Bicicleta.

    Tiene un identificador formado por letras y dígitos, sabe cuantos viajes ha hecho y está asignada a una estación en concreto.

*/

class Bicicleta
{
private:
    /** @brief Identificador de la bici*/
    string id;
    /** @brief Lista de los identificadores de las estaciones entre las que la bici ha viajado 

      Ordenada por el orden en el que se han hecho los viajes */
    list<pair<string,string>> viajes;
    /** @brief Identificador de la estacion donde esta asignada la bici.*/
    string id_est;

public:

    //constructoras

    /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar una Bicicleta.
      \pre <em>cierto</em>
      \post El resultado es una Bicicleta
    */
    Bicicleta();

    /** @brief Creadora con valores concretos.

      \pre <em>cierto</em>
      \post El resultado es una Bicicleta con id "id" e id_est "id_est"
    */
    Bicicleta(const string& id, const string& id_est);

    //modificadoras

    /** @brief Modificadora del id de la estación asignada
      \pre  <em>cierto</em>
      \post El parámetro implícito pasa a tener id_est "new_id"
    */
    void cambiar_ID_est(const string& new_id);

    /** @brief Modificadora de los viajes del parámetro implícito
      \pre  <em>cierto</em>
      \post El parámetro implícito pasa a tener un viaje mas en la lista: est_origen,est_destino;
    */
    void aumentar_VIAJES(const string& id_dest);


    //consultoras

    /** @brief Consultora del identificador
      \pre <em>cierto</em>
      \post El resultado es el identificador del parámetro implícito
    */
    string consultar_ID() const;

    /** @brief Consultora del identificador de la estación donde el parámetro implícito está asignado
      \pre <em>cierto</em>
      \post El resultado es el identificador de la estación asignada del parámetro implícito
    */
    string consultar_ID_est() const;

    //Escritura de una Bicicleta

    /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Escribe que viajes ha hecho el parámetro implícito por el canal estándar de salida.
   */
   void escribir_VIAJES() const;




};

#endif
