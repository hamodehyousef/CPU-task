# About CPU TASK

![Screenshot of allEventsExample](allEventsExample.png)


### Learning Objectives

// To get handle to the processor idle time performance counter
	PDH_HQUERY idleQuery;
	PDH_HCOUNTER idleCounter;
	PdhOpenQuery(NULL, NULL, &idleQuery);
	PdhAddCounter(idleQuery, L"\\Processor(_Total)\\% Idle Time", NULL, &idleCounter);
	PdhCollectQueryData(idleQuery);

	
	PdhGetFormattedCounterValue(idleCounter, PDH_FMT_DOUBLE, NULL, &counterVal);
	double cpuUsage = 100.0 - counterVal.doubleValue;

	// Print CPU usage to console
	cout << "CPU Usage: " << cpuUsage << "%" << endl;

	return cpuUsage;

