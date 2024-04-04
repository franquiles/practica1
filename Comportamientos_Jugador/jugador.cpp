#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

void ComportamientoJugador::MuestraInformacion(Sensores sensores){
	cout << "Posicion: fila " << sensores.posF << " columna " <<
	sensores.posC << " ";
	switch(sensores.sentido){
		case 0: cout << "Norte" << endl; break;
		case 1: cout << "Noreste" << endl; break;
		case 2: cout << "Este" << endl; break;
		case 3: cout << "Sureste" << endl; break;
		case 4: cout << "Sur " << endl; break;
		case 5: cout << "Suroeste" << endl; break;
		case 6: cout << "Oeste" << endl; break;
		case 7: cout << "Noroeste" << endl; break;
	}
	cout << "Terreno: ";
		for (int i=0; i<sensores.terreno.size(); i++)
			cout << sensores.terreno[i];
	cout << endl;

	cout << "Agentes: ";
		for (int i=0; i<sensores.agentes.size(); i++)
		cout << sensores.agentes[i];
	cout << endl;
	
	cout << "Colisión: " << sensores.colision << endl;
	
	cout << "Reset: " << sensores.reset << endl;
	
	cout << "Vida: " << sensores.vida << endl;
	
	cout << endl;
}


void ComportamientoJugador::Orientarse(Sensores sensores){
	current_state.fil = sensores.posF;
	current_state.col= sensores.posC;
	current_state.brujula = sensores.sentido;
	bien_situado = true;
}

