//Cracked by Roath
// xiakedao/yongdao4.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "��");
        set("long", @LONG
������������խ���������˲������������Ҳ���ǵͰ�������
��ɴ������͵ƻζ��������������������Ӱ���Ų���ણ����˶�
��������������о���Щ������
LONG );

      set("exits", ([
		"west" : __DIR__"xiuxi",
		"south" : __DIR__"yongdao1",
		"east" : __DIR__"shufang",
		"north" : __DIR__"yangxinju",
      ]));

	set("indoors", "xiakedao" );
	set("cost", 0);
    	set("objects", ([ 
		__DIR__ +"npc/dali" : 1, 
    	]));

	set("no_clean_up", 1);
	setup();
}

