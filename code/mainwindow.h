#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QMouseEvent>
#include <QTimer>
#include <QTime>
#include <QPixmap>
#include <QSound>

#include "elebackground.h"
#include "eleground.h"
#include "elebird.h"
#include "elepipe.h"
#include "elescoreboard.h"
#include "elereadyboard.h"
#include "eleoverboard.h"
#include "eletitleboard.h"

/* 4 status */
enum GameStatus{GAMETITLE,
                GAMEREADY,
                GAMEPLAY,
                GAMEOVER};

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QPixmap *bufferPixmap;

    /* Buttons on the First interface */
    QPushButton *startButton;
    QPushButton *closeButton;
    QPushButton *infoButton;

    /* Elements that we need to draw */
    EleBackground *background;
    EleGround *ground;
    EleBird *bird;
    ElePipe *pipe[3];
    EleScoreBoard *scoreboard;
    EleReadyBoard *readyboard;
    EleOverBoard *overboard;
    EleTitleBoard *titleboard;

    /* Sound effects*/
    QSound *soundDie;
    QSound *soundHit;
    QSound *soundPoint;
    QSound *soundSwooshing;
    QSound *soundWing;

    int score; // Game score
    QRectF impactBirdRect; // the rectangle used to test the impact of bird.
    GameStatus status;
    QTimer timer; // Main timer, refresh the interface.

    /*Corresponding  to 4 game status or the four interfaces. */
    void gameTitle();
    void gameReady();
    void gamePlay();
    void gameOver();
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void resizeEvent(QResizeEvent *);
public slots:
    void getScore(); // score increase.
    void startGame(); // The button clicked , game began.
    void closeGame(); // The button clicked , game exit.
    void displayInfo(); //The button that shows informations
    void setButtonVisible(bool,bool,bool); // set 3 button visible .
};

#endif // MAINWINDOW_H
