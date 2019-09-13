#include "Qt_GUI/headers/TextListModel.h"

TextListModel::TextListModel(QObject *parent) : QAbstractListModel(parent) {

}

QVector<QString> TextListModel::items() const {
    return m_items;
}

void TextListModel::appendItem(QString item) {
    m_items.append(std::move(item));
}

