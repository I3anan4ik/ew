#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "functions.h"
#include "function.h"

// 2 |   5	27	33	35	38	45

void save_table_to_csv(const std::string& filename, const Table& table) {
    std::ofstream out(filename);
    out << "k;x_k;x_{k+1};f(x_k);f(x_{k+1});d\n";
    out << std::fixed << std::setprecision(8);

    auto write_row = [&](const auto& row) {
        out << static_cast<int>(row[0]) << ";"
            << row[1] << ";"
            << row[2] << ";"
            << row[3] << ";"
            << row[4] << ";"
            << row[5] << "\n";
    };

    if (table.size() <= 30) {
        for (const auto& row : table) {
            write_row(row);
        }
    } else {
        for (size_t i = 0; i < 15; ++i) {
            write_row(table[i]);
        }

        out << "...;...;...;...;...;...\n";

        for (size_t i = table.size() - 15; i < table.size(); ++i) {
            write_row(table[i]);
        }
    }
}



int main() {
    std::cout << std::fixed << std::setprecision(8);

    std::cout << "Uniform:\n";
    Table t_uniform1;
    Table t_uniform2;
    Table t_uniform3;
    Table t_uniform4;
    Table t_uniform5;
    Table t_uniform6;
    double x1_min_uni = min_uniform_search(-9.0, 0.0, 1e-6, foo1, &t_uniform1);
    double x2_min_uni = min_uniform_search(-4.0, 0.0, 1e-6, foo2, &t_uniform2);
    double x3_min_uni = min_uniform_search(-1.0, 3.0, 1e-6, foo3, &t_uniform3);
    double x4_min_uni = min_uniform_search(-4.0, 1.0, 1e-6, foo4, &t_uniform4);
    double x5_min_uni = min_uniform_search(-2.0, 0.0, 1e-6, foo5, &t_uniform5);
    double x6_min_uni = min_uniform_search(0.0, 2.0, 1e-6, foo6, &t_uniform6);
    std::cout << "foo1: x = " << x1_min_uni << " f(x) = " << foo1(x1_min_uni) << '\n';
    std::cout << "foo2: x = " << x2_min_uni << " f(x) = " << foo2(x2_min_uni) << '\n';
    std::cout << "foo3: x = " << x3_min_uni << " f(x) = " << -foo3(x3_min_uni) << '\n';
    std::cout << "foo4: x = " << x4_min_uni << " f(x) = " << foo4(x4_min_uni) << '\n';
    std::cout << "foo5: x = " << x5_min_uni << " f(x) = " << foo5(x5_min_uni) << '\n';
    std::cout << "foo6: x = " << x6_min_uni << " f(x) = " << foo6(x6_min_uni) << '\n';
    save_table_to_csv("uniform_foo1.csv", t_uniform1);
    save_table_to_csv("uniform_foo2.csv", t_uniform2);
    save_table_to_csv("uniform_foo3.csv", t_uniform3);
    save_table_to_csv("uniform_foo4.csv", t_uniform4);
    save_table_to_csv("uniform_foo5.csv", t_uniform5);
    save_table_to_csv("uniform_foo6.csv", t_uniform6);

    std::cout << "Localization:\n";
    Table t_local1;
    Table t_local2;
    Table t_local3;
    Table t_local4;
    Table t_local5;
    Table t_local6;
    double x1_min_local = min_local(-3.0, 0.0, 1e-6, foo1, &t_local1);
    double x2_min_local = min_local(-4.0, 0.0, 1e-6, foo2, &t_local2);
    double x3_min_local = min_local(-1.0, 3.0, 1e-6, foo3, &t_local3);
    double x4_min_local = min_local(-4.0, 1.0, 1e-6, foo4, &t_local4);
    double x5_min_local = min_local(-2.0, 0.0, 1e-6, foo5, &t_local5);
    double x6_min_local = min_local(0.0, 2.0, 1e-6, foo6, &t_local6);
    std::cout << "foo1: x = " << x1_min_local << " f(x) = " << foo1(x1_min_local) << '\n';
    std::cout << "foo2: x = " << x2_min_local << " f(x) = " << foo2(x2_min_local) << '\n';
    std::cout << "foo3: x = " << x3_min_local << " f(x) = " << -foo3(x3_min_local) << '\n';
    std::cout << "foo4: x = " << x4_min_local << " f(x) = " << foo4(x4_min_local) << '\n';
    std::cout << "foo5: x = " << x5_min_local << " f(x) = " << foo5(x5_min_local) << '\n';
    std::cout << "foo6: x = " << x6_min_local << " f(x) = " << foo6(x6_min_local) << '\n';
    save_table_to_csv("local_foo1.csv", t_local1);
    save_table_to_csv("local_foo2.csv", t_local2);
    save_table_to_csv("local_foo3.csv", t_local3);
    save_table_to_csv("local_foo4.csv", t_local4);
    save_table_to_csv("local_foo5.csv", t_local5);
    save_table_to_csv("local_foo6.csv", t_local6);

    std::cout << "Dihotomia:\n";
    Table t_diho1;
    Table t_diho2;
    Table t_diho3;
    Table t_diho4;
    Table t_diho5;
    Table t_diho6;
    double x1_min_dih = min_dihotomia(-3.0, 0.0, 1e-6, foo1, &t_diho1);
    double x2_min_dih = min_dihotomia(-4.0, 0.0, 1e-6, foo2, &t_diho2);
    double x3_min_dih = min_dihotomia(-1.0, 3.0, 1e-6, foo3, &t_diho3);
    double x4_min_dih = min_dihotomia(-4.0, 1.0, 1e-6, foo4, &t_diho4);
    double x5_min_dih = min_dihotomia(-2.0, 0.0, 1e-6, foo5, &t_diho5);
    double x6_min_dih = min_dihotomia(0.0, 2.0, 1e-6, foo6, &t_diho6);
    std::cout << "foo1: x = " << x1_min_dih << " f(x) = " << foo1(x1_min_dih) << '\n';
    std::cout << "foo2: x = " << x2_min_dih << " f(x) = " << foo2(x2_min_dih) << '\n';
    std::cout << "foo3: x = " << x3_min_dih << " f(x) = " << -foo3(x3_min_dih) << '\n';
    std::cout << "foo4: x = " << x4_min_dih << " f(x) = " << foo4(x4_min_dih) << '\n';
    std::cout << "foo5: x = " << x5_min_dih << " f(x) = " << foo5(x5_min_dih) << '\n';
    std::cout << "foo6: x = " << x6_min_dih << " f(x) = " << foo6(x6_min_dih) << '\n';
    save_table_to_csv("diho_foo1.csv", t_diho1);
    save_table_to_csv("diho_foo2.csv", t_diho2);
    save_table_to_csv("diho_foo3.csv", t_diho3);
    save_table_to_csv("diho_foo4.csv", t_diho4);
    save_table_to_csv("diho_foo5.csv", t_diho5);
    save_table_to_csv("diho_foo6.csv", t_diho6);

    std::cout << "Golden_ration:\n";
    Table t_gold1;
    Table t_gold2;
    Table t_gold3;
    Table t_gold4;
    Table t_gold5;
    Table t_gold6;
    double x1_min_gold = min_golden_ration(-3.0, 0.0, 1e-6, foo1, &t_gold1);
    double x2_min_gold = min_golden_ration(-4.0, 0.0, 1e-6, foo2, &t_gold2);
    double x3_min_gold = min_golden_ration(-1.0, 3.0, 1e-6, foo3, &t_gold3);
    double x4_min_gold = min_golden_ration(-4.0, 1.0, 1e-6, foo4, &t_gold4);
    double x5_min_gold = min_golden_ration(-2.0, 0.0, 1e-6, foo5, &t_gold5);
    double x6_min_gold = min_golden_ration(0.0, 2.0, 1e-6, foo6, &t_gold6);
    std::cout << "foo1: x = " << x1_min_gold  << " f(x) = " << foo1(x1_min_gold ) << '\n';
    std::cout << "foo2: x = " << x2_min_gold  << " f(x) = " << foo2(x2_min_gold ) << '\n';
    std::cout << "foo3: x = " << x3_min_gold  << " f(x) = " << -foo3(x3_min_gold ) << '\n';
    std::cout << "foo4: x = " << x4_min_gold  << " f(x) = " << foo4(x4_min_gold ) << '\n';
    std::cout << "foo5: x = " << x5_min_gold  << " f(x) = " << foo5(x5_min_gold ) << '\n';
    std::cout << "foo6: x = " << x6_min_gold  << " f(x) = " << foo6(x6_min_gold ) << '\n';
    save_table_to_csv("gold_foo1.csv", t_gold1);
    save_table_to_csv("gold_foo2.csv", t_gold2);
    save_table_to_csv("gold_foo3.csv", t_gold3);
    save_table_to_csv("gold_foo4.csv", t_gold4);
    save_table_to_csv("gold_foo5.csv", t_gold5);
    save_table_to_csv("gold_foo6.csv", t_gold6);

    std::cout << "Fibbonachi:\n";
    Table t_fibo1;
    Table t_fibo2;
    Table t_fibo3;
    Table t_fibo4;
    Table t_fibo5;
    Table t_fibo6;
    double x1_min_fib = min_fibbonachi(-3.0, 0, 1e-6, foo1, &t_fibo1);
    double x2_min_fib = min_fibbonachi(-4.0, 0.0, 1e-6, foo2, &t_fibo2);
    double x3_min_fib = min_fibbonachi(-1.0, 3.0, 1e-6, foo3, &t_fibo3);
    double x4_min_fib = min_fibbonachi(-4.0, 1.0, 1e-6, foo4, &t_fibo4);
    double x5_min_fib = min_fibbonachi(-2.0, 0.0, 1e-6, foo5, &t_fibo5);
    double x6_min_fib = min_fibbonachi(0.0, 2.0, 1e-6, foo6, &t_fibo6);
    std::cout << "foo1: x = " << x1_min_fib << " f(x) = " << foo1(x1_min_fib) << '\n';
    std::cout << "foo2: x = " << x2_min_fib << " f(x) = " << foo2(x2_min_fib) << '\n';
    std::cout << "foo3: x = " << x3_min_fib << " f(x) = " << -foo3(x3_min_fib) << '\n';
    std::cout << "foo4: x = " << x4_min_fib << " f(x) = " << foo4(x4_min_fib) << '\n';
    std::cout << "foo5: x = " << x5_min_fib << " f(x) = " << foo5(x5_min_fib) << '\n';
    std::cout << "foo6: x = " << x6_min_fib << " f(x) = " << foo6(x6_min_fib) << '\n';
    save_table_to_csv("fibo_foo1.csv", t_fibo1);
    save_table_to_csv("fibo_foo2.csv", t_fibo2);
    save_table_to_csv("fibo_foo3.csv", t_fibo3);
    save_table_to_csv("fibo_foo4.csv", t_fibo4);
    save_table_to_csv("fibo_foo5.csv", t_fibo5);
    save_table_to_csv("fibo_foo6.csv", t_fibo6);

    return 0;
}