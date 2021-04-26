// Code of ShenZhou
// Room: /d/xiangyang/bingyi.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ж������������������ǽ������һ�����ң�д������������ġ�����
��ɽ���ĸ����֡��������������ڼ䣬��춴˴�������顣��ʱ�������Ų�����
��Ϊ��һ��ȫ�����ҵ�������������ü�������Ϻ�ŵĵ�ͼ(ditu)��һ������ȴ
�Ǵ������ҿ�һ�������´����������˵�˼����
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -2, "y" : -4 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"lianwuc",
  "west" : __DIR__"ceting",
  "out" : __DIR__"ysfdamen",
]));
	set("item_desc", ([
		"ditu" : "��ͼ��������ϣ��㿴�ò����������ϡ�Ƽ�������ЩȦȦ��㡣\n",
	]));
        set("objects", ([
               __DIR__"npc/menggong" : 1, 
        ]));
	setup();
	replace_program(ROOM);
}

