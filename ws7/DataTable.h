//
// OOP345 Workshop 7  - STL Algorithms
// Created by Gayeon Ko on 2018-11-07.
// Student Id is 040 704 124
// Email Address is gko4@myseneca.ca 
//
#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H

#include <iostream>
#include <fstream> //otherwise will get a warning in linux
#include <vector>
#include <string>
#include <iomanip> // setw(), setprecision()
#include <cmath> // sqrt(), pow()
#include <algorithm> // sort()
#include <numeric>   // accumulate(), inner_product()

namespace w7 {
	template <typename T>
	class DataTable {
		int m_width;
		int m_decimal;
		//The object retrieves the data values from the file 
		//and stores them in its instance variables.
		std::vector<T> v_xValue;
		std::vector<T> v_yValue;
	public:
		DataTable(std::ifstream& fs, const int w, const int d) : m_width(w), m_decimal(d) {
			std::string lines;
			int count = 0;
			while (!fs.eof()) {
				while (std::getline(fs, lines)) {
					count++;
				}
			}
			fs.clear();
			fs.seekg(0, fs.beg);

			// initialize vector
			T xTemp, yTemp;
			for (int i = 0; i < count; ++i) {
				fs >> xTemp >> yTemp;
				if (fs.fail()) {
					std::string err = "ERROR!!";
					throw err;
				}
				v_xValue.push_back(xTemp);
				v_yValue.push_back(yTemp);
			}
		}

		T mean() const { 
			T avg = std::accumulate(v_yValue.begin(), v_yValue.end(), T(0)) / v_yValue.size();
			return avg;
		}
		T sigma() const { 
			T avg = mean();
			T total = 0;
			for (size_t i = 0; i < v_yValue.size(); ++i) {
				total += std::pow(v_yValue[i] - avg, 2); // std::pow()
			}
			total = total / (T)(getSize() - 1);
			total = std::sqrt(total); // std::sqrt()
			return total;
		}
		T median() const {
			std::vector<T> yTemp = v_yValue;
			std::sort(yTemp.begin(), yTemp.end(), [](T i, T j){return i<j;});
			return yTemp[(v_yValue.size() / 2)];
		}

		void regression(T& slope, T& y_intercept) const {
			T x = std::accumulate(v_xValue.begin(), v_xValue.end(), (T)0);
			T y = std::accumulate(v_yValue.begin(), v_yValue.end(), (T)0);
			T xy = std::inner_product(v_xValue.begin(), v_xValue.end(), v_yValue.begin(), (T)0);
			T xx = std::inner_product(v_xValue.begin(), v_xValue.end(), v_xValue.begin(), (T)0);
			T size = v_yValue.size();

			slope = (size * xy - x * y) / (size * xx - x * x);
			y_intercept = (y - slope * x) / size;
		}
		void display(std::ostream& os) const {
			os << std::setw(m_width) << "x" << std::setw(m_width) << "y" << std::endl;
			os << std::fixed << std::setprecision(m_decimal);
			
			for (size_t i = 0; i < getSize(); ++i) {
				os << std::setw(m_width) << v_xValue[i] << std::setw(m_width) << v_yValue[i] << std::endl;
			}
		}

		size_t getSize() const {
			return v_xValue.size();
		}
	};

	template <typename T>
	std::ostream& operator<<(std::ostream& os, const DataTable<T>& src) {
		src.display(os);
		return os;
	}
}
#endif
