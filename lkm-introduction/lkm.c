#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MatheuZ");
MODULE_DESCRIPTION("Introdução ao LKM");

static int __init lkm_init(void)
{
    printk(KERN_INFO "Olá, Mundo!\n");
    return 0;
} 

static void __exit lkm_exit(void)
{
    printk(KERN_INFO "Adeus, Mundo!\n");
}

module_init(lkm_init);
module_exit(lkm_exit);