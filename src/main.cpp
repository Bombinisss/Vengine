#include "app-controller.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main(){
	Ven::AppController app{};

	try {
		app.Run();
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}