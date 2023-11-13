#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Sala{
    string local;
    int nChaves;
    string portador;
}

struct usuário{
    string Nome;
    string contato;
    string função;
    bool pegouChave;
    string chavepega;
}

main(){

    do{

        cout << "--Menu chave--\n\n";
        
        cout << "1. Cadastrar sala.\n";
        cout << "2. Cadastar autorização.\n";
        cout << "3. Retirar chave\n";
        cout << "4. Devolver Chave\n";
        cout << "5. Listar Chaves\n"
        cout << "6. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao){
        case 1:
            CadastrarSala();
            break;
         
        case 2:
                CadastarUsuario();
                break;
        case 3:
                RetirarChave();
                break;
        case 4:
                DevolverChave();
                break;
        case 5:
                ListarChave();
                break;
        case 6:
                cout << "Até mais.\n";
                break;
        default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    } while (opcao!=6);
}