#include "circuitCNF.h"
#include <sstream>
#include <algorithm>

//create a constructor
circuitCNF::circuitCNF() : variableCounter(0) {}

int circuitCNF::getVariable(const std::string& name) {
	if (variableList.find(name) == variableList.end()) {
		variableCounter++;
		variableList[name] = variableCounter;
	}
	return variableList[name];
}

void circuitCNF::addClause(const Clause& clause) {
	clauses.push_back(clause);
}

//Note gate
void circuitCNF::addNOTGate(const std::string& input, const std::string& output) {
	int in = getVariable(input);
	int out = getVariable(output);

	addClause({ -in, -out });
	addClause({ in, out });
}

//And gate
void circuitCNF::addANDGate(const std::vector<std::string>& inputs, const std::string& output) {
	std::vector<int> inputVariables;
	for (const auto& i : inputs) {
		inputVariables.push_back(getVariable(i));
	}
	int out = getVariable(output);

	Clause clauseAND;
	for (int j : inputVariables) {
		clauseAND.push_back(-j);
	}
	clauseAND.push_back(out);
	addClause(clauseAND);

	for (int j : inputVariables) {
		addClause({ j, -out });
	}
}

//OR gate
void circuitCNF::addORGate(const std::vector<std::string>& inputs, const std::string& output) {
	std::vector<int> inputVariables;
	for (const auto& i : inputs) {
		inputVariables.push_back(getVariable(i));
	}
	int out = getVariable(output);

	Clause clauseOR;
	for (int j : inputVariables) {
		clauseOR.push_back(j);
	}
	clauseOR.push_back(-out);
	addClause(clauseOR);

	for (int j : inputVariables) {
		addClause({ -j, out });
	}
}

//NAND gate
void circuitCNF::addNANDGate(const std::vector<std::string>& inputs, const std::string& output) {
	std::vector<int> inputVariables;
	for (const auto& i : inputs) {
		inputVariables.push_back(getVariable(i));
	}
	int out = getVariable(output);

	for (int j : inputVariables) {
		addClause({ j, -out });
	}

	Clause clauseNAND;
	for (int j : inputVariables) {
		clauseNAND.push_back(-j);
	}
	clauseNAND.push_back(out);
	addClause(clauseNAND);
}

//NOR gate
void circuitCNF::addNORGate(const std::vector<std::string>& inputs, const std::string& output) {
	std::vector<int> inputVariables;
	for (const auto& i : inputs) {
		inputVariables.push_back(getVariable(i));
	}
	int out = getVariable(output);

	for (int j : inputVariables) {
		addClause({ -j, -out });
	}

	Clause clauseNOR;
	for (int j : inputVariables) {
		clauseNOR.push_back(j);
	}
	clauseNOR.push_back(out);
	addClause(clauseNOR);
}

//XOR GATE
void circuitCNF::addXORGate(const std::string& input1, const std::string& input2, const std::string& output) {
	int in1 = getVariable(input1);
	int in2 = getVariable(input2);
	int out = getVariable(output);
	addClause({ -in1, -in2, -out });
	addClause({ in1, in2, -out });
	addClause({ in1, -in2, out });
	addClause({ -in1, in2, out });
}
//test circuit -> essentially want original to not equal the new circuit
void circuitCNF::addTest(const std::string& output1, const std::string& output2) {
	int out1 = getVariable(output1);
	int out2 = getVariable(output2);
	addClause({ out1, out2 });
	addClause({ -out1, -out2 });
}

//total variabls
int circuitCNF::getVariableCount() const {
	return variableCounter;
}

//total clauses
int circuitCNF::getClause() const {
	return clauses.size();
}
//total variable list
const std::map<std::string, int>& circuitCNF::getVariableList() const {
	return variableList;
}

//convert to DIMACS -> finish this
std::string circuitCNF::dimacsFormat() const {
	std::ostringstream oss;
	oss << "p cnf " << variableCounter << " " << clauses.size() << std::endl;
	for (const auto& Clause : clauses) {
		for (int literal : Clause) {
			oss << literal << " ";
		}
		oss << "0\n";
	}
	return oss.str();
}

std::string circuitCNF::propositionalFormat() const {
	std::map<int, std::string> reverseVariableList;
	for (const auto& i : variableList) {
		reverseVariableList[i.second] = i.first;
	}
	std::ostringstream oss;
	bool first = true;

	for (const auto& Clause : clauses) {
		if (!first) {
			oss << " & ";
		}
		first = false;
		oss << "(";
		bool firstLiteral = true;
		for (int literal : Clause) {
			if (!firstLiteral) {
				oss << " | ";
			}
			firstLiteral = false;
			int variableNumber = abs(literal);
			std::string variableName = reverseVariableList[variableNumber];
			std::replace(variableName.begin(), variableName.end(), '_', 'p');
			std::transform(variableName.begin(), variableName.end(), variableName.begin(), ::tolower);
			if (literal < 0) {
				oss << "~";
			}
			oss << variableName;
		}
		oss << ")";
	}
	return oss.str();
}

void circuitCNF::addDIPConstraint(bool a, bool b, bool c, bool d, bool expectedOutput) {
	//adds new constraint per DIP iteration
	Clause constraint;
	if (a) { constraint.push_back(-getVariable("A")); }
	else { constraint.push_back(getVariable("A")); }

	if (b) { constraint.push_back(-getVariable("B")); }
	else { constraint.push_back(getVariable("B")); }

	if (c) { constraint.push_back(-getVariable("C")); }
	else { constraint.push_back(getVariable("C")); }

	if (d) { constraint.push_back(-getVariable("D")); }
	else { constraint.push_back(getVariable("D")); }

	if (expectedOutput) {
		constraint.push_back(getVariable("w26"));
	}
	else {
		constraint.push_back(-getVariable("w26"));
	}
	addClause(constraint);
}
