/** @file Estacion.cc
    @brief Código de la clase Estacion
*/

#include "Estacion.hh"

Estacion::Estacion()
{}

Estacion::Estacion(const int& cap){
    capacidad = cap;
    nbicis = 0;

}

void Estacion::cambiar_CAPACIDAD(int cap){
    capacidad = cap;
}
void Estacion::cambiar_NUMBICIS(int n){
    nbicis = n;
}

void Estacion::anadir_BICI(const string& new_id){
    bicis.insert(new_id);
    ++nbicis;
}

void Estacion::eliminar_BICI(const string& deleted_id){
    bicis.erase(deleted_id);
    --nbicis;
}



int Estacion::consultar_NUMBICIS() const{
    return nbicis;
}

int Estacion::consultar_CAPACIDAD() const{
    return capacidad;
}

int Estacion::consultar_PL() const{
    return capacidad - nbicis;
}

string Estacion::consultar_BICI1() const{
    return *bicis.begin();
}

void Estacion::escribir_BICIS() const{
    for(set<string>::const_iterator it = bicis.begin(); it != bicis.end(); ++it){
        cout << *it << endl;
    }
}