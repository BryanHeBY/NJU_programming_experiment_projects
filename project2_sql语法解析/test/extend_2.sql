DROP TABLE IF EXISTS p_a;
DROP TABLE IF EXISTS p_b;
DROP TABLE IF EXISTS p_c;
DROP TABLE IF EXISTS p_d;
CREATE TABLE p_a (col INT);
CREATE TABLE p_b (col INT);
CREATE TABLE p_c (col INT);
CREATE TABLE p_d (col INT);

INSERT INTO p_a VALUES(1);
INSERT INTO p_a VALUES(2);
INSERT INTO p_a VALUES(3);
INSERT INTO p_a VALUES(4);

INSERT INTO p_b VALUES(1);
INSERT INTO p_b VALUES(2);
INSERT INTO p_b VALUES(3);
INSERT INTO p_b VALUES(4);

INSERT INTO p_c VALUES(1);
INSERT INTO p_c VALUES(2);
INSERT INTO p_c VALUES(3);
INSERT INTO p_c VALUES(4);

INSERT INTO p_d VALUES(1);
INSERT INTO p_d VALUES(2);
INSERT INTO p_d VALUES(3);
INSERT INTO p_d VALUES(4);

SELECT * FROM p_a;
SELECT * FROM p_b;
SELECT * FROM p_c;
SELECT * FROM p_d;

SELECT * FROM p_a,p_b;

SELECT p_a.col,p_b.col,p_c.col,p_d.col FROM p_a,p_b,p_c,p_d WHERE p_a.col<>p_b.col AND p_a.col<>p_c.col AND p_a.col<>p_d.col AND p_b.col<>p_c.col AND p_b.col<>p_d.col AND p_c.col<>p_d.col;
SELECT p_a.col,p_b.col,p_c.col,p_d.col FROM p_a,p_b,p_c,p_d WHERE p_a.col+p_b.col+p_c.col+p_d.col=7;

