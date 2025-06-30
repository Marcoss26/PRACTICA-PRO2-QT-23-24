/** @file Cjt_bicicletas.cc
    @brief Código de la clase Cjt_bicicletas
*/

#include "Cjt_bicicletas.hh"

Cjt_bicicletas::Cjt_bicicletas()
{}

void Cjt_bicicletas::registrar_BICI(const string& idb, const string& ide){
    Bicicleta bici(idb,ide);
    cjt_bicis[idb] = bici;
}

void Cjt_bicicletas::quitar_BICI(const string& a){
    
    cjt_bicis.erase(a);
}

void Cjt_bicicletas::aumentar_VIAJES_BICI(const string& idb, const string& ided){
    cjt_bicis[idb].aumentar_VIAJES(ided);
}
void Cjt_bicicletas::cambiar_IDEST_bici(const string& idb, const string& idest){
    cjt_bicis[idb].cambiar_ID_est(idest);
}

Bicicleta Cjt_bicicletas::consultar_BICI(const string& id) {
    return cjt_bicis[id];
}

string Cjt_bicicletas::consultar_IDEST_BICI(const string& idb) {
    Bicicleta bici;
    bici = cjt_bicis[idb];
    return bici.consultar_ID_est();
}

bool Cjt_bicicletas::existe_bici(const string& idb)const{
    return !(cjt_bicis.find(idb) == cjt_bicis.end());
}

bool Cjt_bicicletas::bici_esta(const string& idb, const string& ided){
    return cjt_bicis[idb].consultar_ID_est() == ided;
}