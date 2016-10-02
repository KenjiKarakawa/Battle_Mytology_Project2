#pragma once
#include "ofApp.h"

#include "jogador.h"
#include "mapa.h"
#include "inimigo.h"

Jogador player;
Inimigo inimigo[2];
Mapa mundo;
ofVec2f v;

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::setup(){
	//Iniciando contagem de tempo de execução
	before = ofGetElapsedTimef();

	//Iniciando o Mundo
	mundo.iniciar(0,0);

	//Inicializando o Player
	player.iniciar();

	inimigo[0].iniciar(800,300, mundo.posicao);
	inimigo[1].iniciar(100, 800, mundo.posicao);
	
	v.set(278, 197);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::update(){
	//Atualizando a contagem de tempo de execução do jogo.
		gameTime = ofGetElapsedTimef() - before;
		before = ofGetElapsedTimef();

		
		player.colidiuCom(v, mundo.posicao, mundo.velocidade, 150);
		for (int i = 0; i < 2; i++) {
			player.colidiuCom(inimigo[i].m_posicao, mundo.posicao, mundo.velocidade, inimigo[i].m_spriteTamX / 2.f);
			if (inimigo[i].m_vida > 0) {
				inimigo[i].animar(gameTime);
				inimigo[i].colidiuCom(inimigo, mundo.posicao, i);
				inimigo[i].mover(player.m_posicao, mundo.posicao, player.m_spriteTamX);
				inimigo[i].levardano(player.m_posicao, mundo.posicao, player.m_spriteTamX, teclado);
			}
		}
	//Controlando o player
		player.animacao(gameTime);
		player.acoes(teclado);

	//Controlando o Mundo
		mundo.mover(teclado);


		
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::draw(){
	
	mundo.desenhar();
	ofDrawCircle(mundo.posicao + v, 150);
	ofSetColor(255, 255, 255);
	player.desenhar(mundo.posicao);
	for (int i = 0; i < 2; i++) {
		if(inimigo[i].m_vida > 0)
		 inimigo[i].desenhar(mundo.posicao);
	}
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::keyPressed(int key){
	//Inputs de movimentação
	if ((key == 'W') || (key == 'w'))
		teclado.keyW = true;
	if ((key == 'S') || (key == 's'))
		teclado.keyS = true;
	if ((key == 'A') || (key == 'a'))
		teclado.keyA = true;
	if ((key == 'D') || (key == 'd'))
		teclado.keyD = true;

	//Inputs de ataque
	if (key == OF_KEY_UP)
		teclado.keyUp = true;
	if (key == OF_KEY_DOWN)
		teclado.keyDown = true;
	if (key == OF_KEY_LEFT	)
		teclado.keyLeft= true;
	if (key == OF_KEY_RIGHT)
		teclado.keyRight = true;
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::keyReleased(int key){
	//Inputs de movimentação
	if ((key == 'W') || (key == 'w'))
		teclado.keyW = false;
	if ((key == 'S') || (key == 's'))
		teclado.keyS = false;
	if ((key == 'A') || (key == 'a'))
		teclado.keyA = false;
	if ((key == 'D') || (key == 'd'))
		teclado.keyD = false;

	//Inputs de ataque
	if (key == OF_KEY_UP)
		teclado.keyUp = false;
	if (key == OF_KEY_DOWN)
		teclado.keyDown = false;
	if (key == OF_KEY_LEFT)
		teclado.keyLeft = false;
	if (key == OF_KEY_RIGHT)
		teclado.keyRight = false;
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
