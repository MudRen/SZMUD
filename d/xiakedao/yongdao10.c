//Cracked by Roath
// xiakedao/yongdao10.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "��");
        set("long", @LONG
�������������࣬�����Ǽ��Ҵҵ�����������в������µ��ӡ�
����˶��ֳ�ʳ����߱߳ԣ�Ω�ֵ�����ʱ�䡣�����������ڵ���ؤ
����ǽ����Ȼ��˯��һ��С������ż⣬������ӵ��͡�
LONG );

      set("exits", ([
		"out" : __DIR__"dadong",
		"north" : __DIR__"gate",
      ]));

	set("indoors", "xiakedao" );
	set("cost", 0);
    	set("objects", ([ 
		__DIR__ +"npc/gaibang" : 1, 
    	]));
	setup();
}
