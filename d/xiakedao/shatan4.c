//Cracked by Roath
// Dong 1/9/98
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";

void create()
{
    	set("short", "ɳ̲");
    	set("long", @LONG
ɳ̲�ı�����һ�Ÿ߸ߵ�Ҭ���������ϻ����ż���Ҭ�ӡ�һ��
�紵����Ҭ�������ҡ���ţ�Ҭ�Ӻ����Ҫ�������Ƶġ������м���
�м���С���������ժҬ�ӡ�
LONG
    	);

    	set("exits", ([
    		"west" : __DIR__"shatan",
    		"east" : __DIR__"shatan5",
    	]));
    	set("outdoors", "xiakedao");
	set("objects", ([ 
                "/d/village/npc/kid" : 3, 
      ]));

    	setup();
}

/*
int do_climb(string arg)
{	object coat, me = this_player();
	int dodge;
	if ( (!arg ) || (arg != "tree") )
		return 0;
	dodge = me->query_skill("dodge", 1);
	if (dodge <= 10)
	{	message_vision("$N˫�ֱ������ˣ�������������ϧû����һ��͵���������\n", me);
		return 1;
	}
	message_vision("$N˫�ֱ������ˣ���������������ȥ��\n", me);
	
	return 1;
}
*/
