bool salaExistente (string local){
    for ( const Sala& sala : listaSalas){
        if (sala.local== local){
            return true;
        }
    }
    return false;
}

void CadastrarChave(){
    sala novasala;
    string resposta;
    do{
        cout << "Digite o local da nova chave: ";
        cin >> novasala.local
        if (salaExistente(novasala.local)){
            cout << "Sala já registrada, está regristrado mais uma cópia de chave ara esta sala(S/N)?";
            cin >> resposta;
            if (resposta == S || resposta == s || resposta == sim || resposta == Sim){

            }
            else {
                
            }
        }
    }
}