#include "mainwindowex4.h"
#include "ui_mainwindowex4.h"

extern MainWindowEx4 *w;

int idFils1, idFils2, idFils3;
// TO DO : HandlerSIGCHLD
void handlerSIGCHLD(int sig);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
MainWindowEx4::MainWindowEx4(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindowEx4)
{
  ui->setupUi(this);
  ui->pushButtonAnnulerTous->setVisible(false);

  // armement de SIGCHLD
  fprintf(stderr, "(Traitement %d) Armement du signal SIGALRM\n", getpid());
  struct sigaction A;
  A.sa_handler = handlerSIGCHLD;
  A.sa_flags = 0;
  sigemptyset(&A.sa_mask);
  sigaction(SIGCHLD ,& A, NULL);
}

MainWindowEx4::~MainWindowEx4()
{
  delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles : ne pas modifier /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowEx4::setGroupe1(const char *Text)
{
  //fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0)
  {
    ui->lineEditGroupe1->clear();
    return;
  }
  ui->lineEditGroupe1->setText(Text);
}

void MainWindowEx4::setGroupe2(const char *Text)
{
  //fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0)
  {
    ui->lineEditGroupe2->clear();
    return;
  }
  ui->lineEditGroupe2->setText(Text);
}

void MainWindowEx4::setGroupe3(const char *Text)
{
  //fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0)
  {
    ui->lineEditGroupe3->clear();
    return;
  }
  ui->lineEditGroupe3->setText(Text);
}

void MainWindowEx4::setResultat1(int nb)
{
  char Text[20];
  sprintf(Text, "%d", nb);
  //fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0)
  {
    ui->lineEditResultat1->clear();
    return;
  }
  ui->lineEditResultat1->setText(Text);
}

void MainWindowEx4::setResultat2(int nb)
{
  char Text[20];
  sprintf(Text, "%d", nb);
  //fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0)
  {
    ui->lineEditResultat2->clear();
    return;
  }
  ui->lineEditResultat2->setText(Text);
}

void MainWindowEx4::setResultat3(int nb)
{
  char Text[20];
  sprintf(Text, "%d", nb);
  //fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0)
  {
    ui->lineEditResultat3->clear();
    return;
  }
  ui->lineEditResultat3->setText(Text);
}

bool MainWindowEx4::traitement1Selectionne()
{
  return ui->checkBoxTraitement1->isChecked();
}

bool MainWindowEx4::traitement2Selectionne()
{
  return ui->checkBoxTraitement2->isChecked();
}

bool MainWindowEx4::traitement3Selectionne()
{
  return ui->checkBoxTraitement3->isChecked();
}

const char *MainWindowEx4::getGroupe1()
{
  if (ui->lineEditGroupe1->text().size())
  {
    strcpy(groupe1, ui->lineEditGroupe1->text().toStdString().c_str());
    return groupe1;
  }
  return NULL;
}

const char *MainWindowEx4::getGroupe2()
{
  if (ui->lineEditGroupe2->text().size())
  {
    strcpy(groupe2, ui->lineEditGroupe2->text().toStdString().c_str());
    return groupe2;
  }
  return NULL;
}

const char *MainWindowEx4::getGroupe3()
{
  if (ui->lineEditGroupe3->text().size())
  {
    strcpy(groupe3, ui->lineEditGroupe3->text().toStdString().c_str());
    return groupe3;
  }
  return NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les boutons ////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowEx4::on_pushButtonDemarrerTraitements_clicked()
{
  if (traitement1Selectionne())
  {
    idFils1 = fork();
    if (idFils1 == 0)
    {
      execl("./Traitement", "Traitement", getGroupe1(), "200", NULL);
      perror("Erreur exec Traitement 1");
      exit(1);
    }
  }
  if (traitement2Selectionne())
  {
    idFils2 = fork();
    if (idFils2 == 0)
    {
      execl("./Traitement", "Traitement", getGroupe2(), "450", NULL);
      perror("Erreur exec Traitement 2");
      exit(1);
    }
  }
  if (traitement3Selectionne())
  {
    idFils3 = fork();
    if (idFils3 == 0)
    {
      execl("./Traitement", "Traitement", getGroupe3(), "700", NULL);
      perror("Erreur exec Traitement 3");
      exit(1);
    }
  }
}

void MainWindowEx4::on_pushButtonVider_clicked()
{
  setResultat1(0);
  setResultat2(0);
  setResultat3(0);
}

void MainWindowEx4::on_pushButtonQuitter_clicked()
{
  exit(0);
}

void MainWindowEx4::on_pushButtonAnnuler1_clicked()
{
  if (idFils1 > 0)
  {
    kill(idFils1, SIGUSR1);
  }
}

void MainWindowEx4::on_pushButtonAnnuler2_clicked()
{
  if (idFils2 > 0)
  {
    kill(idFils2, SIGUSR1);
  }
}

void MainWindowEx4::on_pushButtonAnnuler3_clicked()
{
  if (idFils3 > 0)
  {
    kill(idFils3, SIGUSR1);
  }
}

void MainWindowEx4::on_pushButtonAnnulerTous_clicked()
{
  on_pushButtonAnnuler1_clicked();
  on_pushButtonAnnuler2_clicked();
  on_pushButtonAnnuler3_clicked();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////// Handlers de signaux //////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void handlerSIGCHLD(int sig)
{
  int status;
  int x;

  x = wait(&status);

  if (x == idFils1 && WIFEXITED(status))
  {
    w->setResultat1(WEXITSTATUS(status));
  }
  else if (x == idFils2 && WIFEXITED(status))
  {
    w->setResultat2(WEXITSTATUS(status));
  }
  else if (x == idFils3 && WIFEXITED(status))
  {
    w->setResultat3(WEXITSTATUS(status));
  }
}