#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <algorithm>
using namespace std;


vector<string> cut(string equation)
{
	vector<string> term;
	int count = 0;
	int count_end = 0;
	string term_temp;
	bool var_found = false;
	for (int i = 0; i < equation.length(); i++)
	{
		if ((equation[i] >= 97 && equation[i] <= 123) || (equation[i] >= 65 && equation[i] <= 88))
		{
			var_found = true;
		}
		if ((equation[i] == '+' || equation[i] == '-' || equation[i] == '=') && var_found == false&& i==0)
		{
			count = i;
		}
		if ((equation[i] == '+' || equation[i] == '-' || equation[i] == '=') && var_found == false && i != 0)
		{
			term_temp = equation.substr(count, i - count);
			term.push_back(term_temp);
			term_temp = "";
			count = i;

		}
		else if ((equation[i] == '+' || equation[i] == '-' || equation[i] == '=') && var_found == true)
		{
			term_temp = equation.substr(count, i - count);
			var_found = false;
			term.push_back(term_temp);
			term_temp = "";
			count = i;
		}
		if (equation[i] == '=')
		{
			count_end = i;
			term_temp = equation.substr(count_end, equation.length() - count_end);
			term.push_back(term_temp);
			term_temp = "";
			break;

		}
	}
	return term;
}
void classify(vector<string> term , vector<string> &vars, vector<string> &coff)
{
	string temp;
	for (int i = 0; i < term.size(); i++)
	{
		temp = term[i];
		for (int j = 0; j < temp.length(); j++)
		{
			if ((temp[j] >= 97 && temp[j] <= 123) || (temp[j] >= 65 && temp[j] <= 88)|| temp[j]=='_')
			{
				vars.push_back(temp.substr(j, temp.length() - j));
				coff.push_back(temp.substr(0, j));
				break;
			}
			if (temp[j] == '=')
			{
				coff.push_back(temp);
				break;
			}
		}
	}
}
string order(string temp_equ)
{
	string equation="+";
	if (temp_equ[0] != '-' &&temp_equ[0] != '+')
	{
		equation += temp_equ;
	}
	else
	{
		equation = temp_equ;
	}
	
	vector<string> term;
	term = cut(equation);
	vector<string> vars;
	vector<string> temp_coff;
	classify(term, vars, temp_coff);

	vector<string> temp_vars;
	for (int i = 0; i < vars.size(); i++)
	{
		temp_vars.push_back(vars[i]);
	}
	vector<string> coff;
	sort(vars.begin(), vars.end());
	string variable;

	for (int i = 0; i < vars.size(); i++)
	{
		variable = vars[i];
		for (int j = 0; j < temp_vars.size(); j++)
		{
			if (variable == temp_vars[j])
			{
				coff.push_back(temp_coff[j]);
				temp_vars[j] += "d";
				break;
			}
		}
	}
	coff.push_back(temp_coff[temp_coff.size() - 1]);
	vars.push_back("");


	string out;
	for (int i = 0; i < coff.size(); i++)
	{
		out += coff[i] + vars[i];
	}
	
	return out;
}

bool comp_loop(vector<string> compare, string comp_var)
{

	for (int k = 0; k < compare.size(); k++)
	{
		if (compare[k] == comp_var)
			return true;
	}
	return false;
}

int num_vars(vector<string> inp)
{
	vector<string> compare;
	string equation;
	int count = 0;
	string comp_var;
	bool var = false;
	for (int i = 0; i < inp.size(); i++)
	{
		equation = inp[i];
		if (equation[0] == '-' || equation[0] == '+') equation[0] = ' ';

		for (int j = 0; j < equation.size(); j++)
		{
			if (((equation[j] >= 97 && equation[j] <= 123) || (equation[j] >= 65 && equation[j] <= 88))&&(var == false))
			{
				count = j;
				var = true;
			}
			else if (equation[j] == '+' || equation[j] == '=' || equation[j] == '-')
			{
				comp_var = equation.substr(count, j - count);
				var = false;
				if (comp_loop(compare, comp_var) == false)
				{
					compare.push_back(comp_var);
				}
				if (equation[j] == '=')
				{
					break;
				}
			}
		}
	}
	return compare.size();
}

