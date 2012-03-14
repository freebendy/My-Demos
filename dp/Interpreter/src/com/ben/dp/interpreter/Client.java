package com.ben.dp.interpreter;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Client {
	
	public static void main(String[] args) throws IOException {
		String expStr = getExpStr();
		
		HashMap<String, Integer> var = getValue(expStr);
		
		Calculator calc = new Calculator(expStr);
		System.out.print("The result is :" + expStr + "=" + calc.run(var));
		
	}
	
	public static String getExpStr() throws IOException {
		System.out.print("Please input the expression: ");
		return (new BufferedReader(new InputStreamReader(System.in))).readLine();
	}
	
	public static HashMap<String, Integer> getValue(String expStr) throws IOException {
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		
		for (char ch : expStr.toCharArray()) {
			if (ch != '+' && ch != '-') {
				if (!map.containsKey(String.valueOf(ch))) {
					System.out.print("Please input the value of " + ch + ":");
					String in = (new BufferedReader(new InputStreamReader(System.in))).readLine();
					map.put(String.valueOf(ch), Integer.valueOf(in));
				}
			}
		}
		
		return map;
	}
}
