// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "��ɽ���");
        set("long", @LONG
��ɽ��ֵ���ب�������ϱ���һ���ưܵ����������һ��
�ĳ���������д�š�Ӣ�ۻ�ݡ��ĸ����֡�
LONG
        );
        set("exits", ([
		"south" : __DIR__"yxhuiguan",
		"east" : __DIR__"street2",
		"west" : __DIR__"street0",
	]));

	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
