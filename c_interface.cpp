/*
 * File infixmanipulator.cpp
 * created on 29-8-2018
 * by smit
 *
 * <smit17av@gmail.com>
 */
#include "c_interface.h"
#include "C/infixtoposfix.h"
#include <QDebug>
#include <sstream>
#include <QClipboard>
#include <QGuiApplication>

extern "C"{
long double EvaluatePostfix(char *postfix);
}

C_interface::C_interface(QObject *parent) : QObject(parent) { }


QString C_interface::toPostfix(QString infix)
{
	infix.append(' ');
	QString posfix = InfixToPostfix(const_cast<char*>( infix.toStdString().c_str()));
	return posfix;
}

QString C_interface::toAns(QString postfix)
{
	for(char a : postfix.toStdString())
	{
		if( (a > 64 && a < 91) || (a > 96 && a < 123) )
			return QString(" ");
	}

	long double ans = EvaluatePostfix(const_cast<char*>( postfix.toStdString().c_str()));

	std::stringstream ss ;
	ss << ans;
	return QString::fromStdString(ss.str());
}

void C_interface::copyToClipBoard(QString string)
{
	QClipboard *clipB = QGuiApplication::clipboard();
	clipB->setText(string);
}

