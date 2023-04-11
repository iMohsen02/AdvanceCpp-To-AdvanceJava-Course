package org.example;

import org.apache.poi.xssf.usermodel.XSSFCell;
import org.apache.poi.xssf.usermodel.XSSFRow;
import org.apache.poi.xssf.usermodel.XSSFSheet;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class Test {
    public static void main(String[] args) throws IOException {
//        XSSFWorkbook workbook = new XSSFWorkbook();
//        XSSFSheet sheet = workbook.createSheet("first sheet");
//
//        XSSFRow row = sheet.createRow(0);
//        XSSFCell cell = row.createCell(1);
//
//        cell.setCellValue("Name");
//        sheet.createRow(1).createCell(1).setCellValue("Mohsen");
//
//        FileOutputStream out = new FileOutputStream("C:\\Users\\User\\Desktop\\MicrosoftExcel\\src\\main\\java\\org\\example\\class.xlsx");
//        workbook.write(out);
//        workbook.close();
//        out.close();

        FileInputStream in = new FileInputStream("C:\\Users\\User\\Desktop\\MicrosoftExcel\\src\\main\\java\\org\\example\\class.xlsx");
        XSSFWorkbook workbook = new XSSFWorkbook(in);

        XSSFSheet sheet = workbook.getSheet("first sheet");
        System.out.println(sheet.getLastRowNum());
        System.out.println(sheet.getRow(0).getCell(1).getStringCellValue());

        workbook.close();
    }
}
