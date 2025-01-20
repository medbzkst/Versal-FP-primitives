all: config.cfg

config.cfg: gen_config.py
	rm -f config.cfg
	/usr/bin/python3 $^

clean:
	rm -rf config.cfg
