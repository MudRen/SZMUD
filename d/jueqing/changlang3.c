// Filename:   /d/jueqinggu/changlang3.c ����3
// Code:       Jiuer
// Date:       Aug 15, 2001


inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
����һ�����������ȣ�ǽ�ڶ��������ߺ����ʯ���������ɡ��ϱ�
ǽ�Ͼ��ȵ���Ƕ��һЩС��������ڷ���һЩ��յ���ѳ����յ�������
�ġ����ȱ�����֥��������������(lock)�������ǵ�����
LONG);
	
	set("exits",([ 
		"east" : __DIR__"changlang4",
		"west" : __DIR__"danfang",
		]));
	set("item_desc", (["lock" : "һ�Ѵ�ͭ��,��������Ұ�Կ��(key)���ܴ򿪡�\n",
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
		return notify_fail("�������Ѿ��Ǵ򿪵ġ�\n");
	if (!arg || (arg != "men" && arg != "north"))
		return notify_fail("��Ҫ��ʲô��\n");
	if (!(ob = present("key", this_player())))
		return notify_fail("�������ţ���ȥ���ҹܼ��Ŷ���ɡ�\n");
	set("exits/north", __DIR__"zhifang");
	message_vision("$N��һ��Կ�״򿪷��š�\n", this_player());
    destruct(ob);
	return 1;
}

int valid_leave(object me, string dir)
{
//	if (!wizardp(me) && objectp(present("ling tuisi", environment(me))) && 
	//	(dir == "west" || dir =="east"))
	//	return notify_fail("�躲�ֵ�ס���㣺��������լ��\n");
    return ::valid_leave(me, dir);
}
