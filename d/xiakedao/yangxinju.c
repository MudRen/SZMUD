//Cracked by Roath
// xiakedao/yangxinju.c ���ľ�
// Ssy

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "���ľ�");
        set("long", @LONG
���С���г����˲�ҩζ��ϸ��ʱ����ǽ�Ǳ��в���ҩ�䣬����
װ���˲�ҩ��С��������һ�ŷ�������������һλ���ߡ�
LONG );

	set("exits", ([
		       "south" : __DIR__"yongdao4",
		       ]));

	set("indoors", "xiakedao" );
        set("no_fight", 1);

	set("cost", 0);
    	set("objects", ([ 
		__DIR__ +"npc/doctor" : 1, 
    	]));

	set("no_clean_up", 1);
	setup();
}

