// Convert H from size UxNUM_STATES to size NxNUM_STATES
Eigen::Matrix<double, N, NG_nav::Defs::NUM_STATES> H = 
              Eigen::Matrix<double, N, NG_nav::Defs::NUM_STATES>::Zero();
for(Eigen::Index i = 0; i < static_cast<Eigen::Index>(sensor_states.size()); i++)
{
  NG_nav::Defs::State state = sensor_states[static_cast<size_t>(i)];
  H.block(state, 0, 1, NG_nav::Defs::NUM_STATES) = H_meas.block(i, 0, 1, NG_nav::Defs::NUM_STATES);
}

// this is from crawler ekf estimator 
// keywords: matrix, blocking, size conversion, eigen