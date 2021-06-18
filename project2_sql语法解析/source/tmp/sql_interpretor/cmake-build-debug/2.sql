DROP TABLE IF EXISTS student;
CREATE TABLE student (
	id INTEGER PRIMARY KEY,
	name VARCHAR(50),
	birth_place VARCHAR(20),
	major_code SMALLINT
);
INSERT INTO student VALUES (1,"卷王","Nanjing",1);
INSERT INTO student VALUES (2,"Juan Nei","Shanghai",2);
INSERT INTO student VALUES (3,"蒟蒻","Beijing",1);
INSERT INTO student VALUES (4,"aaa","Nanjing",3);
INSERT INTO student VALUES (5,"bbb","Beijing",4);

SELECT * FROM student;
SELECT DISTINCT birth_place FROM student;
SELECT id,name FROM student WHERE birth_place="Beijing" OR birth_place="Shanghai";
SELECT * FROM student ORDER BY major_code DESC;

UPDATE student SET name=name+"_from_"+birth_place WHERE birth_place="Beijing";
UPDATE student SET id=id+1;
SELECT * FROM student;

