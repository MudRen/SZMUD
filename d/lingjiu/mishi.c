/*Updated by George 98/7*/
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǹ����������ң�ǽ�ϵ��͵Ʒ����谵�Ļƹ⡣������������书�ؼ������ڡ�
LONG
	);

	set("exits", ([
		"south" : __DIR__"midao13",
		"north" : __DIR__"midao14",
		"east" : __DIR__"midao14",
		"up" : __DIR__"huayuan",
		]));
/*
	set("objects",([
		__DIR__"obj/zhemeitu1" : 1,
		__DIR__"obj/zhemeitu2" : 1,
		__DIR__"obj/liuyangzhangfa1" : 1,
		__DIR__"obj/liuyangzhangfa2" : 1,
		__DIR__"obj/qijianpu" : 1,
	]));
*/
	setup();
}

int valid_leave(object me, string dir)
{

	if (  (dir == "up") && (present("iron hand", this_player())||present("bamboo",this_player())||present("silk",this_player())||present("stone",this_player())||present("tu",this_player())||present("pu",this_player())) ) 
	
	return notify_fail
		("�ؼ����ܴ����˵�\n");
	
	return ::valid_leave(me, dir);
}
