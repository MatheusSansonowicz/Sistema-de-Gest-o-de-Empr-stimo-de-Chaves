#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#include CadastrarSala.h



struct aluno{
    string Nome;
    string contato;
    string funcao;
    bool pegouChaveA;
    string autorizacao;
}

/*struct RelacaoDeEmprestimo {
        bool emAndamento;
        string NomePegou;
        string salaPega;
        int copiaPega;
}*/

main(){

    do{

        cout << "--Menu chave--\n\n";
        
        cout << "1. Cadastrar sala.\n";
        cout << "2. Cadastar funcionario.\n";
        cout << "3. Cadastar aluno.\n";
        cut << "4. Cadastrar autorizacao.\n"
        cout << "5. Retirar chave\n";
        cout << "6. Devolver Chave\n";
        cout << "7. Listar Chaves\n";
        cout << "8. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao){
        case 1:
            CadastrarSala();
            break;
         
        case 2:
                CadastrarFuncionario();
                break;
        case 3:
                CadastrarAluno();
                break;
        case 4:
                CadastrarAutorizacao();
                break;
        /*case 5:
                ListarChave();
                break; */
        case 8:
                cout << "Ateh mais.\n";
                break;
        default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    } while (opcao!=8);
}