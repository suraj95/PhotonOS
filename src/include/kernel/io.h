#ifndef _io_h
#define _io_h

#include <system.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <phapi.h>

#include <fs/vfs.h>
#define COM_PORT 0x3f8   /* COM1 */

/* output byte */
void outb(size_t ad, uint8_t v);

/* output word */
void outw(size_t ad, uint16_t v);

/* output word */
void outl(size_t ad, size_t v);

/* input byte */
uint8_t inb(size_t ad);

/* input word */
uint16_t inw(size_t ad);

/* input word */
size_t inl(size_t ad);

/* generic terminal I/O */
int tty_write_char(const char c);

int tty_write(const char *buf, size_t len);

char tty_read_char();

int tty_read(char *buf, size_t len);

/* serial I/O */
void init_serial();

char serial_read_char();

int serial_read(char *buf, size_t len);

int serial_write_char(char a);

int serial_write(const char *buf, size_t len);

/* print registers */
void print_regs(registers_t *regs);

/* write char to vga */
int vga_write_char(const char c);

/* read char from keyboard */
char kb_read_char();

/* write string to vga */
int vga_write(const char *buf, size_t len);

/* read string from keyboard */
int kb_read(char *buf, size_t len);

/* get char from keyboard */
int getchark();

/* get line from keyboard */
char *getsk(char *str);

/* put string to vga */
int putsk(const char* string);

/* formatted printing for kernel mode */
int printk(const char* format, ...);

// Kernel space file functions
int kcreate(const char *pathname, int flags);

int kmkdir(const char *pathname);

int kopen(const char *pathname, int flags);

int kwrite(int fd, char *buf, size_t count);

size_t kread(int fd, void *buf, size_t count);

int kclose(int fd);

int krewind(int fd);

DIR *kopendir(char *pathname);

int kclosedir(DIR *d);

struct dentry *kreaddir(DIR *d);

// User space file functions
int open(const char *pathname, int flags);

int read(int fd, char *buf, size_t count);

int write(int fd, char *buf, size_t count);

int close(int fd);

#endif
