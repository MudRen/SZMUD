// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "����ɽ��");
        set("long", @LONG
�����������һ��ɽ�ڡ����������ϵĴ����ɽ�������Ǻ��ϵ�
�ؽ硣���Ϲ㶫������ʢ�����к���֮ʿ��
LONG
        );
        set("exits", ([
		"northdown": __DIR__"road4",
		"southdown" : __DIR__"ngate",
	]));

	set("cost",3);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
