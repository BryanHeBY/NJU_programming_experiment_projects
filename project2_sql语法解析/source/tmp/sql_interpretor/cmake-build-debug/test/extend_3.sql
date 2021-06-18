DROP TABLE IF EXISTS student;
CREATE TABLE student (
	id INTEGER PRIMARY KEY,
	name VARCHAR(20),
	birth_place VARCHAR(20),
	major_code SMALLINT,
	account INT
);
INSERT INTO student VALUES (1,"卷王","火星",1,100);
INSERT INTO student VALUES (2,"Juan Nei","NJU",2,200);
INSERT INTO student VALUES (3,"蒟蒻","Nowhere",1,300);
INSERT INTO student VALUES (4,"aaa","Nowhere",3,87);
INSERT INTO student VALUES (5,"bbb","Nowhere",1,44);
SELECT * FROM student;

DROP TABLE IF EXISTS majors;
CREATE TABLE majors (
	code SMALLINT PRIMARY KEY,
	abbr VARCHAR(5),
	full_name VARCHAR(40)
);
INSERT INTO majors VALUES (1,"CS","Computer Science");
INSERT INTO majors VALUES (2,"SE","Software Engineering");
INSERT INTO majors VALUES (3,"AI","artificial inteligence");
SELECT * FROM majors;

SELECT * FROM student;
UPDATE student SET account=account+1000 WHERE major_code=1;
SELECT id,student.name,account,majors.full_name FROM student,majors WHERE student.major_code=majors.code;

