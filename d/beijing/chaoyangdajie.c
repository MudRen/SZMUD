//Cracked by Roath
// Room: /d/beijing/chaoyangdajie.c

inherit ROOM;

void fix_exits_for_night(int is_night)
{
    if (is_night) {
	set("exits", ([ 
	  "west" : __DIR__"jingshan",
	  "south": __DIR__"wangfudajie",
	  "north" : __DIR__"dongzhidajie",
	]));
    } else {
	set("exits", ([ 
	  "west" : __DIR__"jingshan",
	  "south": __DIR__"wangfudajie",
	  "east" : __DIR__"chaoyangmen",
	  "north" : __DIR__"dongzhidajie",
	]));
    }
}

void create()
{
	set("short", "�����Ŵ��");
	set("long", @LONG
���Ƿ������ֵĳ����Ŵ�֣���ֽ����������ˮ������������Ϣ����Ⱥ��
�������������������ֱ���ˣǹ���ա��ٻ�С�ԣ�Ӧ�о��У��۶���ò�ɼ�һ�ߡ�
LONG
	);
	fix_exits_for_night(0);
	set("outdoors", "beijing");
	set("cost", 2);
	set("no_clean_up", 0);

	setup();
}


