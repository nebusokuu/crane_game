




# 動作の流れについて
TIM6の割り込み(50Hzか100Hz)

# クロックについて
HSIからPLLで64MHzにしてる

# ADCについて
5ピンをDMA使ってCircularモードでずっと取得する
実用上はリセット直後の値を使うと良いと思う