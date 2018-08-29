/*
 * File infixmanipulator.h
 * created on 29-8-2018
 * by smit
 *
 * <smit17av@gmail.com>
 */
#ifndef INFIXMANIPULATOR_H
#define INFIXMANIPULATOR_H

#include <QObject>

class C_interface : public QObject
{
	Q_OBJECT
public:
	explicit C_interface(QObject *parent = nullptr);
	Q_INVOKABLE QString toPostfix(QString infix);
	Q_INVOKABLE QString toAns(QString postfix);
	Q_INVOKABLE void copyToClipBoard(QString string);



signals:

public slots:
};

#endif // INFIXMANIPULATOR_H
