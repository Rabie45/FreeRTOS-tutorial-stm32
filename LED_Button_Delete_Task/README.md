# Delete Task

## In this part New Functions APIs we gonna use

  - void vTaskDelay( const TickType_t xTicksToDelay ) :  Delay a task for a given number of ticks. The actual time that the task remains blocked depends on the tick rate.\
    __Parameters__
  - xTicksToDelay The amount of time, in tick periods, that the calling task should block.
  
  - void vTaskDelete( TaskHandle_t xTask ) : Remove a task from the RTOS kernels management. The task being deleted will be removed from all ready, blocked, suspended and event lists.\
   __Parameters__
  xTask 	The handle of the task to be deleted. Passing NULL will cause the calling task to be deleted.
  
  
 __Control flow__
  
  the led of the board will toggle until you press the button the task will be deleted from the scudeler you can se the segguer file from sigger dump and the gif using the button 

