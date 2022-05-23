//Daniel Martinez, lab 6
//following the example we did in class but through java

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class bankers {
	public static void main(String[] args) throws IOException {
		Scanner user = new Scanner(System.in);
		
		int[] avail;
		
		
		int count = 0;
		int colcount = 0;
		boolean[] flag = new boolean[5];
		
		String[] files = {"required_resources.csv", "current_allocation.csv"};
		
		int[][] max = new int[5][3];
		int[][] allocation = new int[5][3];
		
		
		
		for(String file: files) {
			Scanner line = new Scanner(new FileReader(file));
			if(colcount == 0) {
				FileReader(max, line);
			}
			else{
				FileReader(allocation, line);
			}
			colcount++;
		}
		System.out.println(Arrays.deepToString(max) + " = Max resources");
		System.out.println(Arrays.deepToString(allocation) + " = Current Allocation");
		System.out.println();
		
		
		
		int[] max_instances =
		 Arrays.stream(new BufferedReader
		  ((new FileReader("max_instances.csv"))).readLine().split(",")).mapToInt(Integer::parseInt).toArray();
		
		System.out.println("Do you want to change the max instances that's given? (Currently 10, 5, 7) (y/n)");
		System.out.println();
		
		String userInput = user.nextLine();
		if(userInput.contains("y")){
			System.out.println("Enter three values that you want to be the instances!\n");
			String userInput2 = user.nextLine();
			
			int[] a = Arrays.stream(userInput2.split(",")).mapToInt(Integer::parseInt).toArray();
			avail = maxInstance(allocation, a);
		}
		else{
			avail = maxInstance(allocation, max_instances);
		}
		
		
	
		int failedSystem = 0;
		int[][] need = createNeed(max, allocation);
		while(containsF(flag)){
				for(int i = 0; i < 5; i++) {
					for(int j = 0; j < 3; j++) {
						if(!flag[i] && !allTrue(flag)) {
							int k = 0;
							if((need[i][j] <= avail[k]) &&
							   (need[i][j + 1] <= avail[k + 1]) &&
							   (need[i][j + 2] <= avail[k + 2])) {
								count =
								 getCount(avail, count, flag, allocation, i, j);
							} else {
								System.out.println("Process " + (i + 1) + " is waiting");
								failedSystem++;
								if(failedSystem > allocation.length){
									System.out.println("\nProgram is not safe!");
									System.out.println(Arrays.toString(avail));
									
									System.exit(0);
								}
								
								flag[i] = false;
								break;
							}
						}
					}
				}
				if(allTrue(flag)){
					
					break;
				}
				else{
					for(int i = 0; i < flag.length; i++){
							for(int j = 0; j < avail.length; j++) {
								if(flag[i]){
									break;
								}
								int k = 0;
								if((need[i][j] <= avail[k]) &&
								   (need[i][j] <= avail[k]) &&
								   (need[i][j] <= avail[k])) {
									count =
									 getCount(avail, count, flag, allocation, i, k);
									break;
								}
						}
					}
				}
		}
		System.out.println();
		if(failedSystem >= count){
			System.out.println("Program is not safe!");
			System.out.println(Arrays.toString(avail));
			
		}
		else{
			System.out.println("Program is safe!");
			System.out.println(Arrays.toString(avail));
			
		}
	}
	
	private static void FileReader(int[][] max, Scanner line) {
		for(int i = 0; i < 5; i++) {
			String test = line.next();
			for(int j = 0; j < 3; j++) {
				String[] test1 = test.split(",");
				max[i][0] = Integer.parseInt(test1[0]);
				max[i][1] = Integer.parseInt(test1[1]);
				max[i][2] = Integer.parseInt(test1[2]);
			}
		}
	}
	
	private static int getCount(int[] avail, int count, boolean[] flag,
								int[][] allocation, int i, int k) {
		System.out.println("Process " + (i + 1) + " is complete");
		count++;
		avail[k] += allocation[i][k];
		avail[k + 1] += allocation[i][k+1];
		avail[k + 2] += allocation[i][k+2];
		flag[i] = true;
		return count;
	}
	
	public static int[][] createNeed(int[][] max, int[][] allocation){
		int[][] need = new int[5][3];
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 3; j++){
				need[i][j] = max[i][j] - allocation[i][j];
			}
		}
		return need;
	}
	
	public static boolean allTrue(boolean[] test){
		int count = 0;
		for(boolean b: test) {
			if(b){
				count++;
			}
		}
		return count == test.length;
	}
	
	public static boolean containsF(boolean[] test){
		for(boolean b: test) {
			if(b){
				return false;
			}
		}
		return true;
	}
	
	public static int[] maxInstance(int[][] firstMatrix, int[] max) {
		int sum = 0;
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < 5; ++j) {
				sum = sum + firstMatrix[j][i];
			}
			max[i] -= sum;
			sum = 0;
		}
		return max;
	}
}
