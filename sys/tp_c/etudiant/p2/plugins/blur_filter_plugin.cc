#include <cv.h>
#include <stdio.h>
#include "plugin.h"
#include "pluginmanager.h"

extern "C" {

  // filtre sans effet
  cv::Mat
  blur_filter(cv::Mat src)
  {
    printf("\nblur_filter: blurring image...\n");

    cv::blur(src, src, cv::Point(5, 5));
    return src;
  }

  // enregistrer le plugin
  void
  init_(plugin_manager * pm)
  {
    register_plugin(pm,
		    "blur_filter",
		    "Floute l'image",
		    blur_filter);
  }
};
