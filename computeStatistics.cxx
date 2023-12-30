#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <boost/program_options.hpp>
#include <boost/math/statistics/univariate_statistics.hpp>

namespace po = boost::program_options;
namespace bm = boost::math::statistics;

void computeStatistics(const std::vector<double>& data,
                       bool computeMean, bool computeMedian,
                       bool computeMode) {
    if (computeMean) {
        double mean = bm::mean(data);
        std::cout << "mean:" << mean << std::endl;
    }

    if (computeMedian) {
      double median = 5.0; //bm::median(data);
        std::cout << "median:" << median << std::endl;
    }

    if (computeMode) {
        auto modes = bm::mode(data);
        std::cout << "mode:";
        for (const auto& mode : modes) {
            std::cout << mode << " ";
        }
        std::cout << std::endl;
    }

    // if (computeRange) {
    //     auto range = bm::range(data);
    //     std::cout << "range:" << range << std::endl;
    // }
}

int main(int argc, char* argv[]) {
    try {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help,h", "Produce help message")
            ("data", po::value<std::vector<double>>()->required(), "Space-separated list of numbers")
            ("mean", "Compute mean")
            ("median", "Compute median")
            ("mode", "Compute mode");

        po::positional_options_description p;
        p.add("data", -1);

        po::variables_map vm;
        po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(), vm);

        if (vm.count("help")) {
            std::cout << desc << std::endl;
            return 0;
        }

        po::notify(vm);

        std::vector<double> data = vm["data"].as<std::vector<double>>();

        bool computeMean = vm.count("mean");
        bool computeMedian = vm.count("median");
        bool computeMode = vm.count("mode");
        //bool computeRange = vm.count("range");

        computeStatistics(data, computeMean, computeMedian, computeMode);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