void ComportamientoJugador::PonerTerrenoEnMatriz(const vector<unsigned char> & terreno,const state & st, vector< vector<unsigned char> > & matriz){
	matriz[st.fil][st.col] = terreno[0];

	switch (st.brujula){
		case norte:
			matriz[st.fil - 1][st.col - 1] = terreno[1];
			matriz[st.fil - 1][st.col] = terreno[2];
			matriz[st.fil - 1][st.col + 1] =terreno[3];
			matriz[st.fil - 2][st.col - 2] =terreno[4];
			matriz[st.fil - 2][st.col - 1] =terreno[5];
			matriz[st.fil - 2][st.col] = terreno[6];
			matriz[st.fil - 2][st.col + 1] =terreno[7];
			matriz[st.fil - 2][st.col + 2] =terreno[8];
			matriz[st.fil - 3][st.col - 3] =terreno[9];
			matriz[st.fil - 3][st.col - 2] =terreno[10];
			matriz[st.fil - 3][st.col - 1] =terreno[11];
			matriz[st.fil - 3][st.col] = terreno[12];
			matriz[st.fil - 3][st.col + 1] =terreno[13];
			matriz[st.fil - 3][st.col + 2] =terreno[14];
			matriz[st.fil - 3][st.col + 3] =terreno[15];
		break;
		case sur:
			matriz[st.fil + 1][st.col + 1] =terreno[1];
			matriz[st.fil + 1][st.col] = terreno[2];
			matriz[st.fil + 1][st.col - 1] =terreno[3];
			matriz[st.fil + 2][st.col + 2] =terreno[4];
			matriz[st.fil + 2][st.col + 1] =terreno[5];
			matriz[st.fil + 2][st.col] = terreno[6];
			matriz[st.fil + 2][st.col - 1] =terreno[7];
			matriz[st.fil + 2][st.col - 2] =terreno[8];
			matriz[st.fil + 3][st.col + 3] =terreno[9];
			matriz[st.fil + 3][st.col + 2] =terreno[10];
			matriz[st.fil + 3][st.col + 1] =terreno[11];
			matriz[st.fil + 3][st.col] = terreno[12];
			matriz[st.fil + 3][st.col - 1] =terreno[13];
			matriz[st.fil + 3][st.col - 2] =terreno[14];
			matriz[st.fil + 3][st.col - 3] =terreno[15];
		break;
		case este:
			matriz[st.fil - 1][st.col + 1] =terreno[1];
			matriz[st.fil][st.col + 1] =terreno[2];
			matriz[st.fil+ 1][st.col + 1]=terreno[3];
			matriz[st.fil - 2][st.col + 2] =terreno[4];
			matriz[st.fil - 1][st.col + 2] =terreno[5];
			matriz[st.fil][st.col + 2] = terreno[6];
			matriz[st.fil + 1][st.col + 2] =terreno[7];
			matriz[st.fil + 2][st.col + 2] =terreno[8];
			matriz[st.fil - 3][st.col + 3] =terreno[9];
			matriz[st.fil - 2][st.col + 3] =terreno[10];
			matriz[st.fil - 1][st.col + 3] =terreno[11];
			matriz[st.fil][st.col + 3] = terreno[12];
			matriz[st.fil + 1][st.col + 3] =terreno[13];
			matriz[st.fil + 2][st.col + 3] =terreno[14];
			matriz[st.fil + 3][st.col + 3] =terreno[15];
		break;
		case oeste:
			matriz[st.fil + 1][st.col - 1] =terreno[1];
			matriz[st.fil][st.col -1 ] = terreno[2];
			matriz[st.fil - 1][st.col - 1] =terreno[3];
			matriz[st.fil + 2][st.col - 2] =terreno[4];
			matriz[st.fil + 1][st.col - 2] =terreno[5];
			matriz[st.fil][st.col - 2] = terreno[6];
			matriz[st.fil - 1][st.col - 2] =terreno[7];
			matriz[st.fil - 2][st.col - 2] =terreno[8];
			matriz[st.fil + 3][st.col - 3] =terreno[9];
			matriz[st.fil + 2][st.col - 3] =terreno[10];
			matriz[st.fil + 1][st.col - 3] =terreno[11];
			matriz[st.fil][st.col - 3] = terreno[12];
			matriz[st.fil - 1][st.col - 3] =terreno[13];
			matriz[st.fil - 2][st.col - 3] =terreno[14];
			matriz[st.fil - 3][st.col - 3] =terreno[15];
		break;
		case noreste:
			matriz[st.fil - 1][st.col] = terreno[1];
			matriz[st.fil - 1][st.col + 1] =terreno[2];
			matriz[st.fil][st.col + 1] = terreno[3];
			matriz[st.fil - 2][st.col] = terreno[4];
			matriz[st.fil - 2][st.col + 1] =terreno[5];
			matriz[st.fil - 2][st.col + 2] =terreno[6];
			matriz[st.fil - 1][st.col + 2] =terreno[7];
			matriz[st.fil][st.col + 2] = terreno[8];
			matriz[st.fil - 3][st.col] = terreno[9];
			matriz[st.fil - 3][st.col + 1] =terreno[10];
			matriz[st.fil - 3][st.col + 2] =terreno[11];
			matriz[st.fil - 3][st.col + 3] =terreno[12];
			matriz[st.fil - 2][st.col + 3] =terreno[13];
			matriz[st.fil - 1][st.col + 3] =terreno[14];
			matriz[st.fil][st.col + 3] = terreno[15];
		break;
		case noroeste:
			matriz[st.fil][st.col - 1] = terreno[1];
			matriz[st.fil - 1][st.col - 1] = terreno[2];
			matriz[st.fil - 1][st.col] = terreno[3];
			matriz[st.fil][st.col - 2] = terreno[4];
			matriz[st.fil - 1][st.col - 2] =terreno[5];
			matriz[st.fil - 2][st.col - 2] =terreno[6];
			matriz[st.fil - 2][st.col - 1] =terreno[7];
			matriz[st.fil - 2][st.col] = terreno[8];
			matriz[st.fil][st.col - 3] = terreno[9];
			matriz[st.fil - 1][st.col - 3] =terreno[10];
			matriz[st.fil - 2][st.col - 3] =terreno[11];
			matriz[st.fil - 3][st.col - 3] =terreno[12];
			matriz[st.fil - 3][st.col - 2] =terreno[13];
			matriz[st.fil - 3][st.col - 1] =terreno[14];
			matriz[st.fil - 3][st.col] = terreno[15];
		break;
		case sureste:
			matriz[st.fil][st.col + 1] = terreno[1];
			matriz[st.fil + 1][st.col + 1] =terreno[2];
			matriz[st.fil + 1][st.col] = terreno[3];
			matriz[st.fil][st.col + 2] = terreno[4];
			matriz[st.fil + 1][st.col + 2] =terreno[5];
			matriz[st.fil + 2][st.col + 2] =terreno[6];
			matriz[st.fil + 2][st.col + 1] =terreno[7];
			matriz[st.fil + 2][st.col] = terreno[8];
			matriz[st.fil][st.col + 3] = terreno[9];
			matriz[st.fil + 1][st.col + 3] =terreno[10];
			matriz[st.fil + 2][st.col + 3] =terreno[11];
			matriz[st.fil + 3][st.col + 3] =terreno[12];
			matriz[st.fil + 3][st.col + 2] =terreno[13];
			matriz[st.fil + 3][st.col + 1] =terreno[14];
			matriz[st.fil + 3][st.col] = terreno[15];	
		break;
		case suroeste:
			matriz[st.fil + 1][st.col] = terreno[1];
			matriz[st.fil + 1][st.col - 1] =terreno[2];
			matriz[st.fil][st.col - 1] = terreno[3];
			matriz[st.fil + 2][st.col] = terreno[4];
			matriz[st.fil + 2][st.col - 1] =terreno[5];
			matriz[st.fil + 2][st.col - 2] =terreno[6];
			matriz[st.fil + 1][st.col - 2] =terreno[7];
			matriz[st.fil][st.col - 2] = terreno[8];
			matriz[st.fil + 3][st.col] = terreno[9];
			matriz[st.fil + 3][st.col - 1] =terreno[10];
			matriz[st.fil + 3][st.col - 2] =terreno[11];
			matriz[st.fil + 3][st.col - 3] =terreno[12];
			matriz[st.fil + 2][st.col - 3] =terreno[13];
			matriz[st.fil + 1][st.col - 3] =terreno[14];
			matriz[st.fil][st.col - 3] = terreno[15];
		break;
}

}




