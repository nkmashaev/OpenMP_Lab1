#include "../../GridReader/grid_reader.h"
#include <fstream>
#include <chrono>
#include <omp.h>
#include <iomanip>

void axis_i_shift(
		GR::msh3d & ic,
		double ishift	
	       );

int main(int argc, char*argv[])
{
	//reading msh file
	std::ifstream in_file;
	in_file.open("./grids/cube.msh");
	if (!in_file)
	{
		std::cerr << "Error: Current file doesn't exists\n";
		return 1;
	}
	GR::msh3d xc;
	GR::msh3d yc;
	GR::msh3d zc;
	GR::read_and_allocate_grid(xc, yc, zc, in_file);
	in_file.close();
	
	//Perform shift
	auto start = std::chrono::system_clock::now();
	double x_shift = 1.0;
	double y_shift = 2.0;
	double z_shift = 3.0;
	#pragma omp parallel \
		shared(x_shift, y_shift, z_shift, \
		       xc, yc, zc)
	{
		#pragma omp sections
		{
			#pragma omp section
			{
				axis_i_shift(xc, x_shift);
			}
			#pragma omp section
			{
				axis_i_shift(yc, y_shift);
			}
			#pragma omp section
			{
				axis_i_shift(zc, z_shift);
			}
		}
	}
	auto end = std::chrono::system_clock::now();

	//Computational time calculating
	std::chrono::duration<double> elapsed = end - start;
	std::cout << std::scientific << std::setprecision(11);
	std::cout << "Computational time: " << elapsed.count() << " s\n";

	//std::ofstream out_file("./grids/cube_new.msh");
	//GR::write_grid(xc, yc, zc, out_file);
	//out_file.close();

	return 0;
}

void axis_i_shift(
		   GR::msh3d & ic,
		   double ishift
		 )
{
	int x_size = static_cast<int>(ic.size());
	int y_size = static_cast<int>(ic[0].size());
	int z_size = static_cast<int>(ic[0][0].size());
	for (int i = 0; i < x_size; ++i)
	{
		for (int j = 0; j < y_size; ++j)
		{
			for (int k = 0; k < z_size; ++k)
			{
				ic[i][j][k] += ishift;
			}
		}
	}	
}
