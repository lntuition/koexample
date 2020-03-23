## 개념 

### udev란?
udev (userspace device) 는 Linux kernel 2.6 이상 제공하는 기능으로, device 연결시 디바이스 드라이버와 연계하여 자동으로 디바이스 노드 (/dev/xxx) 를 생성/제거하게 Control 할 수 있는 기능이다.

### udev 구성 요소
- libudev : 디바이스 정보를 접근할 수 있도록 해주는 library
- udevd : /dev 하위의 디바이스 노드, rules 수행 등을 처리해주는 daemon
- udevadmn : 디바이스 노드에 대한 control 및 diagnostic 를 관리하는 utility

### udev 동작 방법
1. 부팅시 init에서 sysfs를 /sys로 마운트함으로서 udevd 동작
1. udevd(udev daemon)이 각 rules 파일을 읽고, 메모리에 규칙을 저장 그 후 시스템에서 디바이스 노드 생성
1. 실제 디바이스가 detect 되면 sysfs에 등록하고, 해당 디바이스는 사용자 공간에서 /sys에 등록
1. udevd로 netlink socket을 이용하여 새로운 디바이스가 생성되었다는 메세지 전송
1. udevd는 /sys의 디바이스 내용 (Major/Minor number 및 디바이스 파일 이름 등)을 이용하여 /dev에 디바이스 노드 생성

- 등록된 장치에서 변화(연결/해제)등이 발생하면 kernel에서 event(uevent)를 보내주며, udevd가 rule을 실행

### udev 관련 파일
- /etc/udev/udev.conf : 기본적인 환경 설정을 할 수 있는 파일
- /etc/udev/rules.d : rules 파일이 정의된 디렉토리

## 예제
1. `make install` 을 실행해주세요.
1. USB를 연결합니다.
1. `make check` 로 로그를 확인해주세요.
1. `make clean` 으로 예제를 제거합니다.

## 질문

### console 에 출력하는 방법은 없을까요?
udev rule을 수행하는것이 udevd 인것 같아서, 정석 방법은 없는 것 같습니다.

### rules 파일이 수행이 안됩니다 (1)
상관 없는것 같기는 한데 rules 파일이 숫자로 시작하는지 확인해 주세요.

### rules 파일이 수행이 안됩니다 (2)
혹시 실행하려는 파일에 권한이 잘 박혀 있는지(즉, chmod 명령어로 권한을 주셨는지) 확인해 주세요.

### rules 파일은 multiline 지원이 안되나요?
Rules cannot span multiple lines 라는데요, 안됩니다. 

## 참고자료
http://reactivated.net/writing_udev_rules.html  
https://coreos.com/os/docs/latest/using-systemd-and-udev-rules.html  
https://kldp.org/node/154396  
https://mokga.tistory.com/54  
https://lascrea.tistory.com/89  
