#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

  float p1, p2, p3, mediaTurma, mediaAluno;

  cout << fixed;
  cout.precision(1);
  cout << "Insira a nota das 3 provas, respectivamente: " << endl;
  cin >> p1 >> p2 >> p3;
  mediaAluno = (p1 + p2 + p3) / 3;
  cout << "Agora, insira a nota média da turma: " << endl;
  cin >> mediaTurma;
  cout << "Nota média do aluno: " << mediaAluno << endl;
  if (mediaAluno > mediaTurma)
  {
    cout << "Aluno acima da média" << endl;
  }
  else if (mediaAluno == mediaTurma)
  {
    cout << "Aluno na média" << endl;
  }
  else
  {
    cout << "Aluno abaixo da média!" << endl;
  }

  return 0;
}