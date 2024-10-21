#include <iostream>

std::cout << std::endl << "--ORIGINAL DATA--" << std::endl;
std::cout << " sensor states:" << std::endl;
for(auto& st : states_meas)
{
  std::cout << st << std::endl;
}
std::cout << " KF STATES:" << std::endl;
for(auto& st : m_kf_states)
{
  std::cout << st << std::endl;
}
std::cout << " z:" << std::endl;
std::cout << z_meas << std::endl;
std::cout << " H:" << std::endl;
std::cout << H_meas << std::endl;
std::cout << " cov:" << std::endl;
std::cout << cov_meas << std::endl;

std::cout << std::endl << "--MODIFIED DATA--" << std::endl;
std::cout << " states:" << std::endl;
for(auto& st : sensor_states)
{
  std::cout << st << std::endl;
}
std::cout << " z:" << std::endl;
std::cout << z_mod << std::endl;
std::cout << " H:" << std::endl;
std::cout << H_mod << std::endl;
std::cout << " cov:" << std::endl;
std::cout << cov_mod << std::endl;

std::cout << " sensor_to_ekf:" << std::endl;
for(auto& st : sensor_to_ekf)
{
  std::cout << st << std::endl;
}

std::cout << std::endl << "--FINAL DATA--" << std::endl;
std::cout << " states:" << std::endl;
for(auto& st : sensor_states)
{
  std::cout << st << std::endl;
}
std::cout << " z:" << std::endl;
std::cout << z << std::endl;
std::cout << " H:" << std::endl;
std::cout << H << std::endl;
std::cout << " cov:" << std::endl;
std::cout << cov << std::endl;


// This is how i print all my pretty lil matricies in ng_nav
// keywords: matrix, cout, debug, print statements