Action ComportamientoJugador::BuscarCasilla(Sensores sensores){
	Action accion = actIDLE; 

	int pos = -1; 
	bool encontrado = false; 
	bool lobo = false; 
	bool dejarDeCargar = (sensores.vida < vidaBaja) &&
((sensores.vida * factorVidaBateria) < sensores.bateria ); 

	if( (sensores.bateria < bateria_muy_baja) && !dejarDeCargar)
		for(int i = 1; i < sensores.terreno.size() && !encontrado; i++)
		if(sensores.terreno[i] == 'X'){
			encontrado = true;
			pos = i;
		}

	if(!bikini && !encontrado)
		for(int i = 1; i < sensores.terreno.size() &&
		!encontrado; i++)
			if(sensores.terreno[i] == 'K'){
			encontrado = true;
			pos = i;
			}	

	if(!zapatillas && !encontrado)
		for(int i = 1; i < sensores.terreno.size() &&
		!encontrado; i++)
			if(sensores.terreno[i] == 'D'){
			encontrado = true;
			pos = i;
			}


	if(!bien_situado && !encontrado)
		for(int i = 1; i < sensores.terreno.size() &&
		!encontrado; i++)
			if(sensores.terreno[i] == 'G'){
			encontrado = true;
			pos = i;
			}

	if( (sensores.bateria < bateria_baja) && !encontrado &&
	!dejarDeCargar )
		for(int i = 1; i < sensores.terreno.size() &&
		!encontrado; i++)
		if(sensores.terreno[i] == 'X'){
		encontrado = true;
		pos = i;
		}


	if( ( (!bikini && sensores.terreno[0] == 'A') || (!zapatillas
	&& sensores.terreno[0] == 'B' ) ) && !encontrado)
		for(int i = 1; i < sensores.terreno.size() &&
		!encontrado; i++)
			if(sensores.terreno[i] == 'S' || sensores.terreno[i]
			== 'T'){
			encontrado = true;
			pos = i;
			}


	if(bien_situado && (sensores.bateria > bateria_baja)){
		for(int i = 1; i < sensores.terreno.size() &&
		!encontrado; i++)
			if(sensores.agentes[i] == 'l'){
			encontrado = true;
			pos = i;
			lobo = true;
			}
}


	if(encontrado){
		if( (pos == 2 ) || (pos == 6) || (pos == 12) || (pos ==
		5) || (pos == 7) || (pos == 10) || (pos == 11) || (pos == 13) || (pos == 14)){
			if(lobo){
				if(girar_derecha){
				accion = accion = actTURN_SR;
				}
			else{
				accion = accion = actTURN_L;
			}
			}
			else
				accion = actWALK;
		}

		else if( (pos == 3 ) || (pos == 8)|| (pos == 15) ){

			if(lobo)
				accion = accion = actTURN_L;
			else
				accion = actTURN_SR;
		}

		else if( (pos == 1 ) || (pos == 4)|| (pos == 9) ){

			if(lobo)
				accion = actTURN_SR;
			else
				accion = actTURN_L;
	}
}
	return accion;
}



