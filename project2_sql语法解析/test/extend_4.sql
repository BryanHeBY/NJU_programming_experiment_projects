DROP TABLE IF EXISTS test_a;
DROP TABLE IF EXISTS test_b;
CREATE TABLE test_a (a INT,b INT,c VARCHAR(50));
CREATE TABLE test_b (a INT,b VARCHAR(50));

INSERT INTO test_a VALUES(1,7,"TestA1");
INSERT INTO test_a VALUES(2,-33333,"TeestA2");
INSERT INTO test_a VALUES(3,0,"testA");
INSERT INTO test_a VALUES(4,66,"#test#");
INSERT INTO test_a VALUES(5,2,"teestA3");
INSERT INTO test_a VALUES(6,-211,"testAA55");

INSERT INTO test_b VALUES(1,"TestB1");
INSERT INTO test_b VALUES(2,"TestB2");
INSERT INTO test_b VALUES(3,"TestB3");
INSERT INTO test_b VALUES(4,"TestB4");
INSERT INTO test_b VALUES(5,"TestB5");
INSERT INTO test_b VALUES(6,"TestB6");

SELECT * FROM test_a;
SELECT * FROM test_b;

SELECT * FROM test_a WHERE c LIKE "[Tt]estA%";
SELECT test_a.a,test_a.b,test_b.b,test_a.c FROM test_a,test_b WHERE test_a.a=test_b.a AND test_a.a*test_a.b<=100 ORDER BY test_a.b DESC LIMIT 4;

