/*
* Adam Prieto
* Professor Ranjidha Rajan
* CS 3600 - Operating Systems
* 8 May 2022
* Programming Project 2
*
* @Description: Write a java file to read a "c source code file" to find the
*               total number of comments. Assume comments use the "//"
*
* @notes: If a problem occurs at run time, there's probably a problem with the
*         path name. Update said line with the correct path and everything
*         should work fine.
* */

import java.io.*;
import java.util.Scanner;


public class PP2
{
    public static void main(String args[]) throws IOException
    {

        // Create variables
        String path = "/Users/adamprieto/Education/MSU Denver/CS 3600/shmDemo2.c"; // Change line when dealing with other files.
        Scanner inputFile = new Scanner(new File(path));
        String fileLine;
        int totalLines = 0;
        int totalComments = 0;

        // Process file contents
        System.out.println("Begin Processing File");
        while(inputFile.hasNext())
        {
            totalLines++;
            fileLine = inputFile.nextLine();
            if (fileLine.contains("//"))
            {
                totalComments++;
                System.out.println("Line " + totalLines + " has a comment.");
            } // End if
        } // End while

        if(totalComments == 1)
            System.out.println(totalComments + " comment was found.");
        else
            System.out.println(totalComments + " comments were found.");

        inputFile.close();
        System.out.println("File Closed Ending Program");
    } // End main
} // End PP2
