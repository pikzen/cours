#include "../include/pluginmanager.h"
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	int flag_askforfolder = (argc == 1); // Si aucun argument n'a été passé, on demandera le dossier
	int plugin_count = 0;
	int filter_id = -1;
	
	printf("[Debug]\t\tArgument count: %d, arguments : %s\n", argc, *argv);
	
	char dirpath[255];
	if (flag_askforfolder)
	{
		std::cout << ("Veuillez rentrer le dossier ou sont stockés les plugins.\n");
		scanf("%s", dirpath);
	}
	else {
		strcpy(dirpath, argv[1]);
	}

	printf("[Debug]\t\tLooking for plugins in %s\n", dirpath);


	plugin_manager* pluginmanager = make_manager();
	std::cout << ("[Debug]\t\tManager created\n");
	plugin_count = discover_plugins(dirpath, pluginmanager);
	printf("[Debug]\t\tPlugins discovered\n");
	cv::Mat image;
	image = cv::imread("image.jpg", CV_LOAD_IMAGE_COLOR);
	if (!image.data)
	{
		std::cout << ("No image data, couldn't be read.");
		exit(EXIT_FAILURE);
	}
	
	do
	{
		display_menu(pluginmanager);
		std::cout << ("Quel filtre voulez vous appliquer ? (-1 pour quitter): ");
		scanf("%d", &filter_id);

		if (filter_id >= 0 && filter_id < plugin_count)
		{
			plugin_descriptor* plugin = get_plugin(pluginmanager, filter_id);
			plugin->m_filtre(image);
			namedWindow("Image after filter", cv::WINDOW_AUTOSIZE);
			imshow("Image after filter", image);

			waitKey(0);
		}
	}
	while (filter_id != -1);

	release_manager(pluginmanager);

	return 0;

}