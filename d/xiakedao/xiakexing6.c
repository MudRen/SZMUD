//Cracked by Roath
// xiakedao/xiakexing6.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room"; 

#include <room.h>;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
��ǰ�������������δ���κ�װ�Σ���ͺ�ֲڵ�ʯ��������С׭��
�������һ���ܸ٣������˹��桹����������һ��С��(xiaozi)����
��ʯ��ʯ������ذڷ��ţ������������£������ڲ�������
LONG );

      set("exits", ([
		"out" : __DIR__"xiakexing5",
		"north"   : __DIR__"xkx21",
		"south"   : __DIR__"xkx22",
		"east"   : __DIR__"xkx23",
		"west"   : __DIR__"xkx24",
]));
	set("item_desc",([
	    "xiaozi" : "
С��д���ǣ���������ȳ���������Ωʯ�������񹦣�����...����
������ּ���ģ���ѱ档\n",
	]));

//	create_door("out", "ʯ��", "enter", DOOR_CLOSED);
	set("indoors", "xiakedao" );
	set("cost", 0);
	setup();
}

