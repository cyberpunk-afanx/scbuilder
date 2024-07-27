from keystone import *
import sys

if(len(sys.argv) != 3):
    print("USAGE: kstone.exe shellcode.asm shellcode.bin")
    print("pip install keystone-engine")
    exit(-1)

ks = Ks(KS_ARCH_X86, KS_MODE_32)

with open(sys.argv[1], 'r') as f:
    assembly_code = f.read()
    
encoding, count = ks.asm(assembly_code)

print(f"Assembled code: {encoding}")

with open(sys.argv[2],'wb') as f:
    f.write(bytes(encoding))
    
print("[+] Well, done!")
