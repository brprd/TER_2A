#include <iostream>
#include <fstream>
#include "FileTools.h"

void SaveSolution(std::string file_name, int Nx, int Ny, std::vector<Maille *> const &M)
{
    std::ofstream solution;
    solution.open(file_name, std::ios::out);

    solution << "# vtk DataFile Version 3.0" << std::endl;
    solution << "Essai de traction d'un materiau composite unidirectionnel" << std::endl;
    solution << "ASCII" << std::endl;
    solution << "DATASET STRUCTURED_POINTS" << std::endl;
    solution << "DIMENSIONS " << Nx << " " << Ny << " " << 1 << std::endl;
    solution << "ORIGIN " << 0. << " " << 0. << " " << 0. << std::endl;
    solution << "SPACING " << 1. << " " << 1. << " " << 1. << std::endl;

    solution << "POINT_DATA " << Nx * Ny << std::endl;
    solution << "SCALARS ruptures float" << std::endl;
    solution << "LOOKUP_TABLE default" << std::endl;
    for (int j = 0; j < Ny; j++)
    {
        for (int i = 0; i < Nx; i++)
        {
            solution << M[i + j * Ny]->isBroken() << " ";
        }
        solution << std::endl;
    }
    solution.close();
}
