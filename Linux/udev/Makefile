install:
	sudo cp 98-action.rules /etc/udev/rules.d
	sudo cp action.sh /tmp
	sudo chmod +x /tmp/action.sh
	sudo udevadm control --reload

clean:
	sudo rm -f /etc/udev/rules.d/98-action.rules
	sudo rm -f /tmp/action.sh
	sudo rm -f /tmp/action.log
	sudo udevadm control --reload

check:
	cat /tmp/action.log