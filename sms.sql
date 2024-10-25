-- Active: 1719579663058@@127.0.0.1@1433@pubs

CREATE TABLE students (
    student_id INT AUTO_INCREMENT PRIMARY KEY, -- Unique ID for each student
    first_name VARCHAR(50) NOT NULL, -- Student's first name
    last_name VARCHAR(50) NOT NULL, -- Student's last name
    dob DATE NOT NULL, -- Date of birth
    gender ENUM('Male', 'Female', 'Other') NOT NULL, -- Gender with predefined options
    address TEXT, -- Student's address
    phone VARCHAR(15), -- Student's phone number
    email VARCHAR(100) UNIQUE, -- Email address (must be unique)
    enrollment_date DATE NOT NULL -- Date of enrollment
);

CREATE TABLE courses (
    course_id INT AUTO_INCREMENT PRIMARY KEY, -- Unique ID for each course
    course_name VARCHAR(100) NOT NULL, -- Course name
    description TEXT, -- Brief description of the course
    credits INT NOT NULL -- Number of credits the course carries
);

CREATE TABLE faculty (
    faculty_id INT AUTO_INCREMENT PRIMARY KEY, -- Unique ID for each faculty member
    faculty_name VARCHAR(100) NOT NULL, -- Faculty member's name
    department VARCHAR(100) NOT NULL, -- Department to which the faculty belongs
    email VARCHAR(100) UNIQUE NOT NULL -- Email address (must be unique)
);

CREATE TABLE enrollments (
    enrollment_id INT AUTO_INCREMENT PRIMARY KEY, -- Unique enrollment ID
    student_id INT NOT NULL, -- Student ID (foreign key)
    course_id INT NOT NULL, -- Course ID (foreign key)
    enrollment_date DATE NOT NULL,
    FOREIGN KEY (student_id) REFERENCES students (student_id) ON DELETE CASCADE,
    FOREIGN KEY (course_id) REFERENCES courses (course_id) ON DELETE CASCADE
);

CREATE TABLE grades (
    grade_id INT AUTO_INCREMENT PRIMARY KEY, -- Unique ID for the grade record
    student_id INT NOT NULL, -- Student ID (foreign key)
    course_id INT NOT NULL, -- Course ID (foreign key)
    grade CHAR(2) NOT NULL, -- Grade received (e.g., A, B, C, etc.)
    semester VARCHAR(20) NOT NULL, -- Semester information (e.g., Fall 2024)
    FOREIGN KEY (student_id) REFERENCES students (student_id) ON DELETE CASCADE,
    FOREIGN KEY (course_id) REFERENCES courses (course_id) ON DELETE CASCADE
);

CREATE TABLE attendance (
    attendance_id INT AUTO_INCREMENT PRIMARY KEY, -- Unique ID for attendance record
    student_id INT NOT NULL, -- Student ID (foreign key)
    course_id INT NOT NULL, -- Course ID (foreign key)
    date DATE NOT NULL, -- Date of the class
    status ENUM('Present', 'Absent', 'Late') NOT NULL, -- Attendance status
    FOREIGN KEY (student_id) REFERENCES students (student_id) ON DELETE CASCADE,
    FOREIGN KEY (course_id) REFERENCES courses (course_id) ON DELETE CASCADE
);

CREATE TABLE admins (
    admin_id INT AUTO_INCREMENT PRIMARY KEY, -- Unique ID for each admin
    username VARCHAR(50) NOT NULL UNIQUE, -- Admin's username
    password_hash VARCHAR(255) NOT NULL -- Hashed password for security
);

CREATE PROCEDURE EnrollStudent(
    IN p_student_id INT,
    IN p_course_id INT,
    IN p_enrollment_date DATE
)
BEGIN
    
    IF EXISTS (SELECT * FROM enrollments WHERE student_id = p_student_id AND course_id = p_course_id) THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Student is already enrolled in this course';
    ELSE
        
        INSERT INTO enrollments (student_id, course_id, enrollment_date)
        VALUES (p_student_id, p_course_id, p_enrollment_date);
    END IF;
END

CREATE PROCEDURE UpdateGrade(
    IN p_student_id INT,
    IN p_course_id INT,
    IN p_grade CHAR(2),
    IN p_semester VARCHAR(20)
)
BEGIN
    
    IF EXISTS (SELECT * FROM grades WHERE student_id = p_student_id AND course_id = p_course_id) THEN
        
        UPDATE grades
        SET grade = p_grade, semester = p_semester
        WHERE student_id = p_student_id AND course_id = p_course_id;
    ELSE
        
        INSERT INTO grades (student_id, course_id, grade, semester)
        VALUES (p_student_id, p_course_id, p_grade, p_semester);
    END IF;
END

CREATE PROCEDURE GetStudentReport(
    IN p_student_id INT
)
BEGIN
    SELECT c.course_name, g.grade, g.semester, a.status AS attendance_status, a.date AS attendance_date
    FROM courses c
    JOIN enrollments e ON c.course_id = e.course_id
    LEFT JOIN grades g ON e.student_id = g.student_id AND e.course_id = g.course_id
    LEFT JOIN attendance a ON e.student_id = a.student_id AND e.course_id = a.course_id
    WHERE e.student_id = p_student_id
    ORDER BY c.course_name, a.date;
END

CREATE TRIGGER before_insert_enrollment
BEFORE INSERT ON enrollments
FOR EACH ROW
BEGIN
    -- If enrollment_date is NULL, set it to the current date
    IF NEW.enrollment_date IS NULL THEN
        SET NEW.enrollment_date = CURDATE();
    END IF;
END;

CREATE TRIGGER prevent_duplicate_enrollment
BEFORE INSERT ON enrollments
FOR EACH ROW
BEGIN
    -- Check if the student is already enrolled in the course
    IF EXISTS (SELECT * FROM enrollments WHERE student_id = NEW.student_id AND course_id = NEW.course_id) THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Student is already enrolled in this course';
    END IF;
END;

CREATE TRIGGER insert_default_attendance
AFTER INSERT ON enrollments
FOR EACH ROW
BEGIN
    -- Insert a default attendance record for the new enrollment
    INSERT INTO attendance (student_id, course_id, date, status)
    VALUES (NEW.student_id, NEW.course_id, CURDATE(), 'Present');
END;-- First, create the grades_history table to log changes

CREATE TABLE grades_history (
    history_id INT AUTO_INCREMENT PRIMARY KEY,
    student_id INT,
    course_id INT,
    old_grade CHAR(2),
    new_grade CHAR(2),
    change_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TRIGGER log_grade_changes
BEFORE UPDATE ON grades
FOR EACH ROW
BEGIN
    -- Log the old and new grade values into the history table
    INSERT INTO grades_history (student_id, course_id, old_grade, new_grade)
    VALUES (OLD.student_id, OLD.course_id, OLD.grade, NEW.grade);
END;