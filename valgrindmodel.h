/* This file is part of KDevelop
 * Copyright 2006-2008 Hamish Rodda <rodda@kde.org>
 * Copyright 2011 Mathieu Lornac <mathieu.lornac@gmail.com>
 * Copyright 2011 Damien Coppel <damien.coppel@gmail.com>
 * Copyright 2011 Lionel Duc <lionel.data@gmail.com>

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifndef KDEV_VALGRIND_MODEL_H
#define KDEV_VALGRIND_MODEL_H

#include <QHash>
#include <QStack>

#include "ivalgrinditem.h"

class ValgrindError;
class ValgrindFrame;
class ValgrindStack;


/**
 * A class that represents the item model
 * \author Hamish Rodda \<rodda@kde.org\>
 */
class ValgrindModel : public QAbstractItemModel, public ValgrindItem
{
  Q_OBJECT

public:

    ValgrindModel(QObject* parent = 0);

    virtual ~ValgrindModel();

    enum Columns {
        //Index = 0,
        Function,
        Source,
        Object
    };

    static const int numColumns = 1;

    // Item
    virtual ValgrindItem* parent() const { return 0L; }

    // Model
    QModelIndex indexForItem(ValgrindItem* item, int column = 0) const;
    ValgrindItem* itemForIndex(const QModelIndex& index) const;

    virtual void incomingData(QString name, QString value);
    virtual int columnCount ( const QModelIndex & parent = QModelIndex() ) const;
    virtual QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
    virtual QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    virtual QModelIndex index ( int row, int column, const QModelIndex & parent = QModelIndex() ) const;
    virtual QModelIndex parent ( const QModelIndex & index ) const;
    virtual int rowCount ( const QModelIndex & parent = QModelIndex() ) const;

    enum eElementType {
      startError,
      error,
      startFrame,
      frame,
      startStack,
      stack
    };

    void newFrame();
    void newError();
    void newStartError();

public slots:

    /**
     * Reception of a new item in the model
     */
    void newElement(ValgrindModel::eElementType);
    void newData(ValgrindModel::eElementType, QString name, QString value);
    void reset();

 public:
    // private:
    QList<ValgrindError*> errors;
    ValgrindError *m_error;
    ValgrindStack *m_stack;
    ValgrindFrame *m_frame;
    void insertIntoTree(ValgrindModel::eElementType);
};

#endif
