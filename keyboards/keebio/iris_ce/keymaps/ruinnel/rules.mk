# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE =  no        # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
SPLIT_KEYBOARD = yes
ENCODER_ENABLE = no
RGB_MATRIX_ENABLE = no
OS_DETECTION_ENABLE = yes

LTO_ENABLE = yes
TRI_LAYER_ENABLE = yes

# USB 통신 빈도를 낮춰 KVM 및 리눅스 버퍼 과부하 방지
USB_POLLING_INTERVAL_MS = 8  # 125Hz로 설정 (기본값인 1ms/1000Hz에서 변경)
SUSPEND_ENABLE = no  # 키보드가 절전 모드(Suspend)로 들어가는 기능을 아예 차단 [1]
