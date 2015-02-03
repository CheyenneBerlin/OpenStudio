/**********************************************************************
 *  Copyright (c) 2008-2015, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#ifndef AIRFLOW_CONTAM_PRJREADER_HPP
#define AIRFLOW_CONTAM_PRJREADER_HPP

#include <../utilities/core/LogMessage.hpp>
#include <qsharedpointer_impl.h>
#include <qstring.h>
#include <qstringlist.h>
#include <qtextstream.h>
#include <qvector.h>
#include <QFile>
#include <QSharedPointer>
#include <QStringList>
#include <QVector>
#include <memory>
#include <string>
#include <vector>

#include "../utilities/core/Logger.hpp"
#include "PrjDefines.hpp"

class QFile;

namespace openstudio {
namespace contam {

class Reader
{
public:
  explicit Reader(QFile *file);
  explicit Reader(QString *string, int starting=0);
  ~Reader();

  float readFloat();
  double readDouble();
  std::string readString();
  int readInt();
  unsigned readUInt();

  std::string readLine();
  void read999();
  void read999(std::string mesg);
  void readEnd();

  void skipSection();
  std::string readSection();
  int lineNumber(){return m_lineNumber;}

  template <class T> std::vector<T> readSectionVector(std::string name=std::string());

  std::vector<int> readIntVector(bool terminated=false);
  //    std::vector<int> readIntStdVector(bool terminated=false);
  //    template <class T> QList<T*> readSectionPointers(std::string name=STRING_INIT);
  //    template <class T> QList<T> readSectionList(STRING name=STRING_INIT);
  //    template <class T, template <class T> class V> V<T> readSectionVector(STRING name);
  //    template <class T> QVector<T> readSectionQVector(STRING name=STRING_INIT);
  //    template <class T> std::vector<T> readSectionStdVector(STRING name=STRING_INIT);
  template <class T> std::vector<std::shared_ptr<T> > readElementVector(std::string name = std::string());
  template <class T> QVector<QSharedPointer<T> > readElementQVector(std::string name=std::string());

  template <class T> T read();
  template <class T> T readNumber();

private:
  QString readQString();
  std::string readStdString();
  QString readLineQString();

  QTextStream m_stream;
  int m_lineNumber;
  QStringList m_entries;

  REGISTER_LOGGER("openstudio.contam.Reader");
};

template <class T> std::vector<T> Reader::readSectionVector(std::string name)
{
  int n = readInt();
  std::vector<T> vector;
  for(int i=0;i<n;i++)
  {
    T value;
    value.read(*this);
    vector.push_back(value);
  }
  if(name.empty())
    read999("Failed to find section termination");
  else
    read999("Failed to find "+name+" section termination");
  return vector;
}

//template <class T> QList<T*> Reader::readSectionPointers(std::string name)
//{
//    QList<T*> list;
//    T *object;
//    int n = readInt();
//    for(int i=0;i<n;i++)
//    {
//        object = new T();
//        list << object;
//        object->read(this);
//    }
//    if(IS_NULL(name))
//        read999("Failed to find section termination");
//    else
//        read999("Failed to find "+name+" section termination");
//    return list;
//}

//template <class T> QList<T> Reader::readSectionList(std::string name)
//{
//    QList<T> list;
//    int n = readInt();
//    for(int i=0;i<n;i++)
//    {
//        T object;
//        object.read(this);
//        list << object;
//    }
//    if(IS_NULL(name))
//        read999("Failed to find section termination");
//    else
//        read999("Failed to find "+name+" section termination");
//    return list;
//}

//template <class T, template <class T> class V> V<T> Reader::readSectionVector(std::string name)
//{
//    int n = readInt();
//    V<T> vector(n);
//    for(int i=0;i<n;i++)
//        vector[i].read(*this);
//    if(IS_NULL(name))
//        read999("Failed to find section termination");
//    else
//        read999("Failed to find "+name+" section termination");
//    return vector;
//}

//template <class T> QVector<T> Reader::readSectionQVector(std::string name)
//{
//    int n = readInt();
//    QVector<T> vector(n);
//    for(int i=0;i<n;i++)
//        vector[i].read(*this);
//    if(IS_NULL(name))
//        read999("Failed to find section termination");
//    else
//        read999("Failed to find "+name+" section termination");
//    return vector;
//}

//template <class T> std::vector<T> Reader::readSectionStdVector(std::string name)
//{
//    int n = readInt();
//    std::vector<T> vector;
//    for(int i=0;i<n;i++)
//    {
//        T v;
//        v.read(*this);
//        vector.push_back(v);
//    }
//    if(IS_NULL(name))
//        read999("Failed to find section termination");
//    else
//        read999("Failed to find "+name+" section termination");
//    return vector;
//}

template <class T> std::vector<std::shared_ptr<T> > Reader::readElementVector(std::string name)
{
  int n = readInt();
  std::vector<std::shared_ptr<T> > vector;
  for(int i=0;i<n;i++) {
    vector.push_back(std::shared_ptr<T>(T::readElement(*this)));
  }
  if(name.empty()) {
    read999("Failed to find section termination");
  } else {
    read999("Failed to find " + name + " section termination");
  }
  return vector;
}

template <class T> QVector<QSharedPointer<T> > Reader::readElementQVector(std::string name)
{
  int n = readInt();
  QVector<QSharedPointer<T> > vector(n);
  for(int i = 0; i<n; i++)
  {
    // No reset in 4.8
    QSharedPointer<T> element(T::readElement(*this));
    vector[i].swap(element);
    //vector[i].reset(T::readElement(this));
  }
  if(name.empty())
    read999("Failed to find section termination");
  else
    read999("Failed to find " + name + " section termination");
  return vector;
}

} // contam
} // openstudio

#endif // AIRFLOW_CONTAM_PRJREADER_HPP
