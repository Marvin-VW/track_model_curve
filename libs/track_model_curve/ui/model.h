// Copyright (C) 2024 twyleg
#pragma once

#include <fmt/core.h>

#include <QObject>
#include <QPixmap>
#include <QMutex>
#include <QMutexLocker>

namespace track_model_curve::ui {

#define ADD_PROPERTY(datatype, name, funcName, initial_value) \
private: \
	datatype name = initial_value; \
	Q_PROPERTY(datatype name READ get##funcName WRITE set##funcName NOTIFY  name##Changed) \
public: \
	datatype& get##funcName() { \
		QMutexLocker locker(&mMutex); \
		return name; \
	} \
	void set##funcName(const datatype& value) \
	{ \
		if (name != value) {\
			mMutex.lock(); \
			name = value; \
			mMutex.unlock(); \
			emit name##Changed(); \
		}\
	} \
Q_SIGNALS: \
	void name##Changed(); \
private: \



class ParameterModel : public QObject
{
	Q_OBJECT

private:

	QMutex mMutex;

public:

	ADD_PROPERTY(double, positionX, PositionX, 10000.0)
	ADD_PROPERTY(double, positionY, PositionY, 10000.0)
    ADD_PROPERTY(double, curve_radius, Curve_radius, 200.0)
    ADD_PROPERTY(double, track_width, Track_width, 50.0)
    ADD_PROPERTY(double, dashed_length, Dashed_length, 35.0)
    ADD_PROPERTY(double, dashed_space, Dashed_space, 20.0)
    ADD_PROPERTY(double, line_width, Line_width, 5.0)
    ADD_PROPERTY(double, curved_angle_start, Curved_angle_start, 0.0)
    ADD_PROPERTY(double, curved_angle_end, Curved_angle_end, 90.0)
	ADD_PROPERTY(int, dashed_left, Dashed_left, 0.0)
    ADD_PROPERTY(int, dashed_right, Dashed_right, 0.0)

Q_SIGNALS:

	void parameterChanged();

};

class ImageModel : public QObject
{
	Q_OBJECT

private:

	QMutex mMutex;
	QPixmap image;
	Q_PROPERTY(QPixmap image READ getImage WRITE setImage NOTIFY imageChanged)


public:

	const QPixmap& getImage() {
		QMutexLocker locker(&mMutex);
		return image;
	}
	void setImage(const QPixmap& image) {
		mMutex.lock();
		this->image = image;
		mMutex.unlock();
		emit imageChanged();
	}

Q_SIGNALS:

	void imageChanged();

};

}
