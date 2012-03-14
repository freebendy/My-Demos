package com.ben.dp.interpreter;

import java.util.HashMap;

public class VarExpression implements Expression {
	
	private String mKey;
	
	public VarExpression(String key) {
		this.mKey = key;
	}

	@Override
	public int interpreter(HashMap<String, Integer> var) {
		System.out.println("interpreter: " + var.get(this.mKey));
		return var.get(this.mKey);
	}

}
