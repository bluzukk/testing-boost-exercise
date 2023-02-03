#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"

using namespace Eigen;
// using namespace std;

struct MatrixIOFixture {
  MatrixIOFixture()
  {
    filename = "../data/m3.csv";
    dimension = 3;
    expectedMatrix = MatrixXd(dimension, dimension);
    expectedMatrix << 0.680375, 0.59688, -0.329554,
        -0.211234,  0.823295,  0.536459,
         0.566198, -0.604897, -0.444451;
  }
  std::string filename;
  int dimension;
  MatrixXd expectedMatrix;
};

BOOST_FIXTURE_TEST_SUITE(MatrixIOTests, MatrixIOFixture)

BOOST_AUTO_TEST_CASE(openData)
{
  MatrixXd actualMatrix = matrixIO::openData(filename, dimension);
  BOOST_TEST(actualMatrix.isApprox(expectedMatrix, 1e-8));
  BOOST_TEST(actualMatrix.rows() == dimension);
  BOOST_TEST(actualMatrix.cols() == dimension);
}

BOOST_AUTO_TEST_SUITE_END()
