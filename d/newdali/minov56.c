// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov56.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
�����������ļ�����ݣ���Ϊ������������һ����̨��̨�ϰڷ���һ����
����λ����������������֮������λ���ǽ�Ϲ��д����Ƥ���ϻ����λ��ƣ���
�Ǹ����ͼ�ڡ�һλ�ϼ�˾�������ڼ�̨ǰ������ȫ��ļ�˾���
LONG);
	set("objects", ([
		__DIR__"npc/wyjisi" : 1,
		]));
	set("exits", ([
		"out" : __DIR__"minov55",
		]));
	set("area", "��³��");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
