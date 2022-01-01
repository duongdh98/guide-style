# _API Reference_
## [Task Creation](#task-creation)
### [TaskHandle_t (type)](#taskHandle_t)
### [xTaskCreate()](#xtaskCreate)
### [xTaskCreateStatic()](#xtaskCreateStatic)
### [xTaskCreateRestrictedStatic()](#xtaskCreateRestrictedStatic)
### [vTaskDelete()](#vtaskDelete)

## [Task Control](#task-control)
### [vTaskDelay()](#vTaskDelay)
### [vTaskDelayUntil()](#vTaskDelayUntil)
### [xTaskDelayUntil()](#xTaskDelayUntil)
### [uxTaskPriorityGet()](#uxTaskPriorityGet)
### [vTaskPrioritySet()](#vTaskPrioritySet)
### [vTaskSuspend()](#vTaskSuspend)
### [vTaskResume()](#vTaskResume)
### [xTaskResumeFromISR()](#xTaskResumeFromISR)
### [xTaskAbortDelay()](#xTaskAbortDelay)

## [Task Utilities](#task-utilities)
## [RTOS Kernel Control](#RTOS-kernel-control)
## [Direct To Task Notifications](#direct-to-task-notifications)
## [Queues](#queues)
## [Queue Sets](#queues-sets)
## [Stream Buffers](#stream-buffers)
## [Message Buffers](#message-buffers)
## [Semaphore / Mutexes](#semaphore-mutexes)
## [Software Timers](#software-timers)
## [Event Groups (or 'flags')](#event-groups)
## [FreeRTOS-MPU Specific](#FreeRTOS-MPU-specific)
## [Co-routines](#co-routines)

## <a id="task-creation" ></a> Task Creation

### <a id="taskHandle_t"></a> TaskHandle_t (type)
**task. h** <br>
Type by which tasks are referenced. For example, a call to xTaskCreate returns (via a <br> pointer parameter) an TaskHandle_t variable that can then be used as a parameter <br> to vTaskDelete to delete the task.