Action ComportamientoJugador::Decision(Sensores sensores){
	Action accion = actIDLE;
	bool avanza = sensores.terreno[2]=='T' or sensores.terreno[2]=='S'; 
	bool condicion = (sensores.agentes[2]=='_') && (!sensores.colision) && (sensores.terreno[2]!='P') && (sensores.terreno[2]!='M');
	bool dejarDeCargar = (sensores.vida < vidaBaja) && ((sensores.vida * factorVidaBateria) < (sensores.bateria));

	if( (sensores.terreno[0] == 'X') && (sensores.bateria < bateria_baja) && !dejarDeCargar )
		recargando = true;
	if(recargando){
		accion = actIDLE;
	if ( (sensores.bateria + 10) > (bateriaRecarga) || dejarDeCargar)
		recargando = false;
		return accion;
	}

	accion = BuscarCasilla(sensores);
	if(accion != actIDLE){

 
	if(accion == actWALK){
	
		if(condicion){
			return accion;
		}
	}
	else{
	return accion;
	}
}
	if(current_state.brujula % 2 == 0 && bien_situado){
	
		if(sensores.terreno[1] != 'M' && sensores.terreno[5] =='M'){
		accion = actTURN_L;
		return accion;
	}
		if(sensores.terreno[3] != 'M' && sensores.terreno[7] =='M'){
		accion = actTURN_SR;
		return accion;
		}
	}

	if(current_state.brujula % 2 == 0 && bien_situado){
		if(sensores.terreno[1] != 'P' && sensores.terreno[5] =='P' && sensores.terreno[7] !='P'){
			accion = actTURN_L;
			return accion;
	}
	if(sensores.terreno[3] != 'P' && sensores.terreno[7] == 'P' && sensores.terreno[7] !='P' ){
		accion = actTURN_SR;
		return accion;
		}
	}
	if(sensores.bateria > (bateria_muy_baja / 1.5)){
		if(bikini)
			avanza = avanza ||sensores.terreno[2]=='A';
	}

		if(sensores.bateria > (bateria_muy_baja / 1.4) ){
			if(zapatillas)
				avanza = avanza ||
				sensores.terreno[2]=='B';
				}

	if((sensores.terreno[0]=='A') )
		avanza = avanza || sensores.terreno[2]=='A';
	if((sensores.terreno[0]=='B'))
		avanza = avanza || sensores.terreno[2]=='B';
	if( (sensores.terreno[0]=='G' || sensores.terreno[0]=='K' || sensores.terreno[0]=='D' || sensores.terreno[0]=='X') || Giros > 50)
		avanza = avanza || sensores.terreno[2]=='B' || sensores.terreno[2]=='A';
	if (avanza && condicion){
		accion = actWALK;
		if(Giros >= 0)
			Giros--;
		}
		else{
			if(girar_derecha){
				accion = actTURN_SR;
			}
			else{
				accion = actTURN_L;
	}
	girar_derecha = (rand()%2 ==0);
	Giros++;
	}

return accion;
}




Action ComportamientoJugador::think(Sensores sensores){

	Action accion = actIDLE;

	if(sensores.reset){
		bien_situado = false;
		bikini = false;
		zapatillas = false;
		recargando = false;
		current_state.brujula = norte;
		
	}

	
	MuestraInformacion(sensores);

	if(!sensores.colision){
		int a;

		switch (last_action){
			case actWALK:
				if(bien_situado){
				switch (current_state.brujula){
					case norte: current_state.fil--; break;
					case noreste: current_state.fil--; current_state.col++; break;
					case este: current_state.col++; break;
					case sureste: current_state.fil++; current_state.col++; break;
					case sur: current_state.fil++; break;
					case suroeste: current_state.fil++; current_state.col--; break;
					case oeste: current_state.col--; break;
					case noroeste: current_state.fil--;current_state.col--; break;
				}
				}
			break;
			case actRUN:
			
			break;
			
			case actTURN_SR:
				a = current_state.brujula;
				a = (a+1)%8;
				current_state.brujula = static_cast<Orientacion>(a);
				break;

			case actTURN_L:
				a = current_state.brujula;
				a = (a + 6) % 8;
				current_state.brujula = static_cast<Orientacion>(a);
				break;



			break;

	}
	}
		

	if ( !bien_situado and ( sensores.terreno[0]=='G' or sensores.posC != -1) )
		Orientarse(sensores);
		

	
	if (bien_situado){
		PonerTerrenoEnMatriz(sensores.terreno,current_state,mapaResultado);
	}	

	if(sensores.terreno[0] == 'K')
		bikini = true;
	if(sensores.terreno[0] == 'D')
		zapatillas = true;
	
	accion = Decision(sensores);
	
	last_action = accion;
	return accion;
}



		




int ComportamientoJugador::interact(Action accion, int valor)
{
	return false;
}





