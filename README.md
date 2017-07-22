#纯C面向对象
---
##1. C语言实现this指针
###相关接口：
```
Obj(object).       //宏，将变量切换为对象，使用 . 进行后续访问
ObjRef(pObject)->    //宏，将指针变量切换为对象引用，使用 -> 进行后续访问 
_this               //获取当前对象指针,不建议直接使用
THIS(type)      //生成一个类型为type的this指针,注意不要全局作用域上使用该宏
ThisRelease()	//多线程下使用，用于清空当前线程下的this指针cache
```

###注意要点：
1. 如果需要多线程支持，需要在GCC编译参数中增加-D THIS_PTHREAD_SUPPORT 选项（不能在文件中增加），多线程支持模式下，对象访问效率会降低很多；

2. Obj和ObjRef都不能嵌套使用，例如:  `Obj(test1).fun3(Obj(test2).fun4(100));` 这样会导致this指针混乱，请保证每次对象操作的对象单一性；

3. 在对象成员函数中使用_this指针时，应该尽量在开始处获取_this指针然后保存下来，不要反复去获取_this指针。一方面反复获取_this指针会导致效率低下，另一方面，_this指针有可能会被其他操作修改；
( 20170722 更新增加宏 THIS(type) 来自动获取this指针,不建议再使用_this指针);

4. ThisRelease函数是不强制使用的，但是建议使用。多线程支持下，模块会为每个使用过对象的线程都创建一个不多于24字节的this cache，当进程频繁创建线程的时候，this cache累积会不容忽视，因此建议在线程结束前调用ThisRelease;

5. 其他以后继续慢慢补充。


详细用法参考[PeopleObject.c](PeopleObject.c) 和 [PeopleObjectTest.c](PeopleObjectTest.c)

---