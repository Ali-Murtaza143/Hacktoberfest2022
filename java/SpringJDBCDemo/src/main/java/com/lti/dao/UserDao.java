package com.lti.dao;

import java.util.List;

import org.springframework.jdbc.core.JdbcTemplate;

import com.lti.entity.Student;
import com.lti.mapper.StudentRowMapper;

public class UserDao {

	JdbcTemplate jdbcTemplate;

	public JdbcTemplate getJdbcTemplate() {
		return jdbcTemplate;
	}

	public void setJdbcTemplate(JdbcTemplate jdbcTemplate) {
		this.jdbcTemplate = jdbcTemplate;
	}

	public int addStudent(Student student) {

		String qry = "insert into tbl_studentnew values(stud_seq.nextval,?,?,?)";
		int rec = jdbcTemplate.update(qry, new Object[] { student.getName(), student.getAge(), student.getCity() });

		return rec;

	}

	public int updateStudent(Student student) {
		String qry = "update  tbl_studentnew set name=?,age=?,city=?" + "where rollno=?";
		int rec = jdbcTemplate.update(qry,
				new Object[] { student.getName(), student.getAge(), student.getCity(), student.getRollNo(), });
		return rec;
	}

	public int updateStuCity(String city, int rollNo) {

		String qry = "update  tbl_studentnew set city=?" + "where rollno=?";
		int rec = jdbcTemplate.update(qry, new Object[] { city, rollNo });
		return rec;

	}

	public int removeStudent(int rollno) {
		String query = "delete tbl_studentnew where rollno=?";

		int rec = jdbcTemplate.update(query, new Object[] { rollno });
		return rec;

	}
	
	public List<Student> viewAllStudent()
	{
		String query = "select * from tbl_studentnew ";
		return  jdbcTemplate.query(query, new StudentRowMapper());
		
	}
	
	public Student findStudentbyId(int rollNo)
	{
		String qry = "select * from   tbl_studentnew where rollno=?";
	  return  jdbcTemplate.queryForObject(qry, new StudentRowMapper(),
			   new Object[] {rollNo});
	}
}
