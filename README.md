# esp8266-boilerplate
An boilerplate for creating esp 8266 projects.

## Preparing environment

Follow the [esp-env instructions](https://github.com/easyqiot/esp-env) to 
prepare the environment.

### How to use

```bash

cd <path/to/esp>/nonos/sdk
git clone git@github.com:easyqiot/esp8266-boilerplate.git

```

## Transfer compiled boilerplate

```bash

make flash

```

If you want to see the boilperplate output; you can use your favorite *Serial 
Console*. For example:

```bash

screen /dev/ttyUSB0 115200

```

**NOTICE:** The baud rate value is important to be `115200`.

