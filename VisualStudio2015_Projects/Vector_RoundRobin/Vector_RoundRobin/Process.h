#pragma once

#include <string>
#include <iostream>

class Process
{
public:
	Process(const std::string& name) : name_(name) {}

public:
	virtual void DoWorkDuringTimeSlice()
	{
		std::cout << "Process " << name_ << " performing work during time slice." << std::endl;
	}

	bool operator==(const Process& rhs)
	{
		return name_ == rhs.name_;
	}

protected:
	std::string name_;
};

