/**************************************************************************************************
* Copyright (C) 2019-2021 Maxim Integrated Products, Inc. All Rights Reserved.
*
* Maxim Integrated Products, Inc. Default Copyright Notice:
* https://www.maximintegrated.com/en/aboutus/legal/copyrights.html
**************************************************************************************************/

/*
 * This header file was automatically @generated for the ep_test_v3.2_768_qat8_sleep network from a template.
 * Please do not edit; instead, edit the template and regenerate.
 */

#ifndef __CNN_H__
#define __CNN_H__

#include <stdint.h>
typedef int32_t q31_t;
typedef int16_t q15_t;

/* Return codes */
#define CNN_FAIL 0
#define CNN_OK 1

/*
  SUMMARY OF OPS
  Hardware: 445,732 ops (431,152 macc; 14,500 comp; 80 add; 0 mul; 0 bitwise)
    Layer 0 (block1_conv1d_bn_relu_1): 15,380 ops (12,304 macc; 3,076 comp; 0 add; 0 mul; 0 bitwise)
    Layer 1 (block1_maxpool1d_1): 3,072 ops (0 macc; 3,072 comp; 0 add; 0 mul; 0 bitwise)
    Layer 2 (block2_conv1d_bn_relu_1): 32,256 ops (30,720 macc; 1,536 comp; 0 add; 0 mul; 0 bitwise)
    Layer 3 (block2_conv1d_bn_relu_2): 124,416 ops (122,880 macc; 1,536 comp; 0 add; 0 mul; 0 bitwise)
    Layer 4 (block2_conv1d_bn_relu_3): 124,416 ops (122,880 macc; 1,536 comp; 0 add; 0 mul; 0 bitwise)
    Layer 5 (block2_conv1d_bn_relu_4): 100,880 ops (99,328 macc; 1,552 comp; 0 add; 0 mul; 0 bitwise)
    Layer 6 (block2_maxpool1d_1): 1,536 ops (0 macc; 1,536 comp; 0 add; 0 mul; 0 bitwise)
    Layer 7 (block3_conv1d_bn_relu_1): 43,344 ops (43,008 macc; 336 comp; 0 add; 0 mul; 0 bitwise)
    Layer 8 (block3_maxpool1d_1): 320 ops (0 macc; 320 comp; 0 add; 0 mul; 0 bitwise)
    Layer 9 (block5_avgpool1d): 80 ops (0 macc; 0 comp; 80 add; 0 mul; 0 bitwise)
    Layer 10 (block6_dense): 32 ops (32 macc; 0 comp; 0 add; 0 mul; 0 bitwise)

  RESOURCE USAGE
  Weight memory: 6,000 bytes out of 442,368 bytes total (1.4%)
  Bias memory:   84 bytes out of 2,048 bytes total (4.1%)
*/

/* Number of outputs for this network */
#define CNN_NUM_OUTPUTS 2

/* Port pin actions used to signal that processing is active */

#define CNN_START LED_On(1)
#define CNN_COMPLETE LED_Off(1)
#define SYS_START LED_On(0)
#define SYS_COMPLETE LED_Off(0)

/* Run software SoftMax on unloaded data */
void softmax_q17p14_q15(const q31_t * vec_in, const uint16_t dim_vec, q15_t * p_out);
/* Shift the input, then calculate SoftMax */
void softmax_shift_q17p14_q15(q31_t * vec_in, const uint16_t dim_vec, uint8_t in_shift, q15_t * p_out);

/* Stopwatch - holds the runtime when accelerator finishes */
extern volatile uint32_t cnn_time;

/* Custom memcopy routines used for weights and data */
void memcpy32(uint32_t *dst, const uint32_t *src, int n);
void memcpy32_const(uint32_t *dst, int n);

/* Enable clocks and power to accelerator, enable interrupt */
int cnn_enable(uint32_t clock_source, uint32_t clock_divider);

/* Disable clocks and power to accelerator */
int cnn_disable(void);

/* Perform minimum accelerator initialization so it can be configured */
int cnn_init(void);

/* Configure accelerator for the given network */
int cnn_configure(void);

/* Load accelerator weights */
int cnn_load_weights(void);

/* Verify accelerator weights (debug only) */
int cnn_verify_weights(void);

/* Load accelerator bias values (if needed) */
int cnn_load_bias(void);

/* Start accelerator processing */
int cnn_start(void);

/* Force stop accelerator */
int cnn_stop(void);

/* Continue accelerator after stop */
int cnn_continue(void);

/* Unload results from accelerator */
int cnn_unload(uint32_t *out_buf);

/* Turn on the boost circuit */
int cnn_boost_enable(mxc_gpio_regs_t *port, uint32_t pin);

/* Turn off the boost circuit */
int cnn_boost_disable(mxc_gpio_regs_t *port, uint32_t pin);

#endif // __CNN_H__
