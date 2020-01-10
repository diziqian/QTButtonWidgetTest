# QTButtonWidgetTest


本项目用于测试如下事项：
1）QTableWidget的整行的消息响应；
2）QTableWidget的某个Cell的消息响应；
3）QTableWidget的Cell为某个按钮的时候，把按钮的消息转为整个对话框的消息，实现类似的整个QTableWidget的消息响应；
4）QPushButton作为某个元素进入QTableWidget，并对QPushButton进行删除操作，即保证QPushButton的灵活配置；
5）整个对话框避免内存泄漏；
6）避免对话框退出以后的程序崩溃。