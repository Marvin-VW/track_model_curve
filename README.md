[![Build status](https://github.com/Marvin-VW/track_model_curve/actions/workflows/tests.yaml/badge.svg)]()
[![GitHub latest commit](https://badgen.net/github/last-commit/Marvin-VW/track_model_curve)](https://GitHub.com/Marvin-VW/track_model_curve/commit/)

# track_model_curve

Console-based arc calculator using OpenCV, drawn with OpenCV's ellipse function.

## Dependencies

The project is based on the following components:

* CMake
* boost
* googletest
* fmt

See [scripts/](https://github.com/Marvin-VW/track_model_curve/tree/main/scripts) for dependency install scripts for multiple distributions.

GoogleTest is pulled in as a git submodule to avoid problems with missing cmake files in sub distributions.

## Usage

Clone, prepare and build with the following steps:

	git clone https://github.com/Marvin-VW/track_model_curve.git
	cd track_model_curve

	git submodule update --init
	
	mkdir build/
	cd build/
	cmake ../
	make