void CadastrarAutorizacao() {
    string nomeAluno, nomeFuncionario;
    int nivelAutorizacao;

    // Pergunta e verifica o nome do aluno
    cout << "Digite o nome do aluno: ";
    cin >> nomeAluno;

    if (!alunoExistente(nomeAluno)) {
        cout << "Aluno não encontrado. Verifique o nome e tente novamente.\n";
        return;
    }

    // Pergunta e verifica o nome do funcionário que autoriza
    cout << "Digite o nome do funcionário que autoriza: ";
    cin >> nomeFuncionario;

    // Verifica se o funcionário existe e tem um nível de autorização adequado
    if (!funcionarioExistente(nomeFuncionario) || obterNivelAutorizacao(nomeFuncionario) < 2) {
        cout << "Funcionário não encontrado ou não tem nível de autorização suficiente.\n";
        return;
    }

    // Pergunta e verifica a sala autorizada
    string salaAutorizada;
    cout << "Digite o nome da sala autorizada: ";
    cin >> salaAutorizada;

    // Verifica se a sala existe
    if (!salaExistente(salaAutorizada)) {
        cout << "Sala não encontrada. Verifique o nome e tente novamente.\n";
        return;
    }

    // Encontrar o aluno na lista
    for (Aluno& aluno : listaAlunos) {
        if (aluno.Nome == nomeAluno) {
            // Atualiza a autorização do aluno
            aluno.autorizacao = salaAutorizada;
            cout << "Autorização cadastrada com sucesso!\n";

            // Chame a função para escrever a lista atualizada no arquivo CSV
            escreverAlunosCSV();
            return;
        }
    }

    cout << "Erro ao cadastrar a autorização.\n";
}
