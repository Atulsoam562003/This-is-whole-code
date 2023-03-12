-- DROP FUNCTION count_students_by_instructor;
DELIMITER $
CREATE FUNCTION count_students_by_instructor(instructor_name VARCHAR(255))
RETURNS INT
DETERMINISTIC
    BEGIN
        DECLARE student_count INT;
        SELECT COUNT(DISTINCT snum)
        INTO student_count
        FROM enrolled e;
        RETURN student_count;
    END $
DELIMITER ;

select fname
FROM faculty
WHERE count_students_by_instructor(fname) > 1;