vector<string> get_vars(vector<string> inp)
{
	vector<string> compare;
	string equation;
	int count = 0;
	string comp_var;
	bool var = false;
	for (int i = 0; i < inp.size(); i++)
	{
		equation = inp[i];
		if (equation[0] == '-' || equation[0] == '+') equation[0] = ' ';


		for (int j = 0; j < equation.size(); j++)
		{
			if (((equation[j] >= 97 && equation[j] <= 123) || (equation[j] >= 65 && equation[j] <= 88)) && (var == false))
			{
				count = j;
				var = true;
			}
			else if (equation[j] == '+' || equation[j] == '=' || equation[j] == '-')
			{
				comp_var = equation.substr(count, j - count);
				var = false;
				if (comp_loop(compare, comp_var) == false)
				{
					compare.push_back(comp_var);
				}
				if (equation[j] == '=')
				{
					break;
				}
			}
		}
	}
	sort(compare.begin(),compare.end());

	return compare;
}

string fto_string(float f)
{
	string s;
	ostringstream ss;
	ss << f;
	s = ss.str();
	return s;
}

string cancel_repeat(string temp_equation)
{
	string equation;
	equation = order(temp_equation);
	vector<string> term;
	term = cut(equation);

	vector<string> vars;
	vector<string> coff;
	classify(term, vars, coff);

	string temp_var;
	float temp_sum;
	vector<string> final_vars;
	vector<string> final_coff;
	int j = 0;
	int index = 0;
	for (int i = 0; i < vars.size(); i++)
	{
		if (index + 1 > vars.size())
		{
			break;
		}
		temp_var = vars[index];
		temp_sum = atof(coff[index].c_str());

		for ( j = index + 1; j < vars.size(); j++)
		{
			if (temp_var == vars[j])
			{
				temp_sum += atof(coff[j].c_str());
			}
			else
				break;
		}
		index = j;
		final_vars.push_back(temp_var);
		if (temp_sum >= 0)
		{

			final_coff.push_back("+"+fto_string(temp_sum));
		}
		else
		{
			final_coff.push_back(fto_string(temp_sum));
		}
	}
	final_coff.push_back(coff[coff.size() - 1]);
	final_vars.push_back("");

	vector<string> output;
	for (int i = 0; i < final_vars.size(); i++)
	{
		output.push_back(final_coff[i] + final_vars[i]);
	}

	

	string o;
	for (int i = 0; i < output.size(); i++)
	{
		o += output[i];
	}

	return o;
}

string const_coff(string equation)
{
	if (equation[0] != '-' &&equation[0] != '+')
	{
		equation = "+" + equation;
	}
	vector<string> term;
	vector<string> temp_term;
	temp_term = cut(equation);
	string x,temp,sign;
	for (int i = 0; i < temp_term.size(); i++)
	{
		x = temp_term[i];
		if ((x[1] >= 97 && x[1] <= 123) || (x[1] >= 65 && x[1] <= 88))
		{
			sign = x[0];
			for (int j = 1; j < x.size(); j++)
			{
				temp += x[j];
			}
			x = sign + "1" + temp;
			term.push_back(x);
			temp = "";
		}
		else
			term.push_back(x);
	}

	string out;
	for (int i = 0; i < term.size(); i++)
	{
		out += term[i];
	}
	return out;
}

