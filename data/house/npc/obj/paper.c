#include <ansi.h>
inherit ITEM;
void create()
{	set_name("白纸",({"paper"}));
	set("long","一张白纸。上面写着：\n");
	set("unit","张");
	set("value",0);
}
void init()
{	add_action("do_write","write");
}

int do_write(string arg)
{  if(!arg) return notify_fail("你要写什么？\n");
   this_object()->set("long",this_object()->query("long")+arg+"\n");
   write("ok.\n");return 1;
}
