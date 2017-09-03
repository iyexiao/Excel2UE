# Excel2UE
export excel to UE4 cpp script and txt resources

# Node
need python2.7 and install openpyxl setuptools xlrd p

### excel2lua
built in cmd 
	  
	  python excel2lua.py excelDir cppDir projnAME
1.规范sheet 中|线分割前面为注释，后面为导出的TXT和cpp文件名，形如角色|role  
2.excel中第一行为注释、第二行为类型（目前支持int,bool,string,object,class）、第三行为字段名字。其中第二行可以通过|分割是否只有前端或者后端导出，形如string|client  
3.默认第一列为TMap中的key值，并且为int或者string不重复的类型，因为导出的cpp中要用这个来查找和返回数据。
4.表中的数据可以为空，int导出的时候为-1，bool为false 其他字段都为""
### TODO
1.添加git支持
2.添加scp支持
3.多类型判断及对excel表做检查