### <a id="xtaskCreate"></a> xTaskCreate()
**task. h** <br>
```sh
	BaseType_t xTaskCreate( 
			TaskFunction_t pvTaskCode,
			const char * const pcName,
			configSTACK_DEPTH_TYPE usStackDepth,
			void *pvParameters,
			UBaseType_t uxPriority,
			TaskHandle_t *pxCreatedTask
	);
```
Create a new [task](https://www.freertos.org/a00015.html) and add it to the list of tasks that are ready to run. [configSUPPORT_DYNAMIC_ALLOCATION](https://www.freertos.org/a00110.html#configSUPPORT_DYNAMIC_ALLOCATION) must be set to 1 in FreeRTOSConfig.h, or left undefined (in which case it will default to 1), for this RTOS API function to be available.

Each task requires RAM that is used to hold the task state, and used by the task as its stack. If a  <br> task is created using _xTaskCreate()_ then the required RAM is automatically allocated from the <br> [FreeRTOS heap](https://www.freertos.org/a00111.html). If a task is created using [xTaskCreateStatic()](https://www.freertos.org/xTaskCreateStatic.html) then the RAM is provided by the <br> application writer, so it can be statically allocated at compile time. See the [Static Vs Dynamic allocation](https://www.freertos.org/Static_Vs_Dynamic_Memory_Allocation.html) <br> page for more information.

If you are using [FreeRTOS-MPU](https://www.freertos.org/FreeRTOS-MPU-memory-protection-unit.html) then we recommend that you use [xTaskCreateRestricted()](https://www.freertos.org/xTaskCreateRestricted.html) instead of xTaskCreate().

**Parameters:**
  
  - **pvTaskCode** : Pointer to the task entry function (just the name of the function that implements the <br> task, see the example below).
  <br> Tasks are normally [implemented as an infinite loop](https://www.freertos.org/implementing-a-FreeRTOS-task.html); the function which implements the task must never <br> attempt to return or exit. Tasks can, however, [delete themselves](https://www.freertos.org/a00126.html).
  
  - **pcName** : A descriptive name for the task. This is mainly used to facilitate debugging, but can also <br> be used to [obtain a task handle.](https://www.freertos.org/a00021.html#xTaskGetHandle)
  <br> The maximum length of a task's name is defined by configMAX_TASK_NAME_LEN in [FreeRTOSConfig.h](https://www.freertos.org/a00110.html).
  
  - **usStackDepth** : The number of words (not bytes!) [to allocate](https://www.freertos.org/a00111.html) for use as the task's stack. For example, <br> if the stack is 16-bits wide and usStackDepth is 100, then 200 bytes will be allocated for use as the <br> task's stack. As another example, if the stack is 32-bits wide and usStackDepth is 400 then 1600 bytes <br> will be allocated for use as the task's stack.
  <br> The stack depth multiplied by the stack width must not exceed the maximum value that can be contained <br> in a variable of type size_t.
  <br> See the FAQ [How big should the stack be?](https://www.freertos.org/FAQMem.html#StackSize)
  
  - **pvParameters** : A value that is passed as the paramater to the created task.
  <br> If pvParameters is set to the address of a variable then the variable must still exist when the <br> created task executes - so it is not valid to pass the address of a stack variable.
  
  - **uxPriority** : The [priority](https://www.freertos.org/RTOS-task-priority.html) at which the created task will execute.
  <br> 	The priority at which the created task will execute.
	<br> Systems that include MPU support can optionally create a task in a privileged (system) mode by setting <br> the bit portPRIVILEGE_BIT in uxPriority. For example, to create a privileged task at priority 2 set <br> uxPriority to ( 2 | portPRIVILEGE_BIT ).
  <br> Priorities are asserted to be less than configMAX_PRIORITIES. If configASSERT is undefined, priorities <br> are silently capped at (configMAX_PRIORITIES - 1).
  
  - **pxCreatedTask** : Used to pass a handle to the created task out of the xTaskCreate() function. <br> pxCreatedTask is optional and can be set to NULL.

**Returns:**
If the task was created successfully then pdPASS is returned. Otherwise errCOULD_NOT_ALLOCATE_REQUIRED_MEMORY <br> is returned.

**Example usage:**
```sh
	/* Task to be created. */
	void vTaskCode( void * pvParameters )
	{
		/* The parameter value is expected to be 1 as 1 is passed in the
		pvParameters value in the call to xTaskCreate() below. 
		configASSERT( ( ( uint32_t ) pvParameters ) == 1 );

		for( ;; )
		{
			/* Task code goes here. */
		}
	}
	
	/* Function that creates a task. */
	void vOtherFunction( void )
	{
		BaseType_t xReturned;
		TaskHandle_t xHandle = NULL;
	
		/* Create the task, storing the handle. */
		xReturned = xTaskCreate(
			vTaskCode,       /* Function that implements the task. */
			"NAME",          /* Text name for the task. */
			STACK_SIZE,      /* Stack size in words, not bytes. */
			( void * ) 1,    /* Parameter passed into the task. */
			tskIDLE_PRIORITY,/* Priority at which the task is created. */
			&xHandle );      /* Used to pass out the created task's handle. */

		if( xReturned == pdPASS )
		{
			/* The task was created.  Use the task's handle to delete the task. */
			vTaskDelete( xHandle );
		}
	}
```
### xTaskCreateStatic()
**task.h**
```sh
	TaskHandle_t xTaskCreateStatic( 
        TaskFunction_t pxTaskCode,
        const char * const pcName,
        const uint32_t ulStackDepth,
        void * const pvParameters,
        UBaseType_t uxPriority,
        StackType_t * const puxStackBuffer,
        StaticTask_t * const pxTaskBuffer 
	);
```
Create a new [task](https://www.freertos.org/a00015.html) and add it to the list of tasks that are ready to run. <br> [configSUPPORT_STATIC_ALLOCATION](https://www.freertos.org/a00110.html#configSUPPORT_STATIC_ALLOCATION) must be set to 1 in FreeRTOSConfig.h for this RTOS API 
<br> function to be available

Each task requires RAM that is used to hold the task state, and used by the task as its stack. <br> If a task is created using [xTaskCreate()](https://www.freertos.org/a00125.html) then the required RAM is automatically allocated <br> from the [FreeRTOS heap](https://www.freertos.org/a00111.html). If a task is created using xTaskCreateStatic() then the RAM is <br> provided by the application writer, which results in a greater number of parameters, but <br> allows the RAM to be statically allocated at compile time. See the [Static Vs Dynamic](https://www.freertos.org/Static_Vs_Dynamic_Memory_Allocation.html) <br> allocation page for more information.

If you are using [FreeRTOS-MPU](https://www.freertos.org/FreeRTOS-MPU-memory-protection-unit.html) then we recommend you use [xTaskCreateRestricted()](https://www.freertos.org/xTaskCreateRestricted.html) instead of xTaskCreateStatic().

**Parameters:**
  - **pxTaskCode** : Pointer to the task entry function (just the name of the function that <br> implements the task, see the example below).
  
  - **pcName** : Tasks are normally [implemented as an infinite loop](https://www.freertos.org/implementing-a-FreeRTOS-task.html); the function which implements the <br> task must never attempt to return or exit. Tasks can however [delete themselves](https://www.freertos.org/a00126.html).
  <br> The maximum length of a task's name is defined by configMAX_TASK_NAME_LEN in [FreeRTOSConfig.h](https://www.freertos.org/a00110.html).

  - **ulStackDepth** : The puxStackBuffer parameter is used to pass an array of StackType_t <br> variables into xTaskCreateStatic(). ulStackDepth must be set to the number of indexes in <br> the array.
  <br> See the FAQ [How big should the stack be](https://www.freertos.org/FAQMem.html#StackSize)?

  - The value that is passed as the parameter to the created task.
  <br> If pvParameters is set to the address of a variable then the variable must still exist <br> when the created task executes - so it is not valid to pass the address of a stack <br> variable.

  - **uxPriority** : 	The [priority](https://www.freertos.org/RTOS-task-priority.html) at which the created task will execute.
  <br> Systems that include MPU support can optionally create a task in a privileged (system) <br> mode by setting the bit portPRIVILEGE_BIT in uxPriority. For example, to create a <br> privileged task at priority 2 set uxPriority to ( 2 | portPRIVILEGE_BIT ).
  <br> Priorities are asserted to be less than configMAX_PRIORITIES. If configASSERT is <br> undefined, priorities are silently capped at (configMAX_PRIORITIES - 1)
  
  - **puxStackBuffer** : Must point to a StackType_t array that has at least ulStackDepth <br> indexes (see the ulStackDepth parameter above) - the array will be used as the task's stack, <br> so it must be persistent (not declared on the stack of a function).
  
  - **pxTaskBuffer** :  Must point to a variable of type StaticTask_t. The variable will be <br> used to hold the new task's data structures (TCB), so it must be persistent (not <br> declared on the stack of a function).

**Returns:**
If neither puxStackBuffer or pxTaskBuffer are NULL then the task will be created, and the <br> task's handle is returned. If either puxStackBuffer or pxTaskBuffer is NULL then the task will <br> not be created and NULL will be returned.

**Example usage:**
```sh
	/* Dimensions of the buffer that the task being created will use as its stack.
	NOTE:  This is the number of words the stack will hold, not the number of
	bytes.  For example, if each stack item is 32-bits, and this is set to 100,
	then 400 bytes (100 * 32-bits) will be allocated. */
	#define STACK_SIZE 200

	/* Structure that will hold the TCB of the task being created. */
	StaticTask_t xTaskBuffer;

	/* Buffer that the task being created will use as its stack.  Note this is
	an array of StackType_t variables.  The size of StackType_t is dependent on
	the RTOS port. */
	StackType_t xStack[ STACK_SIZE ];

	/* Function that implements the task being created. */
	void vTaskCode( void * pvParameters )
	{
		/* The parameter value is expected to be 1 as 1 is passed in the
		pvParameters value in the call to xTaskCreateStatic(). */
		configASSERT( ( uint32_t ) pvParameters == 1UL );

		for( ;; )
		{
			/* Task code goes here. */
		}
	}

	/* Function that creates a task. */
	void vOtherFunction( void )
	{
		TaskHandle_t xHandle = NULL;

		/* Create the task without using any dynamic memory allocation. */
		xHandle = xTaskCreateStatic(
			vTaskCode,       /* Function that implements the task. */
			"NAME",          /* Text name for the task. */
			STACK_SIZE,      /* Number of indexes in the xStack array. */
			( void * ) 1,    /* Parameter passed into the task. */
			tskIDLE_PRIORITY,/* Priority at which the task is created. */
			xStack,          /* Array to use as the task's stack. */
			&xTaskBuffer );  /* Variable to hold the task's data structure. */

		/* puxStackBuffer and pxTaskBuffer were not NULL, so the task will have
		been created, and xHandle will be the task's handle.  Use the handle
		to suspend the task. */
		vTaskSuspend( xHandle );
	}
```
### xTaskCreateRestrictedStatic()
**task.h**
```sh
	BaseType_t xTaskCreateRestrictedStatic( 
										TaskParameters_t *pxTaskDefinition,
										TaskHandle_t *pxCreatedTask );
```
Create a new Memory Protection Unit (MPU) restricted task and add it to the list of tasks that <br> are ready to run. [configSUPPORT_STATIC_ALLOCATION](https://www.freertos.org/a00110.html#configSUPPORT_STATIC_ALLOCATION) must be set to 1 in FreeRTOSConfig.h for <br> this RTOS API function to be available.

Internally, within the FreeRTOS implementation, each task requires two blocks of memory. The <br> first block is used to hold the task's data structures. The second block is used as the <br> task's stack. If a task is created using xTaskCreateRestricted() then the memory for the <br> task's stack is provided by the application writer, and the memory for the task's data <br> structures is automatically allocated from the [FreeRTOS heap](https://www.freertos.org/a00111.html). If a task is created using <br> xTaskCreateRestrictedStatic() then the application writer must provide the memory for the <br> task's data structures too. xTaskCreateRestrictedStatic() therefore allows a memory <br> protected task to be created without using any dynamic memory allocation.

xTaskCreateRestrictedStatic() is intended for use with [FreeRTOS-MPU](https://www.freertos.org/FreeRTOS-MPU-memory-protection-unit.html), the [demo applications](https://www.freertos.org/FreeRTOS-MPU-memory-protection-unit.html#FreeRTOS-MPU-Demos) <br> which contain comprehensive and documented examples of how to use the similar function, <br> xTaskCreateRestricted().

**Parameters:**
  - **pxTaskDefinition** :	Pointer to a structure that defines the task. The structure is <br> described on this page.
  - **pxCreatedTask** : Used to pass back a handle by which the created task can be referenced.

**Returns:**
pdPASS if the task was successfully created and added to a ready list, otherwise an error code <br> defined in the file projdefs.h
<br> Tasks that include MPU support require even more parameters to create than those that <br> don't. Passing each parameter to xTaskCreateRestrictedStatic() individually would be unwieldy <br> so instead the structure TaskParameters_t is used to allow the parameters to be configured <br> statically at compile time. The structure is defined in task.h as:
```sh
  typedef struct xTASK_PARAMETERS
{
	TaskFunction_t pvTaskCode;
	const signed char * const pcName;
	unsigned short usStackDepth;
	void *pvParameters;
	UBaseType_t uxPriority;
	portSTACK_TYPE *puxStackBuffer;
	MemoryRegion_t xRegions[ portNUM_CONFIGURABLE_REGIONS ];
	#if ( ( portUSING_MPU_WRAPPERS == 1 ) && ( configSUPPORT_STATIC_ALLOCATION == 1 ) )
			StaticTask_t * const pxTaskBuffer;
	#endif
	} TaskParameters_t;
	....where MemoryRegion_t is defined as:
	typedef struct xMEMORY_REGION
	{
			void *pvBaseAddress;
			unsigned long ulLengthInBytes;
			unsigned long ulParameters;
	} MemoryRegion_t;
```
Following is a description of each structure member:

  - pvTaskCode to uxPriority <br>
	These members are exactly the same as the parameters of the same name sent to [xTaskCreate()](https://www.freertos.org/a00125.html). <br> In particular uxPriority is used to set both the priority of the task and the mode in <br> which the task will execute. For example, to create a User mode task at priority 2, <br> simply set uxPriority to 2, to create a Privileged mode task at priority 2 set uxPriority to <br> ( 2 | portPRIVILEGE_BIT ).

	- puxStackBuffer <br >
	Each time a task is switched in, the MPU is dynamically re-configured to define a region that <br> provides the task read and write access to its own stack. MPU regions must meet a number <br> of constraints - in particular, the size and alignment of all such regions must be equal <br> to the same power of two value. 

	Standard FreeRTOS ports use pvPortMalloc() to allocate a new stack each time a task is <br> created. Providing a pvPortMalloc() implementation that took care of the MPU data alignment <br> requirements would be possible but would also be complex and inefficient in its RAM <br> usage. To remove the need for this complexity FreeRTOS-MPU allows stacks to be declared <br> statically at compile time. This allows the alignment to be managed using compiler extensions <br> and RAM usage efficiency to be managed by the linker. For example, if using GCC, a stack <br> could be declared and correctly aligned using the following code:
	
		char cTaskStack[ 1024 ] __attribute__((aligned(1024));
		
	puxStackBuffer would normally be set to the address of the statically declared stack. As an <br> alternative puxStackBuffer can be set to NULL - in which case pvPortMallocAligned() will <br> be called to allocate the task stack and it is the application writer's responsibility <br> to provide an implementation of pvPortMallocAligned() that meets the alignment <br> requirements of the MPU.

	  - xRegions <br>
	xRegions is an array of MemoryRegion_t structures, each of which defines a single user <br> definable memory region for use by the task being created. The ARM Cortex-M3 FreeRTOS-MPU <br>port defines portNUM_CONFIGURABLE_REGIONS to be 3.

	The pvBaseAddress and ulLengthInBytes members are self explanatory as the start of the memory <br> region and the length of the memory region respectively. ulParameters defines how the <br> task is permitted to access the memory region and can take the bitwise OR of the <br> following values:

        portMPU_REGION_READ_WRITE
        portMPU_REGION_PRIVILEGED_READ_ONLY
        portMPU_REGION_READ_ONLY
        portMPU_REGION_PRIVILEGED_READ_WRITE
        portMPU_REGION_CACHEABLE_BUFFERABLE
        portMPU_REGION_EXECUTE_NEVER
	
	- pxTaskBuffer <br>
	Must point to a variable of type StaticTask_t. The variable will be used to hold the new <br> task's data structures, so it must be persistent (not declared on the stack of a function).

Example usage:
```sh
	/* Create an TaskParameters_t structure that defines the task to be created.
	* The StaticTask_t variable is only included in the structure when
	* configSUPPORT_STATIC_ALLOCATION is set to 1.  The PRIVILEGED_DATA macro can
	* be used to force the variable into the RTOS kernel's privileged data area. */
	static PRIVILEGED_DATA StaticTask_t xTaskBuffer;
	static const TaskParameters_t xCheckTaskParameters =
	{
		vATask,     /* pvTaskCode - the function that implements the task. */
		"ATask",    /* pcName - just a text name for the task to assist debugging. */
		100,        /* usStackDepth - the stack size DEFINED IN WORDS. */
		NULL,       /* pvParameters - passed into the task function as the function parameters. */
		( 1UL | portPRIVILEGE_BIT ),/* uxPriority - task priority, set the portPRIVILEGE_BIT 
																			if the task should run in a privileged state. */
		cStackBuffer,/* puxStackBuffer - the buffer to be used as the task stack. */
	
		/* xRegions - Allocate up to three separate memory regions for access by
			* the task, with appropriate access permissions.  Different processors have
			* different memory alignment requirements - refer to the FreeRTOS documentation
			* for full information. */
		{
			/* Base address                 Length  Parameters */
			{ cReadWriteArray,              32,     portMPU_REGION_READ_WRITE },
			{ cReadOnlyArray,               32,     portMPU_REGION_READ_ONLY },
			{ cPrivilegedOnlyAccessArray,   128,    portMPU_REGION_PRIVILEGED_READ_WRITE }
		}
	
		&xTaskBuffer; /* Holds the task's data structure. */
		};
	
	int main( void )
	{
		TaskHandle_t xHandle;
	
		/* Create a task from the const structure defined above.  The task handle
			* is requested (the second parameter is not NULL) but in this case just for
			* demonstration purposes as its not actually used. */
		xTaskCreateRestricted( &xRegTest1Parameters, &xHandle );
	
		/* Start the scheduler. */
		vTaskStartScheduler();
	
		/* Will only get here if there was insufficient memory to create the idle
			* and/or timer task. */
		for( ;; );
	}
```
### vTaskDelete()
**task. h**
```sh
  void vTaskDelete( TaskHandle_t xTask );
```
INCLUDE_vTaskDelete must be defined as 1 for this function to be available. See the <br> [RTOS Configuration](https://www.freertos.org/a00110.html) documentation for more information.

Remove a task from the RTOS kernels management. The task being deleted will be removed from all <br> ready, blocked, suspended and event lists.

NOTE: The idle task is responsible for freeing the RTOS kernel allocated memory from tasks that <br> have been deleted. It is therefore important that the idle task is not starved of <br> microcontroller processing time if your application makes any calls to vTaskDelete (). Memory <br> allocated by the task code is not automatically freed, and should be freed before the task <br> is deleted.

See the demo application file death. c for sample code that utilises vTaskDelete ().

Parameters:
  - **xTask** : The handle of the task to be deleted. Passing NULL will cause the calling task <br> to be deleted.

**Example usage:**
```sh
	void vOtherFunction( void )
	{
	  TaskHandle_t xHandle = NULL;

		// Create the task, storing the handle.
		xTaskCreate( vTaskCode, "NAME", STACK_SIZE, NULL, tskIDLE_PRIORITY, &xHandle );

		// Use the handle to delete the task.
		if( xHandle != NULL )
		{
				vTaskDelete( xHandle );
		}
	}
```
## <a id="task-control" ></a> Task Control
### <a id="vTaskDelay"></a> vTaskDelay
**task. h**
```sh
	void vTaskDelay( const TickType_t xTicksToDelay );
```
INCLUDE_vTaskDelay must be defined as 1 for this function to be available. See the [RTOS Configuration](https://www.freertos.org/a00110.html) <br> documentation for more information.

Delay a task for a given number of ticks. The actual time that the task remains blocked depends <br> on the tick rate. The constant portTICK_PERIOD_MS can be used to calculate real time from <br> the tick rate - with the resolution of one tick period.

vTaskDelay() specifies a time at which the task wishes to unblock **relative to** the time at <br> which vTaskDelay() is called. For example, specifying a block period of 100 ticks will <br> cause the task to unblock 100 ticks after vTaskDelay() is called. vTaskDelay() does not <br> therefore provide a good method of controlling the frequency of a periodic task as the <br> path taken through the code, as well as other task and interrupt activity, will effect the <br> frequency at which vTaskDelay() gets called and therefore the time at which the task next <br> executes. See vTaskDelayUntil() for an alternative API function designed to facilitate <br> fixed frequency execution. It does this by specifying an absolute time (rather than a <br> relative time) at which the calling task should unblock.

**Parameters:**
  - **xTicksToDelay** : 	The amount of time, in tick periods, that the calling task should block.
  
**Example usage:**
```sh
	void vTaskFunction( void * pvParameters )
	{
		/* Block for 500ms. */
		const TickType_t xDelay = 500 / portTICK_PERIOD_MS;
	
		for( ;; )
		{
			/* Simply toggle the LED every 500ms, blocking between each toggle. */
			vToggleLED();
			vTaskDelay( xDelay );
		}
	}
	
```

### <a id="vTaskDelayUntil"></a> vTaskDelayUntil
**task. h**
```sh
	void vTaskDelayUntil( TickType_t *pxPreviousWakeTime,
												const TickType_t xTimeIncrement );
```
INCLUDE_vTaskDelayUntil must be defined as 1 for this function to be available. See the [RTOS Configuration](https://www.freertos.org/a00110.html) <br> documentation for more information.

Delay a task until a specified time. This function can be used by periodic tasks to ensure a <br> constant execution frequency.

This function differs from vTaskDelay() in one important aspect: vTaskDelay() specifies a time <br> at which the task wishes to unblock relative to the time at which vTaskDelay() is called, <br> whereas vTaskDelayUntil() specifies an absolute time at which the task wishes to unblock.

vTaskDelay() will cause a task to block for the specified number of ticks from the time <br> vTaskDelay() is called. It is therefore difficult to use vTaskDelay() by itself to generate a <br> fixed execution frequency as the time between a task unblocking following a call to <br> vTaskDelay() and that task next calling vTaskDelay() may not be fixed [the task may take a <br> different path though the code between calls, or may get interrupted or preempted a different <br> number of times each time it executes].

Whereas vTaskDelay() specifies a wake time relative to the time at which the function is <br> called, vTaskDelayUntil() specifies the absolute (exact) time at which it wishes to unblock.

It should be noted that vTaskDelayUntil() will return immediately (without blocking) if it is <br> used to specify a wake time that is already in the past. Therefore a task using <br> vTaskDelayUntil() to execute periodically will have to re-calculate its required wake time if <br> the periodic execution is halted for any reason (for example, the task is temporarily <br> placed into the Suspended state) causing the task to miss one or more periodic executions. This <br> can be detected by checking the variable passed by reference as the pxPreviousWakeTime <br> parameter against the current tick count. This is however not necessary under most usage <br> scenarios.

The constant portTICK_PERIOD_MS can be used to calculate real time from the tick rate - with <br> the resolution of one tick period.

This function must not be called while the RTOS scheduler has been suspended by a call to <br> vTaskSuspendAll().

**Parameters:**
  - **pxPreviousWakeTime** : 	Pointer to a variable that holds the time at which the task was <br> last unblocked. The variable must be initialised with the current time prior to its <br> first use (see the example below). Following this the variable is automatically updated <br> within vTaskDelayUntil().
  - **xTimeIncrement** : 	The cycle time period. The task will be unblocked at time <br>(*pxPreviousWakeTime + xTimeIncrement). Calling vTaskDelayUntil with the same xTimeIncrement <br> parameter value will cause the task to execute with a fixed interval period.

**Example usage:**
```sh
	// Perform an action every 10 ticks.
	void vTaskFunction( void * pvParameters )
	{
	 	TickType_t xLastWakeTime;
		const TickType_t xFrequency = 10;

		// Initialise the xLastWakeTime variable with the current time.
		xLastWakeTime = xTaskGetTickCount();

		for( ;; )
		{
			// Wait for the next cycle.
			vTaskDelayUntil( &xLastWakeTime, xFrequency );

			// Perform action here.
		}
	}
```
### <a id="xTaskDelayUntil"></a> xTaskDelayUntil
**task. h**
```sh
	BaseType_t xTaskDelayUntil( TickType_t *pxPreviousWakeTime,
															const TickType_t xTimeIncrement );
```
INCLUDE_xTaskDelayUntil must be defined as 1 for this function to be available. See the [RTOS Configuration](https://www.freertos.org/a00110.html) <br> documentation for more information.

Delay a task until a specified time. This function can be used by periodic tasks to ensure a <br> constant execution frequency.

This function differs from vTaskDelay() in one important aspect: vTaskDelay() will cause a task <br> to block for the specified number of ticks from the time vTaskDelay() is called whereas <br> xTaskDelayUntil() will cause a task to block for the specified number of ticks from the <br> time specified in the pxPreviousWakeTime parameter. It is difficult to use vTaskDelay() by <br> itself to generate a fixed execution frequency, as the time between a task starting to <br> execute and that task calling vTaskDelay() may not be fixed [the task may take a different <br> path though the code between calls, or may get interrupted or preempted a different number <br> of times each time it executes]. xTaskDelayUntil() can be used to generate a constant <br> execution frequency.

Whereas vTaskDelay() specifies a wake time relative to the time at which the function is <br> called, xTaskDelayUntil() specifies the absolute (exact) time at which it wishes to unblock.

The macro pdMS_TO_TICKS() can be used to calculate the number of ticks from a time specified in <br> milliseconds with a resolution of one tick period.

**Parameters:**
  - **pxPreviousWakeTime** : 	Pointer to a variable that holds the time at which the task was <br> last unblocked. The variable must be initialised with the current time prior to its <br> first use (see the example below). Following this the variable is automatically updated <br> within xTaskDelayUntil().
  - **xTimeIncrement** 	The cycle time period. The task will be unblocked at time <br>(*pxPreviousWakeTime + xTimeIncrement). Calling xTaskDelayUntil with the same xTimeIncrement <br> parameter value will cause the task to execute with a fixed interval period. <br>

**Returns:**
A value which can be used to check whether the task was actually delayed: pdTRUE if the task <br> way delayed and pdFALSE otherwise. A task will not be delayed if the next expected wake <br> time is in the past.

**Example usage:**
```sh
	// Perform an action every 10 ticks.
	void vTaskFunction( void * pvParameters )
	{
		TickType_t xLastWakeTime;
		const TickType_t xFrequency = 10;
		BaseType_t xWasDelayed;

		// Initialise the xLastWakeTime variable with the current time.
		xLastWakeTime = xTaskGetTickCount ();
		for( ;; )
		{
			// Wait for the next cycle.
			xWasDelayed = xTaskDelayUntil( &xLastWakeTime, xFrequency );

			// Perform action here. xWasDelayed value can be used to determine
			// whether a deadline was missed if the code here took too long.
		}
	}
```

### <a id="uxTaskPriorityGet"></a> uxTaskPriorityGet
**task. h**
```sh
	UBaseType_t uxTaskPriorityGet( TaskHandle_t xTask );
```
INCLUDE_uxTaskPriorityGet must be defined as 1 for this function to be available. See the [RTOS Configuration](https://www.freertos.org/a00110.html) <br> documentation for more information.

Obtain the priority of any task.

**Parameters:**
  - **xTask** 	Handle of the task to be queried. Passing a NULL handle results in the priority <br> of the calling task being returned.
  
<br> **Returns:**
The priority of xTask.

**Example usage:**
```sh
	void vAFunction( void )
	{
		TaskHandle_t xHandle;

		// Create a task, storing the handle.
		xTaskCreate( vTaskCode, "NAME", STACK_SIZE, NULL, tskIDLE_PRIORITY, &xHandle );

		// ...

		// Use the handle to obtain the priority of the created task.
		// It was created with tskIDLE_PRIORITY, but may have changed
		// it itself.
		if( uxTaskPriorityGet( xHandle ) != tskIDLE_PRIORITY )
		{
			// The task has changed its priority.
		}

		// ...

		// Is our priority higher than the created task?
		if( uxTaskPriorityGet( xHandle ) < uxTaskPriorityGet( NULL ) )
		{
			// Our priority (obtained using NULL handle) is higher.
		}
	}
```

### <a id="vTaskPrioritySet"></a> vTaskPrioritySet
### <a id="vTaskSuspend"></a> vTaskSuspend
### <a id="vTaskResume"></a> vTaskResume
### <a id="xTaskResumeFromISR"></a> xTaskResumeFromISR
### <a id="xTaskAbortDelay"></a> xTaskAbortDelay

## <a id="task-utilities" ></a> Task Utilities
## <a id="RTOS-kernel-control" ></a> RTOS Kernel Control
## <a id="direct-to-task-notifications" ></a> [Direct To Task Notifications
## <a id="queues" ></a> Queues
## <a id="queues-sets" ></a> Queue Sets
## <a id="stream-buffers" ></a> Stream Buffers
## <a id="message-buffers" ></a> Message Buffers
## <a id="semaphore-mutexes" ></a> Semaphore / Mutexes
## <a id="software-timers" ></a> Software Timers
## <a id="event-groups" ></a> Event Groups (or 'flags')
## <a id="FreeRTOS-MPU-specific" ></a> FreeRTOS-MPU Specific
## <a id="co-routines" ></a> Co-routines
