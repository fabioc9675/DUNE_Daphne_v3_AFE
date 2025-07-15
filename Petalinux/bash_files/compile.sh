#! bash
# File to create and load the device tree overlay

echo ""
echo ""
echo "#############################################################################"
echo "Creacion de la carpeta device tree"
echo "#############################################################################"
echo ""
echo ""

xmutil unloadapp
mkdir /lib/firmware/xilinx/kr260_slow/
mv kr260_slow.bit.bin kr260_slow.dtbo shell.json /lib/firmware/xilinx/kr260_slow/

echo ""
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
echo "Final del proceso"
echo "#############################################################################"
echo ""
echo ""

#chown petalinux:petalinux /dev/spidev3.0
#chmod 777 /dev/spidev3.0