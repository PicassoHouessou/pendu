#ifndef PROJET_JEUX_H
#define PROJET_JEUX_H

#include <QMainWindow>
#include<QtWidgets>
#include<QtSql>
#include<QtNetwork>
#include"ui_projet_jeux.h"



namespace Ui {
class Projet_Jeux;
}

class Projet_Jeux : public QMainWindow, private Ui::Projet_Jeux
{
    Q_OBJECT

public:
    explicit Projet_Jeux( QWidget *parent = nullptr);
    ~Projet_Jeux();

public slots:
    //slots du premier stackedwidget
    void quittez_clicked();
    void connexion_clicked();

    //slots du second stackedWidget
    void liste_clicked();
    void score_clicked();
    void deconnexion_clicked();
    void jeux_clicked();
    void envoyer_clicked();

    //slots au serveur et à la base de donnée
   //void donneEnvoyer();
    void donneeRecues();
    void connecte();
    void erreurSocket(QAbstractSocket::SocketError erreur);



private:
    Ui::Projet_Jeux *ui;
    QTcpSocket *socket;
    int tailleMessage;
    QString mot;
    int compteur= 3;
        int trouv=0;

    //***************************************************
    //Les Widgets et le QStackedWidget
    QWidget *firstfenetre, *secondfenetre, *thirdfenetre;
    QStackedWidget *stackedd, *stacked2, *stacked;

    //***************************************************



    //***************************************************
    //Le premier QStackedWidget
    //***************************************************

    QPushButton *connexion, *quittez;
    QVBoxLayout *vlayout, *vlayout1, *vlayout2;
    QHBoxLayout *hlayout, *hlayout1, *hlayout2, *hlayout3, *hlayout4, *hlayout5, *hlayout6;
    QLabel *label, *label1, *label2, *label3, *label4;
    QSpinBox *spinbox;
    QScrollArea *scroll;
    QGroupBox *groupe;
    QLineEdit *login, *pass, *ip;
    QHBoxLayout *quitter;
    //*****************************************************


    //*****************************************************
    //Le second QStackedWidget
    //*****************************************************
    QPushButton *liste, *ligne, *deconnexion, *score, *jeux;
      QGroupBox *groupebox, *groupebox1, *groupebox2;
      QHBoxLayout *hayout, *hayout1, *hayout2, *hayout3, *hayout4;
      QVBoxLayout *vayout, *vayout1, *ayout,  *vayou;
      QScrollArea *scrolltout, *scroll_bouton;
      QTextEdit *text_accueil;



      //*****************************************************
      //Le troisième QStackedWidget
      //*****************************************************
      QPushButton *envoyer, *deconnecter, *generer;

      QHBoxLayout *hayout_3, *hayout_31, *hayout_32, *hayout_33, *hayout_34;

      QVBoxLayout *vayout_3, *vayout_31,  *ayout_32,  *vayou_33;

      QScrollArea *scroll_tout_3;

      QLabel *nombre, *indice, *titre, *ecrive, *indice_db, *nombre_essai;

      QLineEdit *mot_envoyer;




};

#endif // PROJET_JEUX_H
