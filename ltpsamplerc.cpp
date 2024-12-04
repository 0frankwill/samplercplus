#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>

using namespace std;

void tocarNota(int frequencia, int durancao){
    if(frequencia > 0) {
        Beep(frequencia,durancao);
    }
}

void salvarNota (const string& nomeArquivo, int frequencia, int duracao) {
    ofstream arquivo(nomeArquivo, ios::app);
    if (arquivo.is_open()) {
        arquivo << frequencia << " " << duracao << endl;
    }else {
        cout << "ERRO!!!. arquivo nao salvo" << endl; 
    }
}

void reproduzirMusica(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    int frequencia, duracao;
    if (arquivo.is_open()) {
        while (arquivo >> frequencia >> duracao) {
            tocarNota(frequencia, duracao);
        }
    } else {
        cout << "ERRO!!!. ao abrir o arquivo para reproducao" << endl;
    }
}

void violinoVirtual(){
    cout << "Voce esta no violino." << endl;
    cout << "Aperte M para mudar de instrumento ou R para reproduzir a musica, E para encerrar." << endl;
     
    while (true){
        char tecla = getch();

        if (tecla == 'm' || tecla == 'M') {
            cout << "Voltando a escolha de instrumento..." << endl;
            return;
        }
        if (tecla == 'r' || tecla == 'R') {
            cout << " Reproduzindo a musica..." << endl;
            reproduzirMusica("musica_violino.txt");
            continue;
        }

        switch (tecla)
        {
        case 'a':
            tocarNota(250, 400); //do
            salvarNota("musica_violino.txt", 250, 400);
            break;
        case 's':
            tocarNota(280, 400); //re
            salvarNota("musica_violino.txt", 280, 400);
            break;
        case 'd':
            tocarNota(310, 400); //mi
            salvarNota("musica_violino.txt", 310, 400);
            break;
        case 'f':
            tocarNota(340, 400); //fa
            salvarNota("musica_violino.txt", 340,400);
            break;
        case 'g':
            tocarNota(380, 400); //sol
            salvarNota("musica_violino.txt", 380, 400);
            break;     
        case 'h':
            tocarNota(410, 400); //la
            salvarNota("musica_violino.txt", 410, 400);
            break;
        case 'j':
            tocarNota(460, 400); //si
            salvarNota("musica_violino.txt", 460, 400);
            break;
        case 'k':
            tocarNota(490, 400); //do
            salvarNota("musica_violino.txt", 490, 400);
            break;
        case 'l':
            tocarNota(550, 400); //re
            salvarNota("musica_violino.txt", 550, 400);
            break;
        case 'p':
            tocarNota(600, 400); //mi
            salvarNota("musica_violino.txt", 600, 400);
            break;
        case 'e':
            cout << "Encerrando..." <<endl;
            return;
            break;
        default:
            cout << "Tecla nao identificada" << endl;
            break;
        }
    }

} 

void tecladoVirtual(){
    cout << "Voce esta no Teclado." << endl;
    cout << "Aperte M para mudar de instrumento ou R para reproduzir a musica, E para encerrar." << endl;

    while (true){
        char tecla = getch();

        if (tecla == 'm' || tecla == 'M') {
            cout << "Voltando ao menu principal..." << endl;
            return;
        }
        if (tecla == 'r' || tecla == 'R') {
            cout << " Reproduzindo a musica..." << endl;
            reproduzirMusica("musica_teclado.txt");
            continue;
        }

        switch (tecla)
        {
        case 'a':
            tocarNota(261, 400); //C4
            salvarNota("musica_teclado.txt", 261, 400);
            break;
        case 's':
            tocarNota(293, 400); //D4
            salvarNota("musica_teclado.txt", 293, 400);
            break;
        case 'd':
            tocarNota(329, 400); //E4
            salvarNota("musica_teclado.txt", 329, 400);
            break;
        case 'f':
            tocarNota(349, 400); //F4
            salvarNota("musica_teclado.txt", 349, 400);
            break;
        case 'g':
            tocarNota(392, 400); //G4
            salvarNota("musica_teclado.txt", 392, 400);
            break;
        case 'h':
            tocarNota(400, 400); //A4
            salvarNota("musica_teclado.txt", 400, 400);
            break;
        case 'j':
            tocarNota(493, 400); //B4
            salvarNota("musica_teclado.txt", 493, 400);
            break;
        case 'e':
            cout << "Encerrando..." <<endl;
            return;
            break;
        default:
            cout << "Tecla nao identificada" << endl;
            break;
        }
    }

}

void mostrarMenu() {
    cout << "Escolha o instrumento:" << endl;
    cout << "1 - Violino" << endl;
    cout << "2 - Teclado" << endl;
    cout << "Digite a opcao (1 ou 2): ";
}

int main() {
    int opcao;

    while (true) {
        mostrarMenu();
        cin >> opcao;

        if (opcao == 1) {
            violinoVirtual();
        } else if (opcao == 2) {
            tecladoVirtual();
        } else {
            cout << "Opcao invalida." << endl;
        }
    }

    return 0;
}