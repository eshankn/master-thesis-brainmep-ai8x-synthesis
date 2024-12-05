#!/bin/sh
python ai8xize.py --verbose --test-dir demos --prefix test \
  --device MAX78000 --compact-data --softmax --overwrite --energy \
  --config-file ./networks/epidenet_b.yaml \
  --checkpoint-file ../brainmep-ai8x-training/logs/cross_validation/epidenet_v3.2_768samples_qat8/2024.10.06-160447-epidenet_b_v3.2_768samples_patient5_leaveout4_lr1e-4_adam_multisteplr132_qat_train/qat_best-q.pth.tar \
  --sample-input ../brainmep-ai8x-training/logs/sample_chbmit_singlech_768samples_patient_5_leave_out_seizure_4.npy "$@"
exec $SHELL