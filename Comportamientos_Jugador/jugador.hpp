#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"
using namespace std;

struct state{
  int fil;
  int col;
  Orientacion brujula;

};



class ComportamientoJugador : public Comportamiento{

  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size){
      current_state.fil= 99;
      current_state.col = 99;
      current_state.brujula = norte;
      last_action = actIDLE;

      girar_derecha = true;
      bien_situado = false;
      bikini = false;
      zapatillas = false;
      recargando = false;
      Giros = 0;

      tamanioMapa = size;

      for(int i = 0; i < 3; i++)
        for(int j = 0; j < tamanioMapa; j++){
          mapaResultado[i][j] = 'P';
          mapaResultado[tamanioMapa - i - 1][j] = 'P';
          mapaResultado[j][i] = 'P';
          mapaResultado[j][tamanioMapa -i -1] = 'P';
      
        }
    }
    

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}
    void PonerTerrenoEnMatriz(const vector<unsigned char> & terreno,
const state & st, vector<vector<unsigned char> > & matriz);
    
    void MuestraInformacion(Sensores sensores);
    void Orientarse(Sensores sensores);
    Action BuscarCasilla(Sensores sensores);
    Action Decision(Sensores sensores);
    
    
    Action think(Sensores sensores);
    int interact(Action accion, int valor);

  private:
    state current_state;
    Action last_action;
    Orientacion brujula;
    bool girar_derecha;
    bool bien_situado; 
    bool bikini; 
    bool zapatillas; 
    bool recargando;
    const int bateria_baja = 3000; 
    const int bateria_muy_baja = 800; 
    const int bateriaRecarga = 4000; 
    const int vidaBaja = 1000; 
    const int factorVidaBateria = 3; 
    int Giros; 

    unsigned int tamanioMapa;


};
#endif