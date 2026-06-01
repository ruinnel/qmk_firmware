/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// #define USE_I2C
#define EE_HANDS
#define RGBLIGHT_LAYERS
#define RGBLIGHT_SPLIT
#define RGBLIGHT_LED_COUNT 68

// =======================================================
// Dell 모니터의 KVM 스위치를 통해 연결 할 경우 Linux에서 키보드가 멈추는 현상 수정을 위한 옵션들
// Linux의 usb driver가 전력 부하등의 처리에 민감해 전력 부하가 걸리는 LED를 끄고 추가로 아래 설정들이 필요.
// VBUS 설정을 상위 핀(GP0) 그대로 유지하며 노이즈만 필터링합니다
// =======================================================
#undef USB_VBUS_PIN
#define USB_VBUS_PIN GP0
#define USB_VBUS_TIMEOUT 500  // KVM 전환 시 전압이 출렁여도 0.5초간 버티며 연결 유지

// KVM 스위치 및 리눅스 환경을 위한 RP2040 방어 옵션
#define HAL_USB_DRIVE_CURRENT_8MA     // RP2040 신호 강도 최대화
#define USB_SUSPEND_WAKEUP_DELAY 1000  // 전환 시 1초 대기 안정화
#define SPLIT_WATCHDOG_ENABLE         // Full-Duplex 통신 끊김 감시
#define SPLIT_CONNECTION_CHECKER      // 통신 유실 시 강제 복구