/** @file Cjt_estaciones.cc
    @brief Código de la clase Cjt_estaciones
*/

#include "Cjt_estaciones.hh"

Cjt_estaciones::Cjt_estaciones()
{}


void Cjt_estaciones::leer_estructura_arb(BinTree<string>& ests, map<string,Estacion>& cjt_ests, int& pl){
    string input;
    cin >> input;
    if(input != "#"){
        int cap;
        cin >> cap;
        Estacion estacion(cap);
        pl += cap;
        cjt_ests[input] = estacion;
        BinTree<string> l;
        leer_estructura_arb(l,cjt_ests,pl);
        BinTree<string> r;
        leer_estructura_arb(r,cjt_ests,pl);
        ests = BinTree<string>(input,l,r);
    }
}

void Cjt_estaciones::subir_bicis_aux(const BinTree<string>& ests,Cjt_bicicletas& bicis, map<string,Estacion>& cjt_estacs){
    
    if(!ests.left().empty() and !ests.right().empty()){
       string idb,ide;
       string raiz = ests.value();
       string idl = ests.left().value();
       string idr = ests.right().value();
       int pl_raiz = cjt_estacs[raiz].consultar_PL();
       int nbicisl = cjt_estacs[idl].consultar_NUMBICIS();
       int nbicisr = cjt_estacs[idr].consultar_NUMBICIS();
       while(pl_raiz > 0 and ( nbicisl > 0 or nbicisr > 0 )){

            if(nbicisl > nbicisr){
                idb = cjt_estacs[idl].consultar_BICI1();
                ide = idl;
                --nbicisl;
            }

            else if(nbicisr > nbicisl){
                idb = cjt_estacs[idr].consultar_BICI1();
                ide = idr;
                --nbicisr;
            }

            else{
                string idbl = cjt_estacs[idl].consultar_BICI1();
                string idbr = cjt_estacs[idr].consultar_BICI1();
                if(idbl < idbr){
                    idb = idbl;
                    ide = idl;
                    --nbicisl;
                } 
                else{
                    idb = idbr;
                    ide = idr;
                    --nbicisr;
                }   
     
            }
            cjt_estacs[ide].eliminar_BICI(idb);
            cjt_estacs[raiz].anadir_BICI(idb);
            bicis.cambiar_IDEST_bici(idb,raiz);
            --pl_raiz;
       }
       subir_bicis_aux(ests.left(),bicis,cjt_estacs);
       subir_bicis_aux(ests.right(),bicis,cjt_estacs);
    }
}

void Cjt_estaciones::ae_rec(const BinTree<string>& a, double& coefmax, double& nests, double& plibs, string& idest, map<string,Estacion>& cjt_ests){
    
    if(a.empty()){
        nests = 0;
        plibs = 0;
    }
    else{
        double nesti,nestd,plibsi,plibsd;
        ae_rec(a.left(),coefmax,nesti,plibsi,idest,cjt_ests);
        ae_rec(a.right(),coefmax,nestd,plibsd,idest,cjt_ests);
        nests = nesti + nestd + 1;
        plibs = plibsi + plibsd + cjt_ests[a.value()].consultar_PL();
        double coef = plibs/nests;
        if(coef > coefmax){
            coefmax = coef;
            idest = a.value();
        }
        else if(coef == coefmax and (coef == 0 or a.value() < idest)){
            coefmax = coef;
            idest = a.value();
        }
    }
}

void Cjt_estaciones::leer_estructura(){

    plibres = 0;
    leer_estructura_arb(ids_ests,cjt_est,plibres);


}

void Cjt_estaciones::alta_bici(const string& idb, const string& ide){    
    cjt_est[ide].anadir_BICI(idb);
    --plibres;
}

void Cjt_estaciones::baja_bici(const string& idb, const string& ide){
  

    cjt_est[ide].eliminar_BICI(idb);
    ++plibres;

}

void Cjt_estaciones::mover_bici(const string& idb, const string& ided, Cjt_bicicletas& bicis){
    
    string ide = bicis.consultar_IDEST_BICI(idb);
    baja_bici(idb,ide);
    alta_bici(idb,ided);
    bicis.aumentar_VIAJES_BICI(idb,ided);
    bicis.cambiar_IDEST_bici(idb,ided);
}

void Cjt_estaciones::mod_cap(const string& ide, const int& n){
    int cap_ant = cjt_est[ide].consultar_CAPACIDAD();
    if(n > cap_ant) plibres += n - cap_ant;
    else plibres -= cap_ant - n;
    cjt_est[ide].cambiar_CAPACIDAD(n);
}

void Cjt_estaciones::subir_bicis(Cjt_bicicletas& bicis){
    subir_bicis_aux(ids_ests,bicis,cjt_est);
}

void Cjt_estaciones::asignar_estacion(const string& idb, Cjt_bicicletas& bicis){
    double nests = 0;
    double plib = 0;
    double coef = 0;
    string idest = "#";
    ae_rec(ids_ests,coef,nests,plib,idest,cjt_est);
    cjt_est[idest].anadir_BICI(idb);
    --plibres;
    bicis.registrar_BICI(idb,idest);
    cout << idest << endl;

}

bool Cjt_estaciones::existe_estacion(const string& ide) const{
    
    //if(cjt_est.find(ide) == cjt_est.end()) return false;
    //return true;
    return !(cjt_est.find(ide) == cjt_est.end());
}

bool Cjt_estaciones::hay_espacio_est(const string& ide){  
    return  cjt_est[ide].consultar_PL() > 0;
}

int Cjt_estaciones::consultar_PLIBRES() const{
    return plibres;
}

int Cjt_estaciones::consultar_NUMBICIS(const string& ide) {
    return cjt_est[ide].consultar_NUMBICIS();
}

string Cjt_estaciones::consultar_PRIM_BICI(const string& ide){
    return cjt_est[ide].consultar_BICI1();
}

int Cjt_estaciones::consultar_PL_EST(const string& ide){
    return cjt_est[ide].consultar_PL();
}

void Cjt_estaciones::bicis_estacion(const string& ide) {
    cjt_est[ide].escribir_BICIS();
}

void Cjt_estaciones::escribir_PLIBRES() const{
    cout << plibres << endl;
}