// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov13.c

inherit ROOM;

void create()
{
	set("short", "�سص̰�");
	set("long", @LONG
�����غ��̰���ֲ��ɫ����ܰ�������ֳơ�����ӡ���������һ����֧����
�����ֻ�ɫ��ӭ�������ʳơ�����ӡ������֭�ӡ�����ͬΪ��صĳ�ˮ�ڣ���
�ƺ��ڡ�
LONG);
	set("exits", ([
		"westdown" : __DIR__"minov4",
		"eastup" : __DIR__"minov14",
		]));
	set("area", "��٤��");
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
