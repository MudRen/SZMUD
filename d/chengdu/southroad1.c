// Room: southroad1.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�������ϴ���ϣ����ż�ʵ����ʯ����档�����Ե����ֶ��ˡ�
���������Ƕ���֣�����һֱ�߶����ϴ�֡����Ϸ������������֣�
�����и��͵꣬��������: �����䡣
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "southeast"  : __DIR__"kedian",
	    "west"       : __DIR__"nandajie2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
