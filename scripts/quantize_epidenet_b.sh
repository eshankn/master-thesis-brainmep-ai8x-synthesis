#!/bin/sh
python quantize.py ./trained_custom/checkpoints/energy_profiling/input_data_size/epidenet_b_v3.2_1016_baseline_qat_best.pth.tar \
  ./trained_custom/checkpoints/energy_profiling/input_data_size/epidenet_b_v3.2_1016_baseline_qat_best-q2.pth.tar \
  -v --device MAX78000 "$@"
exec $SHELL