void seperate_sides(string equation, vector<string> &rhs, vector<string> &lhs)
{
	if (equation[0] != '-'&& equation[0] != '+')
	{
		equation = "+" + equation;
	}


	string right_hs, left_hs;
	for (int i = 0; i < equation.length(); i++)
	{
		if (equation[i] == '=')
		{
			right_hs = equation.substr(0, i);
			left_hs = equation.substr(i + 1, equation.length() - i - 1);
			if (left_hs[0] != '-' && left_hs[0] != '+')
			{
				left_hs = "+" + left_hs;
			}
			break;
		}
	}
	right_hs += "+";
	left_hs += "+";

	rhs = cut(right_hs);
	lhs = cut(left_hs);

}

bool var_found(string term)
{
	for (int i = 0; i < term.size(); i++)
	{
		if ((term[i] >= 97 && term[i] <= 123) || (term[i] >= 65 && term[i] <= 88))
		{
			return true;
		}
	}
	return false;
}


string one_side(string equation)
{
	vector<string> rhs;
	vector<string> lhs;
	seperate_sides(equation, rhs, lhs);
	string temp;
	vector<string> final_rhs;
	vector<string> final_lhs;

	for (int i = 0; i < lhs.size(); i++)
	{
		temp = lhs[i];
		if (var_found(temp) == true)
		{
			if (temp[0] == '-') temp[0] = '+';
			else if (temp[0] == '+') temp[0] = '-';
			rhs.push_back(temp);
			lhs[i] = "";

			/*for (int j = 0; j < lhs.size(); j++)
			{
				if (j == i)
				{
					continue;
				}
				else
				{
					final_lhs.push_back(lhs[j]);
				}
			}*/

		}


	}

	temp = "";

	for (int i = 0; i < rhs.size(); i++)
	{
		temp = rhs[i];
		if (var_found(temp) == false)
		{
			if (temp[0] == '-') temp[0] = '+';
			else if (temp[0] == '+') temp[0] = '-';
			lhs.push_back(temp);
			rhs[i] = "";

			/*for (int j = 0; j < rhs.size(); j++)
			{
				if (j == i)
				{
					continue;
				}
				else
				{
					final_rhs.push_back(rhs[j]);
				}
			}*/

		}

	}

	float summation=0;
	for (int i = 0; i < lhs.size(); i++)
	{
		summation += atof(lhs[i].c_str());
	}
	string lhs_finish = fto_string(summation);

	string out;
	for (int i = 0; i < rhs.size(); i++)
	{
		out += rhs[i];
	}
	out += "=" + lhs_finish;

	return out;
}


vector<string> proper(vector<string> input)
{
	string equation;
	vector<string> proper_input;
	for (int i = 0; i < input.size(); i++)
	{
		equation = input[i];
		proper_input.push_back(cancel_repeat(const_coff(one_side(equation))));
	}
	return proper_input;
}

float coff_of_var(vector<string> term, string var)
{
	vector<string> vars;
	vector<string> coff;
	classify(term, vars, coff);

	float var_coff = 0;

	for (int i = 0; i < vars.size(); i++)
	{
		if (vars[i] == var)
		{
			var_coff += atof(coff[i].c_str());
		}
	}
	return var_coff;
}


vector<float> get_column(vector<string> input, string var)
{
	string equation;
	vector<string> term;
	vector<float> column;

	for (int i = 0; i < input.size(); i++)
	{
		equation = input[i];
		term = cut(equation);
		
		column.push_back(coff_of_var(term, var));
	}
	return column;
}

string collect_side(vector<string>side)
{
	string out;
	for (int i = 0; i < side.size(); i++)
	{
		out += side[i];
	}
	return out;
}


string add_equ(vector <string> input, int e1, int e2)
{
	string final_equ;
	string equ1 = input[e1 - 1];
	string equ2 = input[e2 - 1];
	vector <string> equ1_rhs;
	vector <string> equ1_lhs;
	vector <string> equ2_rhs;
	vector <string> equ2_lhs;

	seperate_sides(equ1, equ1_rhs, equ1_lhs);
	seperate_sides(equ2, equ2_rhs, equ2_lhs);

	string e1_rhs = collect_side(equ1_rhs);
	string e1_lhs = collect_side(equ1_lhs);
	string e2_rhs = collect_side(equ2_rhs);
	string e2_lhs = collect_side(equ2_lhs);

	string temp_equ = e1_rhs + e2_rhs + "=" + e1_lhs + e2_lhs;

	final_equ = cancel_repeat(const_coff(one_side(temp_equ)));

	return final_equ;
}

