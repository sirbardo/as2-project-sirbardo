#ifndef DELAUNAYMANAGER_H
#define DELAUNAYMANAGER_H

#include <QFrame>

#include <viewer/mainwindow.h>

#include <viewer/drawable_objects/drawableboundingbox2d.h>
#include "drawableboundingtriangle.h"
#include "drawabledelaunaytriangulation.h"
#include "drawablevoronoi.h"


namespace Ui {
    class DelaunayManager;
}

class DelaunayManager : public QFrame {
    Q_OBJECT

public:
    /***************************
    * Constructors/Destructors *
    ***************************/

    explicit DelaunayManager(QWidget *parent = 0);
    ~DelaunayManager();

protected:

private:
    /************
    * UI fields *
    *************/

    Ui::DelaunayManager *ui;
    MainWindow& mainWindow;

    /*****************
    * Private fields *
    *****************/

    const DrawableBoundingBox2D boundingBox; //it is const because, once defined and initialized, it will never change!
    const DrawableBoundingTriangle boundingTriangle;
    DrawableDelaunayTriangulation triangulation;
    DrawableVoronoi voronoi;

    /*****************
    * Private methods *
    *****************/

    void fitScene();

private slots:

    /********
    * Slots *
    ********/

    /** UI slots **/
    void on_enablePickingCheckBox_stateChanged(int arg1);
    void on_resetScenePushButton_clicked();
    void on_loadPointsPushButton_clicked();

    void on_clearPointsPushButton_clicked();
    void on_showBoundingTriangleCheckBox_stateChanged(int arg1);
    void on_checkTriangulationPushButton_clicked();
    void on_generatePointsFilePushButton_clicked();
    void on_clearVoronoiDiagramPushButton_clicked();
    void on_voronoiDiagramPushButton_clicked();

    /** Point clicked receiver **/
    void point2DClicked(const Point2Dd& p);

};

#endif // DELAUNAYMANAGER_H
