// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "��ɽ����");
        set("long", @LONG
�����Ƿ�ɽ��Ķ��š��������߾�Ҫ�뿪��ɽ��ȥ�������ˡ���
��һ��������Ĵ���Ƿ�ɽ�����Ҫ�ֵ���
LONG
        );
        set("exits", ([
		"west" : __DIR__"street4",
		"east" : __DIR__"qzroad1",
	]));

	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
