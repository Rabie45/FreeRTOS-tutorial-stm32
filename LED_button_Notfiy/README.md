# FreeRTOS Template

## In this part New Functions APIs we gonna use
```BaseType_t xTaskNotify( TaskHandle_t xTaskToNotify,
                         uint32_t ulValue,
                         eNotifyAction eAction );```
                         
- TaskNotify() is used to send an event directly to and potentially unblock an RTOS task

 **Parameter**\
TaskHandle_t xTaskToNotify : The handle of the RTOS task being notified. This is the target task.
uint32_t ulValue : Used to update the notification value of the target task. 
eNotifyAction eAction : An enumerated type that can take one of the values documented in the table below in order to perform the associated action.

eAction have multible possible case :
- eNoAction = 0  Notify the task without updating its notify value
- eSetBits,	Set bits in the task's notification value. 
- eIncrement  Increment the task's notification value. 
- eSetValueWithOverwrite  Set the task's notification value to a specific value even if the previous value has not yet been read by the task. 
- eSetValueWithoutOverwrite Set the task's notification value if the previous value has been read by the task. 

```xTaskNotifyWait( uint32_t ulBitsToClearOnEntry,
                             uint32_t ulBitsToClearOnExit,
                             uint32_t *pulNotificationValue,
                             TickType_t xTicksToWait );```
- this function used to wait until an event happen

 **Parameter**
 - uint32_t ulBitsToClearOnEntry : if ulBitsToClearOnEntry is 0x01, then bit 0 of the task's notification value will be cleared on entry to the function.
 - uint32_t ulBitsToClearOnExit : if ulBitsToClearOnExit is 0x03, then bit 0 and bit 1 of the task's notification value will be cleared before the function exits.
 - uint32_t *pulNotificationValue : Used to pass out the RTOS task's notification value. 
 - TickType_t xTicksToWait : The maximum time to wait in the Blocked state for a notification to be received if a notification is not already pending when xTaskNotifyWait() is called.

__flowcontrol__
- when the button is pressed the buttontask is goning to notfiy the led task to work without pressing the ledtask will be blocked 
