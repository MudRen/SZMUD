// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov29.c

inherit ROOM;

void create()
{
	set("short", "�����в�");
	set("long", @LONG
����������в�����Ĵ󣬿����������е��㰸��ɫ���㣬���ŵ������
�ƾ�ϸ���Ե����ڲ�ͬ�����̵Ĺ�Ʒ��Ʈ����ζ�����䵱�е�һ����ͷ�ر����ۡ�
���������Ǳ���ļ�������
LONG);
	set("objects", ([
		__DIR__"npc/byjisi.c" : 1,
		]));
	set("exits", ([
		"down" : __DIR__"minov28",
		]));
	set("area", "������");
	set("cost", 3);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
