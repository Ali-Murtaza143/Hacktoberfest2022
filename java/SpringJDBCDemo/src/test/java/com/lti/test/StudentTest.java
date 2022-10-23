package com.lti.test;

import static org.junit.Assert.*;

import java.util.List;

import org.junit.Before;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import com.lti.dao.UserDao;
import com.lti.entity.Student;

public class StudentTest {
	UserDao dao;

	@Before
	public void initialise() {
		ApplicationContext context = new ClassPathXmlApplicationContext("spring-config.xml");
		dao = (UserDao) context.getBean("userDao");
	}
	

	@Test
	public void addStudentTest() {

		Student stu = new Student();
		stu.setName("rurjfjina");
		stu.setAge(80);
		stu.setCity("uejfkjko");

		int rec = dao.addStudent(stu);
		System.out.println("1 new record inserted");
	}

	@Test
	public void updateStudent() {
		Student stu = new Student();
		stu.setRollNo(1003);
		stu.setName("lina");
		stu.setAge(10);
		stu.setCity("kauio");

		int rec = dao.updateStudent(stu);
		System.out.println("NEW RECORD UPDATE");

	}

	@Test
	public void updateCityTest() {
		int rec = dao.updateStuCity("Kolkata", 1002);

		System.out.println("City updated " + rec);
	}

	@Test
	public void deleteStudentTest() {

		int rec = dao.removeStudent(1001);

		System.out.println(" one Record deleted " );
	}
	
	
	@Test
	public void viewAllStudentTest()
	{List<Student> stu=dao.viewAllStudent();
	//assertTrue(stu.isEmpty());
	assertNotNull(stu);
	}	
	@Test
	public void findStudentByIdTest()
	{
		Student atu=dao.findStudentbyId(1002);
		assertNotNull(atu);
	}
	

}
