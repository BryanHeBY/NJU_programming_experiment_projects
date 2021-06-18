DROP TABLE IF EXISTS book;
CREATE TABLE book (name VARCHAR(40),price INTEGER); 
INSERT INTO book VALUES("Computer Science",30);
INSERT INTO book VALUES("Colourful",30);
INSERT INTO book VALUES("colorful",30);
INSERT INTO book VALUES("AI",40);
INSERT INTO book VALUES("算法导论",70);
INSERT INTO book VALUES("人工智能导论",50);
INSERT INTO book VALUES("数据库导论",30);
INSERT INTO book VALUES("机器学习导论",110);

SELECT * FROM book;
SELECT * FROM book WHERE name LIKE "%导论%" AND price<=100;
SELECT * FROM book WHERE name LIKE "[Cc]olou?rful";

