**In previous section we explanid the the FreeRTOS templte we gonna use in this basic tutorial*

In this part we will learn how to mcreate the task which is the basic structure of the RTOS\

# Syntex
 BaseType_t xTaskCreate( TaskFunction_t pxTaskCode,
                            const char * const pcName, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
                            const configSTACK_DEPTH_TYPE usStackDepth,
                            void * const pvParameters,
                            UBaseType_t uxPriority,
                            TaskHandle_t * const pxCreatedTask )
                            
                            
**this function used to create task with some intial parameters**
  - TaskFunction_t pxTaskCode : which is the address of the task the task is the some line of code in function form 
  - const char * const pcName: The name of the task it is better to make a name for every task
  - const configSTACK_DEPTH_TYPE usStackDepth: the stack size you this task gonna take in the system 
  - void * const pvParameters: parameter you wanna pass if needed
  - UBaseType_t uxPriorit: the proirity of the taske the lower number the higher priorty 
  - TaskHandle_t * const pxCreatedTask: Type by which tasks are referenced. For example, a call to xTaskCreate returns (via a pointer parameter) an TaskHandle_t variable that can then be used as a parameter to vTaskDelete to delete the task.
  vTaskStartScheduler();
  - Starts the RTOS scheduler. After calling the RTOS kernel has control over which tasks are executed
  
## Work flow
 
1. first create task 1 and task 2
2. Call the scheduler (by vTaskStartScheduler()) 

watch the output in the output file ;)
