select request_session_id
from sys.dm_tran_locks
where resource_type = 'database' and
	resource_database_id = 3 and
	request_type = 'LOCK' and
	request_status = 'GRANT';

use sms;
CREATE TABLE students
(
	student_id INT IDENTITY(1, 1) PRIMARY KEY,
	name VARCHAR(32),
	dob DATE NOT NULL,
	gender VARCHAR(6) NOT NULL,
	phone VARCHAR(15),
	email VARCHAR(100) UNIQUE,
	enrollment_date DATE DEFAULT GETDATE()
);
insert into students
	(name, email, phone, dob, gender)
VALUES
	(
		'Shanto',
		'zahidshanto@gmail.com',
		'01583778462',
		'2001-01-05',
		'male'
);
select *
from students;

update students set phone = '01983884954' where student_id = 2;

CREATE TABLE courses
(
	course_id INT IDENTITY(1, 1) PRIMARY KEY,
	course_name VARCHAR(100) NOT NULL,
	credits FLOAT NOT NULL,
);
insert into courses
	(course_name, credits)
values
	('Viva-voce', 1.50);
update courses set credits = 1.5 where course_name like '%voce';
select *
from courses;

CREATE TABLE faculty
(
	faculty_id INT IDENTITY(1, 1) PRIMARY KEY,
	faculty_name VARCHAR(100) NOT NULL,
	email VARCHAR(100) UNIQUE NOT NULL
);

insert into faculty
	(faculty_name, email)
values
	('Sohag Sarker Anol', 'sohagsarkeranol@pust.ac.bd');
select *
from faculty;


CREATE TABLE enrollments
(
	enrollment_id INT IDENTITY(1,1) PRIMARY KEY,
	student_id INT NOT NULL,
	course_id INT NOT NULL,
	enrollment_date DATE DEFAULT GETDATE(),
	FOREIGN KEY (student_id) REFERENCES students(student_id) ON DELETE CASCADE,
	FOREIGN KEY (course_id) REFERENCES courses(course_id) ON DELETE CASCADE
);

insert into enrollments
	(student_id, course_id)
values
	(1, 11);
select *
from enrollments;

CREATE TABLE grades
(
	grade_id INT IDENTITY(1,1) PRIMARY KEY,
	student_id INT NOT NULL,
	course_id INT NOT NULL,
	grade CHAR(2) NOT NULL,
	semester VARCHAR(20) NOT NULL,
	FOREIGN KEY (student_id) REFERENCES students(student_id) ON DELETE CASCADE,
	FOREIGN KEY (course_id) REFERENCES courses(course_id) ON DELETE CASCADE
);

select *
from grades;


select *
from grades;

CREATE TABLE attendance
(
	attendance_id INT IDENTITY(1,1) PRIMARY KEY,
	student_id INT NOT NULL,
	course_id INT NOT NULL,
	date DATE DEFAULT GETDATE(),
	status CHAR(1) DEFAULT 'P' CHECK (status in ('P', 'A')),
	FOREIGN KEY (student_id) REFERENCES students(student_id) ON DELETE CASCADE,
	FOREIGN KEY (course_id) REFERENCES courses(course_id) ON DELETE CASCADE
);

insert into attendance
	(student_id, course_id, status)
values
	(1, 1, 'P');
select *
from attendance;

CREATE TABLE admins
(
	admin_id INT IDENTITY(1, 1) PRIMARY KEY,
	username VARCHAR(50) NOT NULL UNIQUE,
	password_hash VARCHAR(255) NOT NULL
);


SELECT s.name AS Student_Name, c.course_name AS Course_Name, e.enrollment_date
FROM students s
	JOIN enrollments e ON s.student_id = e.student_id
	JOIN courses c ON e.course_id = c.course_id
ORDER BY s.name;

SELECT student_id, name, dob, gender
FROM students
WHERE name LIKE '%r%';

SELECT c.course_name, COUNT(e.student_id) AS Number_of_Students
FROM courses c
	JOIN enrollments e ON c.course_id = e.course_id
GROUP BY c.course_name
HAVING COUNT(e.student_id) > 2;


SELECT c.course_name, COUNT(e.student_id) AS Number_of_Students
FROM courses c
	JOIN enrollments e ON c.course_id = e.course_id
GROUP BY c.course_name
HAVING COUNT(e.student_id) > 5;

SELECT c.course_name, AVG(CASE 
                             WHEN g.grade = 'A' THEN 4.0 
                             WHEN g.grade = 'B' THEN 3.0
                             WHEN g.grade = 'C' THEN 2.0
                             WHEN g.grade = 'D' THEN 1.0
                             ELSE 0
                          END) AS Avg_Grade
FROM grades g
	JOIN courses c ON g.course_id = c.course_id
WHERE g.semester = 'Fall 2024'
GROUP BY c.course_name
HAVING AVG(CASE 
             WHEN g.grade = 'A' THEN 4.0 
             WHEN g.grade = 'B' THEN 3.0
             WHEN g.grade = 'C' THEN 2.0
             WHEN g.grade = 'D' THEN 1.0
             ELSE 0
          END) < 2.0;



SELECT s.name AS Student_Name,
	SUM(CASE WHEN a.status = 'P' THEN 1 ELSE 0 END) AS Present_Days,
	SUM(CASE WHEN a.status = 'A' THEN 1 ELSE 0 END) AS Absent_Days
FROM students s
	JOIN attendance a ON s.student_id = a.student_id
WHERE a.course_id = 3
GROUP BY s.name;


SELECT s.name AS Student_Name, c.course_name AS Course, g.grade, g.semester
FROM students s
	JOIN grades g ON s.student_id = g.student_id
	JOIN courses c ON g.course_id = c.course_id
ORDER BY g.grade ASC;

