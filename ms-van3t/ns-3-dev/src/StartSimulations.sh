#!/bin/bash

resultsFolder=Sim_Results
traces_dir=$PWD/traces

home_dir=$PWD

ns3_dir=$PWD/../../ns-3-dev/
log_dir=$PWD/../../ns-3-dev/log
sumo_dir=$PWD/../../ns-3-dev/src/automotive/examples/sumo-files

# Check if the folder already exist in the current directory
if [ ! -d ${results_dir} ]; then
	mkdir ${results_dir}
fi

for timeVal in 10 30 40 50 60 70 
do
	results_dir=$PWD/${resultsFolder}_TimeVal_${timeVal}
	#Check if the folder already exist in the current directory
	if [ ! -d ${results_dir} ]; then
		mkdir ${results_dir}
	fi

	for speed in 30 70 100 110 120 130
	do
		cd $ns3_dir

		echo "Project --> Running Simulation with speed=${speed} [km/h], timeVal=$timeVal"
		# Create directories to gather the sim input and output
		mkdir -p -m u=rwx,g=rwx,o= ${results_dir}/speed${speed}

		cp ${traces_dir}/cars.rou.xml ${sumo_dir}/cars.rou.xml

		# Set the folder just now created to save input and outputs
		output_dir=${results_dir}/speed${speed}

		./ns3 run "v2i-80211p --sumo-gui=true --t2c=15 --sumo-updates=0.01 --sim-time=3600 --csv-log=${speed} --speed=${speed} --evasive-maneuver=true --time-val=${timeVal}" > simulation_log.txt

		echo "Simulation finished! Moving files..."

		mv sumo-errors-or-collisions.xml $output_dir
		mv ${speed}* $output_dir
		mv simulation_log.txt $output_dir

		echo "COMPLETED --> Simulation with speed=${speed} [km/h]"			
	done
	cd $home_dir
done
