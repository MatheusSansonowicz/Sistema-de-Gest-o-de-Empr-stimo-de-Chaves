struct funcionario{
    string Nome;
    string contato;
    int funcao;
    /*bool pegouChave;*/
}

vector<Funcionario> listaFuncionarios;

string funcionarioParaCSV(const Funcionario& funcionario) {
    stringstream ss;
    ss << funcionario.Nome << "," << funcionario.contato << "," << funcionario.funcao;
    return ss.str();
}

void escreverFuncionariosCSV() {
    ofstream arquivo("dados_funcionarios.csv");

    if (arquivo.is_open()) {
        for (const Funcionario& funcionario : listaFuncionarios) {
            arquivo << funcionarioParaCSV(funcionario) << "\n";
        }

        arquivo.close();
        cout << "Arquivo CSV de funcionarios criado com sucesso.\n";
    } else {
        cout << "Erro ao abrir o arquivo CSV de funcionarios.\n";
    }
}

bool pessoaExistente(const string& nome) {
    for (const Funcionario& funcionario : listaFuncionarios) {
        if (funcionario.Nome == nome) {
            return true;
        }
    }

    for (const Aluno& aluno : listaAlunos) {
        if (aluno.Nome == nome) {
            return true;
        }
    }

    return false;
}

void CadastrarFuncionario() {
    Funcionario novoFuncionario;

    do {
        cout << "Digite o nome do novo funcionario: ";
        cin >> novoFuncionario.Nome;

        if (pessoaExistente(novoFuncionario.Nome)) {
            cout << "Nome já registrado. Tente novamente.\n";
        }

    } while (pessoaExistente(novoFuncionario.Nome));

    cout << "Digite o contato do novo funcionario: ";
    cin >> novoFuncionario.contato;

    cout << "Nivel de autorização do novo funcionario: \n";
    cout << "1. Básico (faxineiro/ cozinheiro /etc)\n";
    cout << "2. Médio (professor e outras funcoes mais importantes)\n";
    cout << "3. Alto (Membros da administracao, ex: diretor, vicerdiretor.)\n";
    cout << "Digite o nivel: "
    cin >> novoFuncionario.funcao;

    // Lógica para registrar o novo funcionario
    listaFuncionarios.push_back(novoFuncionario);
    cout << "Novo funcionario registrado com sucesso!\n";

    // Chame a função para escrever a lista atualizada no arquivo CSV
    escreverFuncionariosCSV();
}