string switch_sign(string equ)
{
	vector <string> rhs;
	vector <string> lhs;
	vector <string> neg_rhs;
	vector <string> neg_lhs;

	string x,y;

	seperate_sides(equ, rhs, lhs);

	for (int i = 0; i < rhs.size(); i++)///////////////switch sign rhs
	{
		x = rhs[i];
		if (x[0] == '+') x[0] = '-';
		else if (x[0] == '-') x[0] = '+';
		else x = "-" + x;

		neg_rhs.push_back(x);
	}
	for (int i = 0; i < lhs.size(); i++)/////////////switch sign lhs
	{
		y = lhs[i];
		if (y[0] == '+') y[0] = '-';
		else if (y[0] == '-') y[0] = '+';
		else y = "-" + y;

		neg_lhs.push_back(y);
	}


	string f_rhs = "";
	string f_lhs = "";
	for (int i = 0; i < neg_rhs.size(); i++)//////////collect rhs into var
	{
		f_rhs += neg_rhs[i];
	}

	for (int i = 0; i < neg_lhs.size(); i++)//////////collect lhs into var
	{
		f_lhs += neg_lhs[i];
	}

	string out = f_rhs + "=" + f_lhs;
	return out;
}

string neg_sign(string equ)
{
	vector<string> rhs;
	equ += "+";
	rhs = cut(equ);
	vector<string> neg_rhs;
	string x;

	for (int i = 0; i < rhs.size(); i++)///////////////switch sign rhs
	{
		x = rhs[i];
		if (x[0] == '+') x[0] = '-';
		else if (x[0] == '-') x[0] = '+';
		else x = "-" + x;

		neg_rhs.push_back(x);
	}
	string f_rhs = "";
	for (int i = 0; i < neg_rhs.size(); i++)//////////collect lhs into var
	{
		f_rhs += neg_rhs[i];
	}
	return f_rhs;

}

string sub_equ(vector <string> input, int e1, int e2)
{
	string final_equ;
	string equ1 = input[e1 - 1];
	string equ2 = input[e2 - 1];

	string neg_equ2 = switch_sign(equ2);

	vector <string> equ1_rhs;
	vector <string> equ1_lhs;
	vector <string> equ2_rhs;
	vector <string> equ2_lhs;

	seperate_sides(equ1, equ1_rhs, equ1_lhs);
	seperate_sides(neg_equ2, equ2_rhs, equ2_lhs);

	string e1_rhs = collect_side(equ1_rhs);
	string e1_lhs = collect_side(equ1_lhs);
	string e2_rhs = collect_side(equ2_rhs);
	string e2_lhs = collect_side(equ2_lhs);



	string temp_equ = e1_rhs + e2_rhs + "=" + e1_lhs + e2_lhs;

	final_equ = cancel_repeat(const_coff(one_side(temp_equ)));

	return final_equ;
}

