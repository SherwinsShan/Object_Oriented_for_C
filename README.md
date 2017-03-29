#纯C面向对象
---
##1. C语言实现this指针
###相关接口：
```
ThisSuppost();//多线程支持下必须调用，且必须在进行对象操作前调用，调用一次即可（建议放在主程序开始处） 
Obj()	//宏，将变量切换为对象，使用 . 进行后续访问
ObjRef（）//宏，将指针变量切换为对象引用，使用 -> 进行后续访问 
_this	//获取当前对象指针
```

###注意要点：
1. 如果需要多线程支持，需要在GCC编译参数中增加-D THIS_PTHREAD_SUPPORT 选项（不能在文件中增加），多线程支持模式下，对象访问效率会降低很多；
2. Obj和ObjRef都不能嵌套使用，例如:  `Obj(test1).fun3(Obj(test2).fun4(100));` 这样会导致this指针混乱，请保证每次对象操作的对象单一性；
3. 在对象成员函数中使用_this指针时，应该尽量在开始处获取_this指针然后保存下来，不要反复去获取_this指针。一方面反复获取_this指针会导致效率低下，另一方面，_this指针有可能会被其他操作修改；
4. 其他以后继续慢慢补充。


详细用法参考[objectTest.c](objectTest.c) 和 [testInterface.c](testInterface.c)

---