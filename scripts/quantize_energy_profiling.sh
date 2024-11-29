#!/bin/sh
python quantize.py ./trained_custom/checkpoints/energy_profiling/input_data_size/ep_demo_1021_qat_best.pth.tar \
  ./trained_custom/checkpoints/energy_profiling/input_data_size/ep_demo_1021_qat_best-q.pth.tar \
  -v --device MAX78000 "$@"
exec $SHELL