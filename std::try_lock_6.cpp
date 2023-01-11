
0. std::try_lock() tries to lock all the mutex passed in it one by one in given order.It can try to lock multiple mutex at the same time.***
1. On success this function returns -1, otherwise it will return 0-based mutex index number which it could not lock.
2. If it fails to lock any of the mutex then it will release all the mutex it locked before.
3. If a call to try_lock results in an exception, unlock is called for any locked objects before re-throwing.
  
  
  if we use m.try_lock() -- we can lock only this mutex. But using std::try_lock we can lock all the mutex **** VVVIMP
