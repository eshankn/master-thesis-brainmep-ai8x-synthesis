#!/bin/sh
python quantize.py ../brainmep-ai8x-training/logs/cross_validation/epidenet_v3.2_768samples/2024.10.03-003225-epidenet_b_v3.2_768samples_patient5_leaveout0_lr1e-4_adam_train/ptq/best_wo_batchnorm.pth.tar \
  ../brainmep-ai8x-training/logs/cross_validation/epidenet_v3.2_768samples/2024.10.03-003225-epidenet_b_v3.2_768samples_patient5_leaveout0_lr1e-4_adam_train/ptq/best_wo_batchnorm-q.pth.tar \
  -v --device MAX78000 "$@"
exec $SHELL