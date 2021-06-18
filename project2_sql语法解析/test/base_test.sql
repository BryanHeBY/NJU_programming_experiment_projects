SHOW TABLES;

DROP TABLE IF EXISTS department;
CREATE TABLE department (name);
CREATE TABLE department (col_a); 
DROP TABLE department;
DROP TABLE department;
SHOW TABLES;

DROP TABLE IF EXISTS test;
DROP TABLE IF EXISTS test;
DROP TABLE test;
CREATE TABLE test (column_one,column_two PRIMARY_KEY);
SHOW TABLES;
DROP TABLE test;
CREATE TABLE test (column_one,column_one);

INSERT INTO student VALUES ("12","张三三","江苏");
INSERT INTO student VALUES ("123","张三三");
INSERT INTO student VALUES ("123",);
INSERT INTO student VALUES ();
INSERT INTO student VALUES ("123","张三三","江苏");

SELECT * FROM student;
SELECT DISTINCT birth_place FROM student;
SELECT name,id FROM student WHERE birth_place="江苏";
SELECT * FROM student WHERE birth_place="江苏" AND name="张三";
SELECT * FROM student WHERE birth_place="江苏" OR birth_place="北京";

SELECT * FROM students;
SELECT born_place FROM student;
SELECT * FROM student WHERE born_place="江苏";
SELECT * FROM student WHERE birth_place = AND;

DROP TABLE IF EXISTS case2;
CREATE TABLE case2 (a,b,c);
INSERT INTO case2 VALUES("1","2","3");
INSERT INTO case2 VALUES("1","3","1");
INSERT INTO case2 VALUES("1","2","4");
INSERT INTO case2 VALUES("1","2","5");
SELECT * FROM case2;
SELECT DISTINCT a,b FROM case2;

UPDATE student SET birth_place="Jiangsu" WHERE birth_place="江苏";
SELECT * FROM student;
UPDATE student SET birth_place="Nanjing" WHERE birth_place="Jiangsu" AND id="12";
SELECT * FROM student;
UPDATE student SET id="12" WHERE id="123";
SELECT * FROM student;

DELETE FROM student WHERE name="王五" OR birth_place="Nanjing";
SELECT * FROM student;

