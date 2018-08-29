/*
 * File %{Cpp:License:FileName}
 * created on 28-8-2018
 * by smit
 *
 * <smit17av@gmail.com>
 */
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "c_interface.h"


int main(int argc, char *argv[])
{
	qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QGuiApplication app(argc, argv);


	qmlRegisterType<C_interface>("Smit.Is.Cool",1,0,"InfixToPostfix");

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	return app.exec();
}
