// Code of ShenZhou
// Room: lumf.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "¹����");
	set("long", @LONG
�������ǳ�������֮һ���ֽ�֥�̷壬λ����ص������档�嶥��һ��
���ӣ�Բ�����̣�ÿ���Ϻ��Ķ����������������ǻ�ѩ����ʱ��Ψ�д˷廹
¶�ڰ�ѩ֮�⣬���Ҳ�ǽ�ɽ�Ĳοͱ��λ�õ���Ҫ��ǡ�
LONG	);
	set("exits", ([ 
              "westdown" : __DIR__"jiglz",
              "southeast" : __DIR__"yuzf",
        ]));
        set("fjing", 1);
/*
        set("objects",([
		__DIR__"npc/laohu" : 1,
	]));
*/
        set("outdoors", "changbai");

        set("count", random(3)+1);

	setup();
}