string substitute(string var, string equ2, string equ1)
{
	vector<string> equ1_terms;
	equ1_terms = cut(equ1);

	string temp_var;
	float coff=1, coff2=1; int index_j;
	//1st eq.
	for (int i = 0; i < equ1_terms.size(); i++)
	{
		for (int j = 0; j < equ1_terms[i].length(); j++)
		{
			if ((equ1_terms[i][j] >= '1' &&equ1_terms[i][j] <= '9') || equ1_terms[i][j] == '+' || equ1_terms[i][j] == '-')
			{
				continue;
			}
			else
			{
				temp_var = equ1_terms[i].substr(j);
				index_j = j;
				break;
			}
		}
		if (temp_var == var)
		{
			coff = atof(equ1_terms[i].substr(0, index_j).c_str());
			equ1_terms[i] = "";
		}
		else
		{
			if (equ1_terms[i][0] == '=')
			{
				equ1_terms[i] = equ1_terms[i].substr(1);
			}
			else
			equ1_terms[i] = neg_sign(equ1_terms[i]);
		}
	}
	// 2nd eq.
	vector<string> equ2_terms;
	equ2_terms = cut(equ2);
	int index_2ndvar;
	string temp_var2;
	for (int i = 0; i < equ2_terms.size() - 1; i++)
	{
		for (int j = 0; j < equ2_terms[i].length(); j++)
		{
			if ((equ2_terms[i][j] >= '1' &&equ2_terms[i][j] <= '9') || equ2_terms[i][j] == '+' || equ2_terms[i][j] == '-')
			{
				continue;
			}
			else
			{
				temp_var2 = equ2_terms[i].substr(j);
				index_j = j;
				break;
			}
		}
		if (temp_var2 == var)
		{
			index_2ndvar = i;
			coff2 = atof(equ2_terms[i].substr(0, index_j).c_str());
			equ2_terms[i] = "";
		}
	}



	// dividing & mult by the coeffecient
	for (int i = equ1_terms.size() - 1; i > 0; i--)
	{
		for (int j = 0; j < equ1_terms[i].size(); j++)
		{
			if ((equ1_terms[i][j] >= 'a'&&equ1_terms[i][j] <= 'z') || (equ1_terms[i][j] >= 'A' && equ1_terms[i][j] <= 'Z'))
			{
				string first = fto_string((atof(equ1_terms[i].substr(0, j).c_str()) / coff)*coff2);
				string second = equ1_terms[i].substr(j);
				equ1_terms[i] = first + second;
				break;
			}
			if (!var_found(equ1_terms[i]))
			{
				equ1_terms[i] = fto_string((atof(equ1_terms[i].c_str()) / coff)*coff2);
				break;
			}
		}
	}
	//getting the whole value
	string var_value = "";
	for (int i = equ1_terms.size() - 1; i > 0; i--)
	{
		var_value += equ1_terms[i];
	}
	//substitution in the vector
	equ2_terms[index_2ndvar] = var_value;
	string finalEq = "";
	for (int i = 0; i < equ2_terms.size(); i++)
	{
		finalEq += equ2_terms[i];
	}
	return cancel_repeat(const_coff(one_side(finalEq)));
}

vector<vector<float>> cramers_matrix(vector<string> inp)
{
	////matrix without factor
	////////////////////////////////////////////////////////////////////////
	vector<string> vars = get_vars(inp);

	vector<vector<float>> matrix;
	vector<vector<float>> final_matrix;
	vector<float> row;
	vector<float> empty;

	for (int i = 0; i < vars.size(); i++)
	{
		row = get_column(inp, vars[i]);
		matrix.push_back(row);
	}

	///////////transpose

	for (int i = 0; i < matrix[0].size(); i++)
	{
		final_matrix.push_back(empty);

		for (int j = 0; j < matrix.size(); j++)
		{
			final_matrix[i].push_back(matrix.at(j).at(i));
		}
	}
	////////////////////////////////////////////////////////
	return final_matrix;
}

string del_plus(string equ)
{
	string out = "";
	for (int i = 1; i < equ.size(); i++)
	{
		out += equ[i];
	}
	return out;
}
int get_varIndex(vector<string> vars, string var)
{
	for (int i = 0; i < vars.size(); i++)
	{
		if (vars[i] == var) return i;
	}
}

vector<float> get_factors(vector<string> inp)
{
	vector<float> factors;
	string equ;
	for (int i = 0; i < inp.size(); i++)
	{
		equ = inp[i];
		int index = equ.find('=');
		float fac = atof(equ.substr(index + 1).c_str());
		factors.push_back(fac);
	}
	return factors;
}

