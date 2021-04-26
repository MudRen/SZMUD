//Cracked by Roath
// Room: /d/beijing/caishikou.c

inherit ROOM;

void fix_exits_for_night(int is_night);

void create()
{
	set("short", "���п�");
	set("long", @LONG
�����ǳ�͢��ն����ʾ�ڵĳ�����·������һ����ͷ̨ (tai)��Ӧ�þ�����
���õġ���Զ�����ŵ����ֻ�����Լ��������������ɱ�����չ����������ĶԱȡ�
LONG
	);
	fix_exits_for_night(0);
	set("no_clean_up", 0);

	set("item_desc", ([
	"tai" : "һ��Ѫ���߰ߵ�ľ̨�ӡ�\n",
]));
	set("outdoors", "beijing");
	set("cost", 2);
	setup();
}


void fix_exits_for_night(int is_night)
{
    object me = this_object();
    if (is_night) {
	me->set("exits", ([ /* sizeof() == 3 */
	  "east"  : __DIR__"tianqiao",
	  "north" : __DIR__"xuanwudajie",
          "south" : __DIR__"youandajie",
	]));
    }else{
	me->set("exits", ([ /* sizeof() == 3 */
	  "east"  : __DIR__"tianqiao",
	  "north" : __DIR__"xuanwudajie",
	  "west"  : __DIR__"guanganmen",
	  "south" : __DIR__"youandajie",
	]));
    }
}

