DROP TABLE IF EXISTS test1;
CREATE TABLE test1 (col_boolean BOOLEAN,col_smallint SMALLINT PRIMARY KEY,col_integer INTEGER,col_bigint BIGINT,col_float FLOAT,col_double DOUBLE,col_varchar_30 VARCHAR(30));
INSERT INTO test1 VALUES(1,-1,-222,998244353,-0.0006,4.5577734378984,"var  str *12  __--++");
SELECT * FROM test1;

