#pragma once

// RoundRobin header

#include "Scheduler.h"

void RoundRobins()
{
	std::vector<Process> processes = {Process("one"), Process("two"), Process("three")};
	Scheduler scd(processes);

	for(int i=0; i <= 4; ++i)
	{
		scd.ScheduleTimeSlice();
	}

	scd.RemoveProcess(processes[0]);
	std::cout << "removing process at position 0" << std::endl;

	for(int i=0; i <= 4; ++i)
	{
		scd.ScheduleTimeSlice();
	}
}

// Main APIs

#include <iostream>

#define PRINTTEXT 1

bool
PrintText(char* msg)
{
	if(PRINTTEXT)
	{
		std::cout << msg << std::endl;
	}
	return (bool)PRINTTEXT;
}

