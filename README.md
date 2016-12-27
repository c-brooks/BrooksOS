# BrooksOS
A simple operating system, following [this book](http://littleosbook.github.io/).

## Usage
```  
  sudo apt-get install build-essential nasm genisoimage
  nasm -f elf32 loader.s
  make brooks_os.iso
```


.iso files can be run easily with VirtualBox.


Go to New -> Type: Other, Version: Other/Unknown(64 bit).

Start the VM and select your .iso file when prompted.
