//Cracked by Roath
// xiakedao/yongdao5.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "��");
        set("long", @LONG
��������ʯ�ף����������Ϊ����������ƽ���ź��ص�ʯש��
����ȥ�Ų�����Ϊ���ơ�������ɨ��һ����Ⱦ��ʯ������Щ���µ�С
�ӣ������ǵ�ȼ���͵ơ�����������������ʱ���������Ц��
LONG );

      set("exits", ([
		"north" : __DIR__"yongdao2",
		"east" : __DIR__"xianliao",
		"west" : __DIR__"bingqi",
		"south" : __DIR__"liangong",
      ]));

	set("indoors", "xiakedao" );
	set("cost", 0);
    	set("objects", ([ 
		__DIR__ +"npc/xingxiu" : 1, 
    	]));

	setup();
}


