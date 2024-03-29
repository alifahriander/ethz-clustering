# Clustering with Iteratively Reweighted Descent

## Folder Structure  
The project source code is saved under __src__ folder. You can find all relevant _.cpp_ and _.h_ files there.  
Before running the algorithm you have to put the csv files for configuration in the folder __config__. Please use the given template to fill the configuration files there.  
If you want to use the data you have created, please put them in the __data__ folder and follow the instructions in Section __Run the Code__.  
The data that is presented in the report can be found in the folder __cases__.


## Run the Code 
- __Build Project:__  
  Use the following command lines to build the project:

  `mkdir build`  
  `cd build`  
  `cmake --configure ..`  
  `cmake --build <path-to-build-file> --target all`


- __Create Data:__
  Change the _variances.csv_ and _centers.csv_ files according to your choices and use the command line  
  `./build/clustering 0`  
  The data will be saved in the __data__ folder as _csv_ files.
- __Run Algorithm__
  To run the algorithm you need to specify the configuration parameters located in __config__ folder. After choosing the parameters you want to run the algorithm with, run the command 
  `./build/clustering 1`  
  This command will generate several _csv_ files containing the output of the algorithm.
- __Run Algorithm for Different Parameters:__
  You can also run the algorithm for several times with different _rZ_ parameters. Please specify the set of _rZ_ parameters in the __run_hyp.sh__ in the _paramRz_ array and how many times you want to run a configuration set repeatedly in **ARG_NR_EXPERIMENT**. To start the loop, use the command:  
  `./run_hyp.sh`  
  This command will create an __experiments__ folder with several __experiment(number)__ folders which contains the outputs of repeated runs with the same configuration.  
- __Computing Scores:__
  To compute the score of all runs, use the command line:  
  `python compute_scores.py --path <path-to-experiments folder>`   
  This will generate a __result.csv__ file containing all the L2 scores of outputs for every run.   
  If you also want to see the mean score of every experiment folder, type:  
  `python plot_scores.py --path <path-to-result.csv-file>`

  
- __Plotting Variables:__ If you want to inspect the sparsity of the variables z and s_z use the command line:  
  `python plot_experiment.py --path <path-to-run-folder>`  
  This will generate several _.png_ files containing the variables as bar plots.

## Code Structure

The code mainly consists of 3 objects: __Observation__, __Data__ and __Trainer__. __Observation__ object can sample the _y_ observations as normal distributions specified in the __config__ folder and saves the data in the __data__ folder. __Data__ object allocates and initializes the variables that are used in the training procedure. __Trainer__ implements the training loop containing variance update and _x_ estimation steps.  
