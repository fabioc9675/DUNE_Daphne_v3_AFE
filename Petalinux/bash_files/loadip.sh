#! bash
# File to load the device tree overlay and provide permissions

echo ""
echo "#############################################################################"
echo "Cargar el device tree overlay"
echo "#############################################################################"
echo ""
echo ""

xmutil unloadapp
xmutil loadapp kr260_slow

echo ""
echo ""
echo "#############################################################################"
echo "Cambiar propietario de los IPs"
echo "#############################################################################"
echo ""
echo ""

chown petalinux:petalinux /dev/spidev3.0
chown petalinux:petalinux /dev/spidev4.0
chown petalinux:petalinux /dev/i2c-7
chown petalinux:petalinux /dev/i2c-8
chown petalinux:petalinux /dev/ttyUL0
chown petalinux:petalinux /dev/ttyUL1
chown petalinux:petalinux /dev/gpiochip2
chown petalinux:petalinux /dev/gpiochip3
# chown petalinux:petalinux -R /sys/class/gpio/gpiochip484/*
# chown petalinux:petalinux -R /sys/class/gpio/gpiochip492/*

echo ""
echo ""
echo "#############################################################################"
echo "Exportar los GPIO pins"
echo "#############################################################################"
echo ""
echo ""

echo 492 | sudo tee /sys/class/gpio/export
echo 493 | sudo tee /sys/class/gpio/export
echo 494 | sudo tee /sys/class/gpio/export
echo 495 | sudo tee /sys/class/gpio/export
echo 496 | sudo tee /sys/class/gpio/export
echo 497 | sudo tee /sys/class/gpio/export
echo 498 | sudo tee /sys/class/gpio/export
echo 499 | sudo tee /sys/class/gpio/export

chown petalinux:petalinux -R /sys/class/gpio/gpio492/*
chown petalinux:petalinux -R /sys/class/gpio/gpio493/*
chown petalinux:petalinux -R /sys/class/gpio/gpio494/*
chown petalinux:petalinux -R /sys/class/gpio/gpio495/*
chown petalinux:petalinux -R /sys/class/gpio/gpio496/*
chown petalinux:petalinux -R /sys/class/gpio/gpio497/*
chown petalinux:petalinux -R /sys/class/gpio/gpio498/*
chown petalinux:petalinux -R /sys/class/gpio/gpio499/*

echo ""
echo ""
echo "#############################################################################"
echo "Cambiar permisos de los IPs"
echo "#############################################################################"
echo ""
echo ""

chmod 777 /dev/spidev3.0
chmod 777 /dev/spidev4.0
chmod 777 /dev/i2c-7
chmod 777 /dev/i2c-8
chmod 777 /dev/ttyUL0
chmod 777 /dev/ttyUL1
chmod 777 /dev/gpiochip2
chmod 777 /dev/gpiochip3

echo ""
echo ""
echo "#############################################################################"
echo "Fin de la prueba"
echo "#############################################################################"
echo ""
echo ""