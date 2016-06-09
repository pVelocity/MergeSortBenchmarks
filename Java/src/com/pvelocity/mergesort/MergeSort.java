package com.pvelocity.mergesort;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class MergeSort
{
	
	private static Integer[] temp = null;

	private static void mergeSort(Integer[] arr, int low, int mid, int high)
	{
	    int i = low;
	    int m = mid + 1;
	    int l = low;

	    while ((l <= mid) && (m <= high)) {

	        if (arr[l] <= arr[m]) {
	        	temp[i]= arr[l];
	            l++;
	        } else {
	        	temp[i]= arr[m];
	            m++;
	        }
	        i++;
	    }

	    if (l > mid) {
		    System.arraycopy(arr, m, temp, i, high - m + 1);
	    } else {
		    System.arraycopy(arr, l, temp, i, mid - l + 1);
	    }
	    
	    System.arraycopy(temp, low, arr, low, high - low + 1);
	}
	
	private static void partition (Integer[] arr, int low, int high) {
	    int mid;
	    if (low < high) {
	        mid = (low + high) / 2;
	        partition(arr, low, mid);
	        partition(arr, mid + 1, high);
	        mergeSort(arr, low, mid, high);
	    }
	}

	public static void main(String[] args) throws IOException
	{
		
		ArrayList<Integer> arr = new ArrayList<Integer>(10000);
		
		File f = new File(".." + File.separator + "TestData.txt");
		FileReader rd = new FileReader(f);
		BufferedReader brd = new BufferedReader(rd);
		String line = null;
		while ((line = brd.readLine()) != null) {
			line = line.trim();
			if (line.length() > 0) {
				arr.add(Integer.parseInt(line.trim()));
			}
		}
		brd.close();
		
		temp = arr.toArray(new Integer[0]);
		Integer[] results = arr.toArray(new Integer[0]);
		
		long start = System.currentTimeMillis();
		partition(results, 0, arr.size() - 1);
		long end = System.currentTimeMillis();
		
		for (Integer integer : results)
		{
			System.out.println(integer.toString());
		}
		System.out.printf("Elapsed time: %.6f (secs)\n", (end - start) / 1000.0);
	
	}

}
