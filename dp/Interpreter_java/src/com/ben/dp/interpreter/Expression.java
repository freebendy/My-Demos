package com.ben.dp.interpreter;

import java.util.HashMap;

public interface Expression {
	//解析公式和数值，其中var中的key是公式中的参数，value值是具体的数字
	public abstract int interpreter(HashMap<String, Integer> var);
}
