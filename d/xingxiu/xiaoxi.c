// Code of ShenZhou
// xiaoxi.c
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "ɽ´СϪ");
	set("long", @LONG
Ϫˮ�ڴ�ת���ƹ�һ��ߵأ�ˮ����ľ��ʢ��ɽ�����һƬ��
�٣�ˮ����䲻����ƥ������������������齦�񣬶ٳ���ۡ���
����һƬ���ɡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"luzhou2",
		"west" : __DIR__"lake2",
	]));
	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

