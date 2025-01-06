#include <QApplication>
#include "LaneLabelingTool.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    LaneLabelingTool window;
    window.show();
    return app.exec();
}
