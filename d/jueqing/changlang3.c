// Filename:   /d/jueqinggu/changlang3.c 长廊3
// Code:       Jiuer
// Date:       Aug 15, 2001


inherit ROOM;

void create()
{
	set("short","长廊");
	set("long",@LONG
这是一条长长的走廊，墙壁都是用两尺厚的青石板垒筑而成。南北
墙上均匀地凿嵌着一些小洞，里面摆放着一些灯盏，把长廊照得亮堂堂
的。长廊北面是芝房，但是门锁着(lock)，西面是丹房。
LONG);
	
	set("exits",([ 
		"east" : __DIR__"changlang4",
		"west" : __DIR__"danfang",
		]));
	set("item_desc", (["lock" : "一把大铜锁,看来你得找把钥匙(key)才能打开。\n",
			]));
	set("cost",1);
	setup();	
}
 
void init()
{
	add_action("do_unlock","unlock");
	add_action("do_open","open");
}
int do_unlock(string arg)
{
	object ob;
	if (query("exits/north"))
		return notify_fail("这扇门已经是打开的。\n");
	if (!arg || (arg != "men" && arg != "north"))
		return notify_fail("你要打开什么？\n");
	if (!(ob = present("key", this_player())))
		return notify_fail("门锁着呐，你去找找管家张二叔吧。\n");
	set("exits/north", __DIR__"zhifang");
	message_vision("$N用一把钥匙打开房门。\n", this_player());
    destruct(ob);
	return 1;
}

int valid_leave(object me, string dir)
{
//	if (!wizardp(me) && objectp(present("ling tuisi", environment(me))) && 
	//	(dir == "west" || dir =="east"))
	//	return notify_fail("凌翰林挡住了你：请勿入内宅。\n");
    return ::valid_leave(me, dir);
}

