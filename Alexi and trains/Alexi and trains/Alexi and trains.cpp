#include <iostream>
#include<vector>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int processInput(int& nStations, vector<pair<int, int>>&scheduledTimes, vector<int>&delays) {
	//recieve input
	cin >> nStations;
	scheduledTimes.resize(nStations);
	delays.resize(nStations);
	for (int i = 0; i < nStations; i++) {
		cin >> scheduledTimes[i].first >> scheduledTimes[i].second;
	}
	for (int i = 0; i < nStations; i++) {
		cin >> delays[i];
	}
	//process input
	int totalTime = scheduledTimes[0].first+delays[0];//base case
	int prevScheduledDeparture = 0;
	for (int i = 0; i < nStations-1;) {
		int currScheduledArrival = scheduledTimes[i].first;
		int currScheduledDeparture = scheduledTimes[i].second;
		//total time=time of arrival at station i

		//for the train to leave we need to meet two conditions
		//the two conditions are totalTime>=currDeparture second(bi)
		//or the train has stayed there for (currDeparture-currArrival+1)/2 (cealing of (ai+bi)/2 + time train arrived at station

		//that said: calculate when is the fucker leaving already
		totalTime = max(currScheduledDeparture, totalTime + (currScheduledDeparture - currScheduledArrival + 1) / 2);
		
		//this other part is pasted from the problem
		//the time needed to get to the next station
		//and since we're now dealing with the next staion:
		i++;

		totalTime += scheduledTimes[i].first - currScheduledDeparture + delays[i];
	}
	return totalTime;
}

int main()
{
	int nTestCases;
	int nStations;
	vector<pair<int, int>>scheduledTimes;
	vector<int>delays;
	cin >> nTestCases;
	vector<int>outputs(nTestCases);
	for (int i = 0; i < nTestCases; i++) {
		outputs[i]=processInput(nStations, scheduledTimes, delays);
		/*
		cout << "\ndata is:\n";
		cout << nStations <<";\n";
		cout << endl;
		for (pair<int,int> p : scheduledTimes) {
			cout << p.first << ' ' << p.second << endl;
		}
		cout << ";\n";
		for (int i : delays)cout << i << ' ';
		*/
	}
	for (int i : outputs) {
		cout << i << endl;
	}
	return 0;
}