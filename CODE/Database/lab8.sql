-- Active: 1674727868130@@127.0.0.1@3306@btech
SELECT * FROM class;
SELECT * FROM enrolled;
SELECT * FROM student;

Delimiter $
CREATE TRIGGER update_credits AFTER UPDATE ON enrolled
FOR EACH ROW
BEGIN
    DECLARE total_credits INT DEFAULT 0;
    SELECT SUM(CASE WHEN grade <> 'F' THEN count ELSE 0 END)
    INTO total_credits
    FROM enrolled JOIN class ON enrolled.cname = class.name
    WHERE enrolled.snum = NEW.snum;
    UPDATE student SET total_credits = total_credits WHERE snum = NEW.snum;
END $
DELIMITER ;
-- DROP Trigger update_credits;


UPDATE enrolled set grade = 'A'
WHERE cname = 'Database Systems' and snum = 112348546;

-- SECOND QUESTION
-- 112348546
SELECT * from student;
SELECT * FROM class;
SELECT * from enrolled;
SELECT * FROM ready_students;
-- Database Systems
UPDATE class SET count = 8
WHERE name = 'Database Systems';

-- create TABLE ready_students (
--   snum int PRIMARY KEY
-- );


DELIMITER $
CREATE TRIGGER update_ready_students AFTER UPDATE ON student
FOR EACH ROW
BEGIN
  IF NEW.total_credits > 10 THEN
    INSERT INTO ready_students (snum) VALUES (NEW.snum);
  ELSE
    DELETE FROM ready_students WHERE snum = NEW.snum;
  END IF;
END $
DELIMITER ;

