// Room: sroad1.c ���
// By jpei

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ������ʯ�̳ɵĴ�������߾����������񶼳ɶ��Ĵ������ˡ�����
������·��
LONG);
        set("outdoors", "chengdu");
        set("cost", 1);
	set("exits", ([
		"north" : __DIR__"dananmen",
                "southwest" : __DIR__"tulu1",
	]));

	setup(); 
	replace_program(ROOM);
}
