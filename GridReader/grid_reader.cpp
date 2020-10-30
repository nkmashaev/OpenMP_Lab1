#include "grid_reader.h"
#include <iostream>
#include <iomanip>

namespace GR
{
	void allocate_msh3d(
			     size_t x_size,
		     	     size_t y_size,
			     size_t z_size,
			     msh3d & xc,
			     msh3d & yc,
			     msh3d & zc
			   )
   	{
		xc.resize(x_size);
		yc.resize(x_size);
		zc.resize(x_size);
		for (size_t i = 0; i < x_size; ++i)
		{
			xc[i].resize(y_size);
			yc[i].resize(y_size);
			zc[i].resize(y_size);
			for (size_t j = 0; j < y_size; ++j)
			{
				xc[i][j].resize(z_size);
				yc[i][j].resize(z_size);
				zc[i][j].resize(z_size);
				for (size_t k = 0; k < z_size; ++k)
				{
					xc[i][j][k] = 0.0;
					yc[i][j][k] = 0.0;
					zc[i][j][k] = 0.0;
				}
			}
		}	
	}		

	void read_grid(
			msh3d & xc,
			msh3d & yc,
			msh3d & zc,
			std::istream & in
		      )
	{
		size_t x_size = 0;
		size_t y_size = 0;
		size_t z_size = 0;
		in >> x_size >> y_size >> z_size;
		for (size_t i = 0; i < x_size; ++i)
		{
			for (size_t j = 0; j < y_size; ++j)
			{
				for (size_t k = 0; k < z_size; ++k)
				{
					in >> xc[i][j][k]
					   >> yc[i][j][k]
					   >> zc[i][j][k];
				}
			}
		}
	}

	void read_and_allocate_grid(
				     msh3d & xc,
				     msh3d & yc,
				     msh3d & zc,
				     std::istream & in
				   )
	{
		size_t x_size = 0;
		size_t y_size = 0;
		size_t z_size = 0;
		in >> x_size >> y_size >> z_size;
		xc.resize(x_size);
		yc.resize(x_size);
		zc.resize(x_size);
		for (size_t i = 0; i < x_size; ++i)
		{
			xc[i].resize(y_size);
			yc[i].resize(y_size);
			zc[i].resize(y_size);
			for (size_t j = 0; j < y_size; ++j)
			{
				xc[i][j].resize(z_size);
				yc[i][j].resize(z_size);
				zc[i][j].resize(z_size);
				for (size_t k = 0; k < z_size; ++k)
				{
					in >> xc[i][j][k]
					   >> yc[i][j][k]
					   >> zc[i][j][k];
				}
			}
		}
	}

	void write_grid(
			 const msh3d & xc,
			 const msh3d & yc,
			 const msh3d & zc,
			 std::ostream & out
		       )
	{
		size_t x_size = xc.size();
		size_t y_size = xc[0].size();
		size_t z_size = xc[0][0].size();
		out << x_size << " " 
		    << y_size << " " 
		    << z_size << "\n";
		out << std::scientific << std::setprecision(11);
		for (size_t i = 0; i < x_size; ++i)
		{
			for (size_t j = 0; j < y_size; ++j)
			{
				for (size_t k = 0; k < z_size; ++k)
				{
					out << xc[i][j][k] << " "
					    << yc[i][j][k] << " "
					    << zc[i][j][k] << " "
					    << "\n";
				}
			}
		}
	}
}
