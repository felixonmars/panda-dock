/*
 * Copyright (C) 2020 PandaOS Team.
 *
 * Author:     rekols <rekols@foxmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef APPSCROLLAREA_H
#define APPSCROLLAREA_H

#include <QScrollArea>
#include <QBoxLayout>
#include <QScroller>
#include "item/appitem.h"

class AppScrollArea : public QScrollArea
{
    Q_OBJECT

public:
    explicit AppScrollArea(QWidget *parent = nullptr);

    QBoxLayout *layout() { return m_mainLayout; };

    void addItem(AppItem *item);
    void removeItem(AppItem *item);
    void scrollToItem(AppItem *item);

    void setRange(int value);
    void setIconSize(int size);

private:
    void onScrollerStateChanged(QScroller::State state);
    void itemDragStarted();
    void handleDragMove(QDragMoveEvent *e, bool isFilter);
    AppItem *itemAt(const QPoint &point);

protected:
    void wheelEvent(QWheelEvent *e) override;
    void dragEnterEvent(QDragEnterEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void dragMoveEvent(QDragMoveEvent *e) override;
    void dropEvent(QDropEvent *e) override;

private:
    AppItem *m_draggingItem;
    QWidget *m_mainWidget;
    QBoxLayout *m_mainLayout;

    int m_range;
    int m_iconSize;
    bool m_dragging = false;
};

#endif // APPSCROLLAREA_H
