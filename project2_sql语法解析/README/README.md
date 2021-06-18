# #[M](project2: 简易**sql parser**)
#[R](Authored by: BryanHe)
## 一、扩展功能
### 1.读取外部输入文件
使用文件格式
```
./sql [-h] [fil1.sql file2.sql .... ]
```
- [-h] 输入-h，输入文件的语句就不会显示在终端
- [fil1.sql file2.sql .... ] 程序会按顺序执行fil1.sql file2.sql ....中的sql语句
e.g.
#[M](==================test/file1.sql==================)
```sql
DROP TABLE IF EXISTS test_file;
CREATE TABLE test_file (test);
INSERT INTO test_file VALUES("test_sentence");
```
#[M](==================test/file2.sql==================)
```sql
SELECT * FROM test_file;
```
执行`./sql file1.sql file2.sql`
<img src=images/1.png width="400px">
### 2.语句颜色标志(示例如上图)
- 白色语句：普通语句
- 蓝色语句：文件读入标志语句
- 黄色语句：语句成功执行提示语句
- 红色语句：异常执行语句
### 3.支持多行输入
### 4.完善的类型系统
当前支持: BOOLEAN, SMAILLINT, INTEGER, BIGINT, FLOAT, DOUBLE, VARCHAR(SIZE) 7种数据类型
在执行函数运算时会自动进行类型转换
> e.g.
> `./sql test/extend_1.sql`
### 5.支持多表联合查询: 理论上支持不限个数表格联合查询
> e.g.
> `./sql test/extend_2.sql`
> p_a, p_b的结构都是
> <img src=images/2.png width="200px">
> <img src=images/3.png width="300px">
### 6.支持多种双目运算符以及含括号的表达式
理论上支持不限长度的语法正确的计算表达式
当前支持的双目运算符以及其优先级
- OR 2
- AND 2
- < 3
- > 3
- <> 3
- = 3
- <= 3
- >= 3
- + 4
- - 4
- * 5
- / 5
- LIKE 6
其中，LIKE是模糊字符串匹配，支持sql通配符以及正则表达式
> e.g.
> `./sql test/extend_4.sql`
> <img src=images/6.png width="300px">
> <img src=images/7.png width="500px">
### 7.WHERE后允许接表达式
> 示例一、
> `./sql test/extend_2.sql`
> p_a, p_b, p_c, p_d的结构都是
> <img src=images/2.png width="200px">
> 获得1,2,3,4全排列
> ```
> SELECT 
> 	p_a.col,p_b.col,p_c.col,p_d.col 
> FROM
> 	p_a,p_b,p_c,p_d
> WHERE 
> 	p_a.col<>p_b.col AND p_a.col<>p_c.col AND p_a.col<>p_d.col AND 
> 	p_b.col<>p_c.col AND p_b.col<>p_d.col AND 
> 	p_c.col<>p_d.col;
> ```
> <img src=images/4.png width="400px">
> 获得[1,4]内和为7的整数解
> ```
> SELECT 
> 	p_a.col,p_b.col,p_c.col,p_d.col 
> FROM 
> 	p_a,p_b,p_c,p_d 
> WHERE 
> 	p_a.col+p_b.col+p_c.col+p_d.col=7;
> ```
> <img src=images/5.png width="400px">
<br>

> 示例二、
> `./sql test/extend_4.sql`

### 8.UPDATE支持多个键值修改
### 9.UPDATE SET允许接表达式
> e.g.
> `./sql test/extend_3.sql`
> <img src=images/8.png width="500px">
> 为major_code为1的同学account充值1000元
> <img src=images/9.png width="500px">
