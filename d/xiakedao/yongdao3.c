//Cracked by Roath
// xiakedao/yongdao3.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "��");
        set("long", @LONG
��֪�������ѽ�������ɽ����������Щ�Ŀİ�����ᵽһ��Ũ
�صĳ���������ʯ������Щ�ವ����̦��ż�������»���µĵ�����
�����������˾�����ʩһ����ɫ������
LONG );

      set("exits", ([
		"west" : __DIR__"yongdao1",
		"north" : __DIR__"dadong",
      ]));
      set("no_clean_up", 1);

	set("indoors", "xiakedao" );
	set("cost", 0);
    	set("objects", ([ 
		__DIR__ +"npc/xueshan" : 1, 
    	]));

	setup();
}
