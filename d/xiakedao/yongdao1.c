//Cracked by Roath
// xiakedao/yongdao1.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "��");
        set("long", @LONG
����һ����������������ǽ�ϵ����͵ƣ������䰵����·ȴҲ
�����ɱ档�����ٲ����֮�������ڶ�������ˮ���ɽ�����������ʪ
������ǰ�м��������
LONG );

      set("exits", ([
		"north" : __DIR__"yongdao4",
		"south" : __DIR__"yongdao2",
		"east" : __DIR__"yongdao3",
      	"out" : __DIR__"pubu",
      ]));

	set("indoors", "xiakedao" );
	set("cost", 2);
	setup();
}

