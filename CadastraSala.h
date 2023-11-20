struct Sala {
    string local;
    int nChaves;
    string portador;
};

vector<Sala> listaSalas; // Certifique-se de que você tem essa declaração em algum lugar do seu código

string salaParaCSV(const Sala& sala) {
    stringstream ss;
    ss << sala.local << "," << sala.nChaves << "," << sala.portador;
    return ss.str();
}

void escreverCSV(const vector<Sala>& salas, const string& nomeArquivo) {
    ofstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        for (const Sala& sala : salas) {
            arquivo << salaParaCSV(sala) << "\n";
        }

        arquivo.close();
        cout << "Arquivo CSV criado com sucesso: " << nomeArquivo << "\n";
    } else {
        cout << "Erro ao abrir o arquivo CSV.\n";
    }
}

bool salaExistente(string local) {
    for (const Sala& sala : listaSalas) {
        if (sala.local == local) {
            return true;
        }
    }
    return false;
}

void CadastrarSala() {
    Sala novaSala;
    string resposta;

    do {
        cout << "Digite o local da nova sala: ";
        cin >> novaSala.local;

        if (salaExistente(novaSala.local)) {
            cout << "Sala já registrada. Deseja registrar mais uma cópia de chave para esta sala? (S/N): ";
            cin >> resposta;
            if (resposta == "S" || resposta == "s" || resposta == "sim" || resposta == "Sim") {
                // Lógica para registrar mais uma cópia de chave
                novaSala.nChaves++; // Adapte conforme necessário
            } else {
                // Lógica para não registrar cópia adicional
                // Adapte conforme necessário
            }
        } else {
            // Lógica para registrar a nova sala
            // Adapte conforme necessário
            novaSala.nChaves = 1; // Definindo o número inicial de chaves
            listaSalas.push_back(novaSala);
            cout << "Nova sala registrada com sucesso!\n";
        }

        // Lógica adicional para continuar o cadastro de salas se necessário
        cout << "Deseja cadastrar outra sala? (S/N): ";
        cin >> resposta;

    } while (resposta == "S" || resposta == "s" || resposta == "sim" || resposta == "Sim");

    // Chame a função para escrever a lista atualizada no arquivo CSV
    escreverCSV(listaSalas, "dados_salas.csv");
}