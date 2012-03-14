package com.ben.dp.interpreter;

import java.util.HashMap;

public class AddExpression extends SymbolExpression {
	
	public AddExpression(Expression left, Expression right) {
		super(left, right);
	}

	@Override
	public int interpreter(HashMap<String, Integer> var) {
		System.out.println("interpreter: +");
		return super.mLeft.interpreter(var) + super.mRight.interpreter(var);
	}

}
