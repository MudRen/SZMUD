// July 31,2000
// Code by April
// /gumu/houtang.c
// add exit north,april 01.08.28

inherit ROOM;

void create()
{
		  set("short","����");

		  set("long",@LONG
�����ǹ�Ĺ�����á�����������һ��ׯ�϶������������գ�����ʱ��
�˸е�һ˿��ܰ����������ʯ���ϸ�����һ����(hua1)(hua2)������ͨ��
�������������ɺ�Ȫ��
LONG);

		  set("item_desc",(["hua1" : "
    ���ڻ������������һ����ʮ�����꣬���ڶԾ���װ����һ����ʮ
�������Ѿ�ߣ��������裬�����̺򡣻��о������곤Ů����ò��������
ü���ޣ��۽�֮��ȴ��������һ��ɱ����\n",
				"hua2" : "
    ���ڻ�����һ��������ߵ�������ˡ�ֻ������������������ʳָָ
�Ŷ����ǣ�ֻ�Ǳ������⣬��òȴ��������
				\n",
				  ]));

	set("objects", ([ 
		"/kungfu/class/gumu/npc/longer": 1, 
		"/kungfu/class/gumu/npc/yangguo": 1,
		]) );

		  set("exits",([ 
			  "south" : __DIR__"mudao14",
			  "north" : __DIR__"songhe",
			  ]));

		  set("cost",1);

	  setup();
}

