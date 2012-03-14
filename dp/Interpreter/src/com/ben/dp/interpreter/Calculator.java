package com.ben.dp.interpreter;

import java.util.HashMap;
import java.util.Stack;

public class Calculator {
	private Expression mExpression;
	
	public Calculator(String expStr) {
		//定义一个堆栈,安排运算的先后顺序
		Stack<Expression> stack = new Stack<Expression>();
		
		char[] charArray = expStr.toCharArray();
		
		Expression left = null;
		Expression right = null;
		
		for(int i = 0; i < charArray.length; ++i ) {
			
			switch(charArray[i]) {
				case '+':
					left = stack.pop();
					right = new VarExpression(String.valueOf(charArray[++i]));
					stack.push(new AddExpression(left, right));
					break;
				case '-':
					left = stack.pop();
					right = new VarExpression(String.valueOf(charArray[++i]));
					stack.push(new SubExpression(left, right));
					break;
				default:
					stack.push(new VarExpression(String.valueOf(charArray[i])));
					
			}
		}
		
		this.mExpression = stack.pop();
		System.out.println("this.mExpression: " + this.mExpression);
	}
	
	public int run(HashMap<String,Integer> var) {
		return this.mExpression.interpreter(var);
	}
}
