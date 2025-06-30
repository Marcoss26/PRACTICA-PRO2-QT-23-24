/** @file Bicicletas.cc
    @brief Código de la clase Bicicletas
*/

#include "Bicicleta.hh"

Bicicleta::Bicicleta()
{}

Bicicleta::Bicicleta(const string& id, const string& id_est){

    this->id = id;
    this->id_est = id_est;
}

void Bicicleta::cambiar_ID_est(const string& new_id){

    id_est = new_id;
}

void Bicicleta::aumentar_VIAJES(const string& id_dest){

    pair<string,string> viaje;
    viaje.first = id_est;
    viaje.second = id_dest;
    viajes.push_back(viaje);  
}

string Bicicleta::consultar_ID() const{
    return id;
}

string Bicicleta::consultar_ID_est() const{
    return id_est;
}

void Bicicleta:: escribir_VIAJES() const{
    for(list<pair<string,string>>::const_iterator it = viajes.begin(); it != viajes.end(); ++it){
        cout << it->first << ' ' << it->second << endl;
    }  
}
