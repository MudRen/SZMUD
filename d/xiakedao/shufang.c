//Cracked by Roath
// xiakedao/shufang.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "�鷿");
        set("long", @LONG
�������͵����鷿�������Ǽ���ֱ���ݶ��Ĵ���ܣ����������
�顣��Щ����ǵ����Ӹ��ظ߼����޶�����ʫ���黭����ѧ�ص䣬��
��������һλ�����������ⷭ�ģ����������������ӭ�˹�����
LONG );

      set("exits", ([
		"west" : __DIR__"yongdao4",
      ]));
	set("objects", ([	
		__DIR__ + "npc/xueshi" : 1,
	]));
	set("indoors", "xiakedao" );
	set("cost", 0);
	setup();
}
