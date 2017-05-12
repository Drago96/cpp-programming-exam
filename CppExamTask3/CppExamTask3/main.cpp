#include <iostream>
#include <memory>
#include <thread>
#include <vector>
#include "Date.h"
#include "Mission.h"
#include "Time.h"
#include "Coordinates.h"
#include "LandLocation.h"

/*Name: Dragomir Lyubomirov Proychev
  SoftUni Account: DragomirProychev */



std::mutex printLock;

void performMissionSearch(std::shared_ptr<LandLocation> testContainer, std::string testName)
{
	printLock.lock();
	testContainer->searchFlight(testName);
	printLock.unlock();
}

int main()
{
	//smart pointers are used in order to prevent memory leak
	std::shared_ptr<Mission> testMission1(new Mission("mission1"));
	std::shared_ptr<Mission> testMission2(new Mission("mission2"));
	std::shared_ptr<LandLocation> testContainer1(new LandLocation());
	std::shared_ptr<LandLocation> testContainer2(new LandLocation());
	testContainer1->addFlight(testMission1);
	testContainer2->addFlight(testMission2);
	std::thread testContainerThread1(performMissionSearch,testContainer1,"mission1");
	std::thread testContainerThread2(performMissionSearch, testContainer2, "mission2");
	testContainerThread1.join();
	testContainerThread2.join();
	return 0;
}



