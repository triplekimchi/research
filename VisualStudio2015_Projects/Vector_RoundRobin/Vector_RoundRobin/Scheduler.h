#pragma once
#include "Process.h"
#include "RoundRobin.h"
#include <vector>

class Scheduler
{
public:
	Scheduler(const std::vector<Process>& processes);
	virtual ~Scheduler(){}

public:
	virtual void ScheduleTimeSlice();
	virtual void RemoveProcess(const Process&);

protected:
	RoundRobin<Process> rorobin_;
};

Scheduler::Scheduler(const std::vector<Process>& processes)
{
	for(auto& process : processes)
	{
		rorobin_.Add(process);
	}
}

void Scheduler::ScheduleTimeSlice()
{
	try
	{
		rorobin_.GetNext().DoWorkDuringTimeSlice();
	}
	catch(const std::out_of_range)
	{
		std::cerr << "No more processes to schedule." << std::endl;
	}
}

void Scheduler::RemoveProcess(const Process& process)
{
	rorobin_.Remove(process);
}

