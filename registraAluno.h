struct Aluno {
    string Nome;
    string contato;
    bool pegouChaveA;
    string autorizacao;
};

vector<Aluno> listaAlunos;

string alunoParaCSV(const Aluno& aluno) {
    stringstream ss;
    ss << aluno.Nome << "," << aluno.contato << "," << aluno.pegouChaveA << "," << aluno.autorizacao;
    return ss.str();
}

void escreverAlunosCSV() {
    ofstream arquivo("dados_alunos.csv");

    if (arquivo.is_open()) {
        for (const Aluno& aluno : listaAlunos) {
            arquivo << alunoParaCSV(aluno) << "\n";
        }

        arquivo.close();
        cout << "Arquivo CSV de alunos criado com sucesso.\n";
    } else {
        cout << "Erro ao abrir o arquivo CSV de alunos.\n";
    }
}

bool alunoExistente(const string& nome) {

    for (const Funcionario& funcionario : listaFuncionarios) {
            arquivo << funcionarioParaCSV(funcionario) << "\n";
        }
        
    for (const Aluno& aluno : listaAlunos) {
        if (aluno.Nome == nome) {
            return true;
        }
    }
    return false;
}

void CadastrarAluno() {
    Aluno novoAluno;

    do {
        cout << "Digite o nome do novo aluno: ";
        cin >> novoAluno.Nome;

        if (alunoExistente(novoAluno.Nome)) {
            cout << "Nome já registrado. Tente novamente.\n";
        }

    } while (alunoExistente(novoAluno.Nome));

    cout << "Digite o contato do novo aluno: ";
    cin >> novoAluno.contato;

    // Lógica para registrar o novo aluno
    listaAlunos.push_back(novoAluno);
    cout << "Novo aluno registrado com sucesso!\n";

    // Chame a função para escrever a lista atualizada no arquivo CSV
    escreverAlunosCSV();
}
