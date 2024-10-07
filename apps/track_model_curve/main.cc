// Copyright (C) 2024 twyleg
#include <track_model_curve/ui/ui.h>
#include <track_model_curve/ui/model.h>
#include <track_model_curve/core/image_processing.h>

int main(int argc, char *argv[]) {

	Q_INIT_RESOURCE(ui);

	track_model_curve::ui::UI ui(argc, argv);

	auto& imageModel = ui.getImageModel();
	auto& parameterModel = ui.getParameterModel();

	track_model_curve::core::ImageProcessing imageProcessing(imageModel, parameterModel);


	imageProcessing.start();
    return ui.run();
}
