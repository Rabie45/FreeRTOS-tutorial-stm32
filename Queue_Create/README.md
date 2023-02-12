# Queue Creation
if you dont know any thing about queue (https://www.geeksforgeeks.org/queue-data-structure/)
 ## In this part New Functions APIs we gonna use 
  -  QueueHandle_t xQueueCreate( UBaseType_t uxQueueLength,
                             UBaseType_t uxItemSize );

Creates a new queue and returns a handle by which the queue can be referenced.(xQueue in the exrcise)
 ## Parameters:
 	 - uxQueueLength  	The maximum number of items the queue can hold at any one time.
 	 - uxItemSize  	The size, in bytes, required to hold each item in the queue.
 
 - BaseType_t xQueueSendToFront( QueueHandle_t xQueue,
                               const void * pvItemToQueue,
                               TickType_t xTicksToWait );


 ## Parameters:

  - xQueue 	The handle to the queue on which the item is to be posted.
  - pvItemToQueue 	A pointer to the item that is to be placed on the queue. The size of the items the queue will hold was defined when the queue was created, so this many bytes will be copied from pvItemToQueue into the queue storage area.
  - xTicksToWait 	The maximum amount of time the task should block waiting for space to become available on the queue, should it already be full. The call will return immediately if this is set to 0. The time is defined in tick periods so the constant portTICK_PERIOD_MS should be used to convert to real time if this is required.
 
 -  xQueueSendToBack the same as previous


__flowcontrol__
 - Create Queue 
 - Add some values from the from and the back 
 - Revome this values from the queue and store them in place holder
