-- Active: 1674727868130@@127.0.0.1@3306@btech
-- drop function count_students_by_instructor
DELIMITER $
CREATE FUNCTION count_students_by_instructor(instructor_id INT, course_name VARCHAR(50))
RETURNS INT
DETERMINISTIC
READS SQL DATA
BEGIN
  DECLARE student_count INT;
  SELECT COUNT(*) INTO student_count FROM enrolled e
  INNER JOIN class c ON e.cname = c.name
  WHERE c.fid = instructor_id AND c.name = course_name;
  RETURN student_count;
END $
DELIMITER ;


SELECT f.fname AS instructor_name
FROM faculty f
INNER JOIN class c ON f.fid = c.fid
GROUP BY f.fname
HAVING SUM(count_students_by_instructor(f.fid, c.name)) > 1;

DELIMITER $
CREATE FUNCTION count_failing_students(course_name VARCHAR(50))
RETURNS INT
DETERMINISTIC
READS SQL DATA
BEGIN
  DECLARE failing_count INT;
  SELECT COUNT(*) INTO failing_count FROM enrolled
  WHERE cname = course_name AND grade = 'F';
  RETURN failing_count;
END $
DELIMITER ;

SELECT f.fname
FROM faculty f
INNER JOIN class c ON f.fid = c.fid
INNER JOIN enrolled e ON c.name = e.cname
WHERE e.grade = 'F'
GROUP BY f.fname , c.name
HAVING count_failing_students(c.name) > 1;