#include "mainwindowex4.h"
#include "ui_mainwindowex4.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
extern MainWindowEx4 *w;

int idFils1, idFils2, idFils3;
// TO DO : HandlerSIGCHLD
void HandlerSIGCHLD(int);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
MainWindowEx4::MainWindowEx4(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindowEx4)
{
  ui->setupUi(this);
  ui->pushButtonAnnulerTous->setVisible(false);

  // armement de SIGCHLD
  // TO DO
   struct sigaction A;
   // Armement de SIGCHLD
   A.sa_handler = HandlerSIGCHLD;
   sigemptyset(&A.sa_mask);
   A.sa_flags = 0;
   if (sigaction(SIGCHLD,&A,NULL) ==-1)
   {
   perror("Erreur de sigaction");
   exit(1);
   }
}

MainWindowEx4::~MainWindowEx4()
{
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles : ne pas modifier /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowEx4::setGroupe1(const char* Text)
{
  fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditGroupe1->clear();
    return;
  }
  ui->lineEditGroupe1->setText(Text);
}

void MainWindowEx4::setGroupe2(const char* Text)
{
  fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditGroupe2->clear();
    return;
  }
  ui->lineEditGroupe2->setText(Text);
}

void MainWindowEx4::setGroupe3(const char* Text)
{
  fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditGroupe3->clear();
    return;
  }
  ui->lineEditGroupe3->setText(Text);
}

void MainWindowEx4::setResultat1(int nb)
{
  char Text[20];
  sprintf(Text,"%d",nb);
  fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditResultat1->clear();
    return;
  }
  ui->lineEditResultat1->setText(Text);
}

void MainWindowEx4::setResultat2(int nb)
{
  char Text[20];
  sprintf(Text,"%d",nb);
  fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditResultat2->clear();
    return;
  }
  ui->lineEditResultat2->setText(Text);
}

void MainWindowEx4::setResultat3(int nb)
{
  char Text[20];
  sprintf(Text,"%d",nb);
  fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
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

const char* MainWindowEx4::getGroupe1()
{
  if (ui->lineEditGroupe1->text().size())
  { 
    strcpy(groupe1,ui->lineEditGroupe1->text().toStdString().c_str());
    return groupe1;
  }
  return NULL;
}

const char* MainWindowEx4::getGroupe2()
{
  if (ui->lineEditGroupe2->text().size())
  { 
    strcpy(groupe2,ui->lineEditGroupe2->text().toStdString().c_str());
    return groupe2;
  }
  return NULL;
}

const char* MainWindowEx4::getGroupe3()
{
  if (ui->lineEditGroupe3->text().size())
  { 
    strcpy(groupe3,ui->lineEditGroupe3->text().toStdString().c_str());
    return groupe3;
  }
  return NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les boutons ////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowEx4::on_pushButtonDemarrerTraitements_clicked()
{
  fprintf(stderr,"Clic sur le bouton Demarrer Traitements\n");
  // TO DO
  
  int fd;
  if((fd = open("Trace.log", O_WRONLY | O_CREAT | O_APPEND, 0644)) == -1)
  {
    perror("ERREUR d'ouverture du fichier avec open\n");
  }
  if((dup2(fd, 2)) == -1)
  {
    perror("ERREUR de duplication\n");
  }

  if(traitement1Selectionne())
  {
    idFils1 = fork();
    if(idFils1 == -1){
    fprintf(stderr,"---Erreur pour la creation d'un fils");
    exit(1);
    }
    if(idFils1 == 0)
    {
      //code du fils 1
      fprintf(stderr,"je suis le fils 1 :%d\n", getpid());
      
      if( execl("./Traitement", "Traitement", getGroupe1(), "200", NULL) == -1)
      {
        perror("erreur de execl()\n");
        exit(1);
      }
      exit(0);
    }
  }

  if(traitement2Selectionne())
  {
    idFils2 = fork();
    if(idFils2 == -1){
    fprintf(stderr,"---Erreur pour la creation d'un fils");
    exit(1);
    }
    if(idFils2 == 0)
    {
      //code du fils 2
      fprintf(stderr,"je suis le fils 2 :%d\n", getpid());
      
      if( execl("./Traitement", "Traitement", getGroupe2(), "450", NULL) == -1)
      {
        perror("erreur de execl()\n");
        exit(1);
      }
      exit(0);

    }
    
  }
  if(traitement3Selectionne())
  {
    idFils3 = fork();
    if(idFils3 == -1){
    fprintf(stderr,"---Erreur pour la creation d'un fils");
    exit(1);
    }
    if(idFils3 == 0)
    {
      //code du fils 3
      fprintf(stderr,"je suis le fils 3 :%d\n", getpid());
      
      if( execl("./Traitement", "Traitement", getGroupe3(), "700", NULL) == -1)
      {
        perror("erreur de execl()\n");
        exit(1);
      }
      exit(0);

    }
    
  }
  fprintf(stderr,"(PERE) Je realise une tache...\n");
  // while(1) pause();
  

  if(::close(fd))
  {
    perror("ERREUR de close()");
    exit(1);
  }
}

void MainWindowEx4::on_pushButtonVider_clicked()
{
  fprintf(stderr,"Clic sur le bouton Vider\n");
  // TO DO
  ui->lineEditGroupe1->clear();
  ui->lineEditGroupe2->clear();
  ui->lineEditGroupe3->clear();
  ui->lineEditResultat1->clear();
  ui->lineEditResultat2->clear();
  ui->lineEditResultat3->clear();
}

void MainWindowEx4::on_pushButtonQuitter_clicked()
{
  fprintf(stderr,"Clic sur le bouton Quitter\n");
  // TO DO
  exit(0);
}

void MainWindowEx4::on_pushButtonAnnuler1_clicked()
{
  fprintf(stderr,"Clic sur le bouton Annuler1\n");
  // TO DO
  if(idFils1 > 0){kill(idFils1, SIGUSR1);}


}

void MainWindowEx4::on_pushButtonAnnuler2_clicked()
{
  fprintf(stderr,"Clic sur le bouton Annuler2\n");
  // TO DO
  if(idFils2 > 0){kill(idFils2, SIGUSR1);}

}

void MainWindowEx4::on_pushButtonAnnuler3_clicked()
{
  fprintf(stderr,"Clic sur le bouton Annuler3\n");
  // TO DO
  if(idFils3 > 0){kill(idFils3, SIGUSR1);}

}

void MainWindowEx4::on_pushButtonAnnulerTous_clicked()
{
  fprintf(stderr,"Clic sur le bouton Annuler tout\n");
  // NOTHING TO DO --> bouton supprimé
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////// Handlers de signaux //////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

// TO DO : HandlerSIGCHLD
void HandlerSIGCHLD(int sig)
{

  int id, status;

  fprintf(stderr,"\nJ’ai recu le signal no %d\n",sig);
  
  id = wait(&status);
  fprintf(stderr,"\n(PERE) Suppression du fils %d de la table des processus\n",id);
  if (WIFEXITED(status)){
    int code = WEXITSTATUS(status);
    fprintf(stderr,"(PERE) Le fils %d s’est termine par un exit(%d)\n",id,code);
    if(id == idFils1){w->setResultat1(code);}
    if(id == idFils2){w->setResultat2(code);}
    if(id == idFils3){w->setResultat3(code);}
  }
  
}