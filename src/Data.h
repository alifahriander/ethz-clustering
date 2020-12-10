#ifndef DATA_H
#define DATA_H

#include <eigen3/Eigen/Core>
#include <iostream>
#include <random>
#include "Observation.h"

using namespace std;
using namespace Eigen;

class Data{
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW;

        unsigned int numberClusters;
        unsigned int numberSamples;

        // Matrix consisting of unit matrix numberSamnumberSamples 
        MatrixXd A;
        MatrixXd W_x;
        MatrixXd W_z;


        // Mean value of cluster points 
        VectorXd x_true;
        VectorXd x_estimate;

        //y_observed is the observation vector with y_0, y_1, ..., y_N
        VectorXd y_observed;
        // y is the extended observation vector with y_0, y_0, ...,y_0,y_1,... 
        // where every observation is repeated K times 
        VectorXd y;
        VectorXd assignments;
        // z = Ax - y
        VectorXd z;

        // SNUV parameters 
        double r_z;

        // For weighted update 
        long double alpha = 0.1;


        VectorXd s_x;
        VectorXd s_z;

        double costX;
        double costZ;

        VectorXd forwardMessageW;
        VectorXd forwardMessageEta;


        default_random_engine generator_data;
    
        Data(Observation inputObservation, double r_z, unsigned random_seed);
        void updateW(MatrixXd& W,VectorXd s, double r);
        void updateData();
        void updateCost(VectorXd v, double r, double& cost);
        double normalDistribution(double mean, double variance);
        double uniformDistribution(double min, double max);
        void printData();
        void saveData(bool init);
        int VectorToCSV(const MatrixXd& inputMatrix, const string& fileName, const streamsize dPrec);
        int VectorToCSV(double Scalar, const string& fileName, const streamsize dPrec);
        VectorXd initXEstimate();
        VectorXd computeDistances(double center);
        unsigned int selectFromDistribution(VectorXd distances);

};

#endif
