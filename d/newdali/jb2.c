// Code of ShenZhou
// Room: /dali/jb2.c
// AceP

inherit ROOM;

void create()
{
	set("short", "���˶�");
	set("long", @LONG
��������С·��ǰ�����������������ţ�����ʯ�Ͽ��С����˶ɡ�������ȥ��
�ͻص�����ɽ���ˡ�
LONG );

	set("exits", ([
                "east"   : __DIR__"jb1",
                "west" : __DIR__"wls17",
	]));

	set("cost", 2);
        set("outdoors", "dali");
	setup();
}
