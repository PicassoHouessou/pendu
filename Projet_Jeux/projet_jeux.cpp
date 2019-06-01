#include "projet_jeux.h"
#include "ui_projet_jeux.h"
#include<iostream>
using namespace std;

Projet_Jeux::Projet_Jeux(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Projet_Jeux)
{

   ui->setupUi(this);
   setFont(QFont("Century Schoolbook L"));
   setFixedSize(700, 375);




   //***********************************************************************************************************************************************************************************
   // Le premier Stacked
   //***********************************************************************************************************************************************************************************
   //Les boutons de la fenêtres

    connexion = new QPushButton("Connexion");
    connexion->setCursor(Qt::PointingHandCursor);
    connexion->setStyleSheet("QPushButton{background:green; color:white}");
    connexion->minimumSize();


    quittez = new QPushButton("Quittez");
    quittez->setCursor(Qt::PointingHandCursor);
    quittez->setStyleSheet("QPushButton{background:green; color:white}");
    quittez->setCursor(Qt::PointingHandCursor);
//*****************************************************************


    //*****************************************************************
    //L'image, le texte au dessus et leurs positionnements

    label = new QLabel(" Veuillez utiliser votre login et votre \n password pour vous connecter. \nL'adresse IP et ainsi que le Port sont \nrespectivement 127.0.0.1 et 9089.");
    label1= new QLabel;
    label1->setPixmap(QPixmap("/home/elipson/C++/Projet_Jeux/image.jpeg"));

    vlayout = new QVBoxLayout;
    vlayout->addWidget(label);
    vlayout->addWidget(label1);
//***************************************************************




    //*******************************************************
    //Le groupe box pour la connexion

    groupe = new QGroupBox("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tConnexion");


    label1 = new QLabel("Login : \t\t");
    label2 = new QLabel("Password : \t");
    label3 = new QLabel("IP : \t\t");
    label4 = new QLabel("Port : \t\t");

    login = new QLineEdit;
    login->setWhatsThis("Entrer votre login");
    login->setStyleSheet("QLineEdit{ background: silver}");

    pass = new QLineEdit;
    pass->setWhatsThis("Entrer votre mot de passse");
    pass->setStyleSheet("QLineEdit{ background: silver}");
    pass->setEchoMode(QLineEdit::Password);

    ip = new QLineEdit;
    ip->setWhatsThis("Entrer l'IP du serveur");
    ip->setStyleSheet("QLineEdit{ background: silver}");

    spinbox = new QSpinBox;
    spinbox->setWhatsThis("Entrer le Port du serveur");
    spinbox->setRange(0, 10000000);
    spinbox->setStyleSheet("QSpinBox{ background: silver}");



    hlayout = new QHBoxLayout;
    hlayout->addWidget(label1);
    hlayout->addWidget(login);

    hlayout1 = new QHBoxLayout;
    hlayout1->addWidget(label2);
    hlayout1->addWidget(pass);


    hlayout2 = new QHBoxLayout;
    hlayout2->addWidget(label3);
    hlayout2->addWidget(ip);


    hlayout3 = new QHBoxLayout;
    hlayout3->addWidget(label4);
    hlayout3->addWidget(spinbox);

    hlayout6 = new QHBoxLayout;
    hlayout6->addWidget(connexion);
    hlayout6->addWidget(quittez);


    QSpacerItem *espace = new QSpacerItem(50, 50);
    QSpacerItem *espace1 = new QSpacerItem(15, 15);



    vlayout2 = new QVBoxLayout;
      vlayout2->addLayout(hlayout);
       vlayout2->addItem(espace1);
     vlayout2->addLayout(hlayout1);
      vlayout2->addItem(espace1);
    vlayout2->addLayout(hlayout2);
     vlayout2->addItem(espace1);
    vlayout2->addLayout(hlayout3);
    vlayout2->addItem(espace);
    vlayout2->addLayout(hlayout6);

    vlayout2->addStretch(5);

     groupe->setLayout(vlayout2);


    //**************************************************************




     //**************************************************************
     //Le positionnement du groupe Box et du ScrollArea

     hlayout4 = new QHBoxLayout;
     hlayout4->addLayout(vlayout);
     hlayout4->addWidget(groupe);
     hlayout4->setAlignment(Qt::AlignCenter);
     hlayout4->setSpacing(10);
     //****************************************************************



     //****************************************************************
     //Barre de Tâche
     //***************************************************************




//********************************************
//Widget et StackedWidget

     firstfenetre = new QWidget;
     firstfenetre->setLayout(hlayout4);
     firstfenetre->setMaximumWidth(750);
//*********************************************************************************************************************************************************************************


//*********************************************************************************************************************************************************************************
// Le second StackedWidget
//*********************************************************************************************************************************************************************************

                 //*********************************************************
                   //Les boutons de la fenêtres

                              liste = new QPushButton("Liste des Jeux");
                              liste->setCursor(Qt::PointingHandCursor);
                              liste->setStyleSheet("QPushButton{background:green; color:white}");
                              liste->minimumSize();


                              score = new QPushButton("Meilleurs Scores");
                              score->setCursor(Qt::PointingHandCursor);  
                              score->setStyleSheet("QPushButton{background:green; color:white}");


                              deconnexion = new QPushButton("Deconnexion");
                              deconnexion->setCursor(Qt::PointingHandCursor);
                              deconnexion->setStyleSheet("QPushButton{background:green; color:white}");


                              jeux = new QPushButton("Pendul");
                              jeux->setCursor(Qt::PointingHandCursor);
                              jeux->setStyleSheet("QPushButton{background:green; color:white}");
                   //**************************************************************************************


                   //**************************************************************************************
                   //Les layout pour les boutons et le ScrollArea pour les boutons

                              ayout = new QVBoxLayout;
                              ayout->addWidget(liste);
                              ayout->addItem(espace1);
                              ayout->addWidget(score);
                              ayout->addItem(espace1);
                              ayout->addWidget(deconnexion);
                              ayout->setMargin(50);
                              ayout->addStretch(3);

                              vayou=new QVBoxLayout;
                              vayou->addWidget(jeux);
                              vayou->setMargin(70);

                              scroll_bouton = new QScrollArea;
                              scroll_bouton->setLayout(ayout);


                  //***************************************************************



                  //***************************************************************
                              //Les éléments du StackedWidget

                              text_accueil = new QTextEdit;

                              groupebox = new QGroupBox("Liste des Jeux");

                              groupebox->setLayout(vayou);

                              groupebox1 = new QGroupBox("Meilleurs Scores");
                              groupebox2 = new QGroupBox("Joueurs en Ligne");

                              stacked2 = new QStackedWidget;
                              stacked2->addWidget(text_accueil);
                              stacked2->addWidget(groupebox);
                              stacked2->addWidget(groupebox1);
                              stacked2->addWidget(groupebox2);

                  //******************************************************************


                  //*****************************************************************
                          //Positionnement du scroll et du stacked2 sur le Widget et dans le secondWidget

                              hayout4 = new QHBoxLayout;
                              hayout4->addWidget(scroll_bouton);
                              hayout4->addWidget(stacked2);

                              scrolltout = new QScrollArea;
                              scrolltout->setLayout(hayout4);

                              vayout1 = new QVBoxLayout;
                              vayout1->addWidget(scrolltout);

                              secondfenetre = new QWidget;
                              secondfenetre->setLayout(vayout1);

//********************************************************************************************************************************************************************************************
//********************************************************************************************************************************************************************************************



//*******************************************************************************************************************************************************************************************
                              //Le troisième stacked


                              envoyer = new QPushButton("Envoyer");
                              envoyer->setCursor(Qt::PointingHandCursor);
                              envoyer->setStyleSheet("QPushButton{background-color:green;color: white; font-weight:bold; font-family: Century Schoolbook L}");

                              generer = new QPushButton("Generer un indice");
                              generer->setCursor(Qt::PointingHandCursor);
                              generer->setStyleSheet("QPushButton{background-color:green;color: white; font-weight:bold; font-family: Century Schoolbook L}");


                              deconnecter = new QPushButton("Deconnexion");
                              deconnecter->setCursor(Qt::PointingHandCursor);
                              deconnecter->setStyleSheet("QPushButton{background-color:green; color: white; font-weight:bold; font-family: Century Schoolbook L}");



                              indice = new QLabel("Indice");
                              indice->setStyleSheet("QLabel{font-weight:bold; font-family: Century Schoolbook L}");

                              nombre = new QLabel("Nombre d'essai");
                              nombre->setStyleSheet("QLabel{font-weight:bold; font-family: Century Schoolbook L}");

                              titre  = new QLabel("JEU DE PENDU");
                              titre->setStyleSheet("QLabel{font-weight:bold; font-family: Century Schoolbook L}");
                              titre->setAlignment(Qt::AlignCenter);

                              ecrive = new QLabel("Ecriver le mot");
                              ecrive->setStyleSheet("QLabel{font-weight:bold; font-family: Century Schoolbook L}");





                              nombre_essai = new QLabel("0");

                              indice_db = new QLabel("Indice pour le mot");
                              indice_db->setStyleSheet("QLabel{font-weight:bold; font-family: Century Schoolbook L}");

                              mot_envoyer = new QLineEdit;




                              vayout_3 = new QVBoxLayout;
                              vayout_3->addWidget(titre);

                              hayout_31 = new QHBoxLayout;
                              hayout_31->addWidget(nombre);
                              hayout_31->addWidget(nombre_essai);

                              hayout_32 = new QHBoxLayout;
                              hayout_32->addWidget(indice);
                              hayout_32->addWidget(indice_db);


                              vayout_31 = new QVBoxLayout;
                              vayout_31->addLayout(hayout_31);
                              vayout_31->addLayout(hayout_32);
                              vayout_31->setMargin(30);
                              vayout_31->addStretch(5);

                              scroll_tout_3 = new QScrollArea;
                              scroll_tout_3->setLayout(vayout_31);



                              ecrive = new QLabel;
                              ecrive->setText("Ecriver le mot: ");

                              hayout_34 = new QHBoxLayout;
                              hayout_34->addWidget(ecrive);

                              hayout_34->addWidget(mot_envoyer);



                              hayout_33 = new QHBoxLayout;
                              hayout_33->addWidget(envoyer);
                              hayout_33->addWidget(generer);
                              hayout_33->addWidget(deconnecter);



                              ayout_32 = new QVBoxLayout;
                              ayout_32->addLayout(vayout_3);
                              ayout_32->addWidget(scroll_tout_3);connect(ui->actionQuittez, SIGNAL(triggered()), this, SLOT(quittez_clicked()));
                              connect(ui->actionAbout_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
                              ayout_32->addLayout(hayout_34);
                              ayout_32->addLayout(hayout_33);
                                hayout_33->setMargin(25);




                              thirdfenetre = new QWidget;
                              thirdfenetre->setLayout(ayout_32);
                               thirdfenetre->setMaximumWidth(750);




                              //**********************************
                              //Le dernier positionnement dans la fenetre des StackedWidget

                              stackedd = new QStackedWidget;
                              stackedd->addWidget(firstfenetre);
                              stackedd->addWidget(secondfenetre);
                              stackedd->addWidget(thirdfenetre);
                              this->setCentralWidget(stackedd);




     //********************************************************************************
     //Les signals et slots

     //Le premier StackedWidget
     connect(ui->actionQuittez, SIGNAL(triggered()), this, SLOT(quittez_clicked()));
     connect(ui->actionAbout_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
      connect(quittez, SIGNAL(clicked()), this, SLOT(quittez_clicked()));
      connect(connexion, SIGNAL(clicked()), this, SLOT(connexion_clicked()));

      //********************************************************************************



      //********************************************************************************
       //Les signals et slots
      //Le second StackedWidget

      connect(liste, SIGNAL(clicked()), this, SLOT(liste_clicked()));
      connect(jeux, SIGNAL(clicked()), this, SLOT(jeux_clicked()));
      connect(score, SIGNAL(clicked()), this, SLOT(score_clicked()));
      connect(deconnexion, SIGNAL(clicked()), this, SLOT(deconnexion_clicked()));

//****************************************************


      //********************************************************************************
      //Les signals et slots

      //Le troisième StackedWidget

      connect(quittez, SIGNAL(clicked()), this, SLOT(quittez_clicked()));
      connect(deconnecter, SIGNAL(clicked()), this, SLOT(quittez_clicked()));

      //********************************************************************************





      //La connexion à la base de donnée et au serveur
      socket = new QTcpSocket(this);

      connect(socket, SIGNAL(connected()), this, SLOT(connecte()));
      connect(socket, SIGNAL(readyRead()), this, SLOT(donneeRecues()));
      connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(erreurSocket(QAbstractSocket::SocketError)));
      connect(envoyer, SIGNAL(clicked()), this, SLOT(envoyer_clicked()));
      connect(generer, SIGNAL(clicked()), this, SLOT(envoyer_clicked()));


      tailleMessage =0;


}

void Projet_Jeux::quittez_clicked()
{
    int rep = QMessageBox::critical(this, "Quittez", "Voulez-vous quitter?", QMessageBox::No | QMessageBox::Yes);

    if (rep == QMessageBox::No)
    {
        this->show();
    }else
    {
        this->close();
    }
}
void Projet_Jeux::connexion_clicked()
{
   QString user =  login->text();
    QString word = pass->text();
    if(!user.isEmpty() || !word.isEmpty())
    {
    socket->abort();
    socket->connectToHost(ip->text(), spinbox->value());
    }
}


void Projet_Jeux::liste_clicked()
{
    stacked2->setCurrentIndex(1);
}

void Projet_Jeux::score_clicked()
{
    stacked2->setCurrentIndex(2);
}

void Projet_Jeux::deconnexion_clicked()
{
    stackedd->setCurrentIndex(0);
}

Projet_Jeux::~Projet_Jeux()
{}

void Projet_Jeux::jeux_clicked()
{
    stackedd->setCurrentIndex(2);
}

void Projet_Jeux::connecte()
{
 text_accueil->setText("Connexion Réussie!");
  stackedd->setCurrentIndex(1);
}

void Projet_Jeux::erreurSocket(QAbstractSocket::SocketError erreur)
{
    switch(erreur) // On affiche un message différent selon l'erreur qu'on nous indique
    {
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::critical(this, "Erreur", "<em>ERREUR : le serveur \n n'a pas pu être trouvé. \nVérifiez l'IP et le port.</em>");
        stackedd->setCurrentIndex(0);
        break;
    case QAbstractSocket::ConnectionRefusedError:
         QMessageBox::critical(this, "Erreur", "<em>ERREUR : le serveur \n a refusé la connexion. \nVérifiez si le programme \"serveur\" a \n bien été lancé. \n Vérifiez aussi l'IP et \n le port.</em>");
         stackedd->setCurrentIndex(0);
         break;
    case QAbstractSocket::RemoteHostClosedError:
        QMessageBox::critical(this, "Erreur", "<em>ERREUR : le serveur a \n coupé la connexion.</em>");
        stackedd->setCurrentIndex(0);
        break;
    default:
       QMessageBox::critical(this, "Erreur", "<em>ERREUR : " + socket->errorString() + "\n</em>");
        stackedd->setCurrentIndex(0);
    }
}

void Projet_Jeux::envoyer_clicked()
{

    generer->setEnabled(false);
    generer->setStyleSheet("QPushButton{color: white}");
    QTextStream out(socket);
    // On prépare le paquet à envoyer

    QString messageAEnvoyer = (mot_envoyer->text());
    //out << (quint16) 0;
    out <<messageAEnvoyer<<endl;
    qDebug()<<messageAEnvoyer;
    //  out.device()->seek(0);
   // out << (quint16) (paquet.size() - sizeof(quint16));
    //socket->write(paquet); // On envoie le paquet

    mot_envoyer->clear(); // On vide la zone d'écriture du message
    mot_envoyer->setFocus(); // Et on remet le curseur à l'intérieur
    // Appuyer sur la touche Entrée a le même effet que cliquer sur le bouton "Envoyer"


}


/*void FenClient::on_lineEdit_3_returnPressed()
    {
    on_pushButton_2_clicked();
    }*/
// On a reçu un paquet (ou un sous-paquet)

void Projet_Jeux::donneeRecues()
{
    /* Même principe que lorsque le serveur reçoit un paquet :
    On essaie de récupérer la taille du message
    Une fois qu'on l'a, on attend d'avoir reçu le message entier (en se
    basant sur la taille annoncée tailleMessage)
    */
    QTextStream in(socket);

    if (tailleMessage == 0)
    {
        cout<<"Etape 1"<<endl;
        if (socket->bytesAvailable() < (int)sizeof(quint16))
        {
            cout<<"Etape 2"<<endl;
            return;
        }
    }
    in >> tailleMessage;
    cout<<"Etape 3"<<endl;
    if (socket->bytesAvailable() < tailleMessage)
    {
        cout<<"Etape 4"<<endl;
        return;
    }
    // Si on arrive jusqu'à cette ligne, on peut récupérer le message entier

    cout<<"Etape 5"<<endl;

      QString messageRecu;

    in >> messageRecu;

    if(messageRecu == true)
    {

        trouv=+1;
        QMessageBox::information(this, "Gagner", "Vous avez trouver le mot");
    }else if(messageRecu == false)
    {
        int comp = compteur--;
        QMessageBox::critical(this, "Echec", "Vous n'avez pas trouvé le mot et il vous reste "+QString::number(comp)+" esssais");

        if(compteur == 0)
        {
            QMessageBox::critical(this, "Echec", "Vous avez trouve "+QString::number(trouv)+"\nGAME OVER");
            this->close();

        }
    }
    indice_db->setText(messageRecu);
    nombre_essai->setText(QString::number(compteur));
    // On affiche le message sur la zone de Chat

    // On remet la taille du message à 0 pour pouvoir recevoir de futurs messages
    tailleMessage = 0;
}
