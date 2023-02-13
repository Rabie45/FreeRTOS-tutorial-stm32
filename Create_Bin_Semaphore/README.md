# Binary Semaphore
 
 - If you dont know about semaphore check this link(https://www.geeksforgeeks.org/semaphores-in-process-synchronization/)
 
  ## In this part New Functions APIs we gonna use: 

     - vSemaphoreCreateBinary( SemaphoreHandle_t xSemaphore )


  	  ## Parameters:
	   - xSemaphore 	Handle to the created semaphore. Should be of type SemaphoreHandle_t.

     - xSemaphoreTake( SemaphoreHandle_t xSemaphore,
                 TickType_t xTicksToWait );

          ## Parameters:
	   - xSemaphore 	A handle to the semaphore being taken - obtained when the semaphore was created.
	   - xTicksToWait 	The time in ticks to wait for the semaphore to become available. The macro portTICK_PERIOD_MS can be used to convert this to a real time. A block time of zero can be used to poll the semaphore.

           ## Returns:
             pdTRUE if the semaphore was obtained. pdFALSE if xTicksToWait expired without the semaphore becoming available.

      - xSemaphoreGive( SemaphoreHandle_t xSemaphore );

          ## Parameters:
           - xSemaphore 	A handle to the semaphore being released. This is the handle returned when the semaphore was created.

           ## Returns:
            pdTRUE if the semaphore was released. pdFALSE if an error occurred. Semaphores are implemented using queues. An error can occur if there is no space on the queue to post a message - indicating that the semaphore was not first obtained correctly.

__Flowcontrol__
- Create two task ,semphore ,queue
- The first task has piroity greater than the second
- The semaphore would take the handle and goes into loop
  - Send the id to the queue
  - IF the return == pass the data added succefully  
  - Else no space in the queue switch to the second task
- The second task take the semaphore to use and check if the queue recive print id of the taske
- Else the queue is empty  
