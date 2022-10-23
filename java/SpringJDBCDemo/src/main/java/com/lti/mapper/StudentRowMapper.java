package com.lti.mapper;

import java.sql.ResultSet;
import java.sql.SQLException;

import org.springframework.jdbc.core.RowMapper;

import com.lti.entity.Student;

public class StudentRowMapper implements RowMapper<Student>

{

	public Student mapRow(ResultSet rs, int rowNum) throws SQLException {
		
		Student stu=new Student();
		stu.setRollNo(rs.getInt(1));
		stu.setName(rs.getString(2));
		stu.setAge(rs.getInt(3));
		stu.setCity(rs.getString(4));
		
		
		return stu;
	}

}
