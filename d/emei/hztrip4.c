// Code of ShenZhou
//Jay 9/30/96

inherit ROOM;

void create()
{
        set("short", "С����");
	set("long", @LONG
���Ƕ���ɽ�𶥻��������һƬС���֡������Ƕ�����Ů�����ǵ��޹���
���������º������һ���ˡ�
LONG);
	set("exits", ([
		"northwest" : __DIR__"hztrip3",
		"north" : __DIR__"sleeproom",
	]));
	set("objects", ([
		__DIR__"npc/qingshu" : 1,
	]));

        set("outdoors", "emei" );

	set("cost", 2);
	setup();

}

int valid_leave(object me, string dir)
{
	if (dir=="north") {
	return notify_fail("��ô�ĵ��ӣ��봳����Ů���ӵ��޹���\n");
	}
	   return ::valid_leave(me, dir);
}

