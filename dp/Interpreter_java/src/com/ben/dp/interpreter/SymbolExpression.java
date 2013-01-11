package com.ben.dp.interpreter;

public abstract class SymbolExpression implements Expression {
	
	protected Expression mLeft;
	protected Expression mRight;
	
	//所有的解析公式都应该只关心自己左右两个表达式的结果
	public SymbolExpression(Expression left, Expression right) {
		this.mLeft = left;
		this.mRight = right;
	}

}
