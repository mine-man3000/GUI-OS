What I want to do: 
- [X] Booting 
- [X] Basic GUI 
- [X] Mouse Detection 
- [ ] Working Mouse Sensitivity
- [ ] Buttons
- [X] Keyboard Driver
- [ ] Window system
- [ ] Read From FAT32
- [ ] Terminal
- [ ] Port *Something*
- [X] fix GUI flickers
- [ ] fix Window rendering
- [ ] Fix Icon and Text rendering

What I need to do:
- [X] Load an IDT so that exceptions and interrupts can be handled.
- [ ] Write a physical memory allocator, a good starting point is a bitmap allocator.
- [ ] Write a virtual memory manager that can map, remap and unmap pages.
- [ ] Begin parsing ACPI tables, the most important one is the MADT since it contains information about the APIC.
- [ ] Start up the other CPUs. stivale2 provides a facility to make this less painful.
- [ ] Set up an interrupt controller such as the APIC.
- [ ] Configure a timer such as the Local APIC timer, the PIT, or the HPET.
- [ ] Implement a scheduler to schedule threads in order make multitasking possible.
- [ ] Design a virtual file system (VFS) and implement it. The traditional UNIX VFS works and saves headaches when porting software, but you can make your own thing too.
- [ ] Implement a simple virtual file system like a memory-only tmpfs to avoid crippling the design of your VFS too much while implementing it alongside real storage filesystems.
- [ ] Decide how to abstract devices. UNIX likes usually go for a /dev virtual filesystem containing device nodes and use ioctl() alongside standard FS calls to do operations on them.
- [ ] Get a userland going by loading executables from your VFS and running them in ring 3. Set up a way to perform system calls.
- [ ] Write a PCI driver.
- [ ] Add support for a storage medium, the easiest and most common ones are AHCI and NVMe.
