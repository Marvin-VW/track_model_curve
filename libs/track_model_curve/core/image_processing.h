// Copyright (C) 2024 twyleg, Marvin-VW
#pragma once
#include <QThread>
#include <QPixmap>

#include <track_model_curve/ui/model.h>

namespace track_model_curve::core {

class ImageProcessing: public QThread {

	Q_OBJECT

public:

	ImageProcessing(
		track_model_curve::ui::ImageModel& imageModel,
		track_model_curve::ui::ParameterModel& parameterModel,
		QObject* parent=nullptr
	);
	virtual ~ImageProcessing();

	void run() override;

	track_model_curve::ui::ImageModel& mImageModel;
	track_model_curve::ui::ParameterModel& mParameterModel;


private:

	QPixmap generate_test_image(int red, int green, int blue);

};

}
