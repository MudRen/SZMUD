// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "��ɽ����");
        set("long", @LONG
�����Ƿ�ɽ��ı��š��������򱱣���������ɴ���ԭ����
��һ��������Ĵ���Ƿ�ɽ�����Ҫ�ֵ���
LONG
        );
        set("exits", ([
		"northup" : __DIR__"nanling",
		"south" : __DIR__"street2",
	]));

	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