vector<vector<float>> cramers_matrix_of_var(vector<string> inp , string var)
{
	vector<string> vars = get_vars(inp);

	vector<vector<float>> matrix;
	vector<vector<float>> final_matrix;
	vector<float> row;
	vector<float> empty;


	int index = get_varIndex(vars, var);

	for (int i = 0; i < vars.size(); i++)
	{
		if (i == index)
		{
			row = get_factors(inp);
			matrix.push_back(row);
		}
		else
		{
			row = get_column(inp, vars[i]);
			matrix.push_back(row);
		}
	}

	/////////transpose
	for (int i = 0; i < matrix[0].size(); i++)
	{
		final_matrix.push_back(empty);

		for (int j = 0; j < matrix.size(); j++)
		{
			final_matrix[i].push_back(matrix.at(j).at(i));
		}
	}
	////////////////////////////////////////////////////////
	return final_matrix;
}
vector < vector<float>> remove_column(vector<vector<float>> det,int col_index)
{	
	det.erase(det.begin());
	for (int i = 0; i < det.size(); i++){
		det[i].erase(det[i].begin() + col_index);
	}
	return det;
}
float solveDet(vector<vector<float>> det)
{
	//Base case
	if (det.size() == 2)
	{
		return det.at(0).at(0)*det.at(1).at(1) - det.at(0).at(1)*det.at(1).at(0);
	}
	//recursive part
	float res = 0;
	int sign = 1;
	for (int i = 0; i < det.size(); i++)
	{
		sign = (i % 2 == 0) ? 1 : -1;
		res += sign * det.at(0).at(i)*solveDet(remove_column(det, i));
	}
	return res;
}

vector<string> solve_equs(vector<string> inp)
{
	vector<vector<float>> D = cramers_matrix(inp);
	float delta = solveDet(D);
	vector<string>soluns;

	vector<string> vars = get_vars(inp);
	for (int i = 0; i < vars.size(); i++)
	{
		vector<vector<float>> D_var = cramers_matrix_of_var(inp,vars[i]);
		float delta_var = solveDet(D_var);
		soluns.push_back(vars[i]+"="+fto_string(delta_var / delta));
	}
	return soluns;
}


string add(vector<string> inp , int eq1_index, int eq2_index)
{
	vector<float> factors = get_factors(inp);
	vector<string> vars = get_vars(inp);

	vector<vector<float>> det = cramers_matrix(inp);

	vector<float> equation1 = det[eq1_index];
	vector<float> equation2 = det[eq2_index];

	vector<float> out_equ;
	for (int i = 0; i < equation1.size(); i++)
	{
		out_equ.push_back(equation1[i] + equation2[i]);
	}

	string final_equation = "";
	for (int i = 0; i < out_equ.size(); i++)
	{
		if (out_equ[i]>=0)
		{
			final_equation =final_equation+ "+" + fto_string(out_equ[i]) + vars[i];
		}
		else
		{
			final_equation = final_equation + fto_string(out_equ[i]) + vars[i];
		}
	}

	float final_factor = factors[eq1_index] + factors[eq2_index];
	final_equation = final_equation + "=" + fto_string(final_factor);
	if (final_equation[0] == '+')
	{
		final_equation = del_plus(final_equation);
	}

	return final_equation;
}

string subtract(vector<string> inp, int eq1_index, int eq2_index)
{
	vector<float> factors = get_factors(inp);
	vector<string> vars = get_vars(inp);

	vector<vector<float>> det = cramers_matrix(inp);

	vector<float> equation1 = det[eq1_index];
	vector<float> equation2 = det[eq2_index];

	vector<float> out_equ;
	for (int i = 0; i < equation1.size(); i++)
	{
		out_equ.push_back(equation1[i] - equation2[i]);
	}

	string final_equation = "";
	for (int i = 0; i < out_equ.size(); i++)
	{
		if (out_equ[i]>=0)
		{
			final_equation = final_equation + "+" + fto_string(out_equ[i]) + vars[i];
		}
		else
		{
			final_equation = final_equation + fto_string(out_equ[i]) + vars[i];
		}
	}

	float final_factor = factors[eq1_index] - factors[eq2_index];
	final_equation = final_equation + "=" + fto_string(final_factor);

	if (final_equation[0] == '+')
	{
		final_equation = del_plus(final_equation);
	}

	return final_equation;
}

