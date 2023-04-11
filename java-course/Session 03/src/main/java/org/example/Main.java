package org.example;

import org.apache.poi.xssf.usermodel.XSSFSheet;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

import java.io.FileInputStream;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {

//        XSSFWorkbook workbook = new XSSFWorkbook();
//        XSSFSheet sheet = workbook.createSheet("student");
//
//        XSSFRow row =  sheet.createRow(0);
//        XSSFCell cell = row.createCell(0);
//
//        cell.setCellValue("Student id");
//        sheet.createRow(1).createCell(0).setCellValue("99999999");
//        sheet.createRow(2).createCell(0).setCellValue("99999998");
//        sheet.createRow(3).createCell(0).setCellValue("99999997");
//
//        FileOutputStream out = new FileOutputStream(new File("C:\\Users\\User\\Desktop\\MicrosoftExcel\\src\\main\\resources\\students.xlsx"));
//        workbook.write(out);
//        workbook.close();


        FileInputStream in = new FileInputStream("C:\\Users\\User\\Desktop\\MicrosoftExcel\\src\\main\\resources\\students.xlsx");
        XSSFWorkbook workbook = new XSSFWorkbook(in);
        XSSFSheet sheet = workbook.getSheet("student");

        System.out.println(sheet.getLastRowNum());
        System.out.println(sheet.getRow(sheet.getLastRowNum()).getLastCellNum());

        System.out.println(sheet.getRow(0).getCell(0).getStringCellValue());
        System.out.println(sheet.getRow(1).getCell(0).getStringCellValue());
        System.out.println(sheet.getRow(2).getCell(0).getStringCellValue());

        workbook.close();
        in.close();
    }
}