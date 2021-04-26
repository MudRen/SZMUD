// Code of ShenZhou
// Room: /dali/wls.c
// AceP

inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
������һȺ��ɽ��������ɽ�ˣ�ɽ�����������ɵĽ�������������ɽ���¡�
��ɽ������̫�ߣ���ʮ���վ��������������ĵ�����������ɽ��·�ڣ����峤
�����������ࡣ·���п�����(paizi)��
LONG );

	set("item_desc", ([
		"paizi" :"������ֵ���ɶ�������֮�ʣ�Ӧ��ǰ������֮������������ɽ�������˵���أ�\n",
		]));

	set("exits", ([
		"westup" : __DIR__"jhg1",
		"north"  : __DIR__"wls1",
		"south"  : __DIR__"wls1",
		"east"   : __DIR__"wls17",
	]));
	set("cost", 3);
        set("outdoors", "dali");
	setup();
}

int valid_leave(object me, string dir)
{
	object *inv;
	object ob;
	int i;
	me=this_player();

	if (dir == "westup")
	{
		if (!present("bai tie", me) || query("visited")) 
			return notify_fail("����������˵��: ���������ڶ������䣬�����˵Ȳ��ô��ţ���\n"); 
		else {
			inv=all_inventory(me);
			for(i=0; i<sizeof(inv); i++) 
				if (inv[i]->is_character())
					return notify_fail("����������˵��: ���������ڶ������䣬�����˵Ȳ��ô��ţ���\n"); 
			if (objectp(ob=present("corpse", me)))
				return notify_fail("���������Ӻȵ�: ������������ʬ������ʲô����\n"); 
			message_vision("���������Ӷ�$N�������˸�Ҿ����: ����ӭ����ǰ�����񡣡�\n",me);
			set("visited",1);
			return ::valid_leave(me, dir);
		}
	}
	return ::valid_leave(me, dir);
}