vector<vector<float>> get_equations_det(vector<string> inp)
{
	////////////////////////////////////////////////////////////////////////
	vector<string> vars = get_vars(inp);

	vector<vector<float>> matrix;
	vector<vector<float>> final_matrix;
	vector<float> fac = get_factors(inp);
	vector<float> row;
	vector<float> empty;

	for (int i = 0; i < vars.size(); i++)
	{
		row = get_column(inp, vars[i]);
		matrix.push_back(row);
	}
	matrix.push_back(fac);

	///////////transpose

	for (int i = 0; i < matrix[0].size(); i++)
	{
		final_matrix.push_back(empty);

		for (int j = 0; j < matrix.size(); j++)
		{
			final_matrix[i].push_back(matrix.at(j).at(i));
		}
	}
	////////////////////////////////////////////////////////
	return final_matrix;
}

string exchange(vector<string> inp, string var, int equ1_index, int equ2_index)
{
	vector<vector<float>> coff_det = cramers_matrix(inp);
	vector<float> fac = get_factors(inp);
	vector<string> vars = get_vars(inp);
	int index = get_varIndex(vars,var);

	

	vector<float> equation1=coff_det[equ1_index];
	vector<float> equation2 = coff_det[equ2_index];

	vector<string> final_equ;
	int coff1, coff2;

	////////////////get the coffs
	coff1 = equation1[index];
	coff2 = equation2[index];
	string factor = fto_string((fac[equ2_index]*coff1) - (fac[equ1_index]*coff2));
	////
	//////////////multiply coffs
	for (int i = 0; i < equation1.size(); i++)
	{
		if (i == index)
		{
			equation1[i] = 0;
		}
		else
		{
			equation1[i] *= -1 * coff2;
		}
	}
	for (int i = 0; i < equation2.size(); i++)
	{
		if (i == index)
		{
			equation2[i] = 0;
		}
		else
		{
			equation2[i] *=  coff1;
		}
	}
	////
	////////////////collect
	string out = "";
	for (int j = 0; j < vars.size(); j++)
	{
		if (j == index)
		{
			string x = "";
		}
		else
		{
			if (equation1[j] + equation2[j] >= 0)
			{
				out+="+"+fto_string(equation1[j] + equation2[j]) + vars[j];
			}
			else
			{
				out+=fto_string(equation1[j] + equation2[j]) + vars[j];
			}
		}
	}

	out += "=" + factor;
	////////

	return out;
}

string zero_coff(string equation)
{
	vector<string> terms = cut(equation);
	string collect = "";
	string o = "";
	for (int i = 0; i < terms.size(); i++)
	{
		collect = "";
		string temp = terms[i];
		for (int j = 0; j < temp.size(); j++)
		{
			if ((temp[j] >= '0'&& temp[j] <= '9') || temp[j] == '+' || temp[j] == '-')
			{
				collect += temp[j];
			}
			else if (temp[j] == '=')
			{
				collect += "1";
				break;
			}
			else
			{
				break;
			}
		}

		if (atof(collect.c_str()) == 0)
		{
			terms[i] = "";
		}
		o += terms[i];
	}

	return o;
}


