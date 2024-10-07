#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QPushButton>
#include <QColorDialog>
#include <QTabWidget>
#include <QLabel>
#include <QPalette>
#include <QFontDialog>
#include <QFileDialog>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget *window = new QWidget;
    window->setWindowTitle("example");
    window->resize(300, 300);
    QTabWidget *tabwidget = new QTabWidget;
    QWidget *tab1 = new QWidget;
    QWidget *tab2 = new QWidget;
    QWidget *tab3 = new QWidget;
    QWidget *tab4 = new QWidget;
    tabwidget->addTab(tab1, "組長");
    tabwidget->addTab(tab2, "組員1");
    tabwidget->addTab(tab3, "組員2");
    tabwidget->addTab(tab4, "組員3");
    QVBoxLayout *tab1Layout = new QVBoxLayout;
    QLabel *leaderLabel = new QLabel("黃建宗41043260\n謝於潔41243109\n洪翊評41243223\n李瑋澄50915104");
    tab1Layout->addWidget(leaderLabel);
    tab1->setLayout(tab1Layout);

    //組員1




    //組員2




    //組員3
    QVBoxLayout *tab4Layout = new QVBoxLayout;
    QPushButton *fileButton = new QPushButton("選擇檔案並更改文字");
    tab4Layout->addWidget(fileButton);
    tab4->setLayout(tab4Layout);
    //檔案選擇功能
    QObject::connect(fileButton, &QPushButton::clicked, [&]() {
        QString filePath = QFileDialog::getOpenFileName(window, "選擇檔案");
        if (!filePath.isEmpty()) {
            leaderLabel->setText(filePath);
        }
    });



    // 設定 Layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(tabwidget);
    window->setLayout(layout);

    window->show();
    return app.exec();
}