int main()
{


	////////////input
	int n; string line; string y;
	cin >> n;
	vector<string> input;
	for (int i = 0; i < n; i++)
	{
		cin >> ws;
		getline(cin, line);
	    y = zero_coff(cancel_repeat(const_coff(one_side(line)))); ///////////to be proper before entering vector
		if (y[0] == '+') y = del_plus(y);
		input.push_back(y);
	}
////////////////////////////////to print the matrix
	/*vector<vector<float>> mat = cramers_matrix(input);
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[i].size(); j++)
		{
			cout << mat.at(i).at(j) << " ";
		}
		cout << endl;
	}*/
	//////////////////////////////////
	////////////////operation
	string operation;
	getline(cin, operation);

	while (true)
	{
		if (operation == "quit")
		{
			break;
		}
		else if (operation == "num_vars")
		{
			cout << num_vars(input);
		}
		else if (operation == "D")
		{
			vector<vector<float>> mat = cramers_matrix(input);
			for (int i = 0; i < mat.size(); i++)
			{
			for (int j = 0; j < mat[i].size(); j++)
			{
			cout << mat.at(i).at(j) << " ";
			}
			cout << endl;
			}
		}
		else if (operation == "D_value")
		{
			cout<<solveDet(cramers_matrix(input));
		}
		else if (operation == "solve")
		{
			if (n == num_vars(input))
			{
				vector<string> solns = solve_equs(input);
				for (int i = 0; i < solns.size(); i++)
				{
					cout << solns[i] << endl;
				}
			}
			else
				cout << "can't solve" << endl;
		}

		else
		{
			int space_index=operation.find(' ');
			string oper = operation.substr(0, space_index);
			if (oper == "equation")
			{
				int num = atof(operation.substr(space_index + 1).c_str());
				if (input[num - 1][0] == '+')
				{
					cout << del_plus(input[num - 1])<< endl;
				}
				else
				{
					cout << input[num - 1] << endl;
				}
			}

			else if (oper == "column")
			{
				string var = operation.substr(space_index+1);
				vector<float> column = get_column(input, var);
				for (int i = 0; i < column.size(); i++)
				{
					cout << column[i] << endl;
				}
			}

			else if (oper == "add")
			{
				int nd_space = operation.rfind(' ');
				int equ2 = atof(operation.substr(nd_space + 1).c_str());
				int equ1 = atof(operation.substr(space_index + 1, nd_space - space_index - 1).c_str());

				string out = zero_coff(add(input, equ1-1, equ2-1));
				if (out[0] == '+') out = del_plus(out);
				cout << out<< endl;
			}
			else if (oper == "subtract")
			{
				int nd_space = operation.rfind(' ');
				int equ2 = atof(operation.substr(nd_space + 1).c_str());
				int equ1 = atof(operation.substr(space_index + 1, nd_space - space_index - 1).c_str());

				string out = zero_coff(subtract(input, equ1-1, equ2-1));
				if (out[0] == '+') out = del_plus(out);
				cout << out << endl;
			}

			else if (oper == "D")
			{
				string var = operation.substr(space_index + 1);

				vector<vector<float>> mat = cramers_matrix_of_var(input,var);
				for (int i = 0; i < mat.size(); i++)
				{
					for (int j = 0; j < mat[i].size(); j++)
					{
						cout << mat.at(i).at(j) << " ";
					}
					cout << endl;
				}
				
			}


			else if (oper == "substitute")
			{
				int last_space = operation.rfind(' '); int second_space;
				for (int i = 0; i < operation.length(); i++)
				{
					if (operation[i] == ' ' && i != space_index)
					{
						second_space = i;
						break;
					}
				}
				string var = operation.substr(space_index + 1, second_space - space_index - 1);
				int equ1 = atof(operation.substr(second_space + 1, last_space - second_space - 1).c_str());
				int equ2 = atof(operation.substr(last_space + 1).c_str());
				//string out = substitute(var, input[equ1 - 1], input[equ2 - 1]);
				string out = zero_coff(exchange(input, var, equ1 - 1, equ2 - 1));
				if (out[0] == '+') out = del_plus(out);
				cout << out <<endl;
			}

		}



		getline(cin, operation);

	}







	return